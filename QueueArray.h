#include <iostream>

using namespace std;

class Node1
{	
public:
	Node1 *rChild;
	int data;
	Node1 *lChild;

	Node1()
	{
		data = 0;
		rChild = NULL;
		lChild = NULL;
	}

	Node1(int data)
	{
		this->data = data;
		rChild = NULL;
		lChild = NULL;
	}

	~Node1()
	{
		delete rChild;
		delete lChild;
	}
};


template<class T>
class QueueArray
{
	public:
			int size, rear,front;
			T* queue;
	public:
		QueueArray(int size);
		QueueArray();
		~QueueArray();
		void Enqueue(T);
		T Dequeue();
		bool IsEmpty();
		bool IsFull();
		void Show();
};


template<class T>
QueueArray<T>::QueueArray(int size)
{
	this->size = size;
	rear = front = -1;
	queue = new T[size];
}

template<class T>
QueueArray<T>::QueueArray()
{
	size = 10;
	rear = front = -1;
	queue = new T[size];
}

template<class T>
QueueArray<T>::~QueueArray()
{
	delete [] queue;
}

//Addition function
template<class T>
void QueueArray<T>::Enqueue(T data)
{
	if(IsFull())
		cout <<"Queue Array is full"<<endl;
	else
		queue[++rear] = data;
}

//Deletion function
template<class T>
T QueueArray<T>::Dequeue()
{
	T data = 0;

	if(IsEmpty())
		cout <<"Queue Array is empty"<<endl;
	else
		data = queue[++front];
	
	return data;
}

template<class T>
bool QueueArray<T>::IsEmpty()
{
	return (rear == front)?1:0;
}

template<class T>
bool QueueArray<T>::IsFull()
{
	return (rear == size-1)?1:0;
}

template<class T>
void QueueArray<T>::Show()
{
	cout << "Elements of the queue array are listed as below:"<<endl;

	for(int i=front+1; i<=rear; i++)
	{
		cout << i <<".element of the stack is:" << queue[i] << endl;
	}
	
	cout<<endl;
}

