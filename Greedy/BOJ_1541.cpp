#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {

    vector<int> numbers;
    vector<char> booho;
    string s;
    cin >> s;

    int plusCounter = 0;
    int tmp = 0;
    for (int i = 0; i < s.size(); i++) {
        if(s[i]=='+'){
            plusCounter++;
        }
        if (s[i] == '+' || s[i] == '-') {
            numbers.push_back(tmp);
            booho.push_back(s[i]);
            tmp = 0;
            continue;
        }
        tmp = tmp * 10 + (int) (s[i] - '0');
    }
    numbers.push_back(tmp);

    //더할거 먼저 다 더하기
    for(int i = 0; i<plusCounter;i++){
        vector<int> tmpN;
        vector<char> tmpB;
        int checker = 0;
        for(int j = 0; j<booho.size();j++){
            if(booho[j]=='+'){
                checker = j;
                break;
            }
        }

        // 앞에꺼 다 넣기
        for(int j = 0; j<checker;j++){
            tmpN.push_back(numbers[j]);
            tmpB.push_back(booho[j]);
        }
        // 중간꺼 넣기
        tmpN.push_back(numbers[checker]+numbers[checker+1]);

        // 끝에거 넣기
        for(int j = checker+2; j<numbers.size();j++){
            tmpN.push_back(numbers[j]);
            tmpB.push_back(booho[j-1]);
        }

        numbers = tmpN;
        booho = tmpB;
    }

    //더할거 먼저 다 더하기
    while(booho.size()>0){
        vector<int> tmpN;
        vector<char> tmpB;
        int checker = 0;
        for(int j = 0; j<booho.size();j++){
            if(booho[j]=='-'){
                checker = j;
                break;
            }
        }

        // 앞에꺼 다 넣기
        for(int j = 0; j<checker;j++){
            tmpN.push_back(numbers[j]);
            tmpB.push_back(booho[j]);
        }
        // 중간꺼 넣기
        tmpN.push_back(numbers[checker]-numbers[checker+1]);

        // 끝에거 넣기
        for(int j = checker+2; j<numbers.size();j++){
            tmpN.push_back(numbers[j]);
            tmpB.push_back(booho[j-1]);
        }

        numbers = tmpN;
        booho = tmpB;
    }

    cout << numbers[0];

    return 0;
}