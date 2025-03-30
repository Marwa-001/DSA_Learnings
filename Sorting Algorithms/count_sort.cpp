#include<iostream>
using namespace std;

int maximum(int a[], int b){
    int max=a[0];
    for(int i=0; i<b; i++){
        if(a[i]>max){
            max= a[i];
        }
    }
    return max;
}

void countSort(int a[], int n){
    int max = maximum(a, n);
    int count[max+1];

    // Initialize count array will zeros
    for(int i=0; i<=max; i++){
        count[i]=0;
    }

    for(int i=0; i<n; i++){
        count[a[i]]++;
    }

    int i=0, j=0;
    while(i<=max){
        if(count[i]>0){
            a[j]=i;
            count[i]=count[i]-1;
            j++;
        }
        else{
            i++;
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

 int main(){
    int A[6]={46,82, 94, 2, 6, 1};
    print(A, 6);
    countSort(A, 6);
    print(A, 6);
    return 0;
 }