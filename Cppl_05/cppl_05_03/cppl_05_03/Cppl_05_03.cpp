#include <iostream>
#include <vector>

class simple_functor
{
    int sum = 0;
    int count = 0;
public:
    simple_functor() {};
    void operator()(std::vector <int> Vector1)
    {
        for (int i : Vector1)
        {
            if (i % 3 == 0)
            {
                sum += i;
                count++;
            }
        }
    }

    int get_sum()
    {
        return sum;
    }

    int get_count()
    {
        return count;
    }
};

int main()
{
    std::vector<int> Vec{ 4, 1, 3, 6, 25, 54 };
    std::cout << "Изначальный массив: ";
    for (int i : Vec)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    simple_functor sf;
    sf(Vec);

    std::cout << "Сумма чисел делящихся на 3: " << sf.get_sum() << std::endl;
    std::cout << "Количество чисел делящихся на 3: " << sf.get_count() << std::endl;
}