#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
#include <set>

using namespace std;

typedef pair<int, int> P;

vector<P> positions;
int n;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        positions.push_back(make_pair(tmp1, tmp2));
    }

    sort(positions.begin(), positions.end());


    int distance = 0;
    int endPoint = -2100000000;
    for (int i = 0; i < n; i++) {
        if (positions[i].first <= endPoint) {
            if (endPoint >= positions[i].second) {
                continue;
            }
            else {
                distance += positions[i].second - endPoint;
                endPoint = positions[i].second;
            }
        }
        else {
            distance += positions[i].second - positions[i].first;
            endPoint = positions[i].second;
        }
    }

    cout << distance;

    //cout << solution("111011110011111011111100011111",3);

    return 0;
}