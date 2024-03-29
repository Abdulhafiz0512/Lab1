#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void customSort(vector<int> &arr, int v) {
    auto it = find(arr.begin(), arr.end(), v);
    int idx = it - arr.begin();
    sort(arr.begin(), arr.begin() + idx, greater<int>());
    sort(arr.begin() + idx + 1, arr.end());
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int v;
    cin >> v;

    customSort(arr, v);

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}