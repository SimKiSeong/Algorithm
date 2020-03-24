#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef pair<int, int> P;
vector<P> tmpNumbers;
vector<P> numbers;
vector<int> same;

int main() {
    int n = 100000;
    int position = 0;
    int counter = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        if (tmp1 != tmp2) {
            tmpNumbers.push_back(make_pair(tmp1, tmp2));
        }
        else {
            same.push_back(tmp1);
        }
    }

    sort(tmpNumbers.begin(), tmpNumbers.end());

    if (tmpNumbers.size() > 0) {
        numbers.push_back(tmpNumbers[0]);
        for (int i = 1; i < tmpNumbers.size(); i++) {
            if (tmpNumbers[i].first != tmpNumbers[i - 1].first) {
                numbers.push_back(tmpNumbers[i]);
            }
        }
    }
    for (int i = 0; i < same.size(); i++) {
        numbers.push_back(make_pair(same[i], same[i]));
    }
    sort(numbers.begin(), numbers.end());

    while (position < numbers.size()) {

        // 움직임 별 최소값

        int tmpBefore = numbers[position].second;
        int tmpPosition = -1;

        for (int i = position; i < numbers.size() && numbers[i].first < numbers[position].second; i++) {
            if (tmpBefore > numbers[i].second) {
                tmpBefore = numbers[i].second;
                tmpPosition = i;
            }
        }

        if (tmpPosition == -1) {
            if (numbers[position].first == numbers[position].second) {
                position++;
                counter++;
                continue;
            }
        }

        if (tmpPosition != -1) {
            if (numbers[tmpPosition].first == numbers[tmpPosition].second) {
                position = tmpPosition+1;
                counter++;
                continue;
            }
        }

        //포지션 찾고 움직임 개수 더하고
        while (position < numbers.size() && numbers[position].first < tmpBefore) {
            position++;
        }
        counter++;
    }


    cout << counter;
    return 0;
}