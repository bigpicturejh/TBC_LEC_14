#include <iostream>
using namespace std;

class Exception
{
public:
	void report()
	{
		cerr << "Exception report" << endl;
	}
};

class ArrayException :public Exception
{
public:
	void report()
	{
		cerr << "Array exception" << endl;
	}
};

class MyArray
{
private:
	int _data[5];

public:
	int& operator [](const int& index)
	{
		//if (index < 0 || index >= 5) throw - 1;
		//if (index < 0 || index >= 5) throw Exception();
		if (index < 0 || index >= 5) throw ArrayException();

		return _data[index];
	}
};



void ds()
{
	MyArray my_array;

	try
	{
		my_array[100];
	}

	catch (const int& x)
	{
		cerr << "Exception" << x << endl;
	}

	//catch (ArrayException& e) 
	//{
	//	cout << "ds()" << endl;
	//	e.report();
	//	throw e; //main의 catch에서 받게됨(re-throw)
	//}

	catch (Exception& e)
	{
		cout << "ds()" << endl;
		e.report();
		//throw e;
		throw; // main에서 catch를 할때 특정 값을 throw하지 않고 ds에서 받은 throw를 그대로 main으로 넘겨주는 방법(main에서 자식 클래스의 catch를 할 수 있게됨)
		       // 객체잘림 문제 없어짐
	}

	//catch (ArrayException& e) //자식 클래스에서 catch되도록 구현해도 부모클래스의 Exception에서 catch가 먼저 됨(solution: 부모 클래스 catch보다 위에 선언)
	//{
	//	e.report();
	//}
}

int main()
{
	try
	{

		ds();
	}
	catch (ArrayException& e)
	{
		cout << "main()" << endl;
		e.report();
	}

	catch (Exception& e)
	{
		cout << "main()" << endl;
		e.report();
	}

	return 0;
}

