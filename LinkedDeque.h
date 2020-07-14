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
		string elem; //원소값 정보
		DNode* prev; //리스트의 이전 항목
		DNode* next; //리스트의 다음 항목

		friend class DLinkedList; //friend로 클래스에 접근 제공
	};

private:
	DNode* header; //dummy 더미/센트럴 node -> 원소 저장x
	DNode* trailer;

protected: //나와 자식 class만 접근 가능
	void add(DNode* v, const string& e); //v 전에 새로운 node 삽입
	void remove(DNode* v); //v 노드 제거

public:
	bool empty() const; //리스트가 비었나?
	const string& front() const; //앞의 원소를 얻는다
	const string& back() const; //뒤의 원소를 얻는다

	void addFront(const string& e); //리스트의 앞에서 추가
	void addBack(const string& e); //리스트의 뒤에서 추가

	void removeFront(); //앞에서 제거
	void removeBack(); //뒤에서 제거

	//생성자 -> 센티널 node들을 생성하고 서로가 서로를 가르키도록 설정
	DLinkedList();

	//소멸자 -> 센티널/dummy더미 node를 제외한 모든 node들을 제거
	~DLinkedList();
};


//메인
typedef string Elem;
class LinkedDeque:public DLinkedList
{
private:
	DLinkedList D;
	int n;

public:
	//생성자
	LinkedDeque();

	int size() const;
	bool empty() const;

	const Elem& front() const throw(DequeEmpty); //첫 번째 원소
	const Elem& back() const throw(DequeEmpty); //마지막 원소

	void insertFront(const Elem& e);
	void insertBack(const Elem& e);
	void removeFront() throw(DequeEmpty);
	void removeBack() throw(DequeEmpty);
};