#include"UI.h"



void Menu::read() {

	string num, name, price, discount;

	ifstream infile("menu.txt");

	if (!infile) {

		cout << "No txt";

		exit(0);

	}

	while (!infile.eof()) {

		infile >> num >> name >> price >> discount;

		phead->add(pphead, num, name, discount, price);

	}

	Menu::num = atoi(num.c_str()) + 1;

	infile.close();

}



void Menu::save() const {

	string num, name, price, discount;

	ofstream outfile("menu.txt");

	if (!outfile) {

		cout << "No txt";

		exit(0);

	}

	link_node* cur = phead;

	while (cur->next) {

		outfile << cur->num << "\t" << cur->name << "\t" << cur->price << "\t" << cur->discount << "\n";

		cur = cur->next;

	}

	if (cur) {

		outfile << cur->num << "\t" << cur->name << "\t" << cur->price << "\t" << cur->discount;

	}

	cout << "Null\n";

	outfile.close();

}



void Order::read() {

	string num, name, price, discount, sale;

	ifstream infile("order.txt");

	if (!infile) {

		cout << "No txt";

		exit(0);

	}

	while (!infile.eof()) {

		infile >> num >> name >> price >> discount >> sale;

		phead->add(pphead, num, name, discount, price, sale);

	}

	Order::num = atoi(num.c_str()) + 1;

	infile.close();

}



void Order::save() const {

	ofstream outfile("order.txt");

	if (!outfile) {

		cout << "No txt";

		exit(0);

	}

	link_node* cur = phead;

	while (cur->next) {

		outfile << cur->num << "\t" << cur->name << "\t" << cur->price << "\t" << cur->discount << "\t" << cur->sale << "\n";

		cur = cur->next;

	}if (cur) {

		outfile << cur->num << "\t" << cur->name << "\t" << cur->price << "\t" << cur->discount << "\t" << cur->sale;

	}

	cout << "Null\n";

	outfile.close();

}







link_node* Order::roll(const int num) const {

	link_node* cur = phead;

	for (int i = 1; i < num; ++i) {

		cur = cur->next;

	}

	return cur;

}



int UI::log() const {

	cout << endl;

	cout << "****************************************\n";

	cout << "*��ѡ�����ȷ�����                    *\n";

	cout << "*   1.����Ա                           *\n";

	cout << "*   2.�˿�                             *\n";

	cout << "****************************************\n";

	int choice = 0, res = 0;

	cin >> choice;

	while (choice != 1 && choice != 2) {

		cout << "����������";

		cin >> choice;

	}

	if (choice == 1) {

		if (login()) {

			res = 1;

		}

	}

	else {

		res = 2;

	}

	return res;

}







void UI::userUI() {

	string num, name, discount, price, sale;

	link_node* cur;

	cout << "****************************************\n";

	cout << "*   1.���Ҷ���                         *\n";

	cout << "*   2.�޸Ķ���                         *\n";

	cout << "*   3.ɾ������                         *\n";

	cout << "*   4.��Ʒ��Ϣ����                     *\n";

	cout << "*   5.��Ʒ��Ϣ�޸�                     *\n";

	cout << "*   6.��Ʒ��Ϣɾ��                     *\n";

	cout << "*   7.��Ʒ��Ϣ����                     *\n";

	cout << "*   8.�������ͳ��(ûҪ������δ���)   *\n";

	cout << "*   9.�˵�չʾ                         *\n";

	cout << "*   0.�˳�                             *\n";

	cout << "****************************************\n";

	int choice = 10;

	int t;

	char a[25];

	while (choice != 0) {

		cur = 0;

		cout << "������ѡ��";

		cin >> choice;

		switch (choice) {

		case 1:cout << "�������ţ�"; cin >> t; cur = order.roll(t); cout << num << "\t" << cur->num << "\t" << cur->name << "\t" << cur->discount << "\t" << cur->price << "\t" << cur->sale << "\n"; break;

		case 2:cout << "�������ţ�"; cin >> t; cur = order.roll(t);  _itoa(t, a, 10); cout << "�������޸���Ϣ�����֣��ۿۣ���Ǯ, ������\n "; cin >> name >> discount >> price >> sale; order.phead->change(order.pphead, cur, a, name, discount, price, sale); break;

		case 3:cout << "�������ţ�"; cin >> t; cur = order.roll(t); if (cur) { order.phead->del(order.pphead, cur); } cout << "ɾ����ɣ�\n"; break;

		case 4:_itoa(Menu::num, a, 10); Menu::num++; cout << "������������Ϣ�����֣��ۿۣ���Ǯ��\n "; cin >> name >> discount >> price; menu.phead->add(menu.pphead, a, name, discount, price); break;

		case 5:cout << "�������ţ�"; cin >> num; cur = menu.phead->find(menu.phead, num); cout << "�������޸���Ϣ�����֣��ۿۣ���Ǯ��\n "; cin >> name >> discount >> price; menu.phead->change(menu.pphead, cur, num, name, discount, price); break;

		case 6:cout << "�������ţ�"; cin >> num; cur = menu.phead->find(menu.phead, num); if (cur) { menu.phead->del(menu.pphead, cur); } cout << "ɾ����ɣ�\n"; break;

		case 7:cout << "�������ţ�"; cin >> num; cur = menu.phead->find(menu.phead, num); cout << cur->num << "\t" << cur->name << "\t" << cur->discount << "\t" << cur->price << "\t"; break;

		case 8:break;

		case 9:menu.phead->show(menu.phead); break;

		}

	}

}



void UI::customerUI() {

	menu.phead->show(menu.phead);

	cout << "*****************************************\n";

	cout << "*������Ҫ��Ĳ�Ʒ��ź�����������x������*\n";

	cout << "*****************************************\n";

	string num, con;

	link_node* cur;

	while (cin >> num, num != "x") {

		cin >> con;

		cur = menu.phead->find(menu.phead, num);

		char a[25];

		_itoa(Order::num, a, 10);

		order.phead->add(order.pphead, a, cur->name, cur->discount, cur->price, con);

		Order::num++;

	}

}

