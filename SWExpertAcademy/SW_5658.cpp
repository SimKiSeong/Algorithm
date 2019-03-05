#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int changeOneNumber(char n){
    if(n=='0'){
        return 0;
    }
    if(n=='1'){
        return 1;
    }
    if(n=='2'){
        return 2;
    }
    if(n=='3'){
        return 3;
    }
    if(n=='4'){
        return 4;
    }
    if(n=='5'){
        return 5;
    }
    if(n=='6'){
        return 6;
    }
    if(n=='7'){
        return 7;
    }
    if(n=='8'){
        return 8;
    }
    if(n=='9'){
        return 9;
    }
    if(n=='A'){
        return 10;
    }
    if(n=='B'){
        return 11;
    }
    if(n=='C'){
        return 12;
    }
    if(n=='D'){
        return 13;
    }
    if(n=='E'){
        return 14;
    }
    return 15;
}

long long changeNumber(string number){
    long long result = 0;
    long long zari = 1;
    int checkNumber = number.length()-1;
    while(checkNumber >= 0){
        result += changeOneNumber(number[checkNumber])*zari;
        zari = zari * 16;
        checkNumber--;
    }
    return result;
}

int main(){
    int t;
    cin >> t;

    for(int z = 0; z<t;z++){
        int n,k;
        int pLength;
        string password;
        vector<string> numbers;
        vector<long long> changedNumbers;
        vector<long long> lastNumbers;

        cin >> n >> k;
        cin >> password;

        pLength = n/4;

        // 글자 넣기
        for(int i = 0;i<n;i++){
            string tmp = "";
            for(int j = 0;j<pLength;j++){
                if(i+j < n){
                    tmp += password[i+j];}
                else{
                    tmp += password[i+j-n];
                }
            }
            numbers.push_back(tmp);
        }

        //글자 변환
        for(int i = 0;i<numbers.size();i++){
            changedNumbers.push_back(changeNumber(numbers[i]));
        }
        sort(changedNumbers.begin(),changedNumbers.end());

        lastNumbers.push_back(changedNumbers[0]);

        for(int i = 1;i<changedNumbers.size();i++){
            if(changedNumbers[i] != changedNumbers[i-1]){
                lastNumbers.push_back(changedNumbers[i]);
            }
        }
        cout << "#" <<z+1<<" "<<lastNumbers[lastNumbers.size()-k+1]<<endl;
    }

    return 0;
}