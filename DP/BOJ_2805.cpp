#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;
int n, m;
vector<int> trees;
vector<int> cha;
int hap;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        trees.push_back(tmp);
    }

    sort(trees.begin(), trees.end(), greater<int>());
    for (int i = 0; i < n-1; i++) {
        cha.push_back(trees[i]-trees[i+1]);
    }

    int i = 0;
    int answer = trees[0];
    for (; i < n - 1; i++) {
        int nowCut = cha[i] + (cha[i] * i);
        if (nowCut < m) {
            m -= nowCut;
            answer = trees[i+1];
        }
        else {
            if ((m % (i + 1)) == 0) {
                answer -= (m / (i + 1));
            }
            else {
                answer -= (m / (i + 1))+1;
            }
            m = 0;
            break;
        }
    }

    if (m > 0) {
        if ((m % (i + 1)) == 0) {
            answer -= (m / (i + 1));
        }
        else {
            answer -= (m / (i + 1)) + 1;
        }
    }

    if (answer < 0) {
        cout << 0;
    }
    else {
        cout << answer;
    }
    return 0;
}