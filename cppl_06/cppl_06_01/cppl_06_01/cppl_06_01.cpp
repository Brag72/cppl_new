#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	cout << "[IN]: ";
	string Hello;

	getline(cin, Hello);
	cout << Hello;

	map<char, int> Increment;
	
	for (char i : Hello)
	{
		Increment[i]++;
	}

	vector<pair<char, int>> sorted_chars(Increment.begin(), Increment.end());
	
	sort(sorted_chars.begin(), sorted_chars.end(),
		[](const auto& a, const auto& b)
		{
			return a.second > b.second;
		});
	
	cout << "[OUT]: " << endl;
	for (auto i : sorted_chars)
	{
		cout << i.first << ": " << i.second<< endl;
	}
}