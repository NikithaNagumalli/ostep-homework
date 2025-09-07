#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <iostream>

using std::cout;
using std::endl;

int main() {
    pid_t pid = fork();
    int x = 100;

    if (pid > 0) {
        // wait(NULL);
        // x = 20;
        cout << "parent pid is " << getpid() << " value of x is " << x << endl;
    } else if (pid == 0) {
        // x = 10;
        cout << "child pid is " << getpid() << " with parent pid " << getppid() << " value of x is " << x << endl;
    } else {
        cout << "fork failed" << endl;
    }
    return 0;
}