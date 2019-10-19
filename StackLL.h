#include <iostream>
using namespace std;

template <class T>
struct Node
{
		T data;
		Node* next;
};

template <class T>
class StackLL
{	
	private:
		Node<T> *top;

	public:
		
		StackLL()
		{	
			top = NULL;
		}

		~StackLL()
		{	
			delete top;
		}

		void Push(int);
		void Pop();
		bool isEmpty();
		bool isFull();
		void Show();
		int isBalanced(char*);
};

template <class T>
bool StackLL<T>::isEmpty()
{
	return (!top)?1:0;
}

template <class T>
bool StackLL<T>::isFull()
{
	Node<int>* temp = new Node<int>; 
	return (!temp)?1:0;
}

template <class T>
void StackLL<T>::Push(int X)
{
	if(isFull())
		return;
	else
	{
		Node<T>* temp = new Node<T>; 
		temp->data = X;
		temp->next = top;
		top = temp;
	}
}

template <class T>
void StackLL<T>::Pop()
{
	if(isEmpty())
		return;
	else
	{
		Node<T>* temp = top;
		top = top->next;
		delete temp;
	}
}


template <typename T> 
void StackLL<T>::Show()
{
	cout << "Elements of the linked list stack are listed:";
	
	while(top!=0)
	{
		cout << top->data;
		top = top->next;
	}

	cout << endl;
}

template <typename T> 
int StackLL<T>::isBalanced(char* sstring)
{
	StackLL<char> parantez;

	for(int i=0;sstring[i]!='\0';i++)
	{
		if(sstring[i] == '(')
			parantez.Push(sstring[i]);
		else if(sstring[i] == ')')
			parantez.Pop();			
	}

	return parantez.top ? 0:1;
}