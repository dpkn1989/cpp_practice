#include "Accounts.h"
#include "Templates.h"
#include "lambdas.h"

int main()
{
    std::cout << "Jai SriRam!!!" << std::endl;

    /* SavingsAccount savingsAcc("Sitaram", 1000.0, 5.0);
    CheckingAccount checkingAcc("Raghuram", 500.0, 200.0);

    Transaction(&savingsAcc);
    std::cout << std::endl;
    Transaction(&checkingAcc);  
    std::cout << std::endl;

    Templates_example_perfect_forward();
    Templates_example_variadic_template();
    Templates_example_class_template();
    
    Console consoleFunc = Display;
    Show(consoleFunc);

    std::cout << "The value of division is: " << divide(24.4, 2.2) << std::endl; */

    function_object();    // Function object, lambda, std::function, std::bind examples

    return 0;
}