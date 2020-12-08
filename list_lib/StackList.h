#pragma once
#include "List.h"
#include <iostream>

using namespace std;

template <class T>
class TStackList
{
private:
	TList<T> list;
public:
	TStackList();
	TStackList(const TStackList& other);
	~TStackList();

	TStackList<T>& operator = (const TStackList<T>& other);

	void push(const T& elem);
	T pull();

	template <class T1>
	friend ostream& operator << (ostream& ostr, const TStackList<T1>& A);
	template <class T1>
	friend istream& operator >> (istream& istr, TStackList<T1>& A);

	TStackList<T> stack(T* mas, int size);
	void InsertSort(T elem);
};

template<class T>
TStackList<T>::TStackList()
{
}

template<class T>
TStackList<T>::TStackList(const TStackList& other)
{
	list = other.list;
}

template<class T>
 TStackList<T>::~TStackList()
{
}

 template<class T>
 inline TStackList<T>& TStackList<T>::operator=(const TStackList<T>& other)
 {
	 list = other.list;
	 return *this;
 }

 template<class T>
 void TStackList<T>::push(const T& elem)
 {
	 list.InsFirst(elem);
 }

 template<class T>
T TStackList<T>::pull()
 {
	T tmp = list.GetFirst()->GetData();
	list.DelFirst();
	return tmp;
 }

template<class T>
inline TStackList<T> TStackList<T>::stack(T* mas, int size)
{
	TStackList<T> result;
	for (int i = 0; i < size; i++)
		result.pull(mas[i]);
	return result;
}

template<class T>
inline void TStackList<T>::InsertSort(T elem)
{
	list.InsertSort(elem);
}

template<class T1>
inline ostream& operator<<(ostream& ostr, const TStackList<T1>& A)
{
	return ostr << A.list;
}

template<class T1>
inline istream& operator>>(istream& istr, TStackList<T1>& A)
{
	return istr >> A.list;
}
