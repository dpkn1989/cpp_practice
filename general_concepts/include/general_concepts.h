#ifndef GENERAL_CONCEPTS_H
#define GENERAL_CONCEPTS_H

#include<memory>
#include<iostream>

class Operation{
       int m_multiplier;
    
    public:
    Operation(int multiplier): m_multiplier{multiplier} {}

    void operator()(int value){
        std::cout << "The value after operation is: " << value * m_multiplier << std::endl;
    }
};

int factorial(int n);
int add(int a, int b);
int funcptr(int a, int b);

class Integer{
    int* m_int;
    static int m_count;
    
public:
    Integer();
    Integer(int value);

    Integer(const Integer& obj);
    Integer(Integer&& obj);

    Integer& operator=(const Integer& obj);
    Integer& operator=(Integer&& obj);

    Integer operator+(const Integer& obj);
    operator int();

    static int getCount();
    int getValue() const;
    void setValue(int value);

    ~Integer();
};

std::ostream& operator<<(std::ostream& out, const Integer& obj);
std::istream& operator>>(std::istream& in, Integer& obj);

void Integer_class(void);

Integer Add(const Integer&, const Integer&);

void DisplayInteger_Unique(std::unique_ptr<Integer> ptr);
void DisplayInteger_Shared(std::shared_ptr<Integer> ptr);

class Project;

class Employee{
    std::string m_name;
    int m_id;
    // std::unique_ptr<Project> m_project;
    std::shared_ptr<Project> m_project;

    public:
    // Employee(std::string name, int id, std::unique_ptr<Project> project);
    Employee(std::string name, int id, std::shared_ptr<Project> project);
    void Display() const;
    Project* getProject() const;
    ~Employee();
};

class Project{
    std::string m_project_name;
    int m_project_id;

    public:
    Project(std::string project_name, int project_id);
    void Display() const;
    ~Project();
};

void smart_pointers(void);

class WeakPtr{
    std::weak_ptr<Integer> m_weak_ptr;

    public:
    void setWeakPtr(std::shared_ptr<Integer> ptr);

    void Display() const;
};

void WeakPointer_example(void);

#endif // GENERAL_CONCEPTS_H