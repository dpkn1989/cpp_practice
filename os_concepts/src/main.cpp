#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    
    /*int fd = open("sample.txt", O_CREAT | O_RDWR, 0666);
    if(fd == -1){
        std::cout << "File creation failed" << std::endl;
        return 1;
    }

    pid_t pid = fork();

    if(pid == -1)
         std::cout << "Fork failed" << std::endl;
    else if(pid == 0)
    {
        std::cout << "Child Process: " << getpid() << std::endl;
        for(int i=0; i<10000; i++)
        {
            write(fd, "A\n", 1);
        }
    }
    else
    {    
        std::cout << "Parent Process: " << getpid() << ", Child PID: " << pid << std::endl;
        for(int i=0; i<10000; i++)
        {
            write(fd, "B\n", 1);
        }
    }*/

    pid_t wpid = fork();
    if(wpid == -1)
         std::cout << "Fork failed" << std::endl;
    else if(wpid == 0)
    {
        std::cout << "Second Child Process: " << getpid() << std::endl;
        
        //char* args[] = {(char *)"cd", (char*)"~/MyLearning/", NULL};
        //char* args[] = {(char *)"ls", (char*)"-la", nullptr};
        execvp(argv[1], argv+1);
        perror("exec failed");
    }
    else
    {    
        std::cout << "Parent Process: " << getpid() << ", Second Child PID: " << wpid << std::endl;
        wait(nullptr);
    }

    return 0;
}