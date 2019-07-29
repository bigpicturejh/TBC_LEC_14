#include <iostream>
using namespace std;

class A
{
private:
	int _x;

public:
	A(int x) : _x(x)
	{
		if (x <= 0)
			throw - 1;
	}

};

class B :public A
{
public:
	//B(int x)
	//	: A(x)
	//{}

	B(int x) try : A(x) //**클래스 초기화를 하면서 try를 해줌**
	{
		//do initialization
	}

	catch (...)
	{
		cout << "Catch in B Constructor " << endl;
		//throw;  //thorw가 없지만 있는것 처럼 main으로 값을 throw해줌
	}
};

void ds()
{
	try
	{
		throw - 1;
	}

	catch (...)
	{
		cout << "Catch in ds()" << endl;
	}
}

int main()
{

	try
	{
		//ds();
		B b(0);
	}

	catch(...)
	{
		cout << "Catch in main()" << endl;
	}
	return 0;
}

