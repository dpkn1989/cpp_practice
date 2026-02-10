#include <iostream>

class Operation{
       int m_multiplier;
    
    public:
    Operation(int multiplier): m_multiplier{multiplier} {}

    void operator()(int value){
        std::cout << "The value after operation is: " << value * m_multiplier << std::endl;
    }
};

int main(){
    std::cout << "Jai Sri Ram!!!" << std::endl;
    int value;
    std::cout << "Enter a value to multiply: ";
    std::cin >> value;
    Operation op(3);
    op(value);

    return 0;
}