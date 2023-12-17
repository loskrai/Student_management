#include"login.h"

#define SIZE 100 //�������
using namespace std;
//ְ��������
class Salary {
	friend class System;
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
		m_name.clear(); m_num.clear(); m_title.clear(); m_workage = 0; m_LastSalary = 0; m_StartSalary = 0; m_dTax = 0; memset(m_dSalary, 0, sizeof(m_dSalary));
	}
	void clean() {
		m_name.clear(); m_num.clear(); m_title.clear(); m_workage = 0; m_LastSalary = 0; m_StartSalary = 0; m_dTax = 0; memset(m_dSalary, 0, sizeof(m_dSalary));
	}
	//д������
	//------------------------------------
	void m_In_Basic_Ifo() {
		cout << "������ְ�������������Ϣ������ ���� ְ�� ���䣩��\n";
		cin >> m_num >> m_name >> m_title >> m_workage;
		checkPosition(&m_title);
		checkNum(&m_num);
	}
	void m_Change_Basic_Ifo() {
		string b;
		m_name.clear(); m_num.clear(); m_title.clear(); m_workage = 0;
		cout << "������ְ�������������Ϣ������ ���� ְ�� ���䣩��\n";
		cin >> b >> m_name >> m_title >> m_workage;
		checkNum(&b);
		checkPosition(&m_title);
		m_num = b;
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
		cout << m_LastSalary << "\t";
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
		m_Get_LastSalary();
		m_Show_Basic_Ifo();
		m_Show_dSalary();
		m_Show_LastSalary();
	}
	void m_Show_All(){
		outputtitle();
		for (int i = 0; i < Salary::m_count; i++) {
			workers[i].m_Show_Member();
			cout << "\n";
		}

	}
	void batchInput() {
		int num = 0,temp=0;
		cout << "������¼��������";
		cin >> num;
		cout << "������" << num << "λ�̹��Ĺ�����Ϣ" << endl;
		temp = Salary::m_count;
		for (int i = 0; i < num ; i++) {
			workers[i+ temp].m_In_Member();
			Salary::m_count++;
		}
	}
	//--------------------------------------
	//����ɾ��
	void deleteRecord(int num) {
		for (int i = num; i < Salary::m_count; i++) {
			workers[num] = workers[num + 1];
		}
	}

	//ƽ��ֵ
	void getTotal() {
		temp.clean();
		for (int i = 0; i < Salary::m_count; i++) {
			temp.m_dTax += workers[i].m_dTax;
			temp.m_LastSalary += workers[i].m_LastSalary;
			temp.m_StartSalary += workers[i].m_StartSalary;
			for (int g = 0; g < 15; g++) {
				temp.m_dSalary[g] += workers[i].m_dSalary[g];
			}
		}
	}
	void getAvg() {
		getTotal();
		temp.m_dTax /=Salary::m_count;
		temp.m_LastSalary /= Salary::m_count;
		temp.m_StartSalary /= Salary::m_count;
		for (int g = 0; g < 15; g++) {
			temp.m_dSalary[g] /= Salary::m_count;
		}
	}
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
	void outputtitle() {
		cout << "����" << "\t" << "����" << "\t" << "ְ��" << "\t" <<"����" <<"\t" << "��λ����" << "\t" <<
			"н������" << "\t" << "��λ����" << "\t" <<
			"�����" << "\t" << "������Ч" << "\t" << "��������" << "\t" <<
			"���·���" << "\t" << "��ͨ��" << "\t" << "Ӧ�ɹ�����" << "\t" <<
			"ʧҵ��" << "\t" << "������" << "\t" << "ְҵ���" << "\t" <<
			"ҽ����" << "\t" << "�����" << "\t" << "ҽ����" << "\t" << "ʵ������" << "\t\n";
	}
	void checkPosition(string* title) {
		if (*title != "����" && *title != "������" && *title != "��ʦ" && *title != "����" && *title != "����") {
			cout << "�޴�ְλ����������:";
			cin >> *title;
			checkPosition(title);
		}
	}
	bool m_findnum(const string num) {
		for (int i = 0; i < Salary::m_count; i++) {
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
int Salary::m_count = 0;
//ѧУ12�����ܶ�
class School {
	friend class Salary;
public:
	int month;
	int startmonth;
	double month_sum[12][3];//1.Ӧ�������ܶ� 2.��˰�� 3.ʵ�������ܶ�
	School() {
		month = 0;
		memset(month_sum, 0, sizeof(month_sum));
		SYSTEMTIME st;
		GetLocalTime(&st);
		month = st.wMonth;
	}
	void m_In_Month_Sum_LastSalary(double LastSalary) {
		month_sum[month-1][2] += LastSalary;
	}
	void m_Get_Month_Sum_LastSalary() {
		for (int i = 0; i < Salary::m_count; i++) {
			m_In_Month_Sum_LastSalary(workers[i].m_LastSalary);
		}
	}
	void m_In_Month_Sum_dTax(double dTax) {
		month_sum[month-1][1] += dTax;
	}
	void m_Get_Month_Sum_dTax() {
		for (int i = 0; i < Salary::m_count; i++) {
			m_In_Month_Sum_dTax(workers[i].m_dTax);
		}
	}
	void m_In_Month_Sum_StartSalary(double StartSalary) {
		month_sum[month-1][0] += StartSalary;
	}
	void m_Get_Month_Sum_StartSalary() {
		for (int i = 0; i < Salary::m_count; i++) {
			m_In_Month_Sum_StartSalary(workers[i].m_StartSalary);
		}
	}
	void m_Get() {
		memset(month_sum, 0, sizeof(month_sum));
		m_Get_Month_Sum_StartSalary();
		m_Get_Month_Sum_dTax();
		m_Get_Month_Sum_LastSalary();
	}
	void m_Show_Month_Sum() {
		m_Get();
		cout << "\tӦ��\t��˰\tʵ��";
		for (int i = 0; i < 12; i++) {
			cout << "\n" << i + 1 << "��\t";
			for (int g = 0; g < 3; g++) {
				cout << month_sum[i][g] << "\t";
			}
		}
	}
	void save() {
		ofstream outfile;
		outfile.open("total.txt", ios::binary);
		if (!outfile) {
			abort();
		}
		for (int i = 0; i < 12; i++) {
			for (int g = 0; g < 3; g++) {
				outfile << month_sum[i][g] << endl;
			}
		}
		outfile.close();
	}
	void read() {
		ifstream infile;
		infile.open("total.txt",ios::binary);
		if (!infile) {
			cout << "��ȡ�ļ�ʧ�ܡ�";
			ofstream test;
			test.open("total.txt");
			test.close();
			abort();
		}
		for (int i = 0; i < 12; i++) {
			for (int g = 0; g < 3; g++) {
				infile >> month_sum[i][g];
			}
		}
		infile.close();
	}
}sc;
//ϵͳ�ࣨ��Ҫ��������
class System {
	friend class Salary;
public:
	int menu()
	{
		string choice;
		cout << setw(29) << setfill(' ') << "���ʹ���ϵͳ" << endl;
		cout << setw(25) << setfill('*') << "�˵�" << setw(25) << setfill('*') << "*" << endl;
		cout << "1.¼�빤��                2.ɾ�����ʼ�¼" << setw(50) << setfill(' ') << " " << endl;
		cout << "3.��ѯ���ʼ�¼            4.�޸Ĺ��ʼ�¼" << setw(50) << setfill(' ') << " " << endl;
		//���빤�ʣ���������Ϊ��Ѱʱ�������ʧȥ����ĳ��λ�ò�������壬��Ĭ�������Ӳ��룬��ô����¼��Ҳ��ʵ�֣����޸�����5
		cout << "5.����                    6.ͳ�Ʒ���" << setw(50) << setfill(' ') << " " << endl;
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
		else if (choice == "5" || choice == "����" ) {
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
	void choice(int choice) {
		switch (choice) {
		case 0:break;
		case 1:temp.batchInput(); cout << "\n\n\n\n\n\n\n\n\n"; break;
		case 2:deleteMenu(); cout << "\n\n\n\n\n\n\n\n\n"; break;
		case 3:findMenu(); cout << "\n\n\n\n\n\n\n\n\n"; break;
		case 4:changeMenu(); break;
		case 5:rebuild(); return;
		case 6:analysisMenu(); cout << "\n\n\n\n\n\n\n\n\n"; break;
		case 7:sortMenu(); cout << "\n\n\n\n\n\n\n\n\n"; break;
		case 8:fixMenu(); cout << "\n\n\n\n\n\n\n\n\n"; break;
		case 9:showMenu(); cout << "\n\n\n\n\n\n\n\n\n"; break;
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
		cout << "�����ڴ˹���\n";
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
		cout << "�����ڴ���\n";
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
	void findLastSalary(double a,double b) {
		bool c = false;
		for (int i = 0; i < Salary::m_count; i++) {
			if (workers[i].m_LastSalary >= a && workers[i].m_LastSalary <= b) {
				workers[i].m_Show_Member();
				c = true;
				cout << "\n";
			}
		}
		if (!c) {
			cout << "������";
		}
	}
	int findLastSalaryCount(int a, int b) {
		int count = 0;
		for (int i = 0; i < Salary::m_count; i++) {
			if (workers[i].m_LastSalary >= a && workers[i].m_LastSalary <= b) {
				count++;
			}
		}
		return count;
	}
	void printstar(int num) {
		for (int i = 0; i < num; i++) {
			cout << "*";
		}
	}
	void makepic() {
		int a, b, c, d, e;
		a = b = c = d = e = 0;
		for (int i = 0; i < Salary::m_count; i++) {
			if (workers[i].m_title == "����") {
				a++;
			}
			else if (workers[i].m_title == "����") {
				b++;
			}
			else if (workers[i].m_title == "��ʦ") {
				c++;
			}
			else if (workers[i].m_title == "������") {
				d++;
			}
			else {
				e++;
			}
		}
		cout << "���ڣ�";
		printstar(a);
		cout << "\n";
		cout << "���̣�";
		printstar(b);
		cout << "\n";
		cout << "��ʦ��";
		printstar(c);
		cout << "\n";
		cout << "�����ڣ�";
		printstar(d);
		cout << "\n";
		cout << "������";
		printstar(e);
		cout << "\n";
	}
	double salaryPUP(string title) {
		double uprate = 0;
		if (title == "����") {
			uprate = 0.1;
		}
		else if (title == "������") {
			uprate = 0.08;
		}
		else if (title == "��ʦ") {
			uprate = 0.05;
		}
		else if (title == "����") {
			uprate = 0.04;
		}
		else {
			uprate = 0.03;
		}
		return uprate;
	}
	double salaryYear(int year) {
		double up = 0;
		if (year >= 1 && year <= 10) {
			up = 40;
		}
		else if (year > 10 && year <= 15) {
			up = 45;
		}
		else if (year > 15 && year <= 20) {
			up = 50;
		}
		else if (year > 20 && year <= 25) {
			up = 55;
		}
		else {
			up = 60;
		}
		return up;
	}
	void salaryChange(double& salaryPO, double& salaryYe, string workPOsi, int workage) {
		salaryYe += salaryYear(workage);
		salaryPO *= (1 + salaryPUP(workPOsi));
	}
	void changeMenu() {
		int choice=-1;
		string num;
		while (choice != 0) {
			cout << "  ====>1.�޸Ĺ���\n\n";
			cout << "  ====>2.�޸Ļ�����Ϣ\n\n";
			cout << "  ====>0.�˳�\n\n";
			cout << "��ѡ��0~1��\n\n";
			cin >> choice;
			while (choice != 1 && choice != 2 && choice != 0) {
				cout << "��ʽ����";
				cin >> choice;
			}
			if (choice == 1) {
				cout << "��Ҫ�޸Ĺ���Ϊ���ļ�¼��";
				cin >> num;
				int a = -1;
				a = biSearchNum(workers, num);
				if (a != -1) {
					workers[a].m_Show_Basic_Ifo();
					workers[a].m_In_dSalary();
					cout << "�޸����,�޸ĺ�\n";
					workers[a].m_Show_Member();
					cout << "\n";
				}
			}
			else if (choice == 2) {
				cout << "��Ҫ�޸Ĺ���Ϊ���ļ�¼��";
				cin >> num;
				string g, b, c;
				int d;
				int a = -1,a1=-1;
				a = biSearchNum(workers, num);
				if (a!=-1) {
					workers[a].m_Show_Basic_Ifo();
					workers[a].m_Change_Basic_Ifo();
					cout << "�޸����,�޸ĺ�\n";
					workers[a].m_Show_Member();
					cout << "\n";
				}
			}
			else {
				break;
			}
		}
	}
	void fixMenu() {
		int choice = -1;
		while (choice != 0) {
			string find;
			cout << "  ====>1.����ȫ��\n\n";
			cout << "  ====>2.����ָ�����ŵ�Ա��\n\n";
			cout << "  ====>0.�˳�����\n";
			cout << "��ѡ��1-2��0��";
			cin >> choice;
			while (choice != 1 && choice != 2 && choice != 0) {
				cout << "��ʽ��������������";
				cin >> choice;
			}
			if (choice == 1) {
				for (int g = 0; g < Salary::m_count; g++) {
					workers[g].m_LastSalary = 0;
					salaryChange(workers[g].m_dSalary[0], workers[g].m_dSalary[1], workers[g].m_title, workers[g].m_workage);
					workers[g].m_Get_dTax();
					workers[g].m_Get_StartSalary();
					workers[g].m_Get_LastSalary();
				}
				temp.m_Show_All();
				cout << "�޸����\n";

			}
			else if (choice ==2 ) {
				int a = -1;
				cout << "��������Ҫ�����Ĺ��ţ�";
				cin >> find;
				a = biSearchNum(workers, find);
				if (a != -1) {
					salaryChange(workers[a].m_dSalary[0], workers[a].m_dSalary[1], workers[a].m_title, workers[a].m_workage);
					workers[a].m_Get_dTax();
					workers[a].m_Get_StartSalary();
					workers[a].m_Get_LastSalary();
					temp.m_Show_All();
					cout << "�޸����";
				}
				cout << "\n";
			}
			else {
				break;
			}
		}
	}
	void findMenu() {
		int choice = -1;
		while (choice != 0) {
			string find;
			cout << "  ====>1.��ְ�����Ų�ѯ\n\n";
			cout << "  ====>2.��ְ��������ѯ\n\n";
			cout << "  ====>3.�����ʷ�Χ��ѯ\n\n";
			cout << "  ====>0.�˳���ѯ\n";
			cout << "��ѡ��1-3��0��";
			cin >> choice;
			while (choice != 1 && choice != 2 && choice != 3 && choice != 0) {
				cout << "��ʽ��������������";
				cin >> choice;
			}
			if (choice == 1) {
				int a = -1;
				cout << "��������Ҫ��ѯ�Ĺ��ţ�";
				cin >> find;
				a = biSearchNum(workers, find);
				if (a != -1) {
					workers[biSearchNum(workers, find)].m_Show_Member();
				}
				cout << "\n";
			}
			else if (choice == 2) {
				bool a = false;
				cout << "��������Ҫ��ѯ��������";
				cin >> find;
				for (int i = 0; i < Salary::m_count; i++) {
					if (workers[i].m_name == find) {
						workers[i].m_Show_Member();
						a = true;
						cout << "\n";
					}
				}
				if (!a) {
					cout << "�����ڴ���";
				}
			}
			else if (choice == 3) {
				double a, b;
				cout << "�����빤�ʷ�Χ[a,b]";
				cin >> a >> b;
				findLastSalary(a, b);
				cout << "\n";
			}
			else {
				break;
			}
		}
		cout << "�˳�";
	}
	void sortMenu() {
		int choice = -1;
		while (choice != 0) {
			cout << "  ====>1.��ְ����������\n\n";
			cout << "  ====>2.��ְ����������\n\n";
			cout << "  ====>3.��ʵ����������\n\n";
			cout << "  ====>0.�˳�����\n";
			cout << "��ѡ��1-3��0��";
			cin >> choice;
			while (choice != 1 && choice != 2 && choice != 3 && choice != 0) {
				cout << "��ʽ��������������";
				cin >> choice;
			}
			if (choice == 1) {
				sortNum();
				temp.m_Show_All();
			}
			else if (choice == 2) {
				sortName();
				temp.m_Show_All();
			}
			else {
				sortLastSalary();
				temp.m_Show_All();
			}
		}
		cout << "�˳�";
	}
	void deleteMenu() {
		int choice = -1;
		string num;
		while (choice != 0) {
			cout << "  ====>1.��ְ������ɾ��\n\n";
			cout << "  ====>2.��ְ������ɾ��\n\n";
			cout << "  ====>0.�˳�ɾ��\n";
			cout << "��ѡ��1-2��0��";
			cin >> choice;
			while (choice != 1 && choice != 2 && choice != 0) {
				cout << "�����ʽ�������������룡";
				cin >> choice;
			}
			if (choice == 1) {
				cout << "��Ҫɾ������Ϊ���ļ�¼��";
				cin >> num;
				cout << "\n";
				int a = 0;
				a = biSearchNum(workers, num);
				if (a != -1) {
					temp.deleteRecord(a);
					cout << "ɾ�����\n";
					temp.m_Show_All();
					Salary::m_count--;
				}
			}
			else if (choice == 2) {
				cout << "��Ҫɾ��˭�ļ�¼��";
				cin >> num;
				for (int i = 0; i < Salary::m_count; i++) {
					if (workers[i].m_name == num) {
						temp.deleteRecord(i);
						Salary::m_count--;
					}
				}
				cout << "ɾ�����\n";
				temp.m_Show_All();
			}
			else {
				break;
			}
		}
		cout << "�˳�\n";
	}
	void showMenu() {
		temp.m_Show_All();
		temp.getAvg();
		cout << Salary::m_count << "λԱ���Ĺ��ʼ�¼\n";
		cout << "ƽ��ֵ";
		temp.m_Show_Member();
	}
	void analysisMenu() {
		int choice = -1;
		while (choice != 0) {
			cout << "  ====>1.��ʾȫУ��ְ�������ƽ�����ʼ��ܹ���\n\n";
			cout << "  ====>2.ͳ�Ʒ���ָ�������Ĺ�����Ϣ\n\n";
			cout << "  ====>3.ͳ��ȫУְ����ְ������\n\n";
			cout << "  ====>4.��ʾʵ���������ֵ����Сֵ���Լ�����ƽ�����ʵ�Ա��\n\n";
			cout << "  ====>5.��ʾÿ�µ�Ӧ�������ܶ��˰�ʵ�������ܶ�\n\n";
			cout << "  ====>0.�˳���������\n";
			cin >> choice;
			while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice!=5 && choice != 0) {
				cout << "�����ʽ��������������";
				cin >> choice;
			}
			if (choice == 1) {
				temp.getTotal();
				temp.outputtitle();
				cout << "�ܼƣ�";
				temp.m_Show_Member();
				cout << "\nƽ��ֵ";
				temp.getAvg();
				temp.m_Show_Member();
				cout << "\n";
			}
			else if (choice == 2) {
				double a[100] = {0},section1=0,section2=0;
				int num1 = -1, num2 = 0;
				cout << "����鿴Ա������ǰ����ʵ�ͳ��:";
				cin >> num1;
				while (!(num1 >= 1 && num1 <= 15)) {
					cout << "�����ʽ��������������.";
					cin >> num1;
				}
				for (int i = 0; i < Salary::m_count;i++) {
					for (int g = 0; g < num1; g++) {
						a[i] += workers[i].m_dSalary[g];
					}
				}
				cout << "����ͳ�Ƽ����������䣺";
				cin >> num2;
				while (num2 <= 0) {
					cout << "�����ʽ��������������.";
					cin >> num2;
				}
				for (int i = 1; i <= num2;i++) {
					cout << "��" << i << "����������[a,b](�Կո�Ϊ��)";
					cin >> section1 >> section2;
					if (section2 < section1) {
						cout << "�����ʽ�������������룺";
						cin >> section1 >> section2;
					}
					double count = 0;
					for (int i = 0; i < Salary::m_count; i++) {
						if (a[i] >= section1 && a[i] <= section2) {
							++count;
						}
					}
					cout << "��[" << section1 << "," << section2 << "]����" << count << "�ˣ�ռ" << ((count / Salary::m_count) * 100) << "%\n";
				}
			}
			else if (choice == 3) {
				makepic();
			}
			else if (choice == 4){
				for (int i = 0; i < Salary::m_count-1; i++) {
					temp = workers[i].m_Get_Max_LastSalary(workers[i + 1]);
				}
				cout << "�õ����ʵ�����ʵ��ǣ�\n";
				temp.m_Show_Member();
				cout << "\n";
				for (int i = 0; i < Salary::m_count - 1; i++) {
					temp = workers[i].m_Get_Min_LastSalary(workers[i + 1]);
				}
				cout << "�õ�����ʵ�����ʵ��ǣ�\n";
				temp.m_Show_Member();
				cout << "\n";
				temp.getAvg();
				int a = 0;
				for (int i = 0; i < Salary::m_count; i++) {
					if (workers[i].m_LastSalary < temp.m_LastSalary) {
						a++;
					}
				}
				cout << "����ƽ�����ʵ�Ա������Ϊ��" << a << "��\n";
				cout << "������ԱΪ��\n";
				for (int i = 0; i < Salary::m_count; i++) {
					if (workers[i].m_LastSalary < temp.m_LastSalary) {
						workers[i].m_Show_Basic_Ifo();
						cout<<"\n";
					}
				}
			}
			else if (choice == 5) {
				sc.m_Show_Month_Sum();
				cout << "\n";
			}
			else {
				break;
			}
		}
	}
	void rebuild() {
		ofstream outfile;
		initializeFile();
		outfile.open("userdata.txt");
		outfile.close();
		outfile.open("total.txt", ios::binary);
		outfile.close();
		ofstream otime;
		otime.open("time.txt");
		otime.close();
	}
}sy;


//--------------------------------ȫ�ֺ�������-------------------------------------
//read,save
void read() {
	ifstream infile;
	infile.open("userdata.txt");
	if (!infile) {
		cout << "��ȡ�ļ�ʧ�ܡ�";
		abort();
	}
	for (int i = 0; i<100; i++) {
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



int main() {
	read();
	sc.read();
	int choice = -1;
	bool log = login();
	while (log && choice != 0 && choice != 5) {
		choice = sy.menu();
		sy.choice(choice);
	}
	if (choice == 5) {
		return 0;
	}
	save();
	sc.save();
	return 0;
}