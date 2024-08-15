#include <iostream>
#include <vector>
#include<set>
#include<list>

template<typename T>
void print_container(T cont, size_t size)
{
	for (auto i : cont)
	{
		if (size == 1)
		{
			std::cout << i;
			break;
		}
		std::cout << i << ", ";
		size--;
	}
}


int main()
{
	std::vector<std::string> test_vector{ "one", "two", "three", "four" };
	print_container(test_vector, test_vector.size());
	std::cout << std::endl;

	std::set<std::string> test_set{ "one", "two", "three", "four" };
	print_container(test_set, test_set.size());
	std::cout << std::endl;

	std::list<std::string> test_list{ "one", "two", "three", "four" };
	print_container(test_list, test_list.size());
}