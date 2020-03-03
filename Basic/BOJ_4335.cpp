#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;

int checker[11];

int main() {

    int tmp;
    cin >> tmp;
    while (tmp != 0) {
        string first;
        string second;
        cin >> first >> second;

//        cout << tmp << " " << first << second << endl;
//        for(int i = 1; i<11;i++){
//            cout << checker[i] << " ";
//        }
//        cout << endl;

        if (first[0] == 'r') {
            if (checker[tmp] == 0) {
                cout << "Stan may be honest" << endl;
            } else {
                cout << "Stan is dishonest" << endl;
            }
            for (int i = 1; i < 11; i++) {
                checker[i] = 0;
            }
        }else{
            if(second[0]=='h'){
                for(int i = tmp;i<11;i++){
                    checker[i] = 1;
                }
            }else{
                for(int i = 1;i<=tmp;i++){
                    checker[i] = 1;
                }
            }
        }
        cin >> tmp;
    }

    return 0;
}