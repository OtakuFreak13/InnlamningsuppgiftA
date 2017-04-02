//#include"Queue.h"
#include<iostream>
#include"Test.h"

using namespace std;

int main()
{

	locale swedish("swedish");
	locale::global(swedish);

	test1();//testar int 

	test2();//testar string



	system("pause");
	return 0;
}