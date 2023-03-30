#include<fstream>
#include<iostream>
#include<string>
using namespace std;
#define MaxNumber 1000//����ϵͳ�����ɵ�ѧ������
typedef struct//��������ÿһ��ѧ���ĳɼ�
{
	string num;//ѧ�� 
	string name;//���� 
	int Chinese;// ���ĳɼ� 
	int Math;//��ѧ�ɼ� 
	int English;//Ӣ��ɼ�
	int Science_Comperhensive;//���۳ɼ�
	int sum;//�ܳɼ� 
	int rank;//�ܳɼ�����
}Student;
void menu()//���˵�
{
	cout << "----------ѧ���ɼ�����ϵͳ-------------" << endl;
	cout << "|                                     |" << endl;
	cout << "|         1.���ѧ���ɼ�              |" << endl;
	cout << "|         2.ɾ��ѧ���ɼ�              |" << endl;
	cout << "|         3.�޸�ѧ���ɼ�              |" << endl;
	cout << "|         4.��ѯѧ���ɼ�              |" << endl;
	cout << "|         5.ͳ�Ƴɼ���Ϣ              |" << endl;
	cout << "|         6.ѧ���ɼ���                |" << endl;
	cout << "|         7.����ѧ���ɼ�              |" << endl;
	cout << "|         8.����ѧ���ɼ�              |" << endl;
	cout << "|         9.���ϵͳ����              |" << endl;
	cout << "|         0.�˳�                      |" << endl;
	cout << "|                                     |" << endl;
	cout << "--------------------------------------" << endl;
}
class Student_System {//����ϵͳ����ʵ�ֵ���
protected:
	Student info[MaxNumber];//�洢ѧ���ɼ���Ϣ
	int Student_Number;//��ǰϵͳ��ѧ������
public:
	Student_System();//���캯��
	int Find(string num);//����ѧ�Ų����Ƿ���ڸ�ѧ�� 
	void Add();//���ѧ���ɼ� 
	void Add(int i);//�ڵ�i��λ�����ѧ����Ϣ
	void Delete();//ɾ��ѧ���ɼ� 
	void Modify();//�޸�ѧ���ɼ� 
	void Enquiry();//����������ѧ���ɼ�
	void Display(int i);//�����i��λ��ѧ���ĳɼ�
	void Display_All();//���ȫ��ѧ���ɼ� 
	void Ranking();//���ݳɼ�����ѧ������
	void Inputfile();//�����ⲿ�ļ�
	void Outputfile();//����ⲿ�ļ�
	void ClearSystem();//ɾ����������
	void Statistic();//ͳ�Ƴɼ���Ϣ
};
Student_System::Student_System(){//���캯������ʼ������
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
int  Student_System::Find(string num) {//����ѧ�Ų���ϵͳ���Ƿ���ڸ�ѧ���������ڷ���ѧ����ϵͳ�е�λ�ã��������ڷ���MaxNumber
	for (int i = 0; i < Student_Number; i++)
		if (num == info[i].num) {
			return i;
		}
	cout << "δ�ҵ�ѧ��Ϊ" << num << "��ѧ��" << endl;
	return MaxNumber;
}
void Student_System::Add() {//��ϵͳ��������һ��ѧ���ɼ���Ϣ
	if (Student_Number == MaxNumber)
		cout << "�����Ѵ����ޣ����ʧ��" << endl;
	else {
		cout << "������Ҫ��ӵ�ѧ����Ϣ" << endl;
		Add(Student_Number);
		Student_Number++;
		system("cls");
		Ranking();
		cout << "�����ɣ�" << endl;
	}
}
void Student_System::Add(int i) {//��ϵͳ�ĵ�i��λ�����һ��ѧ����Ϣ
	cout << "ѧ��:";
	cin >> info[i].num;
	cout << "����:";
	cin >> info[i].name;
	cout << "���ĳɼ�:";
	cin >> info[i].Chinese;
	cout << "��ѧ�ɼ�:";
	cin >> info[i].Math;
	cout << "Ӣ��ɼ�:";
	cin >> info[i].English;
	cout << "�ۺϳɼ�:";
	cin >> info[i].Science_Comperhensive;
	info[i].sum = info[i].Math + info[i].Chinese + info[i].English + info[i].Science_Comperhensive;
	
}
void Student_System::Delete() {//��ѧ��ɾ��ѧ����ȫ���ɼ���Ϣ
	string num;
	cout << "������Ҫɾ����ѧ��ѧ�ţ�";
	cin >> num;
	int flag = Find(num);//����Ƿ���ڸ�ѧ��
	if (flag != MaxNumber)
	{
		for (int j = flag; j < Student_Number - 1; j++)//��ɾ��λ�ú��ÿһ����Ϣǰ��
		{
		    info[j] = info[j + 1];
		}
		Student_Number--;
		Ranking();
		cout << "ɾ���ɹ���" << endl;
	}	
	else
		cout << "ɾ��ʧ�ܣ�"<<endl;
	
}
void Student_System::Modify() {//����ѧ���޸�ѧ������Ϣ
	string num;
	cout << "������Ҫ�޸���Ϣ��ѧ��ѧ�ţ�";
	cin >> num;
	int flag = Find(num);//�ҵ�����ѧ����λ��
	if (flag != MaxNumber)
	{
		Add(flag);//���Ǹ�λ�õ�ѧ����Ϣ
		Ranking();
		cout << "�޸ĳɹ�" << endl;
	}
	else 
		cout << "�޸�ʧ��"<<endl;
	
}
void Student_System::Enquiry() {//����������ѯѧ����Ϣ
	string name;
	cout << "������Ҫ��ѯ��Ϣ��ѧ��������";
	cin >> name;
	int flag = Find(name);
	if (flag != MaxNumber)
	{
		cout << "ѧ��\t����\t����\t��ѧ\tӢ��\t�ۺ�\t�ܷ�\t����\t" << endl;
		Display(flag);
	}
}
void Student_System::Display(int i) {//����Ļ�������i��λ�õ�ѧ����Ϣ
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

void Student_System::Ranking() {//��ѧ���ɼ������ܳɼ�����(ð������)
	Student t;
	if (Student_Number == 0)
		cout << "���ȵ���ѧ����Ϣ��" << endl;
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
void Student_System::Display_All() {//���ȫ��ѧ���ĳɼ���Ϣ
	system("cls");
	cout << "ѧ��\t����\t����\t��ѧ\tӢ��\t�ۺ�\t�ܷ�\t����\t" << endl;
	for (int i = 0; i < Student_Number; i++)
		Display(i);
}
void Student_System::Inputfile(){//���ɼ���Ϣͨ��txt��������
	string s;
	ifstream infile("Grade.txt", ios::in);//�����뷽ʽ���ļ���������Ƿ�����ļ�
	if (!infile)
		cout << "�����ļ�ʧ�ܣ������Ƿ�����ļ�Grade.txt" << endl;//�ļ������ڣ���ʧ��
	else {
		getline(infile,s);//��ȥtxt�е�һ�е�Ŀ¼��Ϣ
		for (int i = Student_Number; i < MaxNumber; i++)
		{
			infile >> info[i].num >> info[i].name >> info[i].Chinese >> info[i].Math >> info[i].English >> info[i].Science_Comperhensive;
			info[i].sum= info[i].Math + info[i].Chinese + info[i].English + info[i].Science_Comperhensive;
			if (info[i].num == " ")//��txt�ļ����ֽ��������ǵ�����ɣ��˳�ѭ��
				break;
			Student_Number++;
		}
		cout << "�����ļ��ɹ���" << endl;
		infile.close();
	}
}
void Student_System::Statistic() {//�������ɼ�����߷ֺ�ƽ����
	if (Student_Number == 0)
		cout << "���ȵ���ѧ����Ϣ��" << endl;
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
		cout << "ƽ�����ĳɼ�:" << Ave_Chinese << endl;
		cout << "ƽ����ѧ�ɼ�:" << Ave_Math << endl;
		cout << "ƽ��Ӣ��ɼ�:" << Ave_English << endl;
		cout << "ƽ���ۺϳɼ�:" << Ave_Science << endl;
		cout << "ƽ���ܳɼ�:" << Ave_Sum << endl;
		cout << "�ܳɼ���ߣ�" << info[Max_Sum].name << "  " << info[Max_Sum].sum << endl;
		cout << "������ߣ�" << info[Max_Chinese].name << "  " << info[Max_Chinese].Chinese << endl;
		cout << "��ѧ��ߣ�" << info[Max_Math].name << "  " << info[Max_Chinese].Math << endl;
		cout << "Ӣ����ߣ�" << info[Max_English].name << "  " << info[Max_Chinese].English << endl;
		cout << "�ۺ���ߣ�" << info[Max_Science].name << "  " << info[Max_Chinese].Science_Comperhensive << endl;

	}

}
void Student_System::Outputfile() {//��������ĳɼ�������txt�ļ�
	ofstream outfile;
	outfile.open("GradeRanking.txt", ios::out);
	if (!outfile)
		cout << "��ʧ��!" << endl;
	else {
		if (Student_Number == 0)
			cout << "ϵͳ�в�����ѧ���ɼ���Ϣ,����ʧ�ܣ�"<<endl;
		else {
			outfile << "ѧ��\t����\t����\t��ѧ\tӢ��\t�ۺ�\t�ܷ�\t����\t" << endl;
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
				cout << "�����ɹ���" << endl;
				outfile.close();
			}
		}
		
	}
}
void Student_System::ClearSystem() {//���ڴ��еĳɼ��������
	char flag;
	cout << "���ظ�ȷ���Ƿ�������ݣ�" << endl;
	cout << "Y/N" << endl;
	cin >> flag;
	if (flag == 'Y') {
		system("cls");
		cout << "���������" << endl;
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
			cout << "��������ȷ�����֣�" << endl;
		
		
	}
	cout << "�˳��ɹ�����ӭ�´�ʹ��" << endl;
	return 0;
}
