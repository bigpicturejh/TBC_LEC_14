#include <iostream>
#include<exception>
#include<string>
using namespace std;

class CustomException : public exception
{
public:
	const char* what() const noexcept override
	{
		return "Custom exception";
	}
};



int main()
{

	try
	{
		//string s;
		//s.resize(-1); //string에서 문자열의 길이지정이 이상한 경우 자체적으로 throw하도록 되어있음

		//throw runtime_error("Bad thing happend");

		throw CustomException();

	}

	//exception class의 이름을 정확히 알때 사용가능 하지만, 매번 모든 종류의 exception 종류를 알 수는 없다
	//catch (length_error& exception)
	//{
	//	cerr << "Length error" << endl;
	//	cerr << exception.what() << endl;
	//}

	catch(exception & exception)
	{
		cout << typeid(exception).name() << endl; //exception class의 이름을 던져줌
		cerr << exception.what() << endl;
	}
	return 0;
}

