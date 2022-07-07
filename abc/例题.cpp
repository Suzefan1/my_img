#include<iostream>
using namespace std;
void bubblesort(int*arr,int len)
{
	for (int i = 0; i < len-1; i++)
	{
		for (int j = 0; j < len-i-1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
void print(int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << endl;
	}
}

int main()
{  
	//²½ÖèÒ»£º
	int arr[10] = { 4,1,3,5,7,8,9,2,6,0 };
	int len = sizeof(arr) / sizeof(arr[0]);
	bubblesort(arr,len);
	print(arr, len);

}