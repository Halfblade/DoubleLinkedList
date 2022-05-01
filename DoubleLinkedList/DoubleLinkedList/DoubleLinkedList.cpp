
#include <iostream>
#include "DList.h"

int main()
{
	DList<int> D;
	int data1 = 23;
	int data2 = 35;
	int data3 = 65;
	D.push_back(data1);
	D.push_back(data2);
	D.push_back(data3);
	D.printList();


}

