#include <iostream>
using namespace std;
#include <string>

//내가 확인하지 못한 점: 필요한 class를 먼저 선언하고 main 선언하기!!!

//예외처리
class RuntimeException //오직 자신의 멤버로 오류 메시지를 갖는다
{
private:
	string errorMsg;

public:
	RuntimeException(const string& err)
	{
		errorMsg = err;
	}
	/* ?? 없어도 실행 ㄱㄴ
	string getMessage() const
	{
		return errorMsg;
	}*/
};

//empty stack에 대해서 top 또는 pop을 실행하는 경우에 발생하는 예외
class StackEmpty : public RuntimeException //상속
{
private:

public:
	StackEmpty(const string& err) : RuntimeException(err) { }
};

//full stack에 대해서 push 실행하는 경우에 발생하는 예외
class StackFull : public RuntimeException //상속
{
private:

public:
	StackFull(const string& err) : RuntimeException(err) { }
};



template <typename E>
class ArrayStack
{
	enum //열거, 디폴트 스택 용량
	{
		DEF_CAPACITY = 100
	};

private:

	E* S; //스택 원소들의 배열
	int capacity; //스택 용량
	int t; //스택 top 원소의 인덱스

public:
	//생성자 - 디폴트 용량을 갖는다
	ArrayStack(int cap = DEF_CAPACITY); 

	int size() const;
	bool empty() const;

	const E& top() const throw(StackEmpty);

	void push(const E& e) throw(StackFull);

	void pop() throw(StackEmpty);
};
