//Date: 10.09.2019
 
#include <iostream>
using namespace std;


 class Matrix
 {
	private:
		int size;
		int *array;
		
	public:
		Matrix();
		Matrix(int size);
		int Get(int i , int j);
		void Set(int i, int j, int value);
		void Display();
 };