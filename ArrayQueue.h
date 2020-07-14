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

//empty queue에 대해서 예외 처리
class QueueEmpty :public RuntimeException //상속
{
private:

public:
	QueueEmpty(const string& err):RuntimeException(err) { }
};

//full queue에 대해서 예외 처리
class QueueFull : public RuntimeException 
{
private:

public:
	QueueFull(const string& err): RuntimeException(err) { }
};

//메인 시작
template <typename E>
class ArrayQueue
{
	enum //열거, 디폴트 스택 용량
	{
		DEF_CAPACITY=100
	};

private:
	E* Q; //큐 원소들의 배열
	int capacity; //큐 용량
	int f, r; //front rear 원소의 인덱스

public:
	//생성자- 디폴트 용량을 갖는다
	ArrayQueue(int cap = DEF_CAPACITY);

	int size() const;
	bool empty() const;

	const E& front() const throw(QueueEmpty);

	void enqueue(const E& e) throw(QueueFull);

	void dequeue() throw(QueueEmpty);
};