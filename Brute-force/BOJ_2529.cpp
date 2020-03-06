#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

vector<char> booho;
vector<long long> answers;
int numbers[10];
int n;

bool checkBooho(int now, int beforeNumber, int nowNumber) {
    if (booho[now] == '<') {

        if (beforeNumber < nowNumber) {
            return true;
        }
        return false;
    } else {
        if (beforeNumber > nowNumber) {
            return true;
        }
        return false;
    }
}

void findAns(int now, long long nowAns) {
    if (now == n) {
        answers.push_back(nowAns);
        return;
    }

    for (int i = 0; i < 10; i++) {
        if (numbers[i] == 0) {
            if (checkBooho(now, nowAns % 10, i)) {
                numbers[i] = 1;
                findAns(now + 1, nowAns * 10 + i);
                numbers[i] = 0;
            }
        }
    }

}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        char tmp;
        cin >> tmp;
        booho.push_back(tmp);
    }

    for (int i = 0; i < 10; i++) {
        numbers[i] = 1;
        findAns(0, i);
        numbers[i] = 0;
    }

    sort(answers.begin(), answers.end());

    int checker = 1;

    for (int i = 0; i < n; i++) {
        checker *= 10;
    }

    if (checker > answers[answers.size() - 1]) {
        cout << '0';
    }
    cout << answers[answers.size() - 1] << endl;
    if (checker > answers[0]) {
        cout << '0';
    }
    cout << answers[0];

    return 0;
}