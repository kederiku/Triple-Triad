#ifndef __LIB2D_SIGNAL_LISTER__
#define __LIB2D_SIGNAL_LISTER__

#include "signal_maker.h"
#include <vector>
#include <iostream>

namespace	Lib2D
{
	template <typename TData>
	class	Signal_lister
	{
		private:
			std::vector<Lib2D::func_base<TData>*>	__signals;
			std::vector<TData*>			__typed_datas;
			std::vector<void*>			__datas;
		public:
						Signal_lister(void);
						Signal_lister(const Signal_lister<TData>& right);
			virtual			~Signal_lister(void);
			Signal_lister<TData>&	operator=(const Signal_lister<TData>& right);
			bool			operator()(void);
			bool			operator()(size_t callback);
			bool			operator()(size_t callback, TData* typed_datas,
							   void* datas);
			bool			add(Lib2D::func_base<TData>* f, TData* typed_datas,
						    void* datas);
			bool			remove(Lib2D::func_base<TData>* f);
	};
}

#include "signal_lister.hpp"

#endif
