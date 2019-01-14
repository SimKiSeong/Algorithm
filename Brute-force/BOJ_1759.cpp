#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

vector<char> pass;
string s;
int n, t;

void go(int left,int now) {

    if (left == 0) {
        int zaum = 0;
        int moum = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'u' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o')
            {
                moum++;
            }
            else {
                zaum++;
            }
        }
        if (zaum > 1 && moum > 0) {
            cout << s << "\n";
        }
    }
    else {
        for (int i = now+1; i < t - left+1; i++) {
            s.push_back(pass[i]);
            go(left - 1, i);
            s.pop_back();
        }
    }
}


int main() {


    string now;
    cin >> n >> t;
    for (int i = 0; i < t; i++) {
        char tmp;
        cin >> tmp;
        pass.push_back(tmp);
    }

    sort(pass.begin(), pass.end());

    go(n, -1);

    return 0;
}