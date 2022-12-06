#include <stdio.h>
int bubblesort();
int Insertion_sort();
int Selsortt();
int countingSort();
int Radix_sort();
int main()
{
    int i, n, c;
    printf("enter size of array ");
    scanf("%d", &n);
    int A[n];
    printf("Enter elements ");
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);
label:
    printf("\n**************************\n \t MENU");
    printf("\nEnter No to Sort using : \n 1.Bubble Sort \n 2.Insertion Sort \n 3.Selection Sort \n 4.Counting Sort \n 5.Radix Sort \n 6.Exit");
    printf("\n**************************\n");
    scanf("%d", &c);
    if (c == 1)
    {
        bubblesort(A, n);
        goto label;
    }
    else if (c == 2)
    {
        Insertion_sort(A, n);
        goto label;
    }

    else if (c == 3)
    {
        Selsortt(A, n);
        goto label;
    }

    else if (c == 4)
    {
        countingSort(A, n);
        goto label;
    }

    else if (c == 5)
    {
        Radix_sort(A, n);
        goto label;
    }

    else if (c == 6)
    {

        return 0;
    }

    else
    {
        printf("Enter a valid no\n");
        goto label;
    }
}

int bubblesort(int A[], int n)
{
    int i, j, swap = 0, comp = 0;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            comp++;
            if (A[j] > A[j + 1])
            {
                swap++;
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
        if (swap == 0)

            break;
    }
    printf("\nResultant Array\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\nTotal No. of Comparison = %d", comp);
    printf("\nTotal No. of Swaps = %d", swap);
    printf("\n Nikhil Sharma \n 2101641520097 \n CS-AI \n 3rd Semester \n Section-A");
}
int Insertion_sort(int A[], int n)
{
    int i, j, key, comp = 0;
    for (i = 1; i < n; i++)
    {
        j = i - 1;
        key = A[i];
        while (key < A[j] && j >= 0)
        {
            A[j + 1] = A[j];
            j--;
            comp++;
        }
        comp++;
        A[j + 1] = key;
    }
    printf("\nResultant Array\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\nTotal No. of Comparison = %d", comp);
    printf("\n Nikhil Sharma \n 2101641520097 \n CS-AI \n 3rd Semester \n Section-A");
}
int Selsortt(int A[], int n)
{
    int i, j, min, loc, swap = 0, comp = 0;

    for (i = 0; i < n; i++)
    {
        min = A[i];
        loc = i;
        for (j = i + 1; j < n; j++)
        {
            comp++;
            if (A[j] < min)
            {
                min = A[j];
                loc = j;
            }
        }
        swap++;
        int temp = A[loc];
        A[loc] = A[i];
        A[i] = temp;
    }
    printf("\nResultant Array\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\nTotal No. of Comparison = %d", comp);
    printf("\nTotal no of Swaps = %d", swap);
    printf("\n Nikhil Sharma \n 2101641520097 \n CS-AI \n 3rd Semester \n Section-A");
}
int countingSort(int A[], int n)
{

    int i, max = A[0];
    for (i = 1; i < n; i++)
    {
        if (A[i] > max)
            max = A[i];
    }

    int output[max + 1];
    int count[max + 1];

    for (i = 0; i <= max; ++i)
    {
        count[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        count[A[i]]++;
    }

    for (i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }

    for (i = n - 1; i >= 0; i--)
    {
        output[count[A[i]] - 1] = A[i];
        count[A[i]]--;
    }

    for (i = 0; i < n; i++)
    {
        A[i] = output[i];
    }
    printf("\nResultant Array\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n Nikhil Sharma \n 2101641520097 \n CS-AI \n 3rd Semester \n Section-A");
}
int Radix_sort(int arr[], int n)
{

    int i, j, k, n_swap = 0, n_comp = 0;
    int r, d = 0, div = 1, lar = arr[0], l;
    for (i = 1; i < n; i++)
    {
        if (arr[i] > lar)
        {
            lar = arr[i];
        }
        n_comp++;
    }

    while (lar != 0)
    {
        d++;
        lar /= 10;
    }
    int a[10][n], arr1[10] = {};
    for (i = 0; i < d; i++)
    {
        for (j = 0; j < n; j++)
        {
            r = (arr[j] / div) % 10;
            a[r][arr1[r]] = arr[j];
            arr1[r] += 1;
        }
        j = 0;
        for (k = 0; k < 10; k++)
        {
            for (l = 0; l < arr1[k]; l++)
            {
                arr[j] = a[k][l];
                j++;
                n_swap++;
            }
            arr1[k] = 0;
        }
        div *= 10;
    }
    printf("Resultant Array: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nNo. of Comparisons:%d\n", n_comp);
    printf("No. of Swappings:%d\n", n_swap);
    printf("\n Nikhil Sharma \n 2101641520097 \n CS-AI \n 3rd Semester \n Section-A");
}