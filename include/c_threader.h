#ifndef __C_THREADER__
#define __C_THREADER__

#include <pthread.h>
#include <iostream>
#include <vector>
#include "fc_timer.h"

namespace	ns_cmc
{
	class	c_threader
	{
		private:
			class	__c_lock
			{
				public:
					pthread_mutex_t*	v_mutex;
					pthread_cond_t*		v_condition;
					bool			v_locked;
				private:
					void	__f_destroy(void);
				public:
							__c_lock(void);
							__c_lock(const __c_lock& right);
					virtual		~__c_lock(void);
					__c_lock&	operator=(const __c_lock& right);
					bool		f_init(void);
			};
		public:
			typedef void*	(*thread_function)(void*);
			typedef std::vector<pthread_t>			t_thread_vect;
			typedef t_thread_vect::iterator			t_thread_it;
			typedef t_thread_vect::const_iterator		t_thread_cit;
			typedef t_thread_vect::reverse_iterator		t_thread_rit;
			typedef t_thread_vect::const_reverse_iterator	t_thread_crit;
			typedef std::vector<__c_lock*>			t_lock_vect;
			typedef t_lock_vect::iterator			t_lock_it;
			typedef t_lock_vect::const_iterator		t_lock_cit;
			typedef t_lock_vect::reverse_iterator		t_lock_rit;
			typedef t_lock_vect::const_reverse_iterator	t_lock_crit;
		private:
			t_thread_vect	__v_threads;
			t_lock_vect	__v_locks;
		private:
			void	__f_destroy(void);
		public:
					c_threader(void);
					c_threader(const c_threader& right);
			virtual		~c_threader(void);
			bool		f_init(size_t locks);
			c_threader&	operator=(const c_threader& right);
			bool		f_add_thread(thread_function fct, void* arg = NULL);
			size_t		f_threads(void) const;
			bool		f_join_threads(void);
			bool		f_lock(size_t lock, bool error = false);
			bool		f_try_lock(size_t lock, bool error = false);
			bool		f_unlock(size_t lock, bool error = false);
			bool		f_wait(size_t lock);
			bool		f_timed_wait(size_t lock, ns_cmc::fc_timer::s_ts timer);
			bool		f_broadcast(size_t lock);
			bool		f_locked(size_t lock) const;
			void		f_set_lock(size_t lock, bool state);
	};
}

#endif
