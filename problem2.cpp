#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> &v) {
    int n = v.size();
    for (int i = 1; i < n; ++i) {
        int key = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] < key) {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = key;
    }
}
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    insertionSort(v);
    for (int i = 0; i < n; ++i) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}