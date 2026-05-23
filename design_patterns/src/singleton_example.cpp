#include "singleton_example.h"

DiagnosticLogger::DiagnosticLogger()
{
    std::cout << "Diagnostic Logger Initialized!" << std::endl;
}

DiagnosticLogger& DiagnosticLogger::getInstance(){
    static DiagnosticLogger instance;
    return instance;
}

void DiagnosticLogger::Log(const std::string& msg)
{
    std::cout << "Diagnostic Log: " << msg << std::endl;
}

void singleton_example()
{
    DiagnosticLogger& DLT = DiagnosticLogger::getInstance();
    DLT.Log("Om namah Sivaya!");
    DLT.Log("Om Srimatre namaha!");
    DLT.Log("Om Gan Ganapataye Namah!");

    DiagnosticLogger& Logger = DiagnosticLogger::getInstance();
    Logger.Log("Om Namo Narayanaya!");
    Logger.Log("Om Srilakshmiye namah!");

    std::cout << "Are the logger instances the same? " << std::boolalpha << (&DLT == &Logger) << std::endl;
}