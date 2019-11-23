#include <iostream>

using namespace std;

template<class T>
class Node2
{
	public:
		T data;
		Node2* next;
		Node2()
		{
			next = NULL;
		}
		~Node2()
		{
			delete next;
		}
};


template<class M>
class QueueLL
{
	private:
		Node2<M> *rear, *front;
	
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
	Node2<M>* temp = new Node2<M>();

	if(temp == NULL)
		cout << "HEAP memory is full" << endl;
	else
	{
		temp->data = value;
		temp->next = NULL;

		if(front == NULL) // first time adding Node2
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
	Node2<M>* temp;
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