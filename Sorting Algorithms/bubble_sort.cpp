#include <iostream>
using namespace std;

// bubble sort is not adaptive but can be made so
void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        cout << "Pass" << i + 1 << " ";
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp;
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

// Adapative -> if array is already sorted one then there is no need to do further comparisons, if the algorithm meet this requirement then it is an adaptive one
void bubbleSortAdaptive(int a[], int n)
{
    bool isSorted = false;
    for (int i = 0; i < n - 1; i++)
    {
        isSorted = true;
        cout << "Pass" << i + 1 << " ";
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                isSorted = false;
                int temp;
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
        if (isSorted)
        {
            return;
        }
    }
}

void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int a[6] = {15, 23, 66, 21, 50, 43};
    print(a, 6);
    bubbleSort(a, 6);
    bubbleSortAdaptive(a, 6);
    print(a, 6);

    return 0;
}