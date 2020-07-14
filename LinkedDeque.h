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

class DequeEmpty:public RuntimeException
{
private:
public:
	DequeEmpty(const string& err):RuntimeException(err) { }
};


//Doubly Linked List



class DLinkedList
{
	class DNode
	{
	private:
		string elem; //���Ұ� ����
		DNode* prev; //����Ʈ�� ���� �׸�
		DNode* next; //����Ʈ�� ���� �׸�

		friend class DLinkedList; //friend�� Ŭ������ ���� ����
	};

private:
	DNode* header; //dummy ����/��Ʈ�� node -> ���� ����x
	DNode* trailer;

protected: //���� �ڽ� class�� ���� ����
	void add(DNode* v, const string& e); //v ���� ���ο� node ����
	void remove(DNode* v); //v ��� ����

public:
	bool empty() const; //����Ʈ�� �����?
	const string& front() const; //���� ���Ҹ� ��´�
	const string& back() const; //���� ���Ҹ� ��´�

	void addFront(const string& e); //����Ʈ�� �տ��� �߰�
	void addBack(const string& e); //����Ʈ�� �ڿ��� �߰�

	void removeFront(); //�տ��� ����
	void removeBack(); //�ڿ��� ����

	//������ -> ��Ƽ�� node���� �����ϰ� ���ΰ� ���θ� ����Ű���� ����
	DLinkedList();

	//�Ҹ��� -> ��Ƽ��/dummy���� node�� ������ ��� node���� ����
	~DLinkedList();
};


//����
typedef string Elem;
class LinkedDeque:public DLinkedList
{
private:
	DLinkedList D;
	int n;

public:
	//������
	LinkedDeque();

	int size() const;
	bool empty() const;

	const Elem& front() const throw(DequeEmpty); //ù ��° ����
	const Elem& back() const throw(DequeEmpty); //������ ����

	void insertFront(const Elem& e);
	void insertBack(const Elem& e);
	void removeFront() throw(DequeEmpty);
	void removeBack() throw(DequeEmpty);
};