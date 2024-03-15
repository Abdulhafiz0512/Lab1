#include <iostream>

#include <bits/stdc++.h>
#include "vector"
#include "iterator"
using namespace std;
int main(){
    int a ,t ;
    cin >>a;
    int arr[a],sum=0;
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin>>t;
            sum=sum+t;
        }
        arr[i]=sum;
        sum=0;
    }
    int item=arr[1];
    int item0=arr[0];
    sort(arr, arr+a,greater<int>());
    int index=0;
    for (int o :arr){
        index++;
        if (item==o){
            break;
        }

    }
    if (item==item0){
        cout<<index-1;
    }
    else{
        cout<<index;
    }


}
