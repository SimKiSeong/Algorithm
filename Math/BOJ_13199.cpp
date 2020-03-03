#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int t = 0;
    cin >> t;
    for (int z = 0; z < t; z++) {
        int p, m, f, c;
        cin >> p >> m >> f >> c;

        // 두영이 치킨수
        int dChicken = m / p + ((m / p) * c / f);

        // 상언이 치킨수
        int sChicken = m / p;
        int sCoupon = (m / p) * c;

        int cha = f - c;
        if (sCoupon >= f) {
            sChicken = sChicken + (sCoupon - f) / cha + 1;
        }

        cout << sChicken - dChicken << '\n';
    }


    return 0;
}