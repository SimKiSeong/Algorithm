#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;
int n,chong,boo;
long long answer;
vector<int> numbers;

int big(int a,int b) {
    if (a > b) {
        return b;
    }
    return a;
}

int withChong(int now) {
    int cha = numbers[now] - chong;
    if(cha>0){
        if (cha % boo == 0) {
            return cha / boo+1;
        }
        return cha / boo+2;
    }
    return 1;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> n;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        numbers.push_back(tmp);
    }
    cin >> chong >> boo;

    for (int i = 0; i < n; i++) {
        answer += withChong(i);
    }


    cout << answer;

    return 0;
}