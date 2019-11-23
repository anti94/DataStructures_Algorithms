#include <iostream>

using namespace std;

template<class T>
class QueueArrayCircular
{
	private:
			int size, rear, front;
			T* queue;
	public:
		QueueArrayCircular()
		{
			size = 10;
			rear = front = 0;
			queue = new T[size];
		}

		QueueArrayCircular(int size):size(size), rear(0), front(0)
		{
			queue = new T[size];
		}

		~QueueArrayCircular()
		{
			delete [] queue;
		}

		void Enqueue(int);
		int Dequeue();
		bool IsEmpty();
		bool IsFull();
		void Show();
};





//Addition function
template<class T>
void QueueArrayCircular<T>::Enqueue(int number)
{
	if(IsFull())
		cout <<"Circular Queue Array is full"<<endl;
	else
	{	
		rear = (rear+1) % size;
		queue[rear] = number;
	}
}

//Deletion function
template<class T>
int QueueArrayCircular<T>::Dequeue()
{
	int x = -1;

	if(IsEmpty())
	{
		cout <<"Circular Queue Array is empty"<<endl;
		return x;
	}

	else
	{
		front = (front+1) % size;
		return x = queue[front];
	}
		 
}

template<class T>
bool QueueArrayCircular<T>::IsEmpty()
{
	return rear == front;
}

template<class T>
bool QueueArrayCircular<T>::IsFull()
{
	return (rear+1) % size == front;
}

template<class T>
void QueueArrayCircular<T>::Show()
{
	static int counter = 0;

	//Case 1: rear == front condition
	if(IsEmpty())
	{
		cout << "Elements of the circular queue array is empty:"<<endl;
	}
	
	//Case 2: rear < front, queue is returned to beginning
	else if( rear < front )
	{
		for(int i=front+1; i<=size-1; i++)
		{
			cout << counter <<".element of the QueueArrayCircular is:" << queue[i] << endl;
			counter++;
		}

		for(int i=0; i<=rear; i++)
		{
			cout << counter <<".element of the QueueArrayCircular is:" << queue[i] << endl;
		}
	}

	//Case 3: rear > front 
	else
	{
		for(int i=front+1; i<=rear; i++)
		{
			cout << counter <<".element of the QueueArrayCircular is:" << queue[i] << endl;
			counter++;
		}
	}

	
	cout<<endl;
}

