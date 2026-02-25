#include "lambdas.h"
#include <array>
#include <fstream>
#include <functional>

template <typename T>
bool Comparator<T>::operator()(T a, T b)
{
    return a > b;
}

/* template <typename T, size_t size, typename function>
void applyFunction(std::array<T, size>& arr, function func)
{
    for (size_t i = 0; i < size; ++i)
    {
        func(arr[i]);
    }
} */

template <typename T, int size, typename function>
void applyFunction(T(&arr)[size], function func)
{
    for (int i = 0; i < size; ++i)
    {
        func(arr[i]);
    }
}

void function_object()
{
    Comparator<int> comp;
    std::cout << "Comparing 5 and 10: " << comp(5, 10) << std::endl; // Output: 0 (false)
    std::cout << std::endl;

    // std::array<int, 5> arr = {12, 23, 33, 45, 50};
    int arr[5] = {1, 2, 3, 4, 5};
    Display_value<int> display_int;
    applyFunction(arr, display_int);

    auto fn = [](int value){
        std::cout << "Lambda value: " << value << std::endl;
    };

    fn(14);

    Product product("Gadget", 100.0);
    product.AssignTax();
    std::cout << "Final price of product is " << product.getFinalPrice() << std::endl;

    std::ofstream file_out{"../file.txt"};
    [out = std::move(file_out)]() mutable{
        if(out.is_open()){
            out << "Jai Sita Ram!" << std::endl;
        }
        out.close();
    }();

    std_function_example();
    std_bind_example();
}

void Product::AssignTax()
{
    double taxes[3] = {0.05, 0.10, 0.15};
    double base_price = m_price;
    applyFunction(taxes, [base_price, this](double tax){
        m_price += base_price * tax;
    });
}

double Product::getFinalPrice()
{
    return m_price;
}

void Multiply(int a, int b)
{
    std::cout << "Multiplication: " << a * b << std::endl;
}

void Accumulate(int a, int b, int c)
{
    std::cout << "Accumulation: " << a + b + c << std::endl;
}

void std_function_example()
{
    std::function<void(int, int)> func = Multiply;
    func(5, 10); // Output: Multiplication: 50

    std::function<void(int, int, int)> func_accumulate = Accumulate;
    func_accumulate(1, 2, 3); // Output: Accumulation: 6

    func = [](int x, int y){
        std::cout << "Lambda Addition: " << x + y << std::endl;
    };
    func(3,6);
}

void std_bind_example()
{
    auto bound_multiply = std::bind(Multiply, std::placeholders::_1, 10);
    bound_multiply(5); // Output: Multiplication: 50

    auto bound_accumulate = std::bind(Accumulate, std::placeholders::_1, std::placeholders::_2, 4);
    bound_accumulate(3, 5); // Output: Accumulation: 12
}