#include <stdio.h>

void bucketSort(float a[], int n)
{
    float bucket[10][100];
    int count[10] = {0};
    int i, j, k = 0;
    float temp;

    // Put elements into buckets
    for (i = 0; i < n; i++)
    {
        int index = (int)(a[i] * 10);
        bucket[index][count[index]] = a[i];
        count[index]++;
    }

    // Sort each bucket using insertion sort
    for (i = 0; i < 10; i++)
    {
        for (j = 1; j < count[i]; j++)
        {
            temp = bucket[i][j];
            int p = j - 1;

            while (p >= 0 && bucket[i][p] > temp)
            {
                bucket[i][p + 1] = bucket[i][p];
                p--;
            }

            bucket[i][p + 1] = temp;
        }
    }
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < count[i]; j++)
        {
            a[k] = bucket[i][j];
            k++;
        }
    }
}

int main()
{
    float a[100];
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements (0 to 0.99): ");
    for (i = 0; i < n; i++)
        scanf("%f", &a[i]);

    bucketSort(a, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%.2f ", a[i]);

    return 0;
}