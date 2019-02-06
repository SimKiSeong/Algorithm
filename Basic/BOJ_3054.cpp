#include <iostream>
using namespace std;

char word[16];
int finish;

int main() {

    cin >> word;

    for (int i = 0; i < 16; i++){
        if (word[i] == NULL){
            finish = i;
            break;
        }
    }

    // 첫줄
    printf(".");
    for (int i = 1; i < finish+1; i++){
        char tmp;
        if (i % 3 == 0){
            tmp = '*';
        }
        else{
            tmp = '#';
        }
        cout << "." << tmp << ".." ;
    }

    cout << "\n";

    // 둘째줄
    printf(".");
    for (int i = 1; i < finish + 1; i++){
        char tmp;
        if (i % 3 == 0){
            tmp = '*';
        }
        else{
            tmp = '#';
        }
        cout <<  tmp << "."<<tmp<<".";
    }

    cout << "\n";

    //샛쨰줄

    for (int i = 1; i < finish + 1; i++){
        char tmp;
        if (i % 3 == 0){
            tmp = '*';
        }
        else{
            tmp = '#';
        }
        if (i>1 && i % 3 == 1){
            cout << "*." << word[i - 1] << ".";
        }
        else{
            cout << tmp << "." << word[i - 1] << ".";
        }
    }

    if (finish % 3 == 0){
        cout << "*" << "\n";
    }
    else{
        cout << "#" << "\n";
    }




    // 둘째줄
    printf(".");
    for (int i = 1; i < finish + 1; i++){
        char tmp;
        if (i % 3 == 0){
            tmp = '*';
        }
        else{
            tmp = '#';
        }
        cout << tmp << "." << tmp << ".";
    }

    cout << "\n";

    printf(".");
    for (int i = 1; i < finish + 1; i++){
        char tmp;
        if (i % 3 == 0){
            tmp = '*';
        }
        else{
            tmp = '#';
        }
        cout << "." << tmp << "..";
    }

    return 0;
}