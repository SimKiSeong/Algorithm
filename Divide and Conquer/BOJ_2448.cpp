#include<iostream>

using namespace std;

char star[3074][6150] = { ' ' };

void stamp(int a, int b) {
    star[a][b] = '*';

    star[a+1][b-1] = '*';
    star[a+1][b+1] = '*';

    star[a+2][b-2] = '*';
    star[a+2][b-1] = '*';
    star[a+2][b] = '*';
    star[a+2][b+1] = '*';
    star[a+2][b+2] = '*';
}

// 0, 5, 6
void go(int a,int b,int left) {
    if (left == 3) {
        stamp(a, b);
    }
    else {
        go(a + left / 2, b+left / 2, left / 2);
        go(a + left/2 , b-left / 2, left / 2);
        go(a, b, left / 2);
    }

}

int main() {
    int n;
    cin >> n;


    go(0 , n-1, n);



    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2*n-1; j++) {
            if (star[i][j] == NULL) {
                printf(" ");
            }
            else {
                printf("%c", star[i][j]);
            }
        }

        printf("\n");
    }

    return 0;
}