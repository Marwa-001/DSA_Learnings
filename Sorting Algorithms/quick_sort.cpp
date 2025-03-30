#include<iostream>
using namespace std;

int partition(int a[], int low, int high){
    int pivot = a[low];
    int i=low+1;
    int j=high;
    do{
        while (a[i]<=pivot)
        {
            i++;
        }
        while(a[j]>pivot){
            j--;
        }
        if(i<j){
            int temp=a[j];
            a[j]=a[i];
            a[i]=temp;
        }
    }while(i<j);

    int temp = a[low];
    a[low]=a[j];
    a[j]=temp;
    return j;
}

void quickSort(int a[], int low, int high){
    int partiotion_index;
    if(low<high){
        partiotion_index=partition(a, low, high);
        quickSort(a, low, partiotion_index-1);
        quickSort(a, partiotion_index+1, high);
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

 int main(){
    int A[6]={46,82, 94, 2, 6, 1};
    print(A, 6);
    quickSort(A, 0, 5);
    print(A, 6);
    return 0;
 }