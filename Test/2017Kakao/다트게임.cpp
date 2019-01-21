#include <string>

using namespace std;




int solution(string dartResult) {
    int answer = 0;


    int point[3] = { 0,0,0 };
    int position = 0;
    int nowPoint = 0;

    for (int i = 0; i < dartResult.size(); i++) {
        if ('0' <= dartResult[i] & dartResult[i] <= '9') {
            nowPoint = nowPoint * 10 + (int)(dartResult[i] - '0');
        }
        else if (dartResult[i] == 'S') {
            point[position] = nowPoint;
            position++;
            nowPoint = 0;
        }
        else if (dartResult[i] == 'D') {
            point[position] = nowPoint * nowPoint;
            position++;
            nowPoint = 0;
        }
        else if (dartResult[i] == 'T') {
            point[position] = nowPoint * nowPoint * nowPoint;
            position++;
            nowPoint = 0;
        }
        else if (dartResult[i] == '*') {
            if (position == 1) {
                point[0] = point[0] * 2;
            }
            else {
                point[position - 2] = point[position - 2] * 2;
                point[position - 1] = point[position - 1] * 2;
            }
        }
        else if (dartResult[i] == '#') {
            point[position - 1] = point[position - 1] * -1;
        }
    }

    for (int i = 0; i < 3; i++) {
        answer = answer + point[i];
    }

    return answer;
}