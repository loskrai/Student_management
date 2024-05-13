#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

class Student {
public:
	string getNum() {
		return num;
	}
	string getName() {
		return name;
	}
	string getGender() {
		return gender;
	}
	string getGrade() {
		return grade;
	}
	int getAge() {
		return age;
	}
	int getScore() {
		return score;
	}
	void setNum(string num) {
		this->num = num;
	}
	void setName(string name) {
		this->name = name;
	}
	void setGender(string gender) {
		this->gender = gender;
	}
	void setGrade(string grade) {
		this->grade = grade;
	}
	void setAge(int age) {
		this->age = age;
	}
	void setScore(int score) {
		this->score = score;
	}
	void input() {
		cout << "������ѧ�ţ�";
		cin >> num;
		cout << "������������";
		cin >> name;
		cout << "�������Ա�";
		cin >> gender;
		cout << "���������䣺";
		cin >> age;
		cout << "�����������";
		cin >> score;
		cout << "������༶��";
		cin >> grade;
	}
	void display() {
		cout << "ѧ�ţ�" << num << "\t";
		cout << "������" << name << "\t";
		cout << "�Ա�" << gender << "\t";
		cout << "���䣺" << age << "\t";
		cout << "������" << score << "\t";
		cout << "�༶��" << grade << "\n";
	}
private:
	string num;
	string name;
	string gender;
	int age;
	int score;
	string grade;
};

bool cmp(Student a, Student b) {
	return a.getScore() > b.getScore();
}

class StudentManage {
public:
	StudentManage() :num(0) {};
	void addStudent() {
		student[num].input();
		++num;
	}
	void showAll() {
		for (int i = 0; i < num; ++i) {
			student[i].display();
		}
	}
	void showByScore() {
		sort(student, student + num,cmp);
		showAll();
	}
	void showByGrade(string grade) {
		for (int i = 0; i < num; ++i) {
			if (student[i].getGrade() == grade) {
				student[i].display();
			}
		}
	}
private:
	Student student[100];
	int num;
};
//int main() {
//	StudentManage a;
//	int choice = 1;
//	while (choice != 0) {
//		cout << "1.���ѧ��������Ϣ\n";
//		cout << "2.��ʾ����ѧ����Ϣ\n";
//		cout << "3.��������ʾ����ѧ���Ļ�����Ϣ\n";
//		cout << "4.��ʾָ���༶ѧ���Ļ�����Ϣ\n";
//		cin >> choice;
//		switch (choice) {
//		case 1:a.addStudent(); break;
//		case 2:a.showAll(); break;
//		case 3:a.showByScore(); break;
//		case 4:cout << "�Ǹ��༶��"; string b; cin >> b; a.showByGrade(b); break;
//		}
//	}
//}