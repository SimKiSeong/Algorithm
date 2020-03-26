#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

string s, r;
deque<int> bigP[26];
deque<int> smallP[26];
map<char, int> rCounter;

int findAnswer(int now) {
    int last = 0;
    map<char, int>::iterator iter = rCounter.begin();
    while (iter != rCounter.end()) {
        char nowChar = iter->first;
        // 위치
        int i = 0;
        if (nowChar <= 'Z') {
            while (0<bigP[nowChar - 'A'].size() && bigP[nowChar - 'A'][i]<now) {
                bigP[nowChar - 'A'].pop_front();
            }
            if (bigP[nowChar - 'A'].size() - i < iter->second) {
                return -1;
            }
            else {
                int tmp = i + iter->second-1;
                if (bigP[nowChar - 'A'][tmp] > last) {
                    last = bigP[nowChar - 'A'][tmp];
                }
            }
        }
            // 소문자
        else {
            while (0<smallP[nowChar - 'a'].size()&& smallP[nowChar - 'a'][i]<now) {
                smallP[nowChar - 'a'].pop_front();
            }
            if (smallP[nowChar - 'a'].size() - i < iter->second) {
                return -1;
            }
            else {
                int tmp = i + iter->second-1;
                if (smallP[nowChar - 'a'][tmp] > last) {
                    last = smallP[nowChar - 'a'][tmp];
                }
            }
        }

        iter++;
    }
    return (last-now+1);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for (int z = 0; z < t; z++) {
        rCounter.clear();
        for (int i = 0; i < 26; i++) {
            bigP[i].clear();
            smallP[i].clear();
        }
        // 입력
        cin >> s >> r;

        //rCounter 제작
        for (int i = 0; i < r.size(); i++) {
            map<char, int>::iterator iter = rCounter.find(r[i]);
            if (iter == rCounter.end()) {
                rCounter.insert(make_pair(r[i], 1));
            }
            else {
                iter->second++;
            }
        }

        //s좌표 셋팅
        for (int i = 0; i < s.size(); i++) {
            map<char, int>::iterator iter = rCounter.find(s[i]);
            if (iter != rCounter.end()) {
                // 대문자
                if (s[i] <= 'Z') {
                    bigP[s[i] - 'A'].push_back(i);
                }
                    // 소문자
                else {
                    smallP[s[i] - 'a'].push_back(i);
                }
            }
        }

        bool isZero = false;
        int answer = 150000;
        int counter = 0;
        while(!isZero && counter <= s.size()-r.size()){
            if (rCounter.find(s[counter]) != rCounter.end()) {
                int now = findAnswer(counter);
                //cout << s[counter] << endl;
                //cout << counter <<" : "<< now << endl;
                if (now == -1) {
                    isZero = true;
                    break;
                }
                else {
                    if (answer > now) {
                        answer = now;
                    }
                }
            }
            counter++;
        }
        if (answer == 150000) {
            cout << 0 << '\n';
        }
        else {
            cout << answer << '\n';
        }
    }

    return 0;
}