#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>
#include <utility>
#include <windows.h>
#include <sstream>

using namespace std;

class parser
{
    unordered_map<string, unordered_map<string,string>> Map_Parser;

public:
    parser()
    {
        char znak;
        string Section;
        string Var;
        string Val;
        string Comment;
        ifstream file("conf.ini");

        if (!file.is_open())
        {
            throw runtime_error("Файл не открылся!");
        }

        while (!file.eof())
        {
            znak = file.peek();
            
            if (znak == ';')
            {
                getline(file,Comment);
                continue;
            }
            if (znak == '[')
            {
                getline(file, Section);
            }
            else
            {
                getline(file, Var);
                Val = Var;
                                
                Var.erase(find(begin(Var), end(Var), '='), end(Var));
                auto pos = find(begin(Val), end(Val), '=');
                if (pos != end(Val))
                {
                    Val.erase(begin(Val),pos+1);
                }
                Val.erase(find(begin(Val), end(Val), ';'), end(Val));
            }
           
            if (!Var.empty() && !Val.empty())
            {
                Map_Parser[Section][Var] = Val;
            }
        }
        file.close();
    }

    template <typename T>
    T get_value(string Value)
    {        
        string rValue = Value;
        Value.erase(begin(Value), find(begin(Value), end(Value), '.') + 1);
        rValue.erase(find(begin(rValue), end(rValue), '.'), end(rValue));
        rValue = '[' + rValue + ']';

        auto SecIt = Map_Parser.find(rValue);
        auto VarIt = Map_Parser[rValue].find(Value);
        if (SecIt == Map_Parser.end())
        {
            throw runtime_error("Секция не найдена");
        }
        if (VarIt == Map_Parser[rValue].end())
        {
            throw runtime_error("Переменная не найдена");
        }

        stringstream res;
        res << Map_Parser.at(rValue).at(Value);
        T Result;
        res >> Result;

        if (res.fail())
        {
            throw runtime_error("Невозможно сконвертировать значение: " + Value + " в требуемое значение");
        }
        return Result;
    }    
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    setlocale(LC_ALL, "Russia");
    try {
        parser Parser_test;

        parser Parser_test1;
        auto res = Parser_test1.get_value<int>("Section2.var2");
        cout << res;
    }
    catch (exception& Ex)
    {
        cout << "Исключение: " << Ex.what() << endl;
    }
}