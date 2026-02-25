#ifndef LAMBDAS_H
#define LAMBDAS_H

#include <iostream>
#include <string>

template <typename T>
class Comparator{
    public:
    bool operator()(T a, T b);
};

template <typename T, int size, typename function>
void applyFunction(T(&arr)[size], function func);

template<typename T>
struct Display_value{
    void operator()(T value){
        std::cout << value << std::endl;
    }
};

void function_object();

class Product{
    std::string m_name;
    double m_price;
public:
    Product(std::string name, double price) : m_name(name), m_price(price) {}
    void AssignTax();
    double getFinalPrice();
};

void Multiply(int a, int b);
void Accumulate(int a, int b, int c);

void std_function_example();
void std_bind_example();

#endif // LAMBDAS_H