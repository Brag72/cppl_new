#include <iostream>
#include <vector>

template<typename T>
void move_vectors(std::vector<T>& from, std::vector<T>& to)
{
	to = std::move(from);
}

int main()
{
	std::vector <std::string> one = { "test_string1", "test_string2" };
	std::vector <std::string> two;
	move_vectors(one, two);

	for (auto i : two)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	for (auto i : one)
	{
		std::cout << i << " ";
	}
}