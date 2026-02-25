#ifndef TEMPLATES_H
#define TEMPLATES_H

#include <string>
#include <iostream>
#include <vector>

class Integer{
    private:
        int value;
    public:
        Integer(int v) : value(v) {}
        int getValue() const { return value; }      
        void setValue(int v) { value = v; }
        friend std::ostream& operator<<(std::ostream& out, const Integer& obj) {
            out << obj.value;
            return out;
        }
};

class Employee{
    private:
        std::string name;
        Integer id;
    public:
        // Employee(const std::string& n, const Integer& i) : name(n), id(i) {}

        template <typename T1, typename T2>
        Employee(T1&& n, T2&& i) : name(std::forward<T1>(n)), id(std::forward<T2>(i)) {}
        
        std::string getName() const { return name; }
        int getId() const { return id.getValue(); }
        void setName(std::string n) { name = n; }
        void setId(int i) { id.setValue(i); }
};

void Templates_example_perfect_forward();

void Templates_example_variadic_template();

template <typename T>
class Stack{
    std::vector<T> data;
    int8_t top;
    public:
    Stack() : top(-1) { std::cout << "Stack Default Constructor called" << std::endl; }
    Stack(std::vector<T>& vec) : data(vec), top(vec.size() - 1) { std::cout << "Stack Parameterized Constructor called" << std::endl; }
    void push(T i) { data.push_back(i); top++; }
    void pop() { if(top >= 0) { data.pop_back(); top--; } else std::cout << "Stack Underflow" << std::endl; }
    int peek() const { if(top >= 0) return data[top]; else { std::cout << "Stack is empty" << std::endl; return -1; } }
    bool isEmpty() const { return top == -1; }
    void display() const{
        std::cout << "Displaying Stack elements -> ";
        for(int i = 0; i <= top; i++)
           std::cout << data[i] << " ";
        std::cout << std::endl;
    }

    static Stack createStack();
};

template <typename T>
Stack<T> Stack<T>::createStack()
{
    return Stack<T>();
}

// Explicit specialization for std::string
template<>
class Stack<std::string>{
    std::vector<std::string> data;
    int8_t top;
    public:
    Stack() : top(-1) { std::cout << "Stack Default Constructor called" << std::endl; }
    Stack(std::vector<std::string>& vec) : data(vec), top(vec.size() - 1) { std::cout << "Stack Parameterized Constructor called" << std::endl; }
    void push(std::string s) { data.push_back(s); top++; }
    void pop() { if(top >= 0) { data.pop_back(); top--; } else std::cout << "Stack Underflow" << std::endl; }
    std::string peek() const { if(top >= 0) return data[top]; else { std::cout << "Stack is empty" << std::endl; return ""; } }
    bool isEmpty() const { return top == -1; }
    void display() const{
        std::cout << "Displaying Stack elements -> ";
        for(int i = 0; i <= top; i++)
           std::cout << data[i] << " ";
        std::cout << std::endl;
    }

    static Stack createStack()
    {
        return Stack();
    }
};

void Templates_example_class_template();

// Partial specialization for pointer types
template <typename T>
class Stack<T*>{
    std::vector<T*> data;
    int8_t top;
    public:
    Stack() : top(-1) { std::cout << "Stack Default Constructor called for pointer type" << std::endl; }
    Stack(std::vector<T*>& vec) : data(vec), top(vec.size() - 1) { std::cout << "Stack Parameterized Constructor called for pointer type" << std::endl; }
    void push(T* ptr) { data.push_back(ptr); top++; }
    void pop() { if(top >= 0) { data.pop_back(); top--; } else std::cout << "Stack Underflow" << std::endl; }
    T* peek() const { if(top >= 0) return data[top]; else { std::cout << "Stack is empty" << std::endl; return nullptr; } } 
    bool isEmpty() const { return top == -1; }
    void display() const{
        std::cout << "Displaying Stack elements (pointer type) -> ";
        for(int i = 0; i <= top; i++)
            std::cout << *(data[i]) << " ";
        std::cout << std::endl;
    }
};

void Display(int count, char ch);

using Console = void(*)(int count, char ch);

void Show(Console func);

template <typename T>
T divide(T a, T b)
{
    static_assert(std::is_floating_point<T>::value,  "Template parameter must be a float type.");
    if(b == 0)
    {
        std::cerr << "Division by zero error!" << std::endl;
        return T(); // Return default value of T
    }
    return a / b;
}

#endif // TEMPLATES_H