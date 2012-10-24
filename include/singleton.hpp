#ifndef __SINGLETON_HPP__
#define __SINGLETON_HPP__

#include <new>
#include <pthread.h>

template <typename T>
class	singleton
{
	public:
		inline static T*	get_instance(void)
		{
			if (instance == NULL)
			{
				pthread_mutex_lock(&(mutex));
				if (instance == NULL)
					instance = new (std::nothrow) T;
				pthread_mutex_unlock(&(mutex));
			}
			return instance;
		};
		static void		kill(void)
		{
			delete instance;
			instance = NULL;
		};
	protected:
		singleton<T>(void)
		{
			pthread_mutex_init(&(this->mutex), 0);
		}
		virtual ~singleton<T>(void)
		{
			pthread_mutex_destroy(&(this->mutex));
		}
	private:
		static T*		instance;
		static pthread_mutex_t	mutex;
};

template <typename T>
	T*	singleton<T>::instance = NULL;

template <typename T>
	pthread_mutex_t	singleton<T>::mutex;

#endif

