#include <stdio.h>
#include <math.h>
void hanoi(int n)
{
    long long total = pow(2,n) - 1;
    char source = 'A';
    char auxiliary = 'B';
    char destination = 'C';

    if (n % 2 == 0)
    {
        char temp = auxiliary;
        auxiliary = destination;
        destination = temp;
    }

    for (long long i = 1; i <= total; i++)
    {
        int disk = 1;
        long long x = i;

        while (x % 2 == 0)
        {
            x /= 2;
            disk++;
        }

        long long moveNo =
            (i / (1LL << (disk - 1)) + 1) / 2;

        if (disk % 2 == 1)
        {
            if (moveNo % 3 == 1)
                printf("Move disk %d from %c to %c\n",
                       disk, source, destination);

            else if (moveNo % 3 == 2)
                printf("Move disk %d from %c to %c\n",
                       disk, destination, auxiliary);

            else
                printf("Move disk %d from %c to %c\n",
                       disk, auxiliary, source);
        }
        else
        {
            if (moveNo % 3 == 1)
                printf("Move disk %d from %c to %c\n",
                       disk, source, auxiliary);

            else if (moveNo % 3 == 2)
                printf("Move disk %d from %c to %c\n",
                       disk, auxiliary, destination);

            else
                printf("Move disk %d from %c to %c\n",
                       disk, destination, source);
        }
    }
}

int main()
{
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    if (n < 1 || n > 20)
    {
        printf("Invalid input");
        return 0;
    }

    hanoi(n);

    return 0;
}
