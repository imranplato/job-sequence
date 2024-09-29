#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> pairsSortedByB, indexSortedByB;
    vector<int> result(n, 0);

    int arrA[n], arrB[n];

    for (int i = 0; i < n; i++) {
        cin >> arrA[i];
        cin >> arrB[i];
        pairsSortedByB.push_back({arrB[i], arrA[i]});
        indexSortedByB.push_back({arrB[i], i});
    }

    for(int i=0;i<n;i++) cerr<<arrA[i]<<" ";
    cerr<<endl;

    for(int i=0;i<n;i++) cerr<<arrB[i]<<" ";
    cerr<<endl;

    sort(pairsSortedByB.rbegin(), pairsSortedByB.rend());
    sort(indexSortedByB.rbegin(), indexSortedByB.rend());

    int sequence[n + 1];
    memset(sequence, -1, sizeof(sequence));

    for (int i = 0; i < pairsSortedByB.size(); i++) {
        int currentIndex = pairsSortedByB[i].second;
        if (sequence[currentIndex] == -1) {
            sequence[currentIndex] = indexSortedByB[i].second + 1;
        } else {
            for (int j = 1; j <= n; j++) {
                if (sequence[j] == -1) {
                    if (pairsSortedByB[i].second >= j) {
                        sequence[j] = indexSortedByB[i].second + 1;
                        break;
                    }
                }
            }
        }
    }

    cout << endl;

    for (int i = 1; i <= n; i++) {
        if (sequence[i] == -1) continue;

        cout << sequence[i] << endl;
    }
    cout << endl;

    return 0;
}
