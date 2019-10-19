#include <iostream>

using namespace std;

template<class T>
class QueueArray
{
	private:
			int size, rear, front;
			T* queue;
	public:
		QueueArray()
		{
			size = 10;
			rear = front = -1;
			queue = new T[size];
		}

		~QueueArray()
		{
			delete [] queue;
		}

		void Enqueue(int);
		void Dequeue();
		bool IsEmpty();
		bool IsFull();
		void Show();
};

//Addition function
template<class T>
void QueueArray<T>::Enqueue(int number)
{
	if(IsFull())
		cout <<"Queue Array is full"<<endl;
	else
		queue[++rear] = number;
}

//Deletion function
template<class T>
void QueueArray<T>::Dequeue()
{
	if(IsEmpty())
		cout <<"Queue Array is empty"<<endl;
	else
		queue[++front] = 0; 
}

template<class T>
bool QueueArray<T>::IsEmpty()
{
	return (rear==front)?1:0;
}

template<class T>
bool QueueArray<T>::IsFull()
{
	return (rear==size-1)?1:0;
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

