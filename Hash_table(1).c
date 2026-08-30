#include <stdio.h>

#define SIZE 10

int hashTable[SIZE];

void insert(int key)
{
    int index = key % SIZE;
    int i = 0;

    while (hashTable[(index + i * i) % SIZE] != -1)
    {
        i++;

        if (i == SIZE)
        {
            printf("Hash table is full\n");
            return;
        }
    }

    hashTable[(index + i * i) % SIZE] = key;
}

void display()
{
    for (int i = 0; i < SIZE; i++)
    {
        if (hashTable[i] == -1)
            printf("%d : Empty\n", i);
        else
            printf("%d : %d\n", i, hashTable[i]);
    }
}

int main()
{
    int n, key;

    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter key: ");
        scanf("%d", &key);
        insert(key);
    }

    display();

    return 0;
}