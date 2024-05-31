#include <bits/stdc++.h>
using namespace std;
void merge(int a[], int l, int m, int r){
    int n1 = m -l +1;
    int n2 = r - m;
    vector<int> first(n1);
    vector<int> second(n2);
    for(int i = 0; i<n1; i++){
        first[i] = a[l + i];
    }
    for(int i = 0; i<n2; i++){
        second[i] = a[m + i + 1];
    }
    int i = 0, j = 0, k = l;
    while( i < n1 && j < n2){
        if(first[i] < second[j]){
            a[k] = first[i];
            i++;
        }
        else{
            a[k] = second[j];
            j++;
        }
        k++;
    }
    while( i< n1){
        a[k] = first[i];
        i++;
        k++;
    }
    while( j < n2){
        a[k] = second[j];
        j++;
        k++;
    }
}
void mergeSort(int a[], int l, int r){
    if(l >= r ){
        return; 
    }
    int m = l + (r - l)/2;
    mergeSort(a, l, m);
    mergeSort(a, m+1, r);
    merge(a, l ,m, r);
}
int main(){
    int a[] = {4, 2 ,1 ,3};
    int l = 0;
    int r = (sizeof(a)/ sizeof(a[0])) -1 ;
    mergeSort(a, l, r);
    for(auto c : a){
        cout << c << " ";
    }

}