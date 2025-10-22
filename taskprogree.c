#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
const int barlength=50;
typedef struct 
{
    int id;
    int p;
    int step;
}task;

void print(task task)
{
    printf("Task %d : [",task.id);
    for(int i=0;i<(task.p*barlength)/100;i++)
    {
        printf("=");
    }
    for(int i=0;i<barlength-(task.p*barlength)/100;i++)
    {
        printf(" ");
    }
    printf("]");
    printf(" %d%%",task.p);
    return;
}

int main()
{
    task tasks[5];
    for(int i=0;i<5;i++)
    {
        tasks[i].id=i+1;
        tasks[i].p=0;
        tasks[i].step = rand() % 5 + 1;
    }
    int taskincomplete=1;
    while(taskincomplete)
    {
        taskincomplete=0;
        system("cls");
        for(int i=0;i<5;i++)
        {
            print(tasks[i]);
            tasks[i].p += tasks[i].step;
            if(tasks[i].p<100)
            {
                taskincomplete=1;
            }
            if(tasks[i].p>100)
            {
                tasks[i].p=100;
            }
            printf("\n");
        }
        sleep(1); 
    }
    return 0;
}