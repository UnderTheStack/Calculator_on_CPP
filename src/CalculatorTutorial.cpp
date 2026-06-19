#include <iostream>
#include "../Classes/Calculator.h" 

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

int main() 
{
#ifdef _WIN32
    // 1. Настройка кодировки
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    // 2. Настройка размеров
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Желаемый размер (ширина и высота)
    short width = 56;
    short height = 25;

    // Сначала уменьшаем окно до минимума, чтобы изменения буфера не вызвали ошибку
    SMALL_RECT minimalRect = { 0, 0, 1, 1 };
    SetConsoleWindowInfo(hConsole, TRUE, &minimalRect);

    // Устанавливаем размер буфера памяти консоли
    COORD bufferSize = { width, height };
    SetConsoleScreenBufferSize(hConsole, bufferSize);

    // Устанавливаем реальный размер физического окна
    // Координаты считаются от 0, поэтому вычитаем 1
    SMALL_RECT windowSize = { 0, 0, static_cast<short>(width - 1), static_cast<short>(height - 1) };
    SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
#endif

    double x = 0.0;
    double y = 0.0;
    double result = 0.0;
    char oper = '+';

    cout << "########################################################" << endl;
    cout << "##############   Коснольный калькулятор   ##############" << endl;
    cout << "########################################################\n" << endl;
    cout << "Please enter the operation to perform. Format:\na + b | a - b | a * b | a / b\n"
        << endl;

    Calculator c;
    while (true)
    {
        cin >> x >> oper >> y;
        try
        {
            result = c.Calculate(x, oper, y);
            cout << "Result of " << x << " " << oper << " " << y << " is: " << result << endl;
        }
        catch(const std::runtime_error& e)
        {
            cout << "Ошибка: " << e.what() << endl;
        }
        catch (const std::invalid_argument& e)
        {
            cout << "Ошибка: " << e.what() << endl;
        }
    }
    return 0;
}