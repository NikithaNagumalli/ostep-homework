#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <iostream>
#include <fstream>
#include <fcntl.h>

using std::cout;
using std::endl;
using std::string;

int main() {
    pid_t pid = fork();

    int fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC);
    printf("fd at creation = %d\n", fd);

    
    if (pid > 0) {
        // wait(NULL);
        cout << "parent pid is " << getpid() << " value of fd is " << fd << endl;
        int sz = write(fd, "hi, it's the parent\n", sizeof("hi, it's the parent\n"));
        cout << "parent returned from write with " << sz << endl;
    } else if (pid == 0) {
        cout << "child pid is " << getpid() << " with parent pid " << getppid() << " value of fd is " << fd << endl;
        int sz = write(fd, "hi, it's the child\n", sizeof("hi, it's the child\n"));
        cout << "parent returned from write with " << sz << endl;
    } else {
        cout << "fork failed" << endl;
    }
    return 0;
}