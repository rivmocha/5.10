#include <iostream>
using namespace std;


int ArraySum(int* Array, int count)		// Ƚ����ŭ ���� �� ���� �Լ���.
{
	int Sum = 0;

	for (int i = 0; i < count; ++i)
	{
		Sum += Array[i];
	}
	return Sum;

}

int main()
{
	int count = 0;
	cin >>  count;		//Ƚ�� �Է�
	cout << "�Է�Ƚ����" << "  " << count << endl;		// �Է°� ���

	int* Array = new int[count];		//���� Ƚ����ŭ ����

	for (int i = 0; i < count; ++i)		//Ƚ������ �迭 ��ĭ�� ����
	{
		cin >> Array[i];
	}
	int Sum = ArraySum(Array, count);
	cout << Sum << endl;

	return 0;
}