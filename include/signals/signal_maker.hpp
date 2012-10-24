#ifndef __SIGNAL_MAKER_PP__
#define __SIGNAL_MAKER_PP__

#include <list>
#include <exception>
#include <new>

/**
 * LIB2D::CLASS_FUNC
 * Son of LIB2D::FUNC_BASE, overloads its () operator
**/

template <typename TClass, typename TData>
Lib2D::class_func<TClass, TData>::class_func(TClass* c, func_type f):
	class_ptr(c),
	func_ptr(f)
{
}

template <typename TClass, typename TData>
bool
Lib2D::class_func<TClass, TData>::operator()(TData* data, void* d)
{
	return (this->class_ptr->*(this->func_ptr))(data, d);
}

/**
 * LIB2D::STATIC_FUNC
 * Son of LIB2D::FUNC_BASE, overloads its () operator
**/

template <typename TData>
Lib2D::static_func<TData>::static_func(func_type f):
	func_ptr(f)
{
}

template <typename TData>
bool
Lib2D::static_func<TData>::operator()(TData* data, void* p)
{
	return (*this->func_ptr)(data, p);
}

/**
 * LIB2D::MAKE_FUNC()
 * Static overloaded functions
 * Depending on parameters, returns a class_func* or a static_func*
**/

template <typename TClass, typename TData>
Lib2D::func_base<TData>*
Lib2D::make_func(TClass* instance, bool (TClass::*func_ptr)(TData*, void*))
{
	return (new (std::nothrow) class_func<TClass, TData>(instance, func_ptr));
}

template <typename TData>
Lib2D::func_base<TData>*
Lib2D::make_func(bool (*func_ptr)(TData*, void*))
{
	return (new (std::nothrow) static_func<TData>(func_ptr));
}

#endif
