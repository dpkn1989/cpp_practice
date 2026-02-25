#include "Templates.h"

void Templates_example_perfect_forward()
{
    //Employee emp("Sitaram", 12345);

    /* Integer empId(123);
    Employee emp("Sitaram", empId); */
    
    Employee emp("Sitaram", Integer(999));
    std::cout << "Employee Name: " << emp.getName() << std::endl;
    std::cout << "Employee ID: " << emp.getId() << std::endl;

    emp.setName("Raghuram");
    emp.setId(54321);

    std::cout << "Updated Employee Name: " << emp.getName() << std::endl;
    std::cout << "Updated Employee ID: " << emp.getId() << std::endl;
}

void Print()
{
    std::cout << std::endl;
}

template <typename T, typename... Args>
void Print(T&& first, Args&&... params)
{
    std::cout << first;
    if(sizeof...(params) > 0)
    std::cout << ", ";
    Print(std::forward<Args>(params)...);
}

void Templates_example_variadic_template()
{
    Print("Hello", "World", 123, 45.67, Integer(5));
}

void Templates_example_class_template()
{
    std::vector<float> vec{3.3,5.1,6.3,9.9,12.3,14.1,15.3,18.3,21.6};
    Stack<float> s(vec);
    s.display();

    s.push(27.3);
    s.push(30.2);
    s.display();
    s.pop();
    s.display();

    Stack<int> s2 = Stack<int>::createStack();
    s2.push(10);
    s2.push(20);
    s2.display();

    Stack<std::string> s3 = Stack<std::string>::createStack();
    s3.push("Sivaram");
    s3.push("Sitaram");
    s3.push("Ganapthi");
    s3.push("Subrahmanyam");
    s3.display();
    s3.pop();
    s3.display();

    std::vector<int*> v{new int(3), new int(5), new int(9)};
    Stack<int*> s4(v);
    s4.display();
}

void Display(int count, char ch)
{
    for(int i = 0; i < count; i++)
        std::cout << ch << " ";
    std::cout << std::endl;
}

void Show(Console func)
{
    func(5, 'R');
}

