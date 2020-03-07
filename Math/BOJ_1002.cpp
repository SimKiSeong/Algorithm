#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int abs(int a, int b) {
    if (b > a) {
        return b - a;
    }
    return a - b;
}

int findAns(int x1, int y1, int r1, int x2, int y2, int r2) {
    double d = sqrt(abs(x2, x1) * abs(x2, x1) + abs(y1, y2) * abs(y1, y2));

    if (x1 == x2 && y1 == y2 && r1 == r2) {
        return -1;
    }

    if (r1 + r2 < d) {
        return 0;
    }

    if (r1 + r2 == d) {
        return 1;
    }

    if (abs(r1, r2) == d) {
        return 1;
    }

    if (abs(r1, r2) > d) {
        return 0;
    }

    return 2;
}


int main() {

    int t;
    cin >> t;
    for (int z = 0; z < t; z++) {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        cout << findAns(x1, y1, r1, x2, y2, r2)<<endl;
    }

    return 0;
}