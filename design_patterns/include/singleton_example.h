#include <iostream>
#include <string>

class DiagnosticLogger{
    DiagnosticLogger();
    DiagnosticLogger(const DiagnosticLogger&) = delete;
    DiagnosticLogger& operator=(const DiagnosticLogger&) = delete;

    public:
    static DiagnosticLogger& getInstance();

    void Log(const std::string& msg);
};

void singleton_example();