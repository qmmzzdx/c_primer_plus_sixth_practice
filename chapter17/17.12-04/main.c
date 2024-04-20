#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"
#define N 2
#define MIN_PER_HR 60.0

static struct
{
    Queue line;
    int hours, perhour, wait_time;
    long cycle, cyclelimit, turnaways;
    long customers, served, sum_line, line_wait;
    double min_per_cust;
} malls[N]; //模拟2个摊位;

bool newcustomer(double x);
Item customertime(long when);

int main(void)
{
    int i;
    Item temp;

    srand((unsigned int)time(0));
    puts("Case Study: Sigmund Lander's Advice Booth");
    puts("Enter the number of simulation hours for the first mall:");
    scanf("%d", &malls[0].hours);
    malls[0].cyclelimit = MIN_PER_HR * malls[0].hours;

    puts("Enter the number of simulation hours for the second mall:");
    scanf("%d", &malls[1].hours);
    malls[1].cyclelimit = MIN_PER_HR * malls[1].hours;

    puts("Enter the average number of customers per hourfor the first mall:");
    scanf("%d", &malls[0].perhour);
    malls[0].min_per_cust = MIN_PER_HR / malls[0].perhour;

    puts("Enter the average number of customers per hourfor the second mall:");
    scanf("%d", &malls[1].perhour);
    malls[1].min_per_cust = MIN_PER_HR / malls[1].perhour;

    for (i = 0; i < N; i++) //使用循环来控制2个摊位;
    {
        for (malls[i].cycle = 0; malls[i].cycle < malls[i].cyclelimit; malls[i].cycle++)
        {
            if (newcustomer(malls[i].min_per_cust))
            {
                if (QueueIsFull(&malls[i].line))
                {
                    malls[i].turnaways++;
                }
                else
                {
                    malls[i].customers++;
                    temp = customertime(malls[i].cycle);
                    EnQueue(temp, &malls[i].line);
                }
            }
            if (malls[i].wait_time <= 0 && !QueueIsEmpty(&malls[i].line))
            {
                DeQueue(&temp, &malls[i].line);
                malls[i].wait_time = temp.processtime;
                malls[i].line_wait += malls[i].cycle - temp.arrive;
                malls[i].served++;
            }
            if (malls[i].wait_time > 0)
            {
                malls[i].wait_time--;
            }
            malls[i].sum_line += QueueItemCount(&malls[i].line);
        }
        if (malls[i].customers > 0)
        {
            printf("\nHere are some messages for the %s mall:\n", 0 == i ? "first" : "second");
            printf("customers accepted: %ld\n", malls[i].customers);
            printf("  customers served: %ld\n", malls[i].served);
            printf("         turnaways: %ld\n", malls[i].turnaways);
            printf("average queue size: %.2f\n",
                   (double)malls[i].sum_line / malls[i].cyclelimit);
            printf(" average wait time: %.2f minutes\n",
                   (double)malls[i].line_wait / malls[i].served);
        }
        else
        {
            printf("No customers for the %s mall!\n", 0 == i ? "first" : "second");
        }
        EmptyTheQueue(&malls[i].line);
    }
    puts("Bye!");

    return 0;
}

bool newcustomer(double x)
{
    return rand() * x / RAND_MAX < 1 ? true : false;
}

Item customertime(long when)
{
    Item cust;

    cust.processtime = rand() % 3 + 1;
    cust.arrive = when;

    return cust;
}
