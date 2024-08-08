#include <iostream>

class Smart_Array
{
    int* Arr;
    int arr_size = 0;
    int number = 0;
    int number_index = 0;
    int i = 0;

public:
    Smart_Array(int size)
    {
        arr_size = size;
        Arr = new int [arr_size] {};
    }
    void add_to_tail(int num)
    {   
        if (i == arr_size)
        {
            arr_size *= 2;
        }        
        Arr[i] = num;
        i++;        
    }
    int get_element(int num)
    {
        if (num <= arr_size - 1)
        {
            return Arr[num];
        }
        else if (num > arr_size - 1)
        { 
            throw std::string{ "Такого индекса не существует!" };
        }
    }
    ~Smart_Array()
    {
        delete[] Arr;
    }
};

int main()
{
    try {
        Smart_Array arr(5);
        arr.add_to_tail(1);
        arr.add_to_tail(4);
        arr.add_to_tail(155);
        arr.add_to_tail(14);
        arr.add_to_tail(15);
        std::cout << arr.get_element(4) << std::endl;
    }
    catch (const std::string& er) {
        std::cout << er << std::endl;
    }
}