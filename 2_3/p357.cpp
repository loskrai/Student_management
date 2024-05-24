#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<time.h>

using namespace std;

class Shape {
public:
	virtual void area() = 0;
	virtual void draw() = 0;
private:
protected:
};

class Triangle:public Shape {
	void area() final override {
		cout << "���������λ�ȡ�������\n";
	}
	void draw() final override {
		cout << "���������λ��ƺ���\n";
	}
};

class Rectangle :public Shape {
	void area() final override {
		cout << "���þ��λ�ȡ�������\n";
	}
	void draw() final override {
		cout << "���þ��λ��ƺ���\n";
	}
};

class Circle :public Shape {
	void area() final override {
		cout << "����Բ��ȡ�������\n";
	}
	void draw() final override {
		cout << "����Բ���ƺ���\n";
	}
};
int main() {
	time_t begin, end;
	begin = clock();
	
	Shape* p = nullptr;
	Triangle a;
	Circle b;
	Rectangle c;
	p = &a;
	p->area();
	p->draw();
	p = &b;
	p->area();
	p->draw();
	p = &c;
	p->area();
	p->draw();


	end = clock();
	cout << "\n run time:" << double(end - begin) / CLOCKS_PER_SEC;
}
