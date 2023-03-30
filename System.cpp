#include<fstream>
#include<iostream>
#include<string>
using namespace std;
#define MaxNumber 1000//定义系统可容纳的学生数量
typedef struct//用来保存每一个学生的成绩
{
	string num;//学号 
	string name;//姓名 
	int Chinese;// 语文成绩 
	int Math;//数学成绩 
	int English;//英语成绩
	int Science_Comperhensive;//理综成绩
	int sum;//总成绩 
	int rank;//总成绩排名
}Student;
void menu()//主菜单
{
	cout << "----------学生成绩管理系统-------------" << endl;
	cout << "|                                     |" << endl;
	cout << "|         1.添加学生成绩              |" << endl;
	cout << "|         2.删除学生成绩              |" << endl;
	cout << "|         3.修改学生成绩              |" << endl;
	cout << "|         4.查询学生成绩              |" << endl;
	cout << "|         5.统计成绩信息              |" << endl;
	cout << "|         6.学生成绩单                |" << endl;
	cout << "|         7.导入学生成绩              |" << endl;
	cout << "|         8.导出学生成绩              |" << endl;
	cout << "|         9.清除系统数据              |" << endl;
	cout << "|         0.退出                      |" << endl;
	cout << "|                                     |" << endl;
	cout << "--------------------------------------" << endl;
}
class Student_System {//用于系统功能实现的类
protected:
	Student info[MaxNumber];//存储学生成绩信息
	int Student_Number;//当前系统中学生数量
public:
	Student_System();//构造函数
	int Find(string num);//根据学号查找是否存在该学生 
	void Add();//添加学生成绩 
	void Add(int i);//在第i个位置添加学生信息
	void Delete();//删除学生成绩 
	void Modify();//修改学生成绩 
	void Enquiry();//按姓名查找学生成绩
	void Display(int i);//输出第i个位置学生的成绩
	void Display_All();//输出全部学生成绩 
	void Ranking();//根据成绩进行学生排名
	void Inputfile();//导入外部文件
	void Outputfile();//输出外部文件
	void ClearSystem();//删除所有数据
	void Statistic();//统计成绩信息
};
Student_System::Student_System(){//构造函数，初始化对象
	for (int i = 0; i < MaxNumber; i++)
	{
		info[i].num = " ";
		info[i].name = " ";
		info[i].Chinese = 0;
		info[i].Math = 0;
		info[i].English = 0;
		info[i].Science_Comperhensive = 0;
		info[i].sum = 0;
		info[i].rank = 0;
	}
	Student_Number = 0;
}
int  Student_System::Find(string num) {//根据学号查找系统中是否存在该学生，若存在返回学生在系统中的位置，若不存在返回MaxNumber
	for (int i = 0; i < Student_Number; i++)
		if (num == info[i].num) {
			return i;
		}
	cout << "未找到学号为" << num << "的学生" << endl;
	return MaxNumber;
}
void Student_System::Add() {//在系统的最后添加一条学生成绩信息
	if (Student_Number == MaxNumber)
		cout << "人数已达上限，添加失败" << endl;
	else {
		cout << "请输入要添加的学生信息" << endl;
		Add(Student_Number);
		Student_Number++;
		system("cls");
		Ranking();
		cout << "添加完成！" << endl;
	}
}
void Student_System::Add(int i) {//在系统的第i个位置添加一条学生信息
	cout << "学号:";
	cin >> info[i].num;
	cout << "姓名:";
	cin >> info[i].name;
	cout << "语文成绩:";
	cin >> info[i].Chinese;
	cout << "数学成绩:";
	cin >> info[i].Math;
	cout << "英语成绩:";
	cin >> info[i].English;
	cout << "综合成绩:";
	cin >> info[i].Science_Comperhensive;
	info[i].sum = info[i].Math + info[i].Chinese + info[i].English + info[i].Science_Comperhensive;
	
}
void Student_System::Delete() {//按学号删除学生的全部成绩信息
	string num;
	cout << "请输入要删除的学生学号：";
	cin >> num;
	int flag = Find(num);//检查是否存在该学生
	if (flag != MaxNumber)
	{
		for (int j = flag; j < Student_Number - 1; j++)//将删除位置后的每一条信息前移
		{
		    info[j] = info[j + 1];
		}
		Student_Number--;
		Ranking();
		cout << "删除成功！" << endl;
	}	
	else
		cout << "删除失败！"<<endl;
	
}
void Student_System::Modify() {//根据学号修改学生的信息
	string num;
	cout << "请输入要修改信息的学生学号：";
	cin >> num;
	int flag = Find(num);//找到该名学生的位置
	if (flag != MaxNumber)
	{
		Add(flag);//覆盖该位置的学生信息
		Ranking();
		cout << "修改成功" << endl;
	}
	else 
		cout << "修改失败"<<endl;
	
}
void Student_System::Enquiry() {//根据姓名查询学生信息
	string name;
	cout << "请输入要查询信息的学生姓名：";
	cin >> name;
	int flag = Find(name);
	if (flag != MaxNumber)
	{
		cout << "学号\t姓名\t语文\t数学\t英语\t综合\t总分\t名次\t" << endl;
		Display(flag);
	}
}
void Student_System::Display(int i) {//在屏幕上输出第i个位置的学生信息
	cout << info[i].num << "\t";
	cout << info[i].name << "\t";
	cout << info[i].Chinese << "\t";
	cout << info[i].Math << "\t";
	cout << info[i].English << "\t";
	cout << info[i].Science_Comperhensive << "\t";
	cout << info[i].sum << "\t";
	cout << info[i].rank << "\t";
	cout << endl;
}

void Student_System::Ranking() {//将学生成绩根据总成绩排名(冒泡排序)
	Student t;
	if (Student_Number == 0)
		cout << "请先导入学生信息！" << endl;
	else {
		for (int i = 0; i < Student_Number ; i++)
			for(int j = 0;j < Student_Number-i-1; j++)
			    if (info[j].sum < info[j + 1].sum)
			    {
				    t = info[j];
				    info[j] = info[j + 1];
				    info[j + 1] = t;
			    }
		for (int i = 0; i < Student_Number; i++)
			info[i].rank = i + 1;
		Display_All();
	}
}
void Student_System::Display_All() {//输出全部学生的成绩信息
	system("cls");
	cout << "学号\t姓名\t语文\t数学\t英语\t综合\t总分\t名次\t" << endl;
	for (int i = 0; i < Student_Number; i++)
		Display(i);
}
void Student_System::Inputfile(){//将成绩信息通过txt导入数组
	string s;
	ifstream infile("Grade.txt", ios::in);//以输入方式打开文件，并检查是否存在文件
	if (!infile)
		cout << "导入文件失败，请检查是否存在文件Grade.txt" << endl;//文件不存在，打开失败
	else {
		getline(infile,s);//除去txt中第一行的目录信息
		for (int i = Student_Number; i < MaxNumber; i++)
		{
			infile >> info[i].num >> info[i].name >> info[i].Chinese >> info[i].Math >> info[i].English >> info[i].Science_Comperhensive;
			info[i].sum= info[i].Math + info[i].Chinese + info[i].English + info[i].Science_Comperhensive;
			if (info[i].num == " ")//当txt文件的字节流结束是导入完成，退出循环
				break;
			Student_Number++;
		}
		cout << "导入文件成功！" << endl;
		infile.close();
	}
}
void Student_System::Statistic() {//输出各项成绩的最高分和平均分
	if (Student_Number == 0)
		cout << "请先导入学生信息！" << endl;
	else
	{
		int Ave_Chinese = 0, Ave_Math = 0, Ave_English = 0, Ave_Science = 0, Ave_Sum = 0;
		int Max_Chinese = 0, Max_Math = 0, Max_English = 0, Max_Science = 0, Max_Sum = 0;
		for (int i = 0; i < Student_Number; i++)
		{
			if (info[Max_Chinese].Chinese < info[i].Chinese)
				Max_Chinese = i;
			if (info[Max_Math].Math < info[i].Math)
				Max_Math = i;
			if (info[Max_English].English < info[i].English)
				Max_English = i;
			if (info[Max_Science].Science_Comperhensive < info[i].Science_Comperhensive)
				Max_Science = i;
			if (info[Max_Sum].sum < info[i].sum)
				Max_Sum = i;
			Ave_Chinese += info[i].Chinese;
			Ave_Math += info[i].Math;
			Ave_English += info[i].English;
			Ave_Science += info[i].Science_Comperhensive;
			Ave_Sum += info[i].sum;
		}
		Ave_Chinese = Ave_Chinese / Student_Number;
		Ave_Math = Ave_Math / Student_Number;
		Ave_English = Ave_English / Student_Number;
		Ave_Science = Ave_Science / Student_Number;
		Ave_Sum = Ave_Sum / Student_Number;
		system("cls");
		cout << "平均语文成绩:" << Ave_Chinese << endl;
		cout << "平均数学成绩:" << Ave_Math << endl;
		cout << "平均英语成绩:" << Ave_English << endl;
		cout << "平均综合成绩:" << Ave_Science << endl;
		cout << "平均总成绩:" << Ave_Sum << endl;
		cout << "总成绩最高：" << info[Max_Sum].name << "  " << info[Max_Sum].sum << endl;
		cout << "语文最高：" << info[Max_Chinese].name << "  " << info[Max_Chinese].Chinese << endl;
		cout << "数学最高：" << info[Max_Math].name << "  " << info[Max_Chinese].Math << endl;
		cout << "英语最高：" << info[Max_English].name << "  " << info[Max_Chinese].English << endl;
		cout << "综合最高：" << info[Max_Science].name << "  " << info[Max_Chinese].Science_Comperhensive << endl;

	}

}
void Student_System::Outputfile() {//将排名后的成绩导出到txt文件
	ofstream outfile;
	outfile.open("GradeRanking.txt", ios::out);
	if (!outfile)
		cout << "打开失败!" << endl;
	else {
		if (Student_Number == 0)
			cout << "系统中不存在学生成绩信息,导出失败！"<<endl;
		else {
			outfile << "学号\t姓名\t语文\t数学\t英语\t综合\t总分\t名次\t" << endl;
			{
				for (int i = 0; i < Student_Number; i++) {
					outfile << info[i].num << "\t";
					outfile << info[i].name << "\t";
					outfile << info[i].Chinese << "\t";
					outfile << info[i].Math << "\t";
					outfile << info[i].English << "\t";
					outfile << info[i].Science_Comperhensive << "\t";
					outfile << info[i].sum << "\t";
					outfile << info[i].rank << "\t";
					outfile << endl;
				}
				cout << "导出成功！" << endl;
				outfile.close();
			}
		}
		
	}
}
void Student_System::ClearSystem() {//将内存中的成绩数据清除
	char flag;
	cout << "请重复确认是否清除数据！" << endl;
	cout << "Y/N" << endl;
	cin >> flag;
	if (flag == 'Y') {
		system("cls");
		cout << "已清空数据" << endl;
		Student_Number = 0;
	}
}
int main()
{
	Student_System Grade;
	int flag = 1;
	while (flag != 0)
	{
		menu();
		cin >> flag;
		if (flag <= 9 && flag >= 0)
		{
			switch (flag)
			{
			case 1:Grade.Add(); break;
			case 2:Grade.Delete(); break;
			case 3:Grade.Modify(); break;
			case 4:Grade.Enquiry(); break;
			case 5:Grade.Statistic(); break;
			case 6:Grade.Ranking(); break;
			case 7:Grade.Inputfile(); break;
			case 8:Grade.Outputfile(); break;
			case 9:Grade.ClearSystem(); break;
			case 0:break;
			}
		}
		else
			cout << "请输入正确的数字！" << endl;
		
		
	}
	cout << "退出成功，欢迎下次使用" << endl;
	return 0;
}
