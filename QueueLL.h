#include <iostream>

using namespace std;

template<class T>
class Nodee
{
	public:
		T data;
		Nodee* next;
		Nodee()
		{
			next = NULL;
		}
		~Nodee()
		{
			delete next;
		}
};


template<class M>
class QueueLL
{
	private:
		Nodee<M> *rear, *front;
	
	public:
		QueueLL();
		~QueueLL();
		void Enqueue(M);
		int Dequeue();
};

template<class M>
QueueLL<M>::QueueLL()
{
	rear = front = NULL;
}

template<class M>
QueueLL<M>::~QueueLL()
{
	if(rear!=NULL && front!=NULL)
	{
		if(rear==front)
			delete rear;
		else
		{
			delete rear;
			delete front;
		}

	}
}

template<class M>
void QueueLL<M>::Enqueue(M value)
{
	Nodee<M>* temp = new Nodee<M>();

	if(temp == NULL)
		cout << "HEAP memory is full" << endl;
	else
	{
		temp->data = value;
		temp->next = NULL;

		if(front == NULL) // first time adding Nodee
			front = rear = temp;
		else
		{
			rear->next = temp;
			rear = temp;
		}
	}
}

template<class M>
int QueueLL<M>::Dequeue()
{
	int value;
	Nodee<M>* temp;
	if(front == NULL)
	{
		cout << "Queue is empty" << endl;
		value = -1;	
	}
	else
	{
		temp = front;
		value = temp->data;
		front = front->next;
		delete temp;
	}

	return value;
}