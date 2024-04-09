#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = n/2-1; i >= 0; i--){
        heapify(arr, n, i);
    }
    heapSort(arr, n);
    int temp = 1;
    for(int i = 1; i < n; i ++){
        if(arr[i-1] == arr[i]){
            temp ++;
        }else{
            if(temp >= (n+1)/2){
                cout << arr[i-1];
                return 0;
            }
            temp = 1;
        }
    }
    cout << arr[n-1];
    return 0;
}