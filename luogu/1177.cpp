//
// 1177 快速排序
//

#include <bits/stdc++.h>

using namespace std;

int a[100005];

void insert_sort(int l, int r)
{
    for (int i = l + 1; i < r; i++)
        for (int j = i; j > l && a[j] < a[j-1]; j--)
            swap(a[j], a[j-1]);
}

void quick_sort(int l, int r){
    if (r - l < 2) return;
    if (r - l < 9) {
        insert_sort(l, r);
        return;
    }
    int p = (rand() % (r - l)) + l;
    swap(a[l], a[p]);
    int mid = l;
    for (int i = l + 1; i < r; i++){
        if (a[i] < a[l]){
            mid++;
            swap(a[i], a[mid]);
        }
    }
    swap(a[l], a[mid]);
    quick_sort(l, mid);
    quick_sort(mid + 1, r);
}

int main() {
    int n;
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    quick_sort(0, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << endl;
    return 0;
}
