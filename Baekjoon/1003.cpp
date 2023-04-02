#include <iostream>
using namespace std;
int main() {
    int T, N, Z[41] = { 1 }, O[41] = { 0, 1 };

    for (int n = 2; n <= 40; n++) // 0과 1에대한 모든 횟수 저장
    {
        Z[n] = Z[n - 1] + Z[n - 2]; // 0의 횟수에 대한 함수식
        O[n] = O[n - 1] + O[n - 2]; // 1의 횟수에 대한 함수식
    }

    cin >> T; // 반복 횟수
    for (int i = 0; i < T; i++)
    {
        cin >> N; // 키 입력
        cout << Z[N] << ' ' << O[N] << endl;
    }
    return 0;
}