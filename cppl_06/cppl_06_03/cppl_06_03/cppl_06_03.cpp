#include <iostream>

template<typename T>
class VectorH
{
    T* data;
    size_t _size; // заполненный объём
    size_t _capacity; // максимальный размер
public:
    VectorH() : data(nullptr), _size(0), _capacity(0)
    { 
        data = new T[_capacity];
    };

    ~VectorH()
    {
        delete[] data;
    }

    T& at(int index)
    {
        return data[index];
    }

    void push_back(T value)
    {
        if (_size == _capacity)
        {
            if (_capacity == 0)
            {
                _capacity = 1;
            }
            _capacity *= 2;
            T* newdata = new T[_capacity];
            
            std::copy(data, data + _size, newdata);
            /*for (int i = 0; i < _size; i++)
            {
                newdata[i] = data[i];
            }*/
            delete[] data;
            data = newdata;
        }
        data[_size++] = value;
    }

    size_t size() const
    {
        return _size;
    }

    size_t capacity() const
    {
        return _capacity;
    }
};

int main()
{
    VectorH<int> vector;
    vector.push_back(10);
    vector.push_back(20);
    vector.push_back(30);

    for (size_t i = 0; i < vector.size();++i)
    {
        std::cout << vector.at(i) << std::endl;
    }
    std::cout << "_____________________" << std::endl;

    std::cout << vector.capacity() << ", " << vector.size() << std::endl;

    vector.push_back(40);
    vector.push_back(30);

    for (size_t i = 0; i < vector.size(); ++i)
    {
        std::cout << vector.at(i) << std::endl;
    }
    std::cout << "_____________________" << std::endl;

    std::cout << vector.capacity() << ", " << vector.size() << std::endl;

}