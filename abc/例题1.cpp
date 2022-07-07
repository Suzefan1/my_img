//#include<iostream>
//
//using namespace std;
//struct student 
//{
//	string name;
//	int score;
//};
//struct teacher
//{
//	string name;
//	struct student sarr[5];
//};
//void fuzhi(struct teacher tarr[],int length)
//{
//	string nameseed = "12345";
//	for (int i = 0; i < length; i++)
//	{
//		tarr[i].name = "Teacher_";
//		tarr[i].name += nameseed[i];
//		for (int j = 0; j < 5; j++)
//		{
//			tarr[i].sarr[j].name = "Student_";
//			tarr[i].sarr[j].name += nameseed[j];
//			int random = rand() % 60 + 40;
//			tarr[i].sarr[j].score = random;
//		}
//	}
//}
//void print(struct teacher tarr[], int length)
//{
//	for (int i = 0; i < length; i++)
//	{
//		cout << tarr[i].name << endl;
//		for (int j = 0; j < 5; j++)
//		{
//			cout <<"学生姓名" << tarr[i].sarr[j].name 
//				 <<"学生成绩" << tarr[i].sarr[j].score << endl;
//		}
//	}
//}
//int main()
//{
//	srand((unsigned int)time(NULL));
//	struct teacher arr1[3];
//	int len = sizeof(arr1) / sizeof(arr1[0]);
//	fuzhi(arr1, len);
//	print(arr1,len);
//	system("pause");
//	return 0;
//}