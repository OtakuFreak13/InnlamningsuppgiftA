#include"Test.h"

using namespace std;

void test1()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	locale swedish("swedish");
	locale::global(swedish);

	cout << "Lägger in 1 till 5 i kön. " << endl;
	Queue<int> *myQueue = new Queue<int>();
	myQueue->enqueue(1);
	myQueue->enqueue(2);
	myQueue->enqueue(3);
	myQueue->enqueue(4);
	myQueue->enqueue(5);

	cout << "Kollar om jag kan få fram den första utan att deleta \ninnan jag dequeue:ar alla fem platser. " << endl;
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

	cout << "Testar nu att kalla på första som borde ge 'Empty queue!'. " << endl;
	try
	{
		cout << myQueue->front() << endl;
	}
	catch (char* e)
	{
		cout << e << endl;
	}

	cout << "Testar att dequeue:a när kön ska vara tom. " << endl;
	try
	{
		cout << to_string(myQueue->dequeue()) << endl;
	}
	catch (char* e)
	{
		cout << e << endl;
	}

	cout << "Testar expand genom att först lägga till 1-5 som fyller capacity. " << endl;

	Queue<int> *myQueue2 = new Queue<int>();
	myQueue2->enqueue(1);
	myQueue2->enqueue(2);
	myQueue2->enqueue(3);
	myQueue2->enqueue(4);
	myQueue2->enqueue(5);

	cout << "Sen lägger jag till två mer och sist dequeue:ar jag alla. " << endl;
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

	cout << "Testar copyKonstruktorn genom att göra en kö'myQueue3' och sedan få myQueue4 att vara som den. " << endl;
	Queue<int> *myQueue3 = new Queue<int>();
	myQueue3->enqueue(1);
	myQueue3->enqueue(2);
	myQueue3->enqueue(3);
	myQueue3->enqueue(4);
	myQueue3->enqueue(5);

	Queue<int> * myQueue4 =  new Queue<int>(*myQueue3);

	cout << "Skriver ut kö myQueue3... " << endl;
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
			cout << to_string(myQueue4->dequeue()) << endl;
		}
		catch (char* e)
		{
			cout << e << endl;
		}
	}
	/////////////////////////////////
	cout << "Testar tilldelningsoperatorn med att sätta myQueue6 = myQueue5. " << endl;
	Queue<int> *myQueue5 = new Queue<int>();
	myQueue5->enqueue(1);
	myQueue5->enqueue(2);
	myQueue5->enqueue(3);
	myQueue5->enqueue(4);
	myQueue5->enqueue(5);

	Queue<int> *myQueue6 = new Queue<int>();
	*myQueue6 = *myQueue5;

	cout << "Skriver ut kö myQueue5... " << endl;
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
	cout << "Skriver ut kö myQueue6... " << endl;
	for (int i = 5; i > 0; i--)
	{
		try
		{
			cout << to_string(myQueue6->dequeue()) << endl;
		}
		catch (char* e)
		{
			cout << e << endl;
		}
	}

	cout << "Skapar kö med 5 kapacitet och köar upp 5 element." << endl;
	Queue<int> *myQueue7 = new Queue<int>();
	myQueue7->enqueue(1);
	myQueue7->enqueue(2);
	myQueue7->enqueue(3);
	myQueue7->enqueue(4);
	myQueue7->enqueue(5);
	cout << "Avköar två element och köar tre nya." << endl;
	try
	{
		cout << to_string(myQueue7->dequeue()) << endl;
		cout << to_string(myQueue7->dequeue()) << endl;
	}
	catch (char* e)
	{
		cout << e << endl;
	}
	
	myQueue7->enqueue(6);
	myQueue7->enqueue(7);
	myQueue7->enqueue(8);
	cout << "Avköar alla element." << endl;
	for (int i = 6; i > 0; i--)
	{
		try
		{
			cout << to_string(myQueue7->dequeue()) << endl;
		}
		catch (char* e)
		{
			cout << e << endl;
		}
	}

	cout << "Lägger in 1 till 3 i kön. " << endl;
	Queue<int> *myQueue8 = new Queue<int>(3);
	myQueue8->enqueue(1);
	myQueue8->enqueue(2);
	myQueue8->enqueue(3);

	cout << "Dequeue:ar 1" << endl;
	try
	{
		cout << myQueue8->dequeue() << endl;
	}
	catch (char* e)
	{
		cout << e << endl;
	}
	cout << "Testar copy och sen dequeue:ar jag både myqueue8 och myqueue9 som ska visa samma." << endl;
	Queue<int> myQueue9 = *myQueue8;
	for (int i = 2; i > 0; i--)
	{
		try
		{
			cout << to_string(myQueue8->dequeue()) << endl;
		}
		catch (char* e)
		{
			cout << e << endl;
		}
	}

	for (int i = 2; i > 0; i--)
	{
		try
		{
			cout << to_string(myQueue9.dequeue()) << endl;
		}
		catch (char* e)
		{
			cout << e << endl;
		}
	}

	cout << "Lägger in 1 till 3 i kön. " << endl;
	Queue<int> *myQueue10 = new Queue<int>(3);
	myQueue10->enqueue(1);
	myQueue10->enqueue(2);
	myQueue10->enqueue(3);

	cout << "Dequeue:ar 1" << endl;
	try
	{
		cout << myQueue10->dequeue() << endl;
	}
	catch (char* e)
	{
		cout << e << endl;
	}
	cout << "Testar tilldelning och sen dequeue:ar jag både myqueue8 och myqueue9 som ska visa samma." << endl;
	Queue<int> *myQueue11 = new Queue<int>(4);
	*myQueue11 = *myQueue10;
	for (int i = 2; i > 0; i--)
	{
		try
		{
			cout << to_string(myQueue10->dequeue()) << endl;
		}
		catch (char* e)
		{
			cout << e << endl;
		}
	}

	for (int i = 2; i > 0; i--)
	{
		try
		{
			cout << to_string(myQueue11->dequeue()) << endl;
		}
		catch (char* e)
		{
			cout << e << endl;
		}
	}

	delete myQueue;
	delete myQueue2;
	delete myQueue3;
	delete myQueue4;
	delete myQueue5;
	delete myQueue6;
	delete myQueue7;
	delete myQueue8;
	delete myQueue10;
	delete myQueue11;
}

void test2()
{
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	locale swedish("swedish");
	locale::global(swedish);

	cout << "Lägger in A-E i kön. " << endl;
	Queue<string> *myQueue = new Queue<string>();
	myQueue->enqueue("A");
	myQueue->enqueue("B");
	myQueue->enqueue("C");
	myQueue->enqueue("D");
	myQueue->enqueue("E");

	cout << "Kollar om jag kan få fram den första utan att deleta \ninnan jag dequeue:ar alla fem platser. " << endl;
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

	cout << "Testar nu att kalla på första som borde ge 'Empty queue!'. " << endl;
	try
	{
		cout << myQueue->front() << endl;
	}
	catch (char* e)
	{
		cout << e << endl;
	}

	cout << "Testar att dequeue:a när kön ska vara tom. " << endl;
	try
	{
		cout << myQueue->dequeue() << endl;
	}
	catch (char* e)
	{
		cout << e << endl;
	}

	cout << "Testar expand genom att först lägga till A-E som fyller capacity. " << endl;

	Queue<string> *myQueue2 = new Queue<string>();
	myQueue2->enqueue("A");
	myQueue2->enqueue("B");
	myQueue2->enqueue("C");
	myQueue2->enqueue("D");
	myQueue2->enqueue("E");

	cout << "Sen lägger jag till F och G mer och sist dequeue:ar jag alla. " << endl;
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

	cout << "Testar copyKonstruktorn genom att göra en kö'myQueue3' och sedan få myQueue4 att vara som den. " << endl;
	Queue<string> *myQueue3 = new Queue<string>();
	myQueue3->enqueue("A");
	myQueue3->enqueue("B");
	myQueue3->enqueue("C");
	myQueue3->enqueue("D");
	myQueue3->enqueue("E");

	Queue<string> *myQueue4 = new Queue<string>(*myQueue3);

	cout << "Skriver ut kö myQueue3... " << endl;
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

	cout << "Testar tilldelningsoperatorn med att sätta myQueue6 = myQueue5. " << endl;
	Queue<string> *myQueue5 = new Queue<string>(5);
	myQueue5->enqueue("A");
	myQueue5->enqueue("B");
	myQueue5->enqueue("C");
	myQueue5->enqueue("D");
	myQueue5->enqueue("E");

	Queue<string> *myQueue6 = new Queue<string>();
	*myQueue6 = *myQueue5;

	cout << "Skriver ut kö myQueue5... " << endl;
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
	cout << "Skriver ut kö myQueue6... " << endl;
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

	cout << "Skapar kö med 5 kapacitet och köar upp 5 element." << endl;
	Queue<string> *myQueue7 = new Queue<string>();
	myQueue7->enqueue("A");
	myQueue7->enqueue("B");
	myQueue7->enqueue("C");
	myQueue7->enqueue("D");
	myQueue7->enqueue("E");
	cout << "Avköar två element och köar tre nya." << endl;
	try
	{
		cout << myQueue7->dequeue() << endl;
		cout << myQueue7->dequeue() << endl;
	}
	catch (char* e)
	{
		cout << e << endl;
	}

	myQueue7->enqueue("F");
	myQueue7->enqueue("G");
	myQueue7->enqueue("H");
	cout << "Avköar alla element." << endl;
	for (int i = 6; i > 0; i--)
	{
		try
		{
			cout << myQueue7->dequeue() << endl;
		}
		catch (char* e)
		{
			cout << e << endl;
		}
	}
	cout << "Lägger in A till C i kön. " << endl;
	Queue<string> *myQueue8 = new Queue<string>(3);
	myQueue8->enqueue("A");
	myQueue8->enqueue("B");
	myQueue8->enqueue("C");

	cout << "Dequeue:ar A" << endl;
	try
	{
		cout << myQueue8->dequeue() << endl;
	}
	catch (char* e)
	{
		cout << e << endl;
	}
	cout << "Testar copy och sen dequeue:ar jag både myqueue8 och myqueue9 som ska visa samma." << endl;
	Queue<string> myQueue9 = *myQueue8;
	for (int i = 2; i > 0; i--)
	{
		try
		{
			cout << myQueue8->dequeue() << endl;
		}
		catch (char* e)
		{
			cout << e << endl;
		}
	}

	for (int i = 2; i > 0; i--)
	{
		try
		{
			cout << myQueue9.dequeue() << endl;
		}
		catch (char* e)
		{
			cout << e << endl;
		}
	}

	cout << "Lägger in A till C i kön. " << endl;
	Queue<string> *myQueue10 = new Queue<string>(3);
	myQueue10->enqueue("A");
	myQueue10->enqueue("B");
	myQueue10->enqueue("C");

	cout << "Dequeue:ar A" << endl;
	try
	{
		cout << myQueue10->dequeue() << endl;
	}
	catch (char* e)
	{
		cout << e << endl;
	}
	cout << "Testar tilldelning och sen dequeue:ar jag både myqueue8 och myqueue9 som ska visa samma." << endl;
	Queue<string> *myQueue11 = new Queue<string>(4);
	*myQueue11 = *myQueue10;
	for (int i = 2; i > 0; i--)
	{
		try
		{
			cout << myQueue10->dequeue() << endl;
		}
		catch (char* e)
		{
			cout << e << endl;
		}
	}

	for (int i = 2; i > 0; i--)
	{
		try
		{
			cout << myQueue11->dequeue() << endl;
		}
		catch (char* e)
		{
			cout << e << endl;
		}
	}

	delete myQueue;
	delete myQueue2;
	delete myQueue3;
	delete myQueue4;
	delete myQueue5;
	delete myQueue6;
	delete myQueue7;
	delete myQueue8;
	delete myQueue10;
	delete myQueue11;

}
