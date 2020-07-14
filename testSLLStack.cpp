#include "SLLStack.h"

#include <iostream>
using namespace std;
#include <string>


//»ý¼ºÀÚ
LinkedStack::LinkedStack()
	:S(),n(0){ }

int LinkedStack::size() const
{
	return n;
}

bool LinkedStack::empty() const
{
	return n == 0;
}

const Elem& LinkedStack::top() const throw(StackEmpty)
{
	if (empty())
		throw StackEmpty("Top of the empty stack");
	return S.front();
}

void LinkedStack::push(const Elem& e) throw(StackFull)
{
	if (empty())
		throw StackFull("Push from full stack");
	++n;
	S.addFront(e);
}

void LinkedStack::pop() throw(StackEmpty)
{
	if (empty())
		throw StackEmpty("Pop from empty stack");
	--n;
	S.removeFront();
}

int main()
{
	LinkedStack A;

	A.push("Hi");
	A.push("Bye");
	cout << A.top() << endl;

	A.pop();
	A.push("lol");
	cout << A.top() << endl;
}
