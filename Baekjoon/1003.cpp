#include <iostream>
using namespace std;
int main() {
    int T, N, Z[41] = { 1 }, O[41] = { 0, 1 };

    for (int n = 2; n <= 40; n++) // 0�� 1������ ��� Ƚ�� ����
    {
        Z[n] = Z[n - 1] + Z[n - 2]; // 0�� Ƚ���� ���� �Լ���
        O[n] = O[n - 1] + O[n - 2]; // 1�� Ƚ���� ���� �Լ���
    }

    cin >> T; // �ݺ� Ƚ��
    for (int i = 0; i < T; i++)
    {
        cin >> N; // Ű �Է�
        cout << Z[N] << ' ' << O[N] << endl;
    }
    return 0;
}