#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;



int main() {

    int t;
    cin >> t;
    for (int z = 0; z < t; z++) {
        deque<int> bae;
        string s;
        string num;
        int dir;
        cin >> s;
        cin >> dir;
        cin >> num;
        bool err = false;
        dir = 1;

        int tmp = 0;
        for (int i = 1; i < num.size(); i++) {
            if (num[i] == ',') {
                bae.push_back(tmp);
                tmp = 0;
            } else if (num[i] == ']') {
                if (tmp != 0) {
                    bae.push_back(tmp);
                }
            } else {
                tmp = tmp * 10 + (int) (num[i] - '0');
            }
        }


        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'D') {
                if (bae.size() == 0) {
                    err = true;
                    break;
                }
                if (dir % 2 == 1) {
                    bae.pop_front();
                } else {
                    bae.pop_back();
                }
            } else {
                dir++;
            }
        }

        if(!err){
            cout<<'[';
            if(bae.size()!=0){
                if(dir%2==1) {
                    for (int i = 0; i < bae.size() - 1;i++){
                        cout << bae[i]<<',';
                    }
                    cout << bae[bae.size()-1];
                }else{
                    for (int i = bae.size()-1; i > 0;i--){
                        cout << bae[i]<<',';
                    }
                    cout << bae[0];
                }
            }
            cout<<']'<<endl;
        }else{
            cout << "error" << endl;
        }
    }

    return 0;
}