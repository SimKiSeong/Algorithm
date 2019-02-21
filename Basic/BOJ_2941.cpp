#include <iostream>
using namespace std;

char word[102];
int num = 0;
int lastNum = 0;


int main() {

    cin >> word;

    for (int i = 0; word[i] != NULL; i++) {
        num++;
    }
    lastNum = num;
    for (int i = 0; i < num - 1; i++) {
        if (word[i] == 'c') {
            if(word[i+1]=='='|| word[i + 1] == '-'){
                lastNum--;
            }
        }
        else if (word[i] == 'd') {
            if (word[i + 1] == '-') {
                lastNum--;
            }
            else if (word[i + 1] == 'z'&&i + 2 < num) {
                if (word[i + 2] == '=') {
                    lastNum--;
                }
            }
        }
        else if (word[i] == 'l'&&word[i + 1] == 'j') {
            lastNum--;
        }
        else if (word[i] == 'n'&&word[i + 1] == 'j') {
            lastNum--;
        }
        else if (word[i] == 's'&&word[i + 1] == '=') {
            lastNum--;
        }
        else if (word[i] == 'z'&&word[i + 1] == '=') {
            lastNum--;
        }

    }

    cout << lastNum;

    return 0;
}