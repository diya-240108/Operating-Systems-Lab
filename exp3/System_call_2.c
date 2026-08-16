#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;

    pid = fork();

    if (pid == 0)
    {
        printf("Child Process Running\n");
        sleep(5);
        printf("Child Process Completed\n");
    }
    else
    {
        wait(NULL);
        printf("Parent Resumes Execution\n");
    }

    return 0;
}
