# 1. Всегда указываем минимальную версию CMake. 3.15+ — отличный современный стандарт
cmake_minimum_required(VERSION 3.15)

# 2. Объявляем имя проекта и язык программирования (CXX означает C++)
project(Calculator_on_CPP LANGUAGES CXX)

# 3. Настраиваем стандарт C++. Обязательно требуем его выполнение
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 4. Создаем исполняемый файл (Цель / Target)
add_executable(CalculatorApp "src/CalculatorTutorial.cpp" "src/Calculator.cpp")