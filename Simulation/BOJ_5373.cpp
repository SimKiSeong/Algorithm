#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;

deque<char> up[3];
deque<char> front[3];
deque<char> lside[3];
deque<char> back[3];
deque<char> rside[3];
deque<char> down[3];

void initCube() {
    for (int i = 0; i < 3; i++) {
        up[i].clear();
        front[i].clear();
        rside[i].clear();
        back[i].clear();
        lside[i].clear();
        down[i].clear();
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            up[i].push_back('w');
            front[i].push_back('r');
            rside[i].push_back('b');
            back[i].push_back('o');
            lside[i].push_back('g');
            down[i].push_back('y');
        }
    }
}

void upPlus() {

    //면 돌리기 시
    char tmp[3][3];

    tmp[0][0] = up[2][0];
    tmp[0][1] = up[1][0];
    tmp[0][2] = up[0][0];

    tmp[1][0] = up[2][1];
    tmp[1][1] = up[1][1];
    tmp[1][2] = up[0][1];

    tmp[2][0] = up[2][2];
    tmp[2][1] = up[1][2];
    tmp[2][2] = up[0][2];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            up[i][j] = tmp[i][j];
        }
    }

    // 옆면 넣기
    for (int i = 0; i < 3; i++) {
        front[0].push_back(rside[0][0]);
        rside[0].push_back(back[0][0]);
        back[0].push_back(lside[0][0]);
        lside[0].push_back(front[0][0]);

        front[0].pop_front();
        rside[0].pop_front();
        back[0].pop_front();
        lside[0].pop_front();
    }
}

void upMinus() {

    //면 돌리기계 반시
    char tmp[3][3];

    tmp[0][0] = up[0][2];
    tmp[0][1] = up[1][2];
    tmp[0][2] = up[2][2];

    tmp[1][0] = up[0][1];
    tmp[1][1] = up[1][1];
    tmp[1][2] = up[2][1];

    tmp[2][0] = up[0][0];
    tmp[2][1] = up[1][0];
    tmp[2][2] = up[2][0];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            up[i][j] = tmp[i][j];
        }
    }

    // 옆면 넣기
    for (int i = 0; i < 3; i++) {
        front[0].push_front(lside[0][lside[0].size() - 1]);
        lside[0].push_front(back[0][back[0].size() - 1]);
        back[0].push_front(rside[0][rside[0].size() - 1]);
        rside[0].push_front(front[0][front[0].size() - 1]);

        back[0].pop_back();
        lside[0].pop_back();
        front[0].pop_back();
        rside[0].pop_back();
    }
}


void downPlus() {

    //면 돌리기계 시
    char tmp[3][3];

    tmp[0][0] = down[2][0];
    tmp[0][1] = down[1][0];
    tmp[0][2] = down[0][0];

    tmp[1][0] = down[2][1];
    tmp[1][1] = down[1][1];
    tmp[1][2] = down[0][1];

    tmp[2][0] = down[2][2];
    tmp[2][1] = down[1][2];
    tmp[2][2] = down[0][2];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            down[i][j] = tmp[i][j];
        }
    }


    // 옆면 넣기
    for (int i = 0; i < 3; i++) {
        front[2].push_front(lside[2][lside[2].size() - 1]);
        lside[2].push_front(back[2][back[2].size() - 1]);
        back[2].push_front(rside[2][rside[2].size() - 1]);
        rside[2].push_front(front[2][front[2].size() - 1]);

        back[2].pop_back();
        lside[2].pop_back();
        front[2].pop_back();
        rside[2].pop_back();
    }
}

void downMinus() {

    //면 돌리기계 반시
    char tmp[3][3];

    tmp[0][0] = down[0][2];
    tmp[0][1] = down[1][2];
    tmp[0][2] = down[2][2];

    tmp[1][0] = down[0][1];
    tmp[1][1] = down[1][1];
    tmp[1][2] = down[2][1];

    tmp[2][0] = down[0][0];
    tmp[2][1] = down[1][0];
    tmp[2][2] = down[2][0];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            down[i][j] = tmp[i][j];
        }
    }


    // 옆면 넣기
    for (int i = 0; i < 3; i++) {
        front[2].push_back(rside[2][0]);
        rside[2].push_back(back[2][0]);
        back[2].push_back(lside[2][0]);
        lside[2].push_back(front[2][0]);

        front[2].pop_front();
        rside[2].pop_front();
        back[2].pop_front();
        lside[2].pop_front();
    }
}

void frontPlus() {

    //면 돌리기계 시
    char tmp[3][3];

    tmp[0][0] = front[2][0];
    tmp[0][1] = front[1][0];
    tmp[0][2] = front[0][0];

    tmp[1][0] = front[2][1];
    tmp[1][1] = front[1][1];
    tmp[1][2] = front[0][1];

    tmp[2][0] = front[2][2];
    tmp[2][1] = front[1][2];
    tmp[2][2] = front[0][2];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            front[i][j] = tmp[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        down[0].push_back(rside[2 - i][0]);
        up[2].push_front(lside[i][2]);
        lside[i][2] = down[0][0];
        rside[2 - i][0] = up[2][up[2].size() - 1];

        down[0].pop_front();
        up[2].pop_back();
    }
}

void frontMinus() {

    //면 돌리기계 반시
    char tmp[3][3];

    tmp[0][0] = front[0][2];
    tmp[0][1] = front[1][2];
    tmp[0][2] = front[2][2];

    tmp[1][0] = front[0][1];
    tmp[1][1] = front[1][1];
    tmp[1][2] = front[2][1];

    tmp[2][0] = front[0][0];
    tmp[2][1] = front[1][0];
    tmp[2][2] = front[2][0];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            front[i][j] = tmp[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        up[2].push_back(rside[i][0]);
        down[0].push_front(lside[2 - i][2]);
        rside[i][0] = down[0][down[0].size() - 1];
        lside[2 - i][2] = up[2][0];

        down[0].pop_back();
        up[2].pop_front();
    }

}

void backPlus() {

    //면 돌리기계 시
    char tmp[3][3];

    tmp[0][0] = back[2][0];
    tmp[0][1] = back[1][0];
    tmp[0][2] = back[0][0];

    tmp[1][0] = back[2][1];
    tmp[1][1] = back[1][1];
    tmp[1][2] = back[0][1];

    tmp[2][0] = back[2][2];
    tmp[2][1] = back[1][2];
    tmp[2][2] = back[0][2];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            back[i][j] = tmp[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        up[0].push_back(rside[i][2]);
        down[2].push_front(lside[2 - i][0]);
        rside[i][2] = down[2][down[2].size() - 1];
        lside[2 - i][0] = up[0][0];

        down[2].pop_back();
        up[0].pop_front();
    }
}

void backMinus() {

    //면 돌리기계 반시
    char tmp[3][3];

    tmp[0][0] = back[0][2];
    tmp[0][1] = back[1][2];
    tmp[0][2] = back[2][2];

    tmp[1][0] = back[0][1];
    tmp[1][1] = back[1][1];
    tmp[1][2] = back[2][1];

    tmp[2][0] = back[0][0];
    tmp[2][1] = back[1][0];
    tmp[2][2] = back[2][0];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            back[i][j] = tmp[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        down[2].push_back(rside[2 - i][2]);
        up[0].push_front(lside[i][0]);
        lside[i][0] = down[2][0];
        rside[2 - i][2] = up[0][up[0].size() - 1];

        down[2].pop_front();
        up[0].pop_back();
    }


}

void rightPlus() {

    //면 돌리기계 시
    char tmp[3][3];

    tmp[0][0] = rside[2][0];
    tmp[0][1] = rside[1][0];
    tmp[0][2] = rside[0][0];

    tmp[1][0] = rside[2][1];
    tmp[1][1] = rside[1][1];
    tmp[1][2] = rside[0][1];

    tmp[2][0] = rside[2][2];
    tmp[2][1] = rside[1][2];
    tmp[2][2] = rside[0][2];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            rside[i][j] = tmp[i][j];
        }
    }

    int tmpUp[3];
    for (int i = 0; i < 3; i++) {
        tmpUp[i] = up[i][2];
    }

    for (int i = 0; i < 3; i++) {
        up[i][2] = front[i][2];
    }
    for (int i = 0; i < 3; i++) {
        front[i][2] = down[i][2];
    }
    for (int i = 0; i < 3; i++) {
        down[i][2] = back[2 - i][0];
    }
    for (int i = 0; i < 3; i++) {
        back[2 - i][0] = tmpUp[i];
    }
}

void rightMinus() {

    //면 돌리기계 반시
    char tmp[3][3];

    tmp[0][0] = rside[0][2];
    tmp[0][1] = rside[1][2];
    tmp[0][2] = rside[2][2];

    tmp[1][0] = rside[0][1];
    tmp[1][1] = rside[1][1];
    tmp[1][2] = rside[2][1];

    tmp[2][0] = rside[0][0];
    tmp[2][1] = rside[1][0];
    tmp[2][2] = rside[2][0];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            rside[i][j] = tmp[i][j];
        }
    }

    int tmpUp[3];
    for (int i = 0; i < 3; i++) {
        tmpUp[i] = up[i][2];
    }

    for (int i = 0; i < 3; i++) {
        up[i][2] = back[2 - i][0];
    }
    for (int i = 0; i < 3; i++) {
        back[2 - i][0] = down[i][2];
    }
    for (int i = 0; i < 3; i++) {
        down[i][2] = front[i][2];
    }
    for (int i = 0; i < 3; i++) {
        front[i][2] = tmpUp[i];
    }
}

void leftPlus() {

    //면 돌리기계 시
    char tmp[3][3];

    tmp[0][0] = lside[2][0];
    tmp[0][1] = lside[1][0];
    tmp[0][2] = lside[0][0];

    tmp[1][0] = lside[2][1];
    tmp[1][1] = lside[1][1];
    tmp[1][2] = lside[0][1];

    tmp[2][0] = lside[2][2];
    tmp[2][1] = lside[1][2];
    tmp[2][2] = lside[0][2];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            lside[i][j] = tmp[i][j];
        }
    }

    int tmpUp[3];
    for (int i = 0; i < 3; i++) {
        tmpUp[i] = up[i][0];
    }

    for (int i = 0; i < 3; i++) {
        up[i][0] = back[2 - i][2];
    }
    for (int i = 0; i < 3; i++) {
        back[2 - i][2] = down[i][0];
    }
    for (int i = 0; i < 3; i++) {
        down[i][0] = front[i][0];
    }
    for (int i = 0; i < 3; i++) {
        front[i][0] = tmpUp[i];
    }

}

void leftMinus() {

    //면 돌리기계 반시
    char tmp[3][3];

    tmp[0][0] = lside[0][2];
    tmp[0][1] = lside[1][2];
    tmp[0][2] = lside[2][2];

    tmp[1][0] = lside[0][1];
    tmp[1][1] = lside[1][1];
    tmp[1][2] = lside[2][1];

    tmp[2][0] = lside[0][0];
    tmp[2][1] = lside[1][0];
    tmp[2][2] = lside[2][0];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            lside[i][j] = tmp[i][j];
        }
    }

    int tmpUp[3];
    for (int i = 0; i < 3; i++) {
        tmpUp[i] = up[i][0];
    }

    for (int i = 0; i < 3; i++) {
        up[i][0] = front[i][0];
    }
    for (int i = 0; i < 3; i++) {
        front[i][0] = down[i][0];
    }
    for (int i = 0; i < 3; i++) {
        down[i][0] = back[2 - i][2];
    }
    for (int i = 0; i < 3; i++) {
        back[2 - i][2] = tmpUp[i];
    }

}


void findHamsu(string s) {

    if (s[0] == 'U') {
        if (s[1] == '+') {
            upPlus();
        } else {
            upMinus();
        }

    } else if (s[0] == 'D') {
        if (s[1] == '+') {
            downPlus();
        } else {
            downMinus();
        }

    } else if (s[0] == 'F') {
        if (s[1] == '+') {
            frontPlus();
        } else {
            frontMinus();
        }

    } else if (s[0] == 'B') {
        if (s[1] == '+') {
            backPlus();
        } else {
            backMinus();
        }

    } else if (s[0] == 'L') {
        if (s[1] == '+') {
            leftPlus();
        } else {
            leftMinus();
        }

    } else if (s[0] == 'R') {
        if (s[1] == '+') {
            rightPlus();
        } else {
            rightMinus();
        }

    }

}

void printSides() {


    //cout << "U" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << up[i][j];
        }
        cout << endl;
    }


//    cout << "R" << endl;
//    for (int i = 0; i < 3; i++) {
//        for (int j = 0; j < 3; j++) {
//            cout << rside[i][j];
//        }
//        cout << endl;
//    }

//    cout << "B" << endl;
//    for (int i = 0; i < 3; i++) {
//        for (int j = 0; j < 3; j++) {
//            cout << back[i][j];
//        }
//        cout << endl;
//    }
//
//    cout << "F" << endl;
//    for (int i = 0; i < 3; i++) {
//        for (int j = 0; j < 3; j++) {
//            cout << front[i][j];
//        }
//        cout << endl;
//    }
//
//
//    cout << "D" << endl;
//    for (int i = 0; i < 3; i++) {
//        for (int j = 0; j < 3; j++) {
//            cout << down[i][j];
//        }
//        cout << endl;
//    }

//    cout << "L" << endl;
//    for (int i = 0; i < 3; i++) {
//        for (int j = 0; j < 3; j++) {
//            cout << lside[i][j];
//        }
//        cout << endl;
//    }


}

int main() {
    int t;
    cin >> t;

    for (int z = 0; z < t; z++) {
        initCube();

        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            findHamsu(s);
        }
        printSides();
    }

    return 0;
}