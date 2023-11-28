#include <stdio.h>

void isSafe(int p, int r, int allocation[50][50], int need[50][50], int available[])
{
    int safeSequence[50];
    int flag = 0;
    int safe = 0;
    while (flag < p)
    {
        int change = 0;
        for (int i = 0; i < p; i++)
        {
            int count = 0;
            for (int j = 0; j < r; j++)
            {
                if (need[i][j] <= available[j])
                {
                    count++;
                }
            }
            if (count == r)
            {
                int present = 0;
                for (int z = 0; z < flag; z++)
                {
                    if (safeSequence[z] == i)
                    {
                        present = 1;
                        break;
                    }
                }
                if (present == 0)
                {
                    safeSequence[flag] = i;
                    for (int x = 0; x < r; x++)
                    {
                        available[x] += allocation[i][x];
                    }
                    flag++;
                    change = 1;
                }
            }
        }
        if (flag == p)
        {
            safe = 1;
            break;
        }
        if (change == 0)
            break;
    }

    if (safe == 1)
    {
        printf("\nThe system is in the safe state!\n");
        printf("\nThe safe sequence is:");

        for (int i = 0; i < p; i++)
        {
            printf(" P%d", safeSequence[i]);
        }
    }
    else
        printf("\nThe system is in the unsafe sate!\n");
}

void request(int p, int r, int allocation[50][50], int need[50][50], int available[50])
{
    int reqProcess;
    printf("\nEnter the process with new request:");
    scanf("%d", &reqProcess);

    int req[50];
    printf("\nEnter the new requests:\n");
    for (int i = 0; i < r; i++)
    {
        scanf("%d", &req[i]);
    }

    int step1 = 1;
    for (int i = 0; i < r; i++)
    {
        if (req[i] > need[reqProcess][i])
            step1 = 0;
    }

    if (step1 == 1)
    {
        int step2 = 1;
        for (int i = 0; i < r; i++)
        {
            if (req[i] > available[i])
                step2 = 0;
        }

        if (step2 == 1)
        {
            for (int i = 0; i < r; i++)
            {
                allocation[reqProcess][i] += req[i];
            }

            printf("\nNew allocation matrix is:\n");
            for (int i = 0; i < p; i++)
            {
                for (int j = 0; j < r; j++)
                {
                    printf(" %d", allocation[i][j]);
                }
                printf("\n");
            }

            for (int i = 0; i < r; i++)
            {
                need[reqProcess][i] -= req[i];
            }

            printf("\nNew need matrix is:\n");
            for (int i = 0; i < p; i++)
            {
                for (int j = 0; j < r; j++)
                {
                    printf(" %d", need[i][j]);
                }
                printf("\n");
            }

            for (int i = 0; i < r; i++)
            {
                available[i] -= req[i];
            }

            printf("\nNew available matrix is:\n");
            for (int j = 0; j < r; j++)
            {
                printf(" %d", available[j]);
            }
            printf("\n");

            isSafe(p, r, allocation, need, available);
        }
        else
            printf("\nThe resources are not available!\n");
    }
    else
        printf("\nMax need reached!");
}

int main()
{
    int p;
    printf("Enter the no of processes: ");
    scanf("%d", &p);
    int r;
    printf("Enter the no of resources: ");
    scanf("%d", &r);
    int allocation[50][50];
    printf("Enter the allocaion matrix: ");
    for (int i = 0; i < p; i++)
    {
        printf("\nEnter resources of process %d:\n", i);
        for (int j = 0; j < r; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }
    int max[50][50];
    printf("Enter the max need matrix: ");
    for (int i = 0; i < p; i++)
    {
        printf("\nEnter resources of process %d:\n", i);
        for (int j = 0; j < r; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }
    int available[50];
    printf("Enter the available matrix:\n");
    for (int i = 0; i < r; i++)
    {
        scanf("%d", &available[i]);
    }

    int need[50][50];
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < r; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    printf("\nAllocation matrix is:\n");
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < r; j++)
        {
            printf(" %d", allocation[i][j]);
        }
        printf("\n");
    }

    printf("\nMax need matrix is:\n");
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < r; j++)
        {
            printf(" %d", max[i][j]);
        }
        printf("\n");
    }

    printf("\nNeed matrix is:\n");
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < r; j++)
        {
            printf(" %d", need[i][j]);
        }
        printf("\n");
    }

    printf("\nAvailable matrix is:\n");
    for (int j = 0; j < r; j++)
    {
        printf(" %d", available[j]);
    }

    request(p, r, allocation, need, available);

    return 0;
}
