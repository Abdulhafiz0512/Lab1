#include <iostream>

#include <bits/stdc++.h>
#include "vector"
#include "iterator"
using namespace std;
int main(){
    int a;
    cin >>a;
    vector <int> l;
    vector <int> v;
    for (int i = 0; i < a; ++i) {
        int y;
        cin>>y;
        v.push_back(y);
    }
    int count;
    for (int i :v) {
        for (int j :v) {
            if (i>j){
                count++;
            }
        }
        l.push_back(count);
        count=0;


    }
    for(int p :l){
        cout<<p<<" ";
    }

}
