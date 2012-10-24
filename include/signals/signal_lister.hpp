#ifndef __SIGNAL_LISTER_PP__
#define __SIGNAL_LISTER_PP__

#include <ns_macros.h>

/**
 * LIB2D::SIGNAL_LISTER >> CONSTRUCTORS/DESTRUCTOR/INITS
**/

template <typename TData>
Lib2D::Signal_lister<TData>::Signal_lister(void)
{
}

template <typename TData>
Lib2D::Signal_lister<TData>::Signal_lister(const Signal_lister<TData>& right):
	__signals(right.__signals)
{
}

template <typename TData>
Lib2D::Signal_lister<TData>::~Signal_lister(void)
{
	typename std::vector<Lib2D::func_base<TData>*>::iterator	it;
	typename std::vector<Lib2D::func_base<TData>*>::iterator	end;

	end = this->__signals.end();
	for (it = this->__signals.begin(); it != end; ++it)
		ns_cmc::ns_macros::f_delete_ptr(*it);
}

/**
 * LIB2D::SIGNAL_LISTER >> OPERATORS
**/

template <typename TData>
Lib2D::Signal_lister<TData>&
Lib2D::Signal_lister<TData>::operator=(const Signal_lister<TData>& right)
{
	this->__signals = right.__signals;
	return *this;
}

/**
 * LIB2D::SIGNAL_LISTER >> PUBLIC FUNCTIONS
**/

template <typename TData>
bool
Lib2D::Signal_lister<TData>::operator()(void)
{
	for (size_t i = 0; i < this->__signals.size(); ++i)
		(*this->__signals[i])(this->__typed_datas[i], this->__datas[i]);
	return true;
}

template <typename TData>
bool
Lib2D::Signal_lister<TData>::operator()(size_t callback)
{
	if (callback >= this->__signals.size())
	{
		m_error("no such callback");
		return false;
	}
	return (*this->__signals[callback])(this->__typed_datas[callback],
					    this->__datas[callback]);
}

template <typename TData>
bool
Lib2D::Signal_lister<TData>::operator()(size_t callback, TData* typed_datas, void* datas)
{
	if (callback >= this->__signals.size())
	{
		m_error("no such callback");
		return false;
	}
	return (*this->__signals[callback])(typed_datas, datas);
}

template <typename TData>
bool
Lib2D::Signal_lister<TData>::add(func_base<TData>* f, TData* typed_datas, void* datas)
{
	try
	{
		this->__signals.push_back(f);
		this->__typed_datas.push_back(typed_datas);
		this->__datas.push_back(datas);
	}
	catch (std::bad_alloc&)
	{
		m_error("could not add signal");
		ns_cmc::ns_macros::f_delete_ptr(f);
		return false;
	}
	return true;
}

template <typename TData>
bool
Lib2D::Signal_lister<TData>::remove(func_base<TData>* f)
{
	typename std::vector<Lib2D::func_base<TData>*>::iterator	it;
	typename std::vector<Lib2D::func_base<TData>*>::iterator	end;
	typename std::vector<TData*>::iterator				it_td;
	std::vector<void*>::iterator					it_d;

	it = this->__signals.end();
	it_td = this->__typed_datas.begin();
	it_d = this->__datas.begin();
	for (it = this->__signals.begin(); (*it)->fct != f; ++it, ++it_td, ++it_d)
		if (it == end)
			return false;
	ns_cmc::ns_macros::f_delete_ptr(*it);
	this->__signals.erase(it);
	this->__signals.erase(it_td);
	this->__signals.erase(it_d);
	return true;
}

#endif
