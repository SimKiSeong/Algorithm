#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Node {
public:
    int level = 0;
    int child[2];
    int leftSize = 0;
    int rightSize = 0;
public:
    Node(int left, int right) {
        child[0] = left;
        child[1] = right;
    }

    Node() {

    };
};

vector<int> point[10002];
vector<Node> nodes;
int n;
int maxLevel = 0;
int ans = 0;
int ansLevel = 0;
int pause;
int parent = 0;
int parentChecker[10002];

int levelAndNumbers(int now, int level) {

    // 레벨 체크
    nodes[now].level = level;
    if (level > maxLevel) {
        maxLevel = level;
    }

    // 왼쪽
    if (nodes[now].child[0] != -1) {
        nodes[now].leftSize = levelAndNumbers(nodes[now].child[0], level + 1);
    }
    // 오른쪽
    if (nodes[now].child[1] != -1) {
        nodes[now].rightSize = levelAndNumbers(nodes[now].child[1], level + 1);
    }

    //cout << now << " " << level << " " << nodes[now].leftSize <<" " << nodes[now].rightSize << endl;
    return nodes[now].leftSize + nodes[now].rightSize + 1;
}

void checkPositions(int now, int motherPosition, int dir) {
    int myPosition = 0;
    // 부모의 왼쪽
    if (dir == 1) {
        myPosition = motherPosition - nodes[now].rightSize - 1;
    }
    // 부모의 오른쪽
    if (dir == 2) {
        myPosition = motherPosition + nodes[now].leftSize + 1;
    }

    point[nodes[now].level].push_back(myPosition);

    if (nodes[now].child[0] != -1) {
        checkPositions(nodes[now].child[0], myPosition, 1);
    }
    // 오른쪽
    if (nodes[now].child[1] != -1) {
        checkPositions(nodes[now].child[1], myPosition, 2);
    }
}


int main() {

    cin >> n;
    nodes.resize(n + 1);

    for (int i = 0; i < n; i++) {
        int now, left, right;
        cin >> now;
        cin >> left;
        cin >> right;
        parentChecker[left]++;
        parentChecker[right]++;
        nodes[now] = Node(left, right);
    }

    for(int i = 1; i<=n;i++){
        if(parentChecker[i] == 0){
            parent = i;
            break;
        }
    }

    levelAndNumbers(parent, 1);
    checkPositions(parent, 0, 0);


    for (int i = 1; i <= maxLevel; i++) {
        int cha = 1;
        if (point[i].size() > 1) {
            sort(point[i].begin(), point[i].end());
            cha = point[i][point[i].size() - 1];
            cha -= (point[i][0]);
            cha++;
        }
        if (cha > ans) {
            ans = cha;
            ansLevel = i;
        }
    }



//    cout << maxLevel << endl;
//    for (int i = 1; i <= maxLevel; i++) {
//        for (int j = 0; j < point[i].size(); j++) {
//            cout << i << " " << j<< " " << point[i][j] << "\n";
//        }
//        cout << endl;
//    }

    cout << ansLevel << " " << ans;

    return 0;
}