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
  int sz1 = (n+1)/2, sz = n/2;
  int a[sz1], b[sz];
  for(int i = 0; i < sz; i ++){
    cin >> a[i] >> b[i];
  }
  if(sz1!=sz) cin >> a[sz];
  for(int i = sz1/2-1; i >= 0; i--){
      heapify(a, sz1, i);
  }
  heapSort(a, sz1);
  for(int i = sz/2-1;i >= 0; i--){
      heapify(b, sz, i);
  }
  heapSort(b, sz);
  for(int i = 0; i < sz1/2; i++){
    swap(a[i], a[sz1-1-i]);
  }
  for(int i = 0; i < sz; i++){
    cout << a[i] << ' ' << b[i] << ' ';
  }
  if(sz1!=sz) cout << a[sz];

  return 0;
}