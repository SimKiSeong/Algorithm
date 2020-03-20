#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for (int z = 0; z < t; z++) {
        int n;
        int d;
        int ans = 0;
        vector<int> numbers;
        vector<int> init;
        cin >> n >> d;
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            numbers.push_back(tmp);
            if (i < d) {
                init.push_back(tmp);
            }
        }

        sort(init.begin(), init.end());

        if (d == 1) {
            for (int i = 1; i < n; i++) {
                if (numbers[i - 1] * 2 <= numbers[i]) {
                    ans++;
                }
            }
            cout << ans << '\n';
            continue;
        }
        multiset<int> low;
        multiset<int> high;
        //짝수
        if (d % 2 == 0) {
            for (int i = 0; i < d / 2; i++) {
                low.insert(init[i]);
            }
            for (int i = d / 2; i < d; i++) {
                high.insert(init[i]);
            }

            for (int i = d; i < n; i++) {
                if ((*(--low.end()) + *high.begin()) <= numbers[i]) {
                    ans++;
                }
                // 기존 원소 지우기
                // 기존 원소 low
                if (numbers[i-d]<= *(--low.end())) {
                    low.erase(low.find(numbers[i-d]));
                    if (numbers[i] > *(--low.end())) {
                        high.insert(numbers[i]);
                        low.insert(*high.begin());
                        high.erase(high.begin());
                    }
                    else {
                        low.insert(numbers[i]);
                    }
                }
                    // 기존 원소 high
                else {
                    high.erase(high.find(numbers[i - d]));

                    if (numbers[i] > *(--low.end())) {
                        high.insert(numbers[i]);
                    }
                    else {
                        low.insert(numbers[i]);
                        high.insert(*(--low.end()));
                        low.erase((--low.end()));
                    }
                }
            }

        }
            //홀수
        else {
            for (int i = 0; i < d / 2+1; i++) {
                low.insert(init[i]);
            }
            for (int i = d / 2 + 1; i < d; i++) {
                high.insert(init[i]);
            }

            for (int i = d; i < n; i++) {
                if ((*(--low.end()))*2 <= numbers[i]) {
                    ans++;
                }

                // 기존 원소 지우기
                // 기존 원소 low
                if (numbers[i - d] <= *(--low.end())) {
                    low.erase(low.find(numbers[i - d]));
                    if (numbers[i] > *(--low.end())) {
                        high.insert(numbers[i]);
                        low.insert(*high.begin());
                        high.erase(high.begin());
                    }
                    else {
                        low.insert(numbers[i]);
                    }
                }
                    // 기존 원소 high
                else {
                    high.erase(high.find(numbers[i - d]));
                    if (numbers[i] > *(--low.end())) {
                        high.insert(numbers[i]);
                    }
                    else {
                        low.insert(numbers[i]);
                        high.insert(*(--low.end()));
                        low.erase((--low.end()));
                    }
                }

            }



        }

        cout << ans << '\n';
    }

    return 0;
}