#ifndef __LIB2D_SIGNAL_MAKER__
#define __LIB2D_SIGNAL_MAKER__

#include <iostream>

namespace	Lib2D
{
	template <typename TData>
	class	func_base
	{
		public:
			virtual bool	operator()(TData* data, void* p) = 0;
	};
	template <typename TClass, typename TData>
	class	class_func: public func_base<TData>
	{
		public:
			typedef bool	(TClass::*func_type)(TData*, void*);
		private:
			TClass*		class_ptr;
			func_type	func_ptr;
		public:
					class_func(TClass* c, func_type f);
			virtual bool	operator()(TData* data, void* d);
	};
	template <typename TData>
	class	static_func: public func_base<TData>
	{
		public:
			typedef bool	(*func_type)(TData* data, void*);
		private:
			func_type	func_ptr;
		public:
					static_func(func_type f);
			virtual bool	operator()(TData* data, void* p);
	};
	template <typename TClass, typename TData>
	func_base<TData>*	make_func(TClass* instance,
					  bool (TClass::*func_ptr)(TData*, void*));
	template <typename TData>
	func_base<TData>*	make_func(bool (*func_ptr)(TData*, void*));
}

#include "signal_maker.hpp"

#endif
