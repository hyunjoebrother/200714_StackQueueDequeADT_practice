//Stack�� Singly Linked List�� �����غ���
//top�� head�� �ұ� tail�� �ұ� -> head�� �ϸ� push/pop ����
//���⼺�� ���ϱ� ���� template�� ���� �ʴ´� (��ſ� Ÿ�� Elem ����)


#include <iostream>
using namespace std;
#include <string>

//����ó��
class RuntimeException
{
private:
	string errorMsg;
public:
	RuntimeException(const string& err)
	{
		errorMsg = err;
	}
};

class StackEmpty:public RuntimeException
{
private:

public:
	StackEmpty(const string& err): RuntimeException(err) { }
};

class StackFull :public RuntimeException
{
private:

public:
	StackFull(const string& err) : RuntimeException(err) { }
};

//SLinkedList Ŭ���� �������. ���� �ڵ� ����


class SLinkedList
{

class StringNode //���ο� ���� node 
{
protected:
	string elem; //���Ұ� ����
	StringNode* next; //����Ʈ�� ���� �׸�

	friend class SLinkedList; //friend�� Ŭ������ ���� ����
};

protected:
	StringNode* head; //����Ʈ�� head�� ����Ű�� ������

public:
	bool empty() const; //����Ʈ�� ����ִ°�?
	const string& front() const; //���� ���Ҹ� ��´�

	void addFront(const string& e); //����Ʈ�� �� head���� �߰��Ѵ�
	void removeFront(); //�� head�� ����Ʈ �׸��� �����Ѵ�.

	//������ -> head �����͸� ����ִ� ����Ʈ�� �����
	SLinkedList();

	//�Ҹ��� -> ����Ʈ�� �ִ� ���ҵ��� �ݺ������� �����Ѵ�
	~SLinkedList();
};

bool SLinkedList::empty() const
{
	return head == NULL;
}

const string& SLinkedList::front() const
{
	return head->elem;
}

//Inserting at Head
void SLinkedList::addFront(const string& e)
{
	//���� v�� �Ҵ�޾Ƽ� ���ο� node�� �����
	StringNode* v = new StringNode;
	//v�� ���ο� ������ ���� �ִ´�
	v->elem = e;
	//���� ���� �����
	v->next = head;
	//���ο� head�� v��
	head = v;
}

//Removing at Head
void SLinkedList::removeFront()
{
	//head�� v���� ���� node�� �Ű��ش�
	StringNode* old = head;
	head = old->next;
	//node ���� delete�� ���� ��ȯ
	delete old;
}

//������
SLinkedList::SLinkedList()
	: head(NULL) { }

//�Ҹ���
SLinkedList::~SLinkedList()
{
	while (!empty())
		removeFront();
}

//����

typedef string Elem; //���� ���� Ÿ��
class LinkedStack
{
private:
	SLinkedList S; //������ linked list
	int n;

public:
	//������
	LinkedStack();

	int size() const;
	bool empty() const;

	const Elem& top() const throw(StackEmpty);

	void push(const Elem& e) throw(StackFull);

	void pop() throw(StackEmpty);
};