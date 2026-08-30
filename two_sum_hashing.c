#include <stdio.h>

#define SIZE 100

int hashTable[SIZE];

int hash(int key)
{
    return (key % SIZE + SIZE) % SIZE;
}

int search(int key)
{
    int index = hash(key);

    while (hashTable[index] != -1)
    {
        if (hashTable[index] == key)
            return 1;

        index = (index + 1) % SIZE;
    }

    return 0;
}

void insert(int key)
{
    int index = hash(key);

    while (hashTable[index] != -1)
        index = (index + 1) % SIZE;

    hashTable[index] = key;
}

int main()
{
    int n, T, a[100];

    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter target: ");
    scanf("%d", &T);

    for (int i = 0; i < n; i++)
    {
        int required = T - a[i];

        if (search(required))
        {
            printf("Pair exists\n");
            return 0;
        }

        insert(a[i]);
    }

    printf("Pair does not exist\n");

    return 0;
}