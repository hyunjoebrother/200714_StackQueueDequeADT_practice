#include "ArrayStack.h"

#include <iostream>
using namespace std;
#include <string>


//»ý¼ºÀÚ
template <typename E>
ArrayStack<E>::ArrayStack(int cap)
	:S(new E[cap]), capacity(cap), t(-1) { }

template <typename E>
int ArrayStack<E>::size() const
{
	return (t + 1);
}

template <typename E>
bool ArrayStack<E>::empty() const
{
	return (t < 0);
}

template <typename E>
const E& ArrayStack<E>::top() const throw(StackEmpty)
{
	if (empty())
		throw StackEmpty("Top of the empty stack");
	return S[t];
}

template <typename E>
void ArrayStack<E>::push(const E& e) throw(StackFull)
{
	if (size() == capacity)
		throw StackFull("Push to full stack");
	S[++t] = e;
}

template <typename E>
void ArrayStack<E>::pop() throw(StackEmpty)
{
	if (empty())
		throw StackEmpty("Pop from empty stack");
	--t;
}

int main()
{
	ArrayStack<int> A;
	ArrayStack<string> B(10);

	A.push(7);
	A.push(13);
	cout << A.top() << endl;

	A.pop();
	A.push(9);
	cout << A.top() << endl;
	
	cout << A.empty() << endl;
	cout << A.size() << endl;
	

	B.push("Mei");
	B.push("Joe");
	cout << B.top() << endl;

	B.pop();
	B.pop();

	cout << B.empty() << endl;
	cout << B.size() << endl;

	
}


