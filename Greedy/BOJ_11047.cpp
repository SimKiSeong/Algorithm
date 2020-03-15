#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;


int main() {

    int n, k;
    cin >> n >> k;

    vector<int> numbers;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        numbers.push_back(tmp);
    }

    int ans = 0;
    int checker = numbers.size() - 1;
    while (0 < k) {
        if (numbers[checker] <= k){
            ans += (k / numbers[checker]);
            k = k%numbers[checker];
        }
        checker--;
    }

    cout << ans;
    return 0;
}