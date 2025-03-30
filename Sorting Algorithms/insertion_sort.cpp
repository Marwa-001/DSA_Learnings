#include<iostream>
using namespace std;

void insertionSort(int a[], int n){
    int key, j;
    for(int i=1; i< n; i++){
        key=a[i];
        j=i-1;
        while(a[j]>key && j>=0){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
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
    insertionSort(A, 6);
    print(A, 6);
    return 0;
 }