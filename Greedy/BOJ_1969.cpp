#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

vector<string> dna;
// 0 1 2 3
// a t g c

int counter[4][1001];
int ans = 0;
string ansString = "";
int n, m;

void min(int now){
    int minNum = 0;
    int position = 0;
    for(int i = 0;i<4;i++){
        if(counter[i][now]>minNum){
            position = i;
            minNum = counter[i][now];
        }
    }
    if(position == 0) {
        ansString += 'A';
    }
    if(position == 1) {
        ansString += 'C';
    }
    if(position == 2) {
        ansString += 'G';
    }
    if(position == 3) {
        ansString += 'T';
    }
    ans += ( n - counter[position][now]);

}

int main() {


    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        dna.push_back(tmp);
    }



    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dna[i][j] == 'A') {
                counter[0][j]++;
            }
            if (dna[i][j] == 'T') {
                counter[3][j]++;
            }
            if (dna[i][j] == 'G') {
                counter[2][j]++;
            }
            if (dna[i][j] == 'C') {
                counter[1][j]++;
            }
        }
    }




    for (int i = 0; i < m; i++) {
        min(i);
    }

    cout << ansString << endl << ans;

    return 0;
}