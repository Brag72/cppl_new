#include <iostream>
#include <vector>

template <typename T>
void my_sqrt(T& My)
{
    for (int i = 0; i < My.size(); i++)
    {
        My[i] *= My[i];
    }
}

template<>
void my_sqrt(int& a)
{
    a *= a;
}

int main()
{
    int number = 0;
    std::cout << "Введите число:\n";
    std::cin >> number;

    std::cout << number << "^2 = ";
    my_sqrt(number);
    std::cout << number << std::endl;

    std::vector <int> vector1 = { -1, 4, 8 };

    std::cout << "Изначальный массив: ";
    for (int i = 0; i < vector1.size(); i++)
    {
        std::cout << vector1[i] << ", ";
    }
    std::cout << std::endl;

    my_sqrt(vector1);
    
    std::cout << "Измененный массив: ";
    for (int i = 0; i < vector1.size(); i++)
    {
        std::cout << vector1[i] << ", ";
    }
    std::cout << std::endl;
}