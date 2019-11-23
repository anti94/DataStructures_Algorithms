#include "StackArray.h"

template <typename T> 
void Stack<T>::Push(T x)
{
	if(isFull())
		cout << "Stack is overflow"<<endl;
	else
	{
		top++;
		stack[top] = x;
	}	
}

template <typename T> 
T Stack<T>::Pop()
{
	if(isEmpty())
		cout << "Stack is underflow"<<endl;
	else
	{
		top-=1;	
		stack[top+1] = 0;
	}
}

template <typename T> 
T Stack<T>::Peek(int index)
{
	if(isEmpty())
	{
		cout << "Stack is underflow"<<endl;
		return -1;
	}
	else
	{
		return stack[top - index + 1];
	}	
}

template <typename T> 
bool Stack::isEmpty()
{
	return -1 == top;
}

template <typename T> 
bool Stack::isFull()
{
	return (size-1) == top;
}

