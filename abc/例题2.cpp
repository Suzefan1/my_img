#include<iostream>
using namespace std;
struct pppp
{
	string name;
	int age;
	string sex;
};
void bobblesort(struct pppp arr[],int length)
{
	struct pppp temp;
	for (int i = 0; i < length-1; i++)
	{
		for (int j = 0; j < length-1-i; j++)
		{
			if (arr[j].age>arr[j+1].age)
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
void print(struct pppp arr[],int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << "\t排序后："
			<< "\t姓名:" << arr[i].name
			<< "\t年龄:" << arr[i].age
			<< "\t性别" << arr[i].sex
			<< endl;
	}
}
int main()
{   
	struct pppp arr[5] =
	{
		{"一",18,"男"},
		{"二",20,"男"},
		{"三",21,"男"},
		{"四",11,"女"},
		{"五",14,"女"},
	};
	int len = sizeof(arr) / sizeof(arr[0]);
	bobblesort(arr,len);
	print(arr,len);
	system("pause");
	return 0;

}