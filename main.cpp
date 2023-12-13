#include<iostream>
#include<string>
#include<Windows.h>
#include<fstream>
#include<iomanip>
#define SIZE 100 //�������
using namespace std;


//ϵͳ�ࣨ��Ҫ��������
class System {
public:
	int menu()
	{
		string choice;
		cout << setw(29) << setfill(' ') << "���ʹ���ϵͳ" << endl;
		cout << setw(25) << setfill('*') << "�˵�" << setw(25) << setfill('*') << "*" << endl;
		cout << "1.¼�빤�ʣ�������        2.ɾ�����ʼ�¼" << setw(50) << setfill(' ') << " " << endl;
		cout << "3.��ѯ���ʼ�¼            4.�޸Ĺ��ʼ�¼" << setw(50) << setfill(' ') << " " << endl;
		cout << "5.���빤�ʣ�������        6.ͳ�Ʒ���" << setw(50) << setfill(' ') << " " << endl;
		cout << "7.���ʼ�¼����            8.��������" << setw(50) << setfill(' ') << " " << endl;
		cout << "9.��ʾ���ʼ�¼            0.�˳�����ϵͳ" << setw(50) << setfill(' ') << " " << endl;
		cout << setw(50) << setfill('*') << "*" << endl;
		cout << setw(29) << setfill('*') << "��ѡ��0~9��" << setw(22) << setfill('*') << " " << endl;
		cin >> choice;
		if (choice == "0" || choice == "�˳�����ϵͳ" || choice == "�˳�" || choice == "�˳�ϵͳ" || choice == "�˳�����") {
			return 0;
		}
		else if (choice == "1" || choice == "¼�빤�ʣ�������" || choice == "����¼�빤��" || choice == "����¼��") {
			return 1;
		}
		else if (choice == "2" || choice == "ɾ�����ʼ�¼" || choice == "ɾ������" || choice == "ɾ����¼") {
			return 2;
		}
		else if (choice == "3" || choice == "��ѯ���ʼ�¼" || choice == "��ѯ����" || choice == "��ѯ��¼") {
			return 3;
		}
		else if (choice == "4" || choice == "�޸Ĺ��ʼ�¼" || choice == "�޸Ĺ���" || choice == "�޸ļ�¼") {
			return 4;
		}
		else if (choice == "5" || choice == "���빤��" || choice == "���빤�ʣ�������" || choice == "���뵥������" || choice == "���뵥��") {
			return 5;
		}
		else if (choice == "6" || choice == "ͳ�Ʒ���" || choice == "����" || choice == "ͳ��") {
			return 6;
		}
		else if (choice == "7" || choice == "���ʼ�¼����" || choice == "����" || choice == "��¼����") {
			return 7;
		}
		else if (choice == "8" || choice == "��������" || choice == "����") {
			return 8;
		}
		else if (choice == "9" || choice == "��ʾ���ʼ�¼" || choice == "��ʾ��¼" || choice == "��ʾ����") {
			return 9;
		}
		else {
			cout << "���������룺";
			cin >> choice;
		}
	}
};

//ְ��������
class Salary {
	friend class System;
	friend  int biSearchNum(Salary arr[], string key);
public:
	static int m_count;
	string m_name;//basic
	string m_title;//basic
	string m_num;//basic
	int m_workage;//basic
	double m_dSalary[15];//������ϸ
	double m_dTax;//��˰8~14
	double m_StartSalary;//Ӧ������0~7
	double m_LastSalary;//ʵ������0~14

	Salary() {
		m_name.clear(); m_num.clear(); m_title.clear(); m_workage = 0; m_LastSalary = 0; m_dTax = 0; memset(m_dSalary, 0, sizeof(m_dSalary));
	}

	//------------------------------------
	void m_In_Basic_Ifo() {
		cout << "������ְ�������������Ϣ������ ���� ְ�� ���䣩��\n";
		cin >> m_num >> m_name >> m_title >> m_workage;
		checkPosition(&m_title);
		checkNum(&m_num);
		++m_count;
	}
	void m_Show_Basic_Ifo() {
		cout << m_num << "\t" << m_name << "\t" << m_title << "\t" << m_workage << "\t";
	}

	void m_In_dSalary() {
		cout << "������ְ����15�����ϸ��\n";
		for (int g = 0; g < 15; g++) {
			cin >> m_dSalary[g];
		}
	}
	void m_Show_dSalary() {
		for (int g = 0; g < 15; g++) {
			cout << m_dSalary[g] << "\t";
		}
	}

	void m_Get_LastSalary() {
		m_LastSalary = 0;
		for (int g = 0; g < 15; g++) {
			m_LastSalary += m_dSalary[g];
		}
	}
	void m_Show_LastSalary() {
		cout << m_LastSalary;
	}

	void m_Get_dTax() {
		m_dTax = 0;
		for (int g = 8; g < 15; g++) {
			m_dTax += m_dSalary[g];
		}
	}
	void m_Show_dTax() {
		cout << m_dTax;
	}

	void m_Get_StartSalary() {
		m_StartSalary = 0;
		for (int g = 0; g < 8; g++) {
			m_StartSalary += m_dSalary[g];
		}
	}
	void m_Show_StartSalary() {
		cout << m_StartSalary;
	}

	void m_In_Member() {
		m_In_Basic_Ifo();
		m_In_dSalary();
		m_Get_dTax();
		m_Get_StartSalary();
		m_Get_LastSalary();
	}
	void m_Show_Member() {
		m_Show_Basic_Ifo();
		m_Show_dSalary();
	}
	void batchInput() {
		int num = 0;
		cout << "������¼��������";
		cin >> num;
		cout << "������" << num << "λ�̹��Ĺ�����Ϣ" << endl;
		for (int i = Salary::m_count; i < num + Salary::m_count; i++) {
			workers[i].m_In_Member();
		}
		Salary::m_count += num;
	}
	//--------------------------------------
	//д������
	Salary m_Get_Max_LastSalary(Salary& a) {
		if (a.m_LastSalary > m_LastSalary) {
			return a;
		}
		else {
			return *this;
		}
	}
	Salary m_Get_Min_LastSalary(Salary& a) {
		if (a.m_LastSalary < m_LastSalary) {
			return a;
		}
		else {
			return *this;
		}
	}
	
private:
	void checkPosition(string* title) {
		if (*title != "����" && *title != "������" && *title != "��ʦ" && *title != "����" && *title != "����") {
			cout << "�޴�ְλ����������:";
			cin >> *title;
			checkPosition(title);
		}
	}
	bool m_findnum(const string num) {
		for (int i = 0; i < Salary::m_count-1; i++) {
			if (workers[i].m_num == num) {
				return true;
			}
		}
		return false;
	}
	void checkNum(string* num)
	{
		if (m_findnum(*num)) {
			cout << "�����Ѵ��ڣ����������룺";
			cin >> *num;
			checkNum(num);
		}
	}
	
}workers[SIZE], temp;

//ѧУ12�����ܶ�
class School {
	friend class Salary;
public:
	int year;
	int startyear;
	int month;
	int startmonth;
	double month_sum[12][3];//1.Ӧ�������ܶ� 2.��˰�� 3.ʵ�������ܶ�
	School() {
		month = 0; year = 0;
		memset(month_sum, 0, sizeof(month_sum));
		SYSTEMTIME st;
		GetLocalTime(&st);
		month = st.wMonth; year = st.wYear;
	}
	void m_In_Month_Sum_LastSalary(double LastSalary) {
		month_sum[month][2] += LastSalary;
	}
	void m_In_Month_Sum_dTax(double dTax) {
		month_sum[month][1] += dTax;
	}
	void m_In_Month_Sum_StartSalary(double StartSalary) {
		month_sum[month][0] += StartSalary;
	}
	void m_Show_Month_Sum() {

	}
};



int Salary::m_count = 0;




//--------------------------------ȫ�ֺ�������-------------------------------------
void outputtitle() {
	cout << "����" << "\t" << "����" << "\t" << "ְ��" << "\t" << "��λ����" << "\t" <<
		"н������" << "\t" << "��λ����" << "\t" <<
		"�����" << "\t" << "������Ч" << "\t" << "��������" << "\t" <<
		"���·���" << "\t" << "��ͨ��" << "\t" << "Ӧ�ɹ�����" << "\t" <<
		"ʧҵ��" << "\t" << "������" << "\t" << "ְҵ���" << "\t" <<
		"ҽ����" << "\t" << "�����" << "\t" << "ҽ����" << "\t" << endl;
}
void deleteRecord(int num) {
	for (int i = num; i < Salary::m_count; i++) {
		workers[num] = workers[num + 1];
	}
}
void sortNum() {
	for (int i = 1; i < Salary::m_count - 1; i++) {
		for (int g = i; g > 0; g--) {
			if (workers[g].m_num < workers[g - 1].m_num) {
				temp = workers[g];
				workers[g] = workers[g - 1];
				workers[g - 1] = temp;
			}
		}
	}
}
int biSearchNum(Salary arr[], string key) {
	sortNum();
	int high = Salary::m_count - 1, low = 0, mid = 0;
	while (high >= low) {
		mid = (high + low) / 2;
		if (arr[mid].m_num > key) {
			high = mid - 1;
		}
		else if (arr[mid].m_num < key) {
			low = mid + 1;
		}
		else {
			return mid;
		}
	}
	return -1;
}
void sortName() {
	for (int i = 1; i < Salary::m_count - 1; i++) {
		for (int g = i; g > 0; g--) {
			if (workers[g].m_name < workers[g - 1].m_name) {
				temp = workers[g];
				workers[g] = workers[g - 1];
				workers[g - 1] = temp;
			}
		}
	}
}
int biSearchName(Salary arr[], string key) {
	sortName();
	int high = Salary::m_count - 1, low = 0, mid = 0;
	while (high >= low) {
		mid = (high + low) / 2;
		if (arr[mid].m_name > key) {
			high = mid - 1;
		}
		else if (arr[mid].m_name < key) {
			low = mid + 1;
		}
		else {
			return mid;
		}
	}
	return -1;
}
void sortLastSalary() {
	for (int i = 1; i < Salary::m_count - 1; i++) {
		for (int g = i; g > 0; g--) {
			if (workers[g].m_LastSalary < workers[g - 1].m_LastSalary) {
				temp = workers[g];
				workers[g] = workers[g - 1];
				workers[g - 1] = temp;
			}
		}
	}
}
int biSearchLastSalary(Salary arr[], string key) {
	sortLastSalary();
	int high = Salary::m_count - 1, low = 0, mid = 0;
	while (high >= low) {
		mid = (high + low) / 2;
		if (arr[mid].m_name > key) {
			high = mid - 1;
		}
		else if (arr[mid].m_name < key) {
			low = mid + 1;
		}
		else {
			return mid;
		}
	}
	return -1;
}
int findnum(string num) {
	for (int i = 0; i < Salary::m_count; i++) {
		if (workers[i].m_num == num) {
			return i;
		}
	}
	return 0;
}


//read,save
void read() {
	ifstream infile;
	infile.open("userdata.txt");
	if (!infile) {
		cout << "��ȡ�ļ�ʧ�ܡ�";
		abort();
	}
	for (int i = 0; i < SIZE; i++) {
		infile.read(reinterpret_cast<char*>(&workers[i]), sizeof(Salary));
		if (workers[i].m_name != temp.m_name) {
			Salary::m_count++;
		}
		else {
			break;
		}
	}
	infile.close();
}
void save() {
	ofstream outfile;
	outfile.open("userdata.txt");
	if (!outfile) {
		cout << "д���ļ�ʧ�ܡ�";
		abort();
	}
	for (int i = 0; i < Salary::m_count; i++) {
		outfile.write(reinterpret_cast<char*>(&workers[i]), sizeof(Salary));
	}
	outfile.close();
}
//---------------------------------------------------------------------------------



void choice(int choice) {
	switch (choice) {
	case 0:break;
	case 1:temp.batchInput(); break;
	case 2:break;
	case 3:break;
	case 4:break;
	case 5:break;
	case 6:break;
	case 7:break;
	case 8:break;
	case 9:break;
	}
}


int main() {
	read();
	//System system12;
	//system12.menu();
	workers[0].m_Show_Member();
	workers[1].m_Show_Member();
	workers[2].m_In_Member();
	workers[2].m_Show_Member();
	/*workers[1].m_In_Basic_Ifo();
	workers[1].m_In_dSalary();
	workers[0].m_In_Basic_Ifo();
	workers[0].m_In_dSalary();*/
	save();
}