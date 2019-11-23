#include "QueueArray.h"
#include "StackArray.h"


using namespace std;

class TreeQueue
{

private:

	Node1* root;

public:

	TreeQueue()
	{
		root = NULL;
	}

	void CreateTree();
	void PreOrder(Node1* p);	// Parametresiz fonksiyon yaratýlarak, private root deðiþkeni parametreli fonksiyonlara sokuldu.
	void PreOrder(){PreOrder(root);}
	void IterativePreOrder(Node1* p);
	void IterativePreOrder(){IterativePreOrder(root);}

	void PostOrder(Node1* p);
	void PostOrder(){PostOrder(root);}
	void IterativePostOrder(Node1* p);
	void IterativePostOrder(){IterativePostOrder(root);}

	void InOrder(Node1* p);
	void InOrder(){InOrder(root);}
	void IterativeInOrder(Node1* p);
	void IterativeInOrder(){IterativeInOrder(root);}

	int Height(Node1* root);
	int Height(){return Height(root);};
	int Count(Node1* root);
	int Count(){return Count(root);};
};


// Description: Root is known.So, firstly left then right child is entered. And, again left and right child is entered of the changing previos parameter.
void TreeQueue::CreateTree()
{
	Node1 *prev, *temp;
	int data;
	QueueArray<Node1*> que(100);

	//left child and right child is null
	root = new Node1();
	
	cout << " Enter the root value:";
	cin >> root->data;
	que.Enqueue(root);

	while(!que.IsEmpty())
	{
		prev = que.Dequeue(); // Burda queue'deki data silinmez, çýkarýlýr.

		cout << "Enter the left child of " << prev->data << ":";
		cin >> data;

		if(data!=-1)
		{
			//left child and right child is null
			temp = new Node1();

			temp->data = data;
			prev->lChild = temp;
			que.Enqueue(temp);
		}


		cout << "Enter the right child of " << prev->data << ":";
		cin >> data;

		if(data!=-1)
		{
			//left child and right child is null
			temp = new Node1();

			temp->data = data;
			prev->rChild = temp;
			que.Enqueue(temp);
		}
	}

}


// These functions are recursive functions
void TreeQueue::PreOrder(Node1* p)
{

	if(p)
	{
		cout << p->data <<" ";
		PreOrder(p->lChild);
		PreOrder(p->rChild);
	}
}

void TreeQueue::PostOrder(Node1* p)
{
	if(p)
	{
		PostOrder(p->rChild);
		cout << p->data <<" ";
		PostOrder(p->lChild);
	}
}

void TreeQueue::InOrder(Node1* p)
{

	if(p)
	{
		InOrder(p->lChild);
		cout << p->data <<" ";
		InOrder(p->rChild);
	}
}


// These functions are iterative functions
void TreeQueue::IterativePreOrder(Node1* root)
{
	StackArray<Node1*> stackArr(100);

	while(!stackArr.isEmpty() || root)
	{
		if(root)
		{
			cout << root->data << " ";
			stackArr.Push(root);
			root = root->lChild;
		}

		else
		{
			root = stackArr.Pop();
			root = root->rChild;
		}
	}
}

void TreeQueue::IterativeInOrder(Node1* root)
{
	StackArray<Node1*> stackArr(100);

	while(!stackArr.isEmpty() || root)
	{
		if(root)
		{
			stackArr.Push(root);
			root = root->lChild;
		}

		else
		{
			root = stackArr.Pop();
			cout << root->data << " ";
			root = root->rChild;
		}
	}
}

void TreeQueue::IterativePostOrder(Node1* root)
{
	StackArray<Node1*> stackArr(100);

	while(!stackArr.isEmpty() || root)
	{
		if(root)
		{
			stackArr.Push(root);
			root = root->rChild;
		}

		else
		{
			root = stackArr.Pop();
			cout << root->data << " ";
			root = root->lChild;
		}
	}
}

// This function is count of nodes in the tree
int TreeQueue::Count(Node1* root)
{
	if(root)
		return Count(root->lChild) + Count(root->rChild) + 1;
	else
		return 0;
}

// This function is calculates height of tree
int TreeQueue::Height(Node1* root)
{
	int x = 0, y = 0;

	if(root==0)
		return 0;
	
	x = Height(root->lChild);
	y = Height(root->rChild);

	if(x<=y)
		return y+1;
	else
		return x+1;
}