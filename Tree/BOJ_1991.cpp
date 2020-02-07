#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Node {
public:
    char me;
    char left;
    char right;
public:
    Node() {

    };

    Node(char first, char second, char third) {
        me = first;
        left = second;
        right = third;
    };
};

int n;

vector<Node> tree;

// 중위
void inOrder(char now) {
    if (tree[(now - 'A')].left != '.') {
        inOrder(tree[(now - 'A')].left);
    }
    cout << now;
    if (tree[(now - 'A')].right != '.') {
        inOrder(tree[(now - 'A')].right);
    }
}

//전위 순회
void preOrder(char now) {
    cout << now;
    if (tree[(now - 'A')].left != '.') {
        preOrder(tree[(now - 'A')].left);
    }
    if (tree[(now - 'A')].right != '.') {
        preOrder(tree[(now - 'A')].right);
    }
}

// 후위
void postOrder(char now) {
    if (tree[(now - 'A')].left != '.') {
        postOrder(tree[(now - 'A')].left);
    }
    if (tree[(now - 'A')].right != '.') {
        postOrder(tree[(now - 'A')].right);
    }
    cout << now;
}

int main() {

    cin >> n;
    tree.resize(n);

    for (int i = 0; i < n; i++) {
        char first, second, third;
        cin >> first >> second >> third;
        tree[first-'A'] = Node(first, second, third);
    }

    preOrder('A');
    cout << endl;
    inOrder('A');
    cout << endl;
    postOrder('A');
    cout << endl;
    return 0;
}