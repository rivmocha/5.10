#include <iostream>
using namespace std;


void SSort(int* Array, int count)			// ���ؼ� �����ϱ�. 
{
	for (int i = 0; i < count; ++i)
	{
		for (int j = 0; j < count; ++j)
		{
			if (Array[i] < Array[j])
			{
				int Temp = Array[i];
				Array[i] = Array[j];
				Array[j] = Temp;
			}
		}
	}

}

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
	cout << "�� ���� " << " " <<  Sum << endl;		

	
	SSort(Array, count);

	for (int i = 0; i < count; ++i)
	{
		cout << Array[i] << endl;
	}

	return 0;
}