#include <iostream>
using namespace std;
#include <string>

//���� Ȯ������ ���� ��: �ʿ��� class�� ���� �����ϰ� main �����ϱ�!!!

//����ó��
class RuntimeException //���� �ڽ��� ����� ���� �޽����� ���´�
{
private:
	string errorMsg;

public:
	RuntimeException(const string& err)
	{
		errorMsg = err;
	}
	/* ?? ��� ���� ����
	string getMessage() const
	{
		return errorMsg;
	}*/
};

//empty stack�� ���ؼ� top �Ǵ� pop�� �����ϴ� ��쿡 �߻��ϴ� ����
class StackEmpty : public RuntimeException //���
{
private:

public:
	StackEmpty(const string& err) : RuntimeException(err) { }
};

//full stack�� ���ؼ� push �����ϴ� ��쿡 �߻��ϴ� ����
class StackFull : public RuntimeException //���
{
private:

public:
	StackFull(const string& err) : RuntimeException(err) { }
};



template <typename E>
class ArrayStack
{
	enum //����, ����Ʈ ���� �뷮
	{
		DEF_CAPACITY = 100
	};

private:

	E* S; //���� ���ҵ��� �迭
	int capacity; //���� �뷮
	int t; //���� top ������ �ε���

public:
	//������ - ����Ʈ �뷮�� ���´�
	ArrayStack(int cap = DEF_CAPACITY); 

	int size() const;
	bool empty() const;

	const E& top() const throw(StackEmpty);

	void push(const E& e) throw(StackFull);

	void pop() throw(StackEmpty);
};
