#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    pid_t pid1, pid2, pid3;

    // Create first child
    pid1 = fork();

    if (pid1 == 0)
    {
        printf("Child 1: PID = %d, PPID = %d\n", getpid(), getppid());
        sleep(2);
        printf("Child 1 completed.\n");
        exit(10);
    }

    // Create second child
    pid2 = fork();

    if (pid2 == 0)
    {
        printf("Child 2: PID = %d, PPID = %d\n", getpid(), getppid());
        sleep(4);
        printf("Child 2 completed.\n");
        exit(20);
    }

    // Create third child
    pid3 = fork();

    if (pid3 == 0)
    {
        printf("Child 3: PID = %d, PPID = %d\n", getpid(), getppid());
        sleep(6);
        printf("Child 3 completed.\n");
        exit(30);
    }

    // Parent
    printf("Parent PID = %d\n", getpid());

    // Wait for any child
    printf("Parent using wait()...\n");
    pid_t completed = wait(NULL);

    printf("wait() detected child PID %d completed.\n", completed);

    // Wait specifically for Child 2
    printf("Parent using waitpid() for Child 2...\n");
    waitpid(pid2, NULL, 0);

    printf("waitpid() detected Child 2 completed.\n");

    // Wait for remaining child
    wait(NULL);

    printf("All children completed.\n");

    return 0;
}
