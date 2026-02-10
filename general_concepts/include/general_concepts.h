#ifndef GENERAL_CONCEPTS_H
#define GENERAL_CONCEPTS_H


class Operation{
       int m_multiplier;
    
    public:
    Operation(int multiplier): m_multiplier{multiplier} {}

    void operator()(int value){
        std::cout << "The value after operation is: " << value * m_multiplier << std::endl;
    }
};

#endif // GENERAL_CONCEPTS_H