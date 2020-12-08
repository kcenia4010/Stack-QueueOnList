#pragma once
#include "List.h"
#include <iostream>
using namespace std;

template <class T>
class TQueueList
{
private:
	TList<T> list;
public:
	TQueueList();
	TQueueList(const TQueueList& other);
	~TQueueList();

	TQueueList<T>& operator = (const TQueueList<T>& other);

	void push(const T& elem);
	T pull();

	template <class T1>
	friend ostream& operator << (ostream& ostr, const TQueueList<T1>& A);
	template <class T1>
	friend istream& operator >> (istream& istr, TQueueList<T1>& A);

	TQueueList<T> queue(T* mas, int size);
	void InsertSort(T elem);
};

template<class T>
TQueueList<T>::TQueueList()
{
}

template<class T>
TQueueList<T>::TQueueList(const TQueueList& other)
{
	list = other.list;
}

template<class T>
TQueueList<T>::~TQueueList()
{
}

template<class T>
inline TQueueList<T>& TQueueList<T>::operator=(const TQueueList<T>& other)
{
	list = other.list;
	return *this;
}

template<class T>
void TQueueList<T>::push(const T& elem)
{
	list.InsLast(elem);
}

template<class T>
T TQueueList<T>::pull()
{
	T tmp = list.GetFirst()->GetData();
	list.DelFirst();
	return tmp;
}

template<class T>
inline TQueueList<T> TQueueList<T>::queue(T* mas, int size)
{
	TQueueList<T> result;
	for (int i = 0; i < size; i++)
		result.pull(mas[i]);
	return result;
}

template<class T>
inline void TQueueList<T>::InsertSort(T elem)
{
	list.InsertSort(elem);
}

template<class T1>
inline ostream& operator<<(ostream& ostr, const TQueueList<T1>& A)
{
	return ostr << A.list;
}

template<class T1>
inline istream& operator>>(istream& istr, TQueueList<T1>& A)
{
	return istr >> A.list;
}
