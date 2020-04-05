#include <iostream>
#include <deque>
#include "Ring.h"
#include <list>

using namespace std;

int main(){


	///////////////////////////////// AUTO LOOP /////////////////////////////////
	//		auto texts = {"caglayan", "caglar", "cagatay"};
	//  	string texts = "Caglayan";
	//  	for(auto text:texts)
	//  	{
	//  		cout << text << endl;
	//  	}


  	///////////////////////////////// NESTED TEMPLATE CLASS //////////////////////
	//  	Ring<int>::Iterator it;
	//  	it.Print();



	Ring<string> ring(3);

	ring.add("bir");
	ring.add("iki");
	ring.add("uc");
	ring.add("dort");


	// C98 style
	for(Ring<string>::Iterator it = ring.begin(); it!= ring.end(); it++)
	{
		cout << *it << endl;
	}


	// C++11 style
	for(auto value : ring)
	{
		cout << value << endl;
	}

	ring.IncrementData();


	return 0;

}





