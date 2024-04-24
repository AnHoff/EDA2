#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ull unsigned long long
#define less(a, b) (a.value == b.value ? a.key < b.key : a.value < b.value)
#define less2(a, b) (a.key == b.key ? a.value < b.value : a.key < b.key)
#define swap(a, b)  \
    {               \
        Item temp = a; \
        a = b;      \
        b = temp;      \
    }
#define cmpswap(a, b) \
    if (less(b, a))   \
    swap(a, b)
#define cmpswap2(a, b) \
    if (less2(b, a))   \
    swap(a, b)

typedef struct
{
    long long key;
    int value;
} Item;

int partition2(Item *arr, int left, int right)
{
    Item pivot = arr[right];
    int i = left;
    for (int j = left; j < right; j++)
        if (less2(arr[j], pivot))
        {
            swap(arr[j], arr[i]);
            i++;
        }
    swap(arr[i], arr[right]);
    return i;
}

void quicksortM3(Item *arr, int left, int right)
{
    if (right - left <= 32)
        return;

    swap(arr[(left + right) / 2], arr[right - 1]);
    cmpswap2(arr[left], arr[right - 1]);
    cmpswap2(arr[left], arr[right]);
    cmpswap2(arr[right - 1], arr[right]);

    int pivotIndex = partition2(arr, left, right);
    quicksortM3(arr, left, pivotIndex - 1);
    quicksortM3(arr, pivotIndex + 1, right);
}

void insertionsort(Item *arr, int left, int right)
{
    for (int i = left + 1, j; i <= right; i++)
    {
        Item key = arr[i];
        for (j = i; j > 0 && less2(key, arr[j - 1]); j--)
            arr[j] = arr[j - 1];
        arr[j] = key;
    }
}

void quicksort2(Item *arr, int left, int right)
{
    quicksortM3(arr, left, right);
    insertionsort(arr, left, right);
}

int partition(Item *arr, int left, int right)
{
    Item pivot = arr[right];
    int i = left;
    for (int j = left; j < right; j++)
        if (less(arr[j], pivot))
        {
            swap(arr[j], arr[i]);
            i++;
        }
    swap(arr[i], arr[right]);
    return i;
}

void quickselect(Item *arr, int left, int right, int index)
{
    cmpswap(arr[(left + right) / 2], arr[right]);
    cmpswap(arr[left], arr[(left + right) / 2]);
    cmpswap(arr[right], arr[(left + right) / 2]);

    int pivotIndex = partition(arr, left, right);
    if (pivotIndex > index)
        quickselect(arr, left, pivotIndex - 1, index);
    else if (pivotIndex < index)
        quickselect(arr, pivotIndex + 1, right, index);
}

Item array[10000001];

void solve()
{
    int k;
    scanf(" %d", &k);
    int n;
    for (n = 0; scanf(" %lld %d", &array[n].key, &array[n].value) == 2; n++);

    quickselect(array, 0, n - 1, k - 1);
    quicksort2(array, 0, k - 1);

    for (int i = 0; i < k; i++)
        printf("%lld %d\n", array[i].key, array[i].value);
}

int main()
{
    solve();

    return 0;
}
