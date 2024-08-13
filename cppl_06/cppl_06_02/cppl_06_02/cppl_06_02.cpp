#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int size = 0;
    cout << "[IN]: ";
    cin >> size;

    set<int> unique;

    int num;
    for (int i = 0; i < size; ++i)
    {
        cin >> num;
        unique.insert(num);
    }
    cout << endl;

    vector<int> sorted(unique.begin(), unique.end());

    sort(sorted.rbegin(), sorted.rend());
    for (int i : sorted)
    {
        cout << i << endl;
    }
}