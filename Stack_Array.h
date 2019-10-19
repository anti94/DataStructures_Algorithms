#include <iostream>
using namespace std;

template<typename T>
class StackArray
{
	private:
		int top;
		int size;
		T* StackElements;
	
	public:
		StackArray()
		{
			top = -1;
			size = 10;
			StackElements = new T[10];
		}

		StackArray(int size)
		{
			top = -1;
			this->size = size;
			StackElements = new T[size];
		}

		~StackArray()
		{
			delete [] StackElements;
		}

		void Push(T);
		void Pop();
		T Peek(int index);
		bool isEmpty();
		bool isFull();	
		void Show();
};


template <typename T> 
void StackArray<T>::Push(T x)
{
	if(isFull())
		cout << "Stack is overflow"<<endl;
	else
	{
		top++;
		StackElements[top] = x;
	}	
}

template <typename T> 
void StackArray<T>::Pop()
{
	if(isEmpty())
		cout << "Stack is underflow"<<endl;
	else
	{
		top-=1;	
		StackElements[top+1] = 0;
	}
}

template <typename T> 
T StackArray<T>::Peek(int index)
{
	if(isEmpty())
	{
		cout << "Stack is underflow"<<endl;
		return -1;
	}
	else
	{
		return StackElements[top - index + 1];
	}	
}

template <typename T> 
bool StackArray<T>::isEmpty()
{
	return -1 == top;
}

template <typename T> 
bool StackArray<T>::isFull()
{
	return (size-1) == top;
}


template <typename T> 
void StackArray<T>::Show()
{
	cout << "Elements of the array stack are listed:";
	
	for(; top>=0 ;top--)
	{
		cout << StackElements[top];
	}

	cout << endl;
}