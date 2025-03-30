#include<iostream>
using namespace std;

void selectionSort(int a[], int n){
    for(int i=0; i<n; i++){
        int min_index=i;
        for(int j=i+1; j<n; j++){
            if(a[j]<a[min_index]){
                min_index=j;
            }
        }

        // swap i and min_index
        int temp=a[i];
        a[i]=a[min_index];
        a[min_index]=temp;
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
    selectionSort(A, 6);
    print(A, 6);
    return 0;
 }