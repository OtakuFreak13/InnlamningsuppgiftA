#include"Test.h"

using namespace std;

void test1()
{
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	locale swedish("swedish");
	locale::global(swedish);

	cout << "L�gger in 1 till 5 i k�n. " << endl;
	Queue<int> *myQueue = new Queue<int>();
	myQueue->enqueue(1);
	myQueue->enqueue(2);
	myQueue->enqueue(3);
	myQueue->enqueue(4);
	myQueue->enqueue(5);

	cout << "Kollar om jag kan f� fram den f�rsta utan att deleta \ninnan jag dequeue:ar alla fem platser. " << endl;
	try
	{
		cout << myQueue->front() << endl;
	}
	catch (char* e)
	{
		cout << e << endl;
	}

	for (int i = 5; i > 0; i--)
	{
		try
		{
			cout << to_string(myQueue->dequeue()) << endl;
		}
		catch (char* e)
		{
			cout << e << endl;
		}
	}

	cout << "Testar nu att kalla p� f�rsta som borde ge 'Empty queue!'. " << endl;
	try
	{
		cout << myQueue->front() << endl;
	}
	catch (char* e)
	{
		cout << e << endl;
	}

	cout << "Testar att dequeue:a n�r k�n ska vara tom. " << endl;
	try
	{
		cout << to_string(myQueue->dequeue()) << endl;
	}
	catch (char* e)
	{
		cout << e << endl;
	}

	cout << "Testar expand genom att f�rst l�gga till 1-5 som fyller capacity. " << endl;

	Queue<int> *myQueue2 = new Queue<int>();
	myQueue2->enqueue(1);
	myQueue2->enqueue(2);
	myQueue2->enqueue(3);
	myQueue2->enqueue(4);
	myQueue2->enqueue(5);

	cout << "Sen l�gger jag till tv� mer och sist dequeue:ar jag alla. " << endl;
	myQueue2->enqueue(6);
	myQueue2->enqueue(7);

	for (int i = 7; i > 0; i--)
	{
		try
		{
			cout << to_string(myQueue2->dequeue()) << endl;
		}
		catch (char* e)
		{
			cout << e << endl;
		}
	}

	cout << "Testar copyKonstruktorn genom att g�ra en k�'myQueue3' och sedan f� myQueue4 att vara som den. " << endl;
	Queue<int> *myQueue3 = new Queue<int>();
	myQueue3->enqueue(1);
	myQueue3->enqueue(2);
	myQueue3->enqueue(3);
	myQueue3->enqueue(4);
	myQueue3->enqueue(5);

	Queue<int> myQueue4(*myQueue3);

	cout << "Skriver ut k� myQueue3... " << endl;
	for (int i = 5; i > 0; i--)
	{
		try
		{
			cout << to_string(myQueue3->dequeue()) << endl;
		}
		catch (char* e)
		{
			cout << e << endl;
		}
	}
	cout << "Sen myQueue4. " << endl;
	for (int i = 5; i > 0; i--)
	{
		try
		{
			cout << to_string(myQueue4.dequeue()) << endl;
		}
		catch (char* e)
		{
			cout << e << endl;
		}
	}
	/////////////////////////////////
	cout << "Testar tilldelningsoperatorn med att s�tta myQueue6 = myQueue5. " << endl;
	Queue<int> *myQueue5 = new Queue<int>();
	myQueue5->enqueue(1);
	myQueue5->enqueue(2);
	myQueue5->enqueue(3);
	myQueue5->enqueue(4);
	myQueue5->enqueue(5);

	Queue<int> myQueue6 = Queue<int>();
	myQueue6 = *myQueue5;

	cout << "Skriver ut k� myQueue5... " << endl;
	for (int i = 5; i > 0; i--)
	{
		try
		{
			cout << to_string(myQueue5->dequeue()) << endl;
		}
		catch (char* e)
		{
			cout << e << endl;
		}
	}
	cout << "Skriver ut k� myQueue6... " << endl;
	for (int i = 5; i > 0; i--)
	{
		try
		{
			cout << to_string(myQueue6.dequeue()) << endl;
		}
		catch (char* e)
		{
			cout << e << endl;
		}
	}
}

void test2()
{
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	locale swedish("swedish");
	locale::global(swedish);

	cout << "L�gger in A-E i k�n. " << endl;
	Queue<string> *myQueue = new Queue<string>();
	myQueue->enqueue("A");
	myQueue->enqueue("B");
	myQueue->enqueue("C");
	myQueue->enqueue("D");
	myQueue->enqueue("E");

	cout << "Kollar om jag kan f� fram den f�rsta utan att deleta \ninnan jag dequeue:ar alla fem platser. " << endl;
	try
	{
		cout << myQueue->front() << endl;
	}
	catch (char* e)
	{
		cout << e << endl;
	}

	for (int i = 5; i > 0; i--)
	{
		try
		{
			cout << myQueue->dequeue() << endl;
		}
		catch (char* e)
		{
			cout << e << endl;
		}
	}

	cout << "Testar nu att kalla p� f�rsta som borde ge 'Empty queue!'. " << endl;
	try
	{
		cout << myQueue->front() << endl;
	}
	catch (char* e)
	{
		cout << e << endl;
	}

	cout << "Testar att dequeue:a n�r k�n ska vara tom. " << endl;
	try
	{
		cout << myQueue->dequeue() << endl;
	}
	catch (char* e)
	{
		cout << e << endl;
	}

	cout << "Testar expand genom att f�rst l�gga till A-E som fyller capacity. " << endl;

	Queue<string> *myQueue2 = new Queue<string>();
	myQueue2->enqueue("A");
	myQueue2->enqueue("B");
	myQueue2->enqueue("C");
	myQueue2->enqueue("D");
	myQueue2->enqueue("E");

	cout << "Sen l�gger jag till F och G mer och sist dequeue:ar jag alla. " << endl;
	myQueue2->enqueue("F");
	myQueue2->enqueue("G");

	for (int i = 7; i > 0; i--)
	{
		try
		{
			cout << myQueue2->dequeue() << endl;
		}
		catch (char* e)
		{
			cout << e << endl;
		}
	}

	cout << "Testar copyKonstruktorn genom att g�ra en k�'myQueue3' och sedan f� myQueue4 att vara som den. " << endl;
	Queue<string> *myQueue3 = new Queue<string>();
	myQueue3->enqueue("A");
	myQueue3->enqueue("B");
	myQueue3->enqueue("C");
	myQueue3->enqueue("D");
	myQueue3->enqueue("E");

	Queue<string> *myQueue4(myQueue3);

	cout << "Skriver ut k� myQueue3... " << endl;
	for (int i = 5; i > 0; i--)
	{
		try
		{
			cout << myQueue3->dequeue() << endl;
		}
		catch (char* e)
		{
			cout << e << endl;
		}
	}
	cout << "Sen myQueue4. " << endl;
	for (int i = 5; i > 0; i--)
	{
		try
		{
			cout << myQueue4->dequeue() << endl;
		}
		catch (char* e)
		{
			cout << e << endl;
		}
	}

	cout << "Testar tilldelningsoperatorn med att s�tta myQueue6 = myQueue5. " << endl;
	Queue<string> *myQueue5 = new Queue<string>(5);
	myQueue5->enqueue("A");
	myQueue5->enqueue("B");
	myQueue5->enqueue("C");
	myQueue5->enqueue("D");
	myQueue5->enqueue("E");

	Queue<string> *myQueue6 = new Queue<string>();
	myQueue6 = myQueue5;

	cout << "Skriver ut k� myQueue5... " << endl;
	for (int i = 5; i > 0; i--)
	{
		try
		{
			cout << myQueue5->dequeue() << endl;
		}
		catch (char* e)
		{
			cout << e << endl;
		}
	}
	cout << "Skriver ut k� myQueue6... " << endl;
	for (int i = 5; i > 0; i--)
	{
		try
		{
			cout << myQueue6->dequeue() << endl;
		}
		catch (char* e)
		{
			cout << e << endl;
		}
	}
}
