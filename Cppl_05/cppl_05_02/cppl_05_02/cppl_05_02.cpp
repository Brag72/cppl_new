#include <iostream>
#include <vector>

template<typename T>
class table
{
    std::vector<std::vector<T>> arr;
    size_t in_row;
    size_t in_col;
public:
    table(size_t row, size_t col) : arr(row, std::vector<T>(col)), in_row(row), in_col(col)
    {}

    std::vector<T>& operator[](size_t row)
    {
        return arr[row];
    }
    const std::vector<T>& operator[](size_t row) const
    {
        return arr[row];
    }
    int size() const
    {
        return in_row * in_col;
    }
};


int main()
{
    auto t = table<int>(2, 3);
    t[0][0] = 4;
    std::cout << t[0][0];

}