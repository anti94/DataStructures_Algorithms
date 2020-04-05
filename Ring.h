/*
 * Ring.h
 *
 *  Created on: 3 Nis 2020
 *      Author: Coder
 */
#include <iostream>

#ifndef MYHEADERS_RING_H_
#define MYHEADERS_RING_H_

using namespace std;

//1.way
//class Ring {
//
//	public:
//
//	class Iterator
//	{
//		public:
//		void Print()
//		{
//			cout << "Hi from iterator!" << endl;
//		}
//	};
//
//};


//2.way
//template<class T>
//class Ring {
//public:
//	class Iterator;
//
//};
//
//template<class T>
//class Ring<T>::Iterator
//{
//	public:
//	void Print()
//	{
//		cout << "Hi from iterator!" << T() << endl;
//	}
//};






template<class T>
class Ring{

	private:

		int m_size;
		int m_pos;
		T* m_values;
		mutable int data;

	public:

		class Iterator;

		Ring()
		{
			m_size = 0;
			m_values = NULL;
			m_pos = 0;
		}

		Ring(int size)
		{
			m_size = size;
			m_values = new T[size];
			m_pos = 0;
		}

		~Ring()
		{
			delete [] m_values;
		}

		void add(T addedValue)
		{
			m_values[m_pos++] = addedValue;

			if(m_pos == m_size)
				m_pos=0;
		}

		int size()
		{
			return m_size;
		}

		T& get(int pos)
		{
			return m_values[pos];
		}

		Iterator begin()
		{
			return Iterator(0, *this);
		}

		Iterator end()
		{
			return Iterator(m_size, *this);
		}

		void IncrementData() const
		{
			data++;
			//m_size++; //this data can not be written because this data is not mutable
		}
};


template<class T>
class Ring<T>::Iterator
{
		int m_pos;
		Ring& ring;

	public:

		Iterator(int pos, Ring& m_ring):m_pos(pos), ring(m_ring){}

		//postfix ++
		Iterator& operator++(int)
		{
			m_pos++;
			return *this;
		}

		//prefix ++
		Iterator& operator++()
		{
			m_pos++;
			return *this;
		}

		T& operator*()
		{
			return ring.get(m_pos);
		}


		bool operator!=(const Iterator& right)
		{
			return m_pos != right.m_pos;
		}
};






#endif /* MYHEADERS_RING_H_ */
