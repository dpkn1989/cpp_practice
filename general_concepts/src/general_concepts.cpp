#include "general_concepts.h"

/* int factorial(int n)
{
    int result = 1;

    if(n <= 0)
    {
        return result;
    }
    else
    {
        for(int i = 1; i <= n; i++)
        {
            result *= i;
        }
    }
    return result;
} */

int factorial(int n)
{
    if(n <= 0)
    {
        return 1;
    }
    
    return n * factorial(n-1);
}

int add(int a, int b)
{
    return a+b;
}

int funcptr(int a, int b)
{
    int (*ptr)(int, int) = add;

    return ptr(a,b);
}

int Integer::m_count = 0;

Integer::Integer() : Integer(0) {
    std::cout << "Default Integer Constructor called" << std::endl;
}

Integer::Integer(int value)
{
    std::cout << "Parameterised Integer Constructor called" << std::endl;
    m_int = new int(value);
    m_count++;
}

Integer::Integer(const Integer& obj)
{
    std::cout << "Copy Integer Constructor called" << std::endl;
    m_int = new int(*obj.m_int);
    m_count++;
}

Integer::Integer(Integer&& obj)
{
    std::cout << "Move Integer Constructor called" << std::endl;
    m_int = obj.m_int;
    obj.m_int = nullptr;
    m_count++;
}

Integer& Integer::operator=(const Integer& obj)
{
    std::cout << "Copy Integer Assignment Operator called" << std::endl;
    if(this != &obj)
    {
        delete m_int;
        m_int = new int(*obj.m_int);
    }
    return *this;
}

Integer& Integer::operator=(Integer&& obj)
{
    std::cout << "Move Integer Assignment Operator called" << std::endl;
    if(this != &obj)
    {
        delete m_int;
        m_int = obj.m_int;
        obj.m_int = nullptr;
    }
    return *this;
}

Integer Integer::operator+(const Integer& obj)
{
    std::cout << "Integer operator+ called" << std::endl;
    return Integer(*m_int + *obj.m_int);
}

Integer::operator int()
{
    std::cout << "Integer Type Conversion operator int() called" << std::endl;
    return *m_int;
}

int Integer::getCount()
{
    return m_count;
}

int Integer::getValue() const
{
    return *m_int;
}

void Integer::setValue(int value)
{
    *m_int = value;
}

Integer::~Integer()
{
    std::cout << "Integer Destructor called" << std::endl;
    delete m_int;
    m_int = nullptr;
    m_count--;
}

std::ostream& operator<<(std::ostream& out, const Integer& obj)
{
    out << obj.getValue();
    return out;
}

std::istream& operator>>(std::istream& in, Integer& obj)
{
    int value;
    in >> value;
    obj.setValue(value);
    return in;
}

Integer Add(const Integer& a, const Integer& b)
{
    return Integer(a.getValue() + b.getValue());
}

void DisplayInteger_Unique(std::unique_ptr<Integer> ptr)
{
    std::cout << "The value in unique ptr is: " << ptr->getValue() << std::endl;
}

void DisplayInteger_Shared(std::shared_ptr<Integer> ptr)
{
    std::cout << "The value in shared ptr is: " << ptr->getValue() << std::endl;
}

void Integer_class(void)
{
	Integer i,j(9),k(12);
	i.setValue(Add(i, j).getValue());
	std::cout << "The value in i object is: " << i.getValue() << std::endl;
	i = j;
	std::cout << "The value in i object after copy assignment is: " << i.getValue() << std::endl;
    std::cout << "The count of Integer objects is: " << Integer::getCount() << std::endl;
	i = std::move(k);
	std::cout << "The value in i object after move assignment is: " << i.getValue() << std::endl;
    std::cout << "The count of Integer objects is: " << Integer::getCount() << std::endl;

	Integer l = i + j;
	std::cout << "The value in i object after operator+ is: " << i.getValue() << std::endl;
	std::cout << "The value in l object after operator+ is: " << l.getValue() << std::endl;
	
	std::cout << "Enter the value to j object: " << std::endl;
	std::cin >> j;
	std::cout << "The value in j object is: " << j.getValue() << std::endl;
    std::cout << "The count of Integer objects is: " << Integer::getCount() << std::endl;

	std::unique_ptr<Integer> pu(new Integer);
	pu->setValue(72);
	DisplayInteger_Unique(std::move(pu));
    std::cout << "The count of Integer objects is: " << Integer::getCount() << std::endl;
	std::cout << std::endl;
	std::shared_ptr<Integer> ps(new Integer);
	ps->setValue(81);
	DisplayInteger_Shared(ps);
    std::cout << "The count of Integer objects is: " << Integer::getCount() << std::endl;

	Integer intr;
	intr = 63;     // Here, Parameterized constr will be called on temporary object and then Move Assignment operator
	               // is called. Observe the output. However, for this to work "explicit" should be removed for the Constr
	               // to allow implicit conversion from Primitive to User defined type.

	int x = i;     // Here, I'm trying to convert User defined type (Integer object 'i') to Primitive type, which is not possible by default. 
	               // Hence, we define a Type Conversion operator to make this conversion possible. Refer to 'operator int()' function
	std::cout << "The value of integer x is : " << x << std::endl;
    std::cout << "The count of Integer objects is: " << Integer::getCount() << std::endl;

	std::cout << std::endl;

    smart_pointers();
    std::cout << std::endl;

    WeakPointer_example();
    std::cout << std::endl;
}

// Employee::Employee(std::string name, int id, std::unique_ptr<Project> project)
//    :  m_name(name), m_id(id), m_project(std::move(project))
Employee::Employee(std::string name, int id, std::shared_ptr<Project> project)
    :  m_name(name), m_id(id), m_project(project)
{
    std::cout << "Employee Constructor called" << std::endl;
}

void Employee::Display() const
{
    std::cout << "Employee Name: " << m_name << std::endl;
    std::cout << "Employee ID: " << m_id << std::endl;
    if(m_project)
    {
        m_project->Display();
    }
    else
    {
        std::cout << "No project assigned" << std::endl;
    }
}

Project* Employee::getProject() const{
    return m_project.get();
}

Employee::~Employee()
{
    std::cout << "Employee Destructor called" << std::endl;
}

Project::Project(std::string project_name, int project_id)
    : m_project_name(project_name), m_project_id(project_id)
{
    std::cout << "Project Constructor called" << std::endl;
}

void Project::Display() const
{
    std::cout << "Project Name: " << m_project_name << std::endl;
    std::cout << "Project ID: " << m_project_id << std::endl;
}

Project::~Project()
{
    std::cout << "Project Destructor called" << std::endl;
}

void smart_pointers(void)
{
    /* std::unique_ptr<Project> prj = std::make_unique<Project>("xPAD",90);
    Employee e1("Sitaram",1,std::move(prj));
    e1.Display();
    e1.getProject()->Display(); */

    std::shared_ptr<Project> prj = std::make_shared<Project>("xPAD",90);
    Employee e1("Sitaram",1,prj);
    e1.Display();
    e1.getProject()->Display();

    Employee e2("Sivaram",2,prj);
    e2.Display();
    e2.getProject()->Display();
}

void WeakPtr::setWeakPtr(std::shared_ptr<Integer> ptr)
{
    m_weak_ptr = ptr;
}

void WeakPtr::Display() const
{
    if(std::shared_ptr<Integer> sptr = m_weak_ptr.lock())
    {
        std::cout << "The value in weak ptr is: " << sptr->getValue() << std::endl;
    }
    else
    {
        std::cout << "The shared object has been destroyed and the weak pointer is now empty." << std::endl;
    }
}

void WeakPointer_example(void)
{
    std::shared_ptr<Integer> sptr = std::make_shared<Integer>(45);
    WeakPtr wptr;
    wptr.setWeakPtr(sptr);
    wptr.Display();

    sptr.reset(); // Destroy the object pointed to by sptr

    wptr.Display();
}