#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

priority_queue<int, vector<int>, less<int> > pq;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for (int z = 0; z < t; z++) {
        int tmp;
        cin >> tmp;
        if (tmp == 0) {
            if (pq.size() == 0) {
                cout << "0\n";
            }
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else {
            pq.push(tmp);
        }

    }
    return 0;
}