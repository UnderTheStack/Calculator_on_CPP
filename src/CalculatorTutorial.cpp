#include <iostream>
#include "../Classes/Calculator.h" 

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

int main() 
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    double x = 0.0;
    double y = 0.0;
    double result = 0.0;
    char oper = '+';

    cout << "Calculator Console Application\n" << endl;
    cout << "Please enter the operation to perform. Format:\na + b | a - b | a * b | a / b"
        << endl;

    Calculator c;
    while (true)
    {
        cin >> x >> oper >> y;
        if (oper == '/' && y == 0) 
        {
            cout << "Math error: Attempted to divide by zero! (Деление на ноль!)" << endl;
            continue;
        }
        else
        {
            result = c.Calculate(x, oper, y);
        }
        cout << "Result of " << x << " " << oper << " " << y << " is: " << result << endl;
    }
    return 0;
}