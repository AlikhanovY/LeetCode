#include <bits/stdc++.h>
using namespace std;



void mergeSort(vector<int> &a, int start, int end){
    if(end - start < 2) return;
    if(end - start == 2){
        if(a[start] > a[end - 1]) swap(a[start], a[end - 1]);
        return ;
    }
    mergeSort(a, start, start+end / 2);
    mergeSort(a, start+ end/2, end);
    vector<int> b;
    int i = start, j = start + end / 2;
    while(i < start + end / 2 && j < end){
        if(a[i] <= a[j]) b.push_back(a[i++]);
        else b.push_back(a[j++]);
        }
        while(i < start + end / 2) b.push_back(a[i++]);
        while(j < end) b.push_back(a[j++]);
        for(int i = 0; i < b.size(); i++) a[start + i] = b[i];

}

int main(){
    vector<int> a;
    for(int i =0 ;i < 20;i ++){
        a.push_back(i);
    }
    for(int i = 0; i<a.size();i++){
        swap(a[i], a[rand() % (a.size() - i)+ i]);
    }
    
   /*  for(int i = 0; i< a.size()- 1;i++){
        int min_index = i;
        for(int j =i+1; j<a.size();j++){
            if(a[min_index] > a[j]){
                min_index = j;
            }
        }
        swap(a[i], a[min_index]);
    } */
    mergeSort(a, 0, a.size());
    for(auto c:a){
        cout << c << " ";
    }
}