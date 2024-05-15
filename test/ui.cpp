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

	int t,s;

	char a[25];

	while (choice != 0) {

		cur = 0;
		cout << "������ѡ��";

		cin >> choice;

		switch (choice) {

		case 1:here1:cout << "�������ţ�"; cin >> t; if (t > (Order::num - 1) || t <= 0) { cout << "\n�����ڴ˱��\n1.��������\n2.��������"; int temp; cout << "\n������ѡ��"; cin >> temp; if (temp == 1) { goto here1; } else { break; } }
			  cur = order.roll(t); cout << num << "\t" << cur->num << "\t" << cur->name << "\t" << cur->discount << "\t" << cur->price << "\t" << cur->sale << "\n"; break;

		case 2:here2:cout << "�������ţ�"; cin >> t; if (t > (Order::num - 1) || t <= 0) { cout << "\n�����ڴ˱��\n1.��������\n2.�����޸�"; int temp; cout << "\n������ѡ��"; cin >> temp; if (temp == 1) { goto here2; } else { break; } }
			  cur = order.roll(t);  _itoa(t, a, 10); cout << "�������޸���Ϣ�����֣��ۿۣ���Ǯ, ������\n "; cin >> name >> discount >> price >> sale; order.phead->change(order.pphead, cur, a, name, discount, price, sale); order.save(); break;

		case 3:here3:cout << "�������ţ�"; cin >> t; if (t > (Order::num-1) || t <= 0) { cout << "\n�����ڴ˱��\n1.��������\n2.����ɾ��"; int temp; cout << "\n������ѡ��"; cin >> temp; if (temp == 1) { goto here3; } else { break; } }
			  cur = order.roll(t); if (cur) { order.phead->del(order.pphead, cur); } cout << "ɾ����ɣ�\n"; order.save(); break;

		case 4:_itoa(Menu::num, a, 10); Menu::num++; cout << "������������Ϣ�����֣��ۿۣ���Ǯ��\n "; cin >> name >> discount >> price; menu.phead->add(menu.pphead, a, name, discount, price); menu.save(); break;

		case 5:here5:cout << "�������ţ�"; cin >> num; s = stoi(num); if (s > (Menu::num)-1 || s <=0) { cout << "\n�����ڴ˱��\n1.��������\n2.�����޸�"; int temp; cout << "\n������ѡ��"; cin >> temp; if (temp == 1) { goto here5; } else { break; } }
			cur = menu.phead->find(menu.phead, num); cout << "�������޸���Ϣ�����֣��ۿۣ���Ǯ��\n "; cin >> name >> discount >> price; menu.phead->change(menu.pphead, cur, num, name, discount, price);  menu.save(); break;

		case 6:here6:cout << "�������ţ�"; cin >> num;  s = stoi(num); if (s > (Menu::num)-1 || s <= 0) { cout << "\n�����ڴ˱��\n1.��������\n2.����ɾ��"; int temp; cout << "\n������ѡ��"; cin >> temp; if (temp == 1) { goto here6; } else { break; } }
			  cur = menu.phead->find(menu.phead, num); if (cur) { menu.phead->del(menu.pphead, cur); } cout << "ɾ����ɣ�\n"; menu.save(); break;

		case 7:here7:cout << "�������ţ�"; cin >> num;  s = stoi(num); if (s > (Menu::num)-1 || s <= 0) { cout << "\n�����ڴ˱��\n1.��������\n2.��������"; int temp; cout << "\n������ѡ��"; cin >> temp; if (temp == 1) { goto here7; } else { break; } }
			cur = menu.phead->find(menu.phead, num); cout << cur->num << "\t" << cur->name << "\t" << cur->discount << "\t" << cur->price << "\t"; break;

		case 8:break;

		case 9:menu.phead->show(menu.phead); break;

		}

	}

}

void UI::customerUI() {

	menu.phead->show(menu.phead);
	cout << "*****************************************\n";
	cout << "*��ѡ�����ѷ�ʽ                         *\n";
	cout << "*1.����                                 *\n";
	cout << "*2.����                                 *\n";
	cout << "*0.�˳�                                 *\n";
	cout << "*****************************************\n";

	int choice = 1;

	cout << "ѡ��";
	cin >> choice;

	while (choice != 0) {
		while (choice != 1 && choice != 2) {
			cout << "���������룺";
			cin >> choice;
		}
		TakeoutOrder* Tphead=NULL, ** Tpphead = &Tphead;
		CanteenOrder* Cphead=NULL, ** Cpphead = &Cphead;

		if (choice == 2) {
			cout << "�������Ͳ�ʱ�䣬�Ͳ͵ص㣬�ֻ��ţ�\n";
			string sendTime, basho;
			unsigned int callNum;
			cin >> sendTime >> basho >> callNum;
			cout << "ѡ���Ʒ��źͷ�����������ʾ������0 0����\n";
			string num = "";
			int amount = 5;
			cin >> num >> amount;
			while (num != "0" && amount != 0) {
				link_node* tem = menu.phead->find(menu.phead, num);
				Tphead->add(Tpphead, tem->num, tem->name, tem->discount, tem->price, tem->sale, basho, callNum, 1.2, sendTime, amount);
				cin >> num >> amount;
			}
			Tphead->show(Tphead);
			Tphead->save(Tphead);
		}
		else {
			cout << "��ѡ�����ţ�\n";
			int tabNum;
			cin >> tabNum;
			cout << "�Ƿ���ᣨ1�ǣ�2��\n";
			bool doesbox = 0;
			cin >> doesbox;
			cout << "ѡ���Ʒ��źͷ�����������ʾ������0 0����\n";
			string num = "";
			int amount = 5;
			cin >> num >> amount;
			while (num != "0" && amount != 0) {
				link_node* tem = menu.phead->find(menu.phead, num);
				Cphead->add(Cpphead, tem->num, tem->name, tem->discount, tem->price, tem->sale, 100, doesbox, tabNum, amount);
				cin >> num >> amount;
			}
			Cphead->show(Cphead);
			Cphead->save(Cphead);
		}
		cout << "ѡ��";
		cin >> choice;
	}
	
}

