#include <iostream>
#include <vector>
#include <functional>

template<typename T>
class Less_Than
{
public:
	Less_Than(const T &v) : m_value(v){};
	bool operator()(const T &x) const
	{
		return x < m_value;
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
int main( int argc, char **argv)
{
	Less_Than<int> lti(42);
	int X = 42;
	std::vector<int> vec = {4, 111, 16, 86, 10, 15, 22, 117};
	// use laambda expression
    std::cout << count01(vec, [&X](int a) {return a < X;}) << std::endl;
    // use functor
    std::cout << count01(vec, lti) << std::endl;
    // use bind
    auto count = std::bind(count01, this, vec, lti);
    auto addition = std::bind(sum, 3, 4);
    std::cout << addition() << std::endl;
    return 0;
}

