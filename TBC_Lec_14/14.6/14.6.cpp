#include <iostream>
#include<memory>
using namespace std;

class A
{
public:
	~A() //소멸자에서는 throw를 하지 않는것이 좋음(필수권장사항!!!!)
	{
		throw "error";
	}
};


int main()
{

	try
	{
		int* i = new int[1000000];
		unique_ptr<int> up_i(i);

		throw "error";

		//delete[] i;  // unique_ptr덕분에 필요 없음, 영역을 벗어나면(try, throw) unique_pointer가 메모리를 제거해줌


		//A a;
	}

	catch (...)
	{
		cout << "Catch" << endl;
	}

	return 0;
}

