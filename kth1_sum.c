#include <stdio.h>
#include <stdlib.h>

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int left, int right) {
    int randomIdx = left + rand() % (right - left + 1);

    swap(arr, randomIdx, right);

    int pivot = arr[right];
    int i = left;

    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            swap(arr, i, j);
            i++;
        }
    }

    swap(arr, i, right);
    return i;
}

int quickSelect(int arr[], int left, int right, int targetIdx) {
    while (left < right) {
        int pivotIdx = partition(arr, left, right);

        if (pivotIdx == targetIdx)
            return arr[pivotIdx];
        else if (pivotIdx < targetIdx)
            left = pivotIdx + 1;
        else
            right = pivotIdx - 1;
    }

    return arr[left];
}

int findKthSmallest(int arr[], int n, int k) {
    return quickSelect(arr, 0, n - 1, k - 1);
}

int main() {
    int n, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    if (k < 1 || k > n) {
        printf("Invalid value of k\n");
        return 0;
    }

    int result = findKthSmallest(arr, n, k);

    printf("The %dth smallest element is: %d\n", k, result);

    return 0;
}
