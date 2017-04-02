#ifndef Queue_H
#define Queue_H


#include "IQueue.h"
template<typename T>
class Queue :
	public IQueue<T>
{
private:
	int start;
	int end;
	T* queue;
	int capacity;
	int elementsInQueue;

	void expand();
public:
	Queue(int capacity = 5);
	~Queue();
	Queue(const Queue<T>& origObj);
	Queue<T> & operator=(const Queue<T>& origObj);
	void enqueue(const T& element);
	T dequeue()throw(...);
	T front() const throw(...);
	bool isEmpty() const;
};

#endif // !Queue



template<typename T>
void Queue<T>::expand()//fixad
{
	this->capacity += 5;
	T *temp = new T[this->capacity];
	for (int i = this->capacity - 1; i > ((this->capacity - this->elementsInQueue) - 1); i--)
	{
		temp[i] = this->queue[(this->start--)];
		if (this->start == -1)
		{
			this->start = (this->elementsInQueue - 1);
		}
	}

	delete[] this->queue;
	this->start = this->capacity - 1;
	this->end = this->capacity - 1 - this->elementsInQueue;
	this->queue = temp;
}

template<typename T>
Queue<T>::Queue(int capacity)
{
	this->start = capacity - 1;
	this->end = capacity - 1;
	this->capacity = capacity;
	this->elementsInQueue = 0;
	this->queue = new T[this->capacity];
}

template<typename T>
Queue<T>::~Queue()
{
	//for (int i = 0; i < this->elementsInQueue; i++)
	//{
	//	delete this->queue[i];
	//}
	delete[] this->queue;
}

template<typename T>
Queue<T>::Queue(const Queue<T>& origObj)//Verkar fungera? Vill gärna veta vad som(om något) är fel. Var det kanske bara mitt test som det var fel på?
{

	this->capacity = origObj.capacity;
	this->start = origObj.start;
	this->end = origObj.end;
	this->elementsInQueue = origObj.elementsInQueue;
	this->queue = new T[origObj.capacity];

	for (int i = this->capacity - 1; i >= 0; i--)//Rättade > till >=
	{
		this->queue[i] = T(origObj.queue[i]);
	}

}



template<typename T>
Queue<T> &Queue<T>::operator=(const Queue<T>& origObj)//ändrade från * till &. Annars verkar den funka. Var det kanske bara mitt test som det var fel på?
{
	if (this != &origObj)
	{

		//for (int i = 0; i < this->elementsInQueue; i++) {
		//	delete this->queue[i];
		//}


		delete[] this->queue;
		this->capacity = origObj.capacity;
		this->start = origObj.start;
		this->end = origObj.end;
		this->elementsInQueue = origObj.elementsInQueue;
		T* temp = new T[origObj.capacity];

		for (int i = this->capacity - 1; i >= 0; i--)//Rättade > till >=
		{
			temp[i] = T(origObj.queue[i]);
		}
		//for (int i = this->capacity-1; i > this->elementsInQueue; i--)
		//{
		this->queue = temp;
		//}
	}
	return *this;
}

template<typename T>
void Queue<T>::enqueue(const T & element)
{
	if (this->elementsInQueue >= this->capacity)
	{
		this->expand();
	}
	this->queue[this->end--] = element;
	this->elementsInQueue++;
	if (this->end == -1)
	{
		this->end = (this->capacity - 1);
	}
}

template<typename T>
T Queue<T>::dequeue() throw(...)
{
	if (this->isEmpty())
	{
		throw "Empty queue!";
	}

	T returnVal = this->queue[this->start--];//Här blir något knasigt? this->queue[this->start++]; == this->queue[5]; <- (-33686019)
	this->elementsInQueue--;
	if (this->start == -1)
	{
		this->start = (this->capacity - 1);
	}

	return returnVal;
}
//T returnVal = this->queue[this->start];//Här blir något knasigt? this->queue[this->start++]; == this->queue[5]; <- (-33686019)
//this->elementsInQueue--;
//if (this->start != 0)
//{
//	this->start--;
//}
//else
//{
//	this->start = (this->capacity - 1);
//}
//
//return returnVal;
//}
template<typename T>
T Queue<T>::front() const throw(...)//ge första utan att ta bort
{
	if (this->isEmpty())
	{
		throw "Empty queue!";
	}

	return this->queue[this->start];
}


template<typename T>
bool Queue<T>::isEmpty() const
{
	bool empty = false;
	if (this->elementsInQueue == 0)
	{
		empty = true;
	}
	return empty;

}