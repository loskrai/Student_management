#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Teacher 
{
public:
	Teacher():TeacherId(-1),age(-1),name(),gender(),title(),department(){}
	Teacher(int TeacherId,string name,string gender,int age,string title,string department)
	{
		this->TeacherId = TeacherId;
		this->age = age;
		this->department = department;
		this->gender = gender;
		this->name = name;
		this->title = title;
	}
	int getTeacherId() { return TeacherId; }
	string getName() { return name; }
	string getGender() { return gender; }
	int getAge() { return age; }
	string getTitle() { return title; }
	string getDepartment() { return department; }
	void setTeacherId(int TeacherId) { this->TeacherId = TeacherId; }
	void setName(string name) { this->name = name; }
	void setGender(string gender) { this->gender = gender; }
	void setAge(int age) { this->age = age; }
	void setTitle(string title) { this->title = title; }
	void setDepartment(string department) { this->department = department; }
	void input() 
	{
		cout << "����ְ���ţ�";
		cin >> TeacherId;
		cout << "����������";
		cin >> name;
		cout << "�����Ա�";
		cin >> gender;
		cout << "�������䣺";
		cin >> age;
		cout << "����ְ�ƣ�";
		cin >> title;
		cout << "����Ժϵ��";
		cin >> department;
	};
	void display() 
	{
		cout << "ְ���ţ�" << TeacherId << "\t";
		cout << "������" << name << "\t";
		cout << "�Ա�" << gender << "\t";
		cout << "���䣺" << age << "\t";
		cout << "ְ�ƣ�" << title << "\t";
		cout << "Ժϵ��" << department << "\n";
	}
private:
	int TeacherId;
	string name;
	string gender;
	int age;
	string title;
	string department;
};


class ManagerTeacher 
{
public:
	ManagerTeacher() : num(0) {};
	void addTeacher();
	void printTeacher();
	void printByDepartment(string dep);
	void deleteById(int teacherId);
	void changeById(int teacherId);
	void read() {
		ifstream input("teacher.txt");
		if (!input) {
			cerr << "�ļ���ȡ����";
			exit(0);
		}
		while (!input.eof()) {
			int a;
			string b;
			input >> a >> b;
			s[num].setTeacherId(a);
			s[num].setName(b);
			input >> b >> a;
			s[num].setGender(b);
			s[num].setAge(a);
			input >> b;
			s[num].setTitle(b);
			input >> b;
			s[num].setDepartment(b);
			++num;
		}
		cout << "��ȡ���!\n";
	}
	void save() {
		ofstream output("teacher.txt");
		if (!output) {
			cerr << "����ļ�����";
			exit(0);
		}
		for (int i = 0; i < num-1; ++i) {
			output << s[i].getTeacherId() << "\t" << s[i].getName() << "\t" << s[i].getGender() << "\t" << s[i].getAge() << "\t" << s[i].getTitle() << "\t" << s[i].getDepartment() << "\n";
		}
		output << s[num-1].getTeacherId() << "\t" << s[num-1].getName() << "\t" << s[num-1].getGender() << "\t" << s[num-1].getAge() << "\t" << s[num-1].getTitle() << "\t" << s[num-1].getDepartment();
		cout << "�������!\n";
	}
private:
	Teacher s[100];
	int num;
};

void ManagerTeacher::addTeacher() {
	s[num].input();
	for (int i = 0; i < num; ++i) {
		if (s[num].getTeacherId() == s[i].getTeacherId()) {
			cerr << "�ý�ʦ�Ѵ��ڣ����������룡";
			s[num].input();
		}
	}
	num++;
}


void ManagerTeacher::printTeacher() {
	for (int i = 0; i < num; ++i) {
		s[i].display();
	}
}

void ManagerTeacher::printByDepartment(string dep) {
	for (int i = 0; i < num; ++i) {
		if (s[i].getDepartment() == dep) {
			s[i].display();
		}
	}
}

void ManagerTeacher::changeById(int teacherId) {
	int i = 0;
	for (i = 0; i < num; ++i) {
		if (s[i].getTeacherId() == teacherId) {
			break;
		}
	}
	if (i < num) {
		s[i].input();
	}
	else {
		cout << "û���ҵ�Ҫ�޸ĵĽ�ʦ\n";
	}
}
void ManagerTeacher::deleteById(int teacherId) {
	int i;
	for (i = 0; i < num; ++i) {
		if (s[i].getTeacherId() == teacherId) {
			break;
		}
	}
	if (i < num) {
		for (int j = i; j < num; ++j) {
			s[j] = s[j + 1];
			--num;
		}
	}
	else {
		cout << "û���ҵ�Ҫɾ���Ľ�ʦ\n";
	}
}

//int main() {
//	ManagerTeacher a;
//	a.read();
//	int choice = -1;
//	while (choice != 0) {
//		cout << "1.��ӽ�ʦ\n";
//		cout << "2.��idɾ����ʦ\n";
//		cout << "3.��id�޸���Ϣ\n";
//		cout << "4.��Ժϵ��ʾ��ʦ��Ϣ\n";
//		cout << "5.��ʾ���н�ʦ��Ϣ\n";
//		cout << "0.�˳�\n";
//		cin >> choice;
//		switch (choice) {
//		case 1: {a.addTeacher(); break; }
//		case 2: {cout << "������Ҫɾ����Id:"; int id; cin >> id; a.deleteById(id); break; }
//		case 3: {cout << "������Ҫ�޸ĵ�Id:"; int id; cin >> id; a.changeById(id); break; }
//		case 4: {cout << "������Ժϵ:"; string pr; cin >> pr; a.printByDepartment(pr); break; }
//		case 5: {a.printTeacher(); break; }
//		}
//	}
//	a.save();
//	return 0;
//}
