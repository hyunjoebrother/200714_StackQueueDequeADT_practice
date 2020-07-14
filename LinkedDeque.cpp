#include "LinkedDeque.h"
#include <iostream>
using namespace std;
#include <string>

//DLL 관련 함수

//생성자
LinkedDeque::LinkedDeque()
	:D() { }

int LinkedDeque::size() const
{
	return n;
}
bool DLinkedList::empty() const
{
	return (header->next == trailer);
}

const string& DLinkedList::front() const
{
	return header->next->elem;
}

const string& DLinkedList::back() const
{
	return trailer->prev->elem;
}

//Inserting at Header
void DLinkedList::add(DNode* v, const string& e)
{
	//공간 u를 할당받아서 새로 추가할 node 생성
	DNode* u = new DNode;
	//u에 새로운 데이터 값을 넣는다
	u->elem = e;
	//node u를 next로 header와 연결
	u->next = v;
	//node v를 prev로 trailer와 연결, u가 들어간다
	u->prev = v->prev = u;
	//node v를 prev로 node u와 연결
	v->prev->next = v->prev = u;
}


void DLinkedList::addFront(const string& e)
{
	add(header->next, e);
}


void DLinkedList::addBack(const string& e)
{
	add(trailer, e);
}

//Removing at Header
void DLinkedList::remove(DNode* v) //삭제할 node v
{
	//선행자
	DNode* u = v->prev;
	//후속자
	DNode* w = v->next;
	//앞 node를 삭제할 node 다음 node와 연결한다
	u->next = w;
	//뒤 node를 삭제할 node 앞 node와 연결한다
	w->prev = u;

	delete v;
}

void DLinkedList::removeFront()
{
	remove(header->next);
}


void DLinkedList::removeBack()
{
	remove(trailer->prev);
}

//생성자
DLinkedList::DLinkedList()
{
	header = new DNode; //dummy더미/센티널 node 생상
	trailer = new DNode;
	header->next = trailer; //서로를 가르키도록 한다
	trailer->prev = header;
}

//소멸자
DLinkedList::~DLinkedList()
{
	while (!empty())
		removeFront(); //dummy들을 제외한 모든 node 삭제
	delete header; //dummy더미들을 삭제
	delete trailer;
}


//Deque 추가 함수
void LinkedDeque::insertFront(const Elem& e)
{
	D.addFront(e);
	n++;
}

void LinkedDeque::insertBack(const Elem& e)
{
	D.addBack(e);
	n++;
}

void LinkedDeque::removeFront() throw(DequeEmpty)
{
	if (empty())
		throw DequeEmpty("empty deque");
	D.removeFront();
	n--;
}

void LinkedDeque::removeBack() throw(DequeEmpty)
{
	if (empty())
		throw DequeEmpty("empty deque");
	D.removeBack();
	n--;
}

int main()
{
	LinkedDeque A;

	A.insertFront("Hi");

	cout << A.front() << endl;

}