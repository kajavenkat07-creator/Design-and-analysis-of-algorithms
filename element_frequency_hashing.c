#include <stdio.h>

#define SIZE 100

int hashTable[SIZE];
int frequency[SIZE];

int hash(int key)
{
    return (key % SIZE + SIZE) % SIZE;
}

void insert(int key)
{
    int index = hash(key);

    while (hashTable[index] != -1 && hashTable[index] != key)
        index = (index + 1) % SIZE;

    if (hashTable[index] == key)
        frequency[index]++;
    else
    {
        hashTable[index] = key;
        frequency[index] = 1;
    }
}

int main()
{
    int n, a[100];

    for (int i = 0; i < SIZE; i++)
    {
        hashTable[i] = -1;
        frequency[i] = 0;
    }

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        insert(a[i]);
    }

    printf("Element : Frequency\n");

    for (int i = 0; i < SIZE; i++)
    {
        if (hashTable[i] != -1)
            printf("%d : %d\n", hashTable[i], frequency[i]);
    }

    return 0;
}