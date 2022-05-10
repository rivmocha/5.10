#include <iostream>
using namespace std;


void SSort(int* Array, int count)			// 비교해서 정렬하기. 
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

int ArraySum(int* Array, int count)		// 횟수만큼 받은 수 합을 함수로.
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
	cin >>  count;		//횟수 입력
	cout << "입력횟수는" << "  " << count << endl;		// 입력값 출력

	int* Array = new int[count];		//받은 횟수만큼 저장

	for (int i = 0; i < count; ++i)		//횟수마다 배열 한칸씩 저장
	{
		cin >> Array[i];
	}
	int Sum = ArraySum(Array, count);
	cout << "총 합은 " << " " <<  Sum << endl;		

	
	SSort(Array, count);

	for (int i = 0; i < count; ++i)
	{
		cout << Array[i] << endl;
	}

	return 0;
}