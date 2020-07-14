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

//empty queue�� ���ؼ� ���� ó��
class QueueEmpty :public RuntimeException //���
{
private:

public:
	QueueEmpty(const string& err):RuntimeException(err) { }
};

//full queue�� ���ؼ� ���� ó��
class QueueFull : public RuntimeException 
{
private:

public:
	QueueFull(const string& err): RuntimeException(err) { }
};

//���� ����
template <typename E>
class ArrayQueue
{
	enum //����, ����Ʈ ���� �뷮
	{
		DEF_CAPACITY=100
	};

private:
	E* Q; //ť ���ҵ��� �迭
	int capacity; //ť �뷮
	int f, r; //front rear ������ �ε���

public:
	//������- ����Ʈ �뷮�� ���´�
	ArrayQueue(int cap = DEF_CAPACITY);

	int size() const;
	bool empty() const;

	const E& front() const throw(QueueEmpty);

	void enqueue(const E& e) throw(QueueFull);

	void dequeue() throw(QueueEmpty);
};