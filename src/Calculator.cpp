#pragma once

#include <iostream>
#include <stdexcept>

class Calculator
{
public:
	double Calculate(double x, char oper, double y);
};

double Calculator::Calculate(double x, char oper, double y)
{
    if ( (oper == '/') && (y == 0) )
    {
        throw std::runtime_error("Деление на ноль!");
    }
    else 
    {
        switch (oper)
        {
        case '+': return x + y;
        case '-': return x - y;
        case '*': return x * y;
        case '/': return x / y;
        default:  throw std::invalid_argument("Неизвестный оператор!");
        }
    }
}