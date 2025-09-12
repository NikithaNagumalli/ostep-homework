#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <iostream>
#include <csignal>

using std::cout;
using std::endl;
using std::signal;

volatile bool child_printed = false;

void handleChildDone(int signal) {child_printed = true; }

int main() {
    
    signal(SIGCHLD, handleChildDone);
    pid_t pid = fork();

    if (pid > 0) {
        while (!child_printed) {}
        cout << "parent says byee"<< endl;
    } else if (pid == 0) {
        cout << "child says hello" << endl;
    } else {
        cout << "fork failed" << endl;
    }
    return 0;
}