#include <iostream>

#include <bits/stdc++.h>
#include "vector"
#include "iterator"
using namespace std;
int main(){
    int a;
    cin >>a;

    list <int> v;
    for (int i = 0; i < a; ++i) {
        int y;
        cin>>y;
        v.push_back(y*y);
    }
    v.sort();
    for (int u :v){
        cout<<u<<" ";
    }
}
