#include <iostream>
#include<vector>
#include<algorithm>

int main()
{
	std::vector<int> Vec{ 1, 1, 2, 5, 6, 1, 2, 4 };
	std::cout << "[IN]: ";

	for (int i : Vec)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	std::sort(Vec.begin(), Vec.end());
	
	auto it = std::unique(Vec.begin(), Vec.end());

	std::cout << "[OUT]: ";
	Vec.erase(it, Vec.end());
	for (int i : Vec)
	{
		std::cout << i << " ";
	}
}