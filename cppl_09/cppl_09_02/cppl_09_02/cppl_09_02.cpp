#include <iostream>
#include <string>
#include <windows.h>

class big_integer
{	
	std::string number;

public:
	big_integer() : number("0") {};

	big_integer(const std::string& num) : number(num) {
		std::cout << "Конструктор копирования" << std::endl;
	}

	big_integer(big_integer&& other) noexcept : number(std::move(other.number)){ std::cout << "Конструктор перемещения" << std::endl; }

	big_integer& operator=(big_integer&& other) noexcept
	{
		if (this != &other)
		{
			this->number = std::move(other.number);
			std::cout << "Оператор перемещения" << std::endl;
		}
		return *this;
	}
	big_integer operator+(big_integer& other) 
	{
		std::string result;
		int size1 = this->number.size();
		int size2 = other.number.size();
		size_t i = 0;
		int temp_buf = 0;
		
		while (size1 > 0 || size2 > 0)
		{
			char t1;
			char t2;
			int temp1;
			int temp2;

			if (size1 == 0)
			{
				temp1 = 0;
			}
			else
			{
				t1 = this->number.at(size1 - 1);
				temp1 = std::atoi(&t1);
			}

			if (size2 == 0)
			{
				temp2 = 0;
			}
			else
			{
				t2 = other.number.at(size2 - 1);
				temp2 = std::atoi(&t2);
			}

			int temp3 = temp1 + temp2 + temp_buf;
			if (temp_buf > 0){temp_buf--;}

			if (temp3 > 9)
			{
				temp3 -= 10;
				temp_buf++;
			}
			
			result.push_back(std::to_string(temp3)[0]);

			size1--;
			size2--;
			i++;			
		}
		std::reverse(result.begin(), result.end());
		return result;
	}
	big_integer operator*(int num) 
	{
		std::string result;
		int size1 = this->number.size();
		size_t i = 0;
		int temp_buf = 0;

		while (size1 > 0 || temp_buf > 0)
		{
			char t;
			int temp; 

			if (size1 < 1){temp = 0;}
			else 
			{
				t = this->number.at(size1 - 1);
				temp = std::atoi(&t);
			}		

			int product = temp * num + temp_buf;
			temp_buf = product / 10;
			int mod = product % 10;
			result.push_back(std::to_string(mod)[0]);
			size1--;
		}
		std::reverse(result.begin(), result.end());
		return result;
	}
	friend std::ostream& operator<<(std::ostream& os, const big_integer& bi)
	{
		os << bi.number;
		return os;
	}
};


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	setlocale(LC_ALL, "Russian");

	auto number1 = big_integer("114575");
	auto number2 = big_integer("78524");
	auto result = number1 + number2;
	std::cout << result << std::endl;

	auto number3 = big_integer("525");
	auto result_mult = number3 * 37;
	std::cout << result_mult;
}