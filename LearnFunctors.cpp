#include <iostream>
#include <vector>
#include <functional>
#include <string>

template<typename T>
class Less_Than
{
public:
	Less_Than(const T &v) : m_value(v){};
	bool operator()(const T &x) const
	{
		return x < m_value;
	};

	int PrintOut(std::string str)
	{
		std::cout << str << std::endl;

		return 0;
	};

private:
	const T m_value;
};

template<typename C, typename P>
int count01 (const C &c, P pred)
{
	int cnt = 0;
	for (const auto &x : c)
	{
		if(pred(x))
		{
			++cnt;
		}
	}
	return cnt;
}
double sum(double a, double b)
{
	return a + b;
}

class TestClass
{
public:
	int PrintOut ()
	{
		std::cout << "string" << std::endl;

		return 0;
	};

};

int main( int argc, char **argv)
{
	Less_Than<int> lti(42);
	TestClass t;
	auto PrintOut = std::mem_fn(&TestClass::PrintOut);
	PrintOut(t);
	int X = 42;
	std::vector<int> vec = {4, 111, 16, 86, 10, 15, 22, 117};
	// use lambda expression
    std::cout << count01(vec, [&X](int a) {return a < X;}) << std::endl;
    // use functor
    std::cout << count01(vec, lti) << std::endl;
    // use bind
   // auto count = std::bind(count01, this, vec, lti);
    auto addition = std::bind(sum, 3, std::placeholders::_1);
    std::cout << addition(4) << std::endl;

    return 0;
}

