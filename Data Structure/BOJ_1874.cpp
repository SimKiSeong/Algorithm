#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

stack<int> numbers;
vector<char> answers;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    int nextVal = 1;
    for (int z = 0; z < t; z++) {
        int now;
        cin >> now;

        while(numbers.size() < 1 || numbers.top() < now) {
            numbers.push(nextVal++);
            answers.push_back('+');
        }

        if (numbers.top() == now) {
            answers.push_back('-');
            numbers.pop();
        }
        else {
            cout << "NO";
            return 0;
        }

    }

    for (int i = 0; i < answers.size(); i++) {
        cout << answers[i] << "\n";
    }

    return 0;
}