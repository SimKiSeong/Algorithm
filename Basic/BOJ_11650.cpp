#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

typedef pair<int, int> P;
vector<P> points;

bool desc(P p1, P p2) {
    if (p1.first < p2.first) {
        return true;
    } else if (p1.first == p2.first) {
        if (p1.second < p2.second) {
            return true;
        }
    }
    return false;
}


int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points.push_back(make_pair(x, y));
    }

    sort(points.begin(), points.end(), desc);

    for (int i = 0; i < n; i++) {
        cout << points[i].first << " " << points[i].second << "\n";
    }

    return 0;
}