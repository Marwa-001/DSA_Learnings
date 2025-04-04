#include<iostream>
using namespace std;

void merge(int a[], int mid, int low, int high){
    // You can dynamically initialize an array, but here for simplicity i am creating it for a larger range
    int i, j, k, b[100];
    i = low;
    j = mid+1;
    k = low;
    while(i<=mid && j<=high){
        if(a[i]<a[j]){
            b[k]=a[i];
            i++;
            k++;
        }
        else{
            b[k]=a[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        b[k]=a[i];
        i++;
        k++;
    }
    while(j<=high){
        b[k]=a[j];
        k++;
        j++;
    }
    for(int i=low; i<=high; i++){
        a[i]=b[i];
    }
}

void mergeSort(int a[], int low, int high){
    if(low<high){
        int mid = (low+high)/2;
        mergeSort(a, low, mid);
        mergeSort(a, mid+1, high);
        merge(a, mid, low, high);
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
    mergeSort(A, 0, 5);
    print(A, 6);
    return 0;
 }