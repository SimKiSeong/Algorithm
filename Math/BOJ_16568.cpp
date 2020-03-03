#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;

void change(int &a, int &b) {
    if (b < a) {
        int tmp = a;
        a = b;
        b = tmp;
    }
}

int main() {

    int n, a, b;
    cin >> n >> a >> b;
    change(a, b);


    if (a == b) {
        cout << n / (b + 1) + n % (b + 1);
    } else {
        int counter = 0;
        int takeB = 0;
        int takeA = 0;
        while (n > b) {
            //뒤에 껄 다 a로 했을때
            takeA = (n - (a + 1)) / (a + 1) + (n - a - 1) % (a + 1);
            //뒤에 껄 다 b로 했을
            takeB = (n - (b + 1)) / (b + 1) + ((n - b - 1) % (b + 1)) / (a + 1) + ((n - b - 1) % (b + 1)) % (a + 1);
            if (takeA >= takeB) {
                n = n - (b + 1);
            } else {
                n = n - (a + 1);
            }
            counter++;
        }

        counter = counter + n / (a + 1) + n % (a + 1);
        cout << counter;
    }


    return 0;
}