#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        // Child executes another program
        char *args[] = {(char*)"ls", (char*)"-l", nullptr};
        execvp(args[0], args);
        perror("exec failed"); // Only if exec fails
    } else {
        std::cout << "Parent waiting...\n";
        wait(nullptr);
        std::cout << "Done.\n";
    }
}
