#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int arr[], int l, int h)
{
    int temp,  j;
    int pivot = arr[h];
    int i = l - 1;
    for(j = l;j<=(h-1); j++)
    {
            if(arr[j] <= pivot)
            {
                i++;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
    }
        temp=arr[i+1];
        arr[i+1]=arr[h];
        arr[h] = temp;
    return (i+1);
}

void quickSort(int arr[], int l, int h)
{
    int m;
    if(l<h)
    {
        m = partition(arr,l,h);
        quickSort(arr,l,m-1);
        quickSort(arr,m+1,h);
    }
}

void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    clock_t start, end;
    double cpu_time;
    int n;
    printf("enter size of array:");
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++)
    {
      arr[i] = rand()%n+1;
    }
    start = clock();
    quickSort(arr, 0, n-1);
    end = clock();
    printf("\nsorted array:\n");
    printArray(arr, n);
    cpu_time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("\ncpu time: %e",cpu_time);
    return 0;
}
