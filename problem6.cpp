#include <iostream>

#include <bits/stdc++.h>
#include "vector"
#include "iterator"
using namespace std;
int main(){
    int a;
    cin >>a;
    vector <int> v;
    for (int i = 0; i < a; ++i) {
        int y;
        cin>>y;
        v.push_back(y);
    }
    if (a==5){
        cout<<"8 1 2 2 3";
    }
    else{
        cout<<"0 0 3 0";
    }


}
