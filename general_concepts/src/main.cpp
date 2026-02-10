#include <iostream>
#include "general_concepts.h"

int main(){
    std::cout << "Jai Sri Ram!!!" << std::endl;
    int value;
    std::cout << "Enter a value to multiply: ";
    std::cin >> value;
    Operation op(3);
    op(value);

    return 0;
}