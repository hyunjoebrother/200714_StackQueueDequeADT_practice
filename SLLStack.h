//Stack를 Singly Linked List로 구현해보자
//top을 head로 할까 tail로 할까 -> head로 하면 push/pop 편함
//복잡성을 피하기 위해 template를 쓰지 않는다 (대신에 타입 Elem 정의)


#include <iostream>
using namespace std;
#include <string>

//예외처리
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

//SLinkedList 클래스 만들어줌. 예전 코드 참고


class SLinkedList
{

class StringNode //새로운 단위 node 
{
protected:
	string elem; //원소값 정보
	StringNode* next; //리스트의 다음 항목

	friend class SLinkedList; //friend로 클래스에 접근 제공
};

protected:
	StringNode* head; //리스트의 head를 가리키는 포인터

public:
	bool empty() const; //리스트가 비어있는가?
	const string& front() const; //이전 원소를 얻는다

	void addFront(const string& e); //리스트의 앞 head에서 추가한다
	void removeFront(); //앞 head의 리스트 항목을 삭제한다.

	//생성자 -> head 포인터를 비어있는 리스트로 만든다
	SLinkedList();

	//소멸자 -> 리스트에 있는 원소들을 반복적으로 삭제한다
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
	//공간 v를 할당받아서 새로운 node를 만든다
	StringNode* v = new StringNode;
	//v에 새로운 데이터 값을 넣는다
	v->elem = e;
	//연결 선울 만든다
	v->next = head;
	//새로운 head는 v다
	head = v;
}

//Removing at Head
void SLinkedList::removeFront()
{
	//head를 v에서 다음 node로 옮겨준다
	StringNode* old = head;
	head = old->next;
	//node 삭제 delete로 공간 반환
	delete old;
}

//생성자
SLinkedList::SLinkedList()
	: head(NULL) { }

//소멸자
SLinkedList::~SLinkedList()
{
	while (!empty())
		removeFront();
}

//메인

typedef string Elem; //스택 원소 타입
class LinkedStack
{
private:
	SLinkedList S; //원소의 linked list
	int n;

public:
	//생성자
	LinkedStack();

	int size() const;
	bool empty() const;

	const Elem& top() const throw(StackEmpty);

	void push(const Elem& e) throw(StackFull);

	void pop() throw(StackEmpty);
};