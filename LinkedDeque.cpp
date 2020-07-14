#include "LinkedDeque.h"
#include <iostream>
using namespace std;
#include <string>

//DLL ���� �Լ�

//������
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
	//���� u�� �Ҵ�޾Ƽ� ���� �߰��� node ����
	DNode* u = new DNode;
	//u�� ���ο� ������ ���� �ִ´�
	u->elem = e;
	//node u�� next�� header�� ����
	u->next = v;
	//node v�� prev�� trailer�� ����, u�� ����
	u->prev = v->prev = u;
	//node v�� prev�� node u�� ����
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
void DLinkedList::remove(DNode* v) //������ node v
{
	//������
	DNode* u = v->prev;
	//�ļ���
	DNode* w = v->next;
	//�� node�� ������ node ���� node�� �����Ѵ�
	u->next = w;
	//�� node�� ������ node �� node�� �����Ѵ�
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

//������
DLinkedList::DLinkedList()
{
	header = new DNode; //dummy����/��Ƽ�� node ����
	trailer = new DNode;
	header->next = trailer; //���θ� ����Ű���� �Ѵ�
	trailer->prev = header;
}

//�Ҹ���
DLinkedList::~DLinkedList()
{
	while (!empty())
		removeFront(); //dummy���� ������ ��� node ����
	delete header; //dummy���̵��� ����
	delete trailer;
}


//Deque �߰� �Լ�
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