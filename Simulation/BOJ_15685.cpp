#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;


int map[204][204];
int t;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int answer;

int add(int dir) {
    if (dir == 3) {
        return 0;
    }
    return dir + 1;
}

vector<int> rotate(vector<int> curve) {

    vector<int> tmp;

    for (int i = 0; i < curve.size(); i++) {
        tmp.push_back(add(curve[i]));
    }
    return tmp;
}

vector<int> addCurve(vector<int> curve1, vector<int> curve2) {

    vector<int> tmp;

    for (int i = curve1.size() - 1; i >= 0; i--) {
        tmp.push_back(curve1[i]);
    }

    for (int i = 0; i < curve2.size(); i++) {
        tmp.push_back(curve2[i]);
    }

    return tmp;
}

void draw(int x, int y, vector<int> curve, int gen) {
    if (gen > 0) {
        vector<int> tmp = rotate(curve);
        for (int i = 0; i < tmp.size(); i++) {
            // map[y + dy[tmp[i]]][x + dx[tmp[i]]] = 1;
            x = x + dx[tmp[i]] * 2;
            y = y + dy[tmp[i]] * 2;
            map[y][x] = 2;

//            for(int i = 0 ;i<12;i++){
//                for(int j = 0; j<12;j++){
//                    cout << map[i][j];
//                }
//                cout << endl;
//            }
//            cout  << endl;

        }
        draw(x, y, addCurve(tmp, curve), gen - 1);
    }
}

int main() {

    cin >> t;

    for (int i = 0; i < t; i++) {
        int x;
        int y;
        int dir;
        int gen;
        cin >> x >> y >> dir >> gen;
        vector<int> curve;
        curve.push_back(dir);

        // map[y * 2 + dy[dir]][x * 2 + dx[dir]] = 1;

        map[y*2][x*2] = 2;
        map[y * 2 + dy[dir]*2][x * 2 + dx[dir]*2] = 2;

        draw(x * 2 + dx[dir] * 2, y * 2 + dy[dir] * 2, curve, gen);
    }






    for (int i = 0; i < 200; i = i + 2) {
        for (int j = 0; j < 200; j = j + 2) {
            if ( map[i][j] == 2 && map[i + 2][j] == 2 && map[i][j + 2] == 2 && map[i + 2 ][j + 2] == 2) {
                answer++;
            }
        }
    }

    cout << answer;

}