#include <iostream>
using namespace std;
#include <string>
#include "ArrayQueue.h"

//생성자
template <typename E>
ArrayQueue<E>::ArrayQueue(int cap)
	:S(new E[cap]),capacity(cap),f(-1),r(-1){ }

template <typename E>
int ArrayQueue<E>::size() const
{
	return (r - f + 1);
}

template <typename E>
bool ArrayQueue<E>::empty() const
{
	return ((f < 0) || (r < 0)); //front 또는 rear가 없을 때
}

template <typename E>
const E& ArrayQueue<E>::front() const throw(QueueEmpty)
{
	if (empty())
		throw QueueEmpty("Front of the empty Queue");
	return Q[f];
}

template <typename E>
void ArrayQueue<E>::enqueue(const E& e) throw(QueueFull)
{
	if (size() == capacity)
		throw QueueFull("Push to full queue");
	S[++f] = e; //front로 enqueue
}

template <typename E>
void ArrayQueue<E>::dequeue() throw(QueueEmpty)
{
	if (empty())
		throw QueueEmpty("Pop from empty queue");
	--r; //rear로 dequeue
}

int main()
{
	ArrayQueue<int> A;
	ArrayQueue<string> B(10);

	A.enqueue(7);
	A.enqueue(13);
	cout << A.front() << endl;
	
	A.dequeue();
	A.enqueue(9);
	cout << A.front() << endl;

	cout << A.empty() << endl;
	cout << A.size() << endl;


	B.enqueue("Mei");
	B.enqueue("Joe");
	cout << B.front() << endl;

	B.dequeue();
	B.dequeue();

	cout << B.empty() << endl;
	cout << B.size() << endl;
}