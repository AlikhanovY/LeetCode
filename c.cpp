#include <bits/stdc++.h>
using namespace std;

void recur(int n){
    if(n == 0) return;
    recur(n-1);
    cout << n << " ";
}
int main(){
    recur(5);
}