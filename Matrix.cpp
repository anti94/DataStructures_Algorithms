#include "Matrix.h"
 
using namespace std;

 Matrix::Matrix()
 {
	size = 5;
	array = new int[size];
 }
 
  Matrix::Matrix(int size)
 {
	this->size = size;
	array = new int[size];
 }
 
 
 int Matrix::Get(int i , int j)
 {
	if(i==j)
		return array[i-1];
	else
		return 0;
 }
 
 void Matrix::Set(int i , int j, int value)
 {
	if(i==j)
		array[i-1] = value;
	else
		array[i-1] = 0;
 }
 
  void Matrix::Display()
 {
	int i,j;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			if(i==j)
				cout << "Value of Matrix["<<i-1<<"]["<<j-1<<"] is "<<array[i-1] << endl;
			else
				cout << "Value of Matrix["<<i-1<<"]["<<j-1<<"] is "<< 0 << endl;	
		}
	}
 }

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 