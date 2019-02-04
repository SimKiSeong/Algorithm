#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

typedef pair<char, char> P;
vector<P> first;
vector<P> second;
unsigned long answer = 0;
int both = 0;

void makeLittle(string &str) {
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= 'A'&&str[i] <= 'Z') {
            str[i] = str[i] - ('A' - 'a');
        }
    }
}

void makeVector(string str,vector<P> &set) {
    for (int i = 0; i < str.size()-1; i++) {
        if (str[i] >= 'a'&&str[i] <= 'z') {
            if (str[i + 1] >= 'a'&&str[i + 1] <= 'z') {
                set.push_back(make_pair(str[i],str[i+1]));
            }
        }
    }
}

void findAnswer() {
    for (int i = 0; i < first.size(); i++) {
        for (int j = 0; j < second.size(); j++) {
            if (second[j].first == first[i].first && second[j].second == first[i].second) {
                both++;
                second[j].first = ' ';
                second[j].second = ' ';
                break;
            }
        }
    }
}

int solution(string str1, string str2) {

    makeLittle(str1);
    makeLittle(str2);

    makeVector(str1, first);
    makeVector(str2, second);

    findAnswer();

    if (first.size() == 0 && second.size() == 0) {
        return 65536;
    }

    answer = both * 65536 / (first.size() + second.size() - both);

    return answer;
}