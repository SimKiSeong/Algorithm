#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

vector<int> bae;
vector<int> counter;

int n;
bool isNowNumber = false;

void findAns(int now, int leftNumber) {
    if (leftNumber == 0) {
        isNowNumber = true;
        return;
    }
    for (int i = now; i >= 0 && !isNowNumber; i--) {
        if (bae[i] <= leftNumber) {
            if (counter[i] <= 0) {
                counter[i] = 1;
                findAns(i - 1, leftNumber - bae[i]);
                counter[i] = 0;
            }
        }
    }
}

int main() {

    cin >> n;

    //bae.push_back(0);
    //counter.push_back(-999);

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        bae.push_back(tmp);
        counter.push_back(0);
    }

    sort(bae.begin(), bae.end());

    bool find = false;
    int counter = 1;
    while (!find) {
        findAns(bae.size()-1,counter);
        if (isNowNumber) {
            isNowNumber = false;
            counter++;
        } else {
            find = true;
        }
    }

    cout << counter;

    return 0;
}