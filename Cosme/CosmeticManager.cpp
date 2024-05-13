#include"CosmeticManager.h"
#define FILENAME "Cosmetic.txt"

struct node {
	string name;
	int num = 0;
	node* next;
};

node* head = nullptr;

time_t gettm(const string& date) {
	tm time = {};
	istringstream tim(date);
	tim >> get_time(&time, "%Y/%m/%d");
	time_t t = mktime(&time);
	return t;
}

CosmeticManager::CosmeticManager() {
	ifstream ifs;
	ifs.open(FILENAME, ios::out);
	if(!ifs.is_open()){
		ofstream ifj(FILENAME);
	}
	string h1, h2, h3, h4, h5, h6, h7;
	ifs >> h1;
	ifs >> h2;
	ifs >> h3;
	ifs >> h4;
	ifs >> h5;
	ifs >> h6;
	ifs >> h7;
	string name;
	double price;
	bool type;
	string date;
	int number;
	int quantity;
	bool typeP;
	int num = 0;
	while (ifs >> number && ifs >> name && ifs >> price && ifs >> type && ifs >> quantity&& ifs >>typeP  && ifs >> date) {
		num++;
	}
	ifs.close();
	ifs.open(FILENAME, ios::out);
	cosNum = num;
	cosptr = new Cosmetic[num];
	int i = 0;
	ifs >> h1;
	ifs >> h2;
	ifs >> h3;
	ifs >> h4;
	ifs >> h5;
	ifs >> h6;
	ifs >> h7;
	while (ifs >> number && ifs >> name && ifs >> price && ifs >> type && ifs >> quantity&& ifs >> typeP && ifs >> date) {
		cosptr[i].setName(name);
		cosptr[i].setPrice(price);
		cosptr[i].setType(type);
		cosptr[i].setDate(date);
		cosptr[i].setTypeP(typeP);
		cosptr[i].setNum(number);
		cosptr[i].setQuantity(quantity);
		i++;
	}
	ifs.close();
}

CosmeticManager::~CosmeticManager() {
	delete[] cosptr;
	cosptr = nullptr;
}

void CosmeticManager::Purchasegoods(int num) {
	if ((num - int(num) != 0 || num <= 0)) {
		cout << "����������Ϊ��������С����" << endl;
		exitsystem();
	}
	int sumnum = num + cosNum;
	Cosmetic* temp = new Cosmetic[sumnum];
	int i = 0;
	if (cosNum > 0) {
		for (i = 0; i < cosNum; i++) {
			temp[i].setName(cosptr[i].getName());
			temp[i].setPrice(cosptr[i].getPrice());
			temp[i].setType(cosptr[i].getType());
			temp[i].setTypeP(cosptr[i].getTypeP());
			temp[i].setDate(cosptr[i].getDate());
			temp[i].setNum(cosptr[i].getNum());
			temp[i].setQuantity(cosptr[i].getQuantity());
		}
	}
	for (int j = 1; i < sumnum; j++, i++) {
		cout << "�������" << j << "����Դ��Ʒ�ƣ�";
		string name;
		cin >> name;
		cout << "�������" << j << "����Դ�ĵ��ۣ�";
		double price;
		cin >> price;
		cout << "�������" << j << "����Դ�Ƿ�Ϊ��������Ϊ1��Ϊ0";
		bool type;
		cin >> type;
		cout << "�������" << j << "����Դ�Ƿ�Ϊ��������Ϊ1��Ϊ0";
		bool typeP;
		cin >> typeP;
		cout << "�������" << j << "����Դ��������";
		int quantity;
		cin >> quantity;
		SYSTEMTIME time;
		GetLocalTime(&time);
		string ntime;
		ntime = to_string(time.wYear) + "/" + to_string(time.wMonth) + "/" + to_string(time.wDay);
		temp[i] = Cosmetic(cosNum + j, quantity, name, type, price, ntime, typeP);
	}
	delete[] this->cosptr;
	this->cosptr = temp;
	cosNum = sumnum;
	save();
	cout << "�����ɹ�";
	system("cls");
	showMenu();
}

void CosmeticManager::printCosmetic() {
	cout << "���\tƷ��\t����\t����\t����\t����\n";
	for (int i = 0; i < this->cosNum; i++) {
		cosptr[i].printCos();
	}
}

void CosmeticManager::SortCosmeticManager() {
	Cosmetic* temp = new Cosmetic[cosNum];
	for (int i = 0; i < cosNum; i++) {
		temp[i].setName(cosptr[i].getName());
		temp[i].setPrice(cosptr[i].getPrice());
		temp[i].setType(cosptr[i].getType());
		temp[i].setTypeP(cosptr[i].getTypeP());
		temp[i].setDate(cosptr[i].getDate());
		temp[i].setNum(cosptr[i].getNum());
		temp[i].setQuantity(cosptr[i].getQuantity());
	}
	for (int i = 0; i < cosNum; i++) {
		for (int j = 0; j < cosNum - i - 1; j++) {
			if(cosptr[j].getPrice() > cosptr[j + 1].getPrice()) {
				Cosmetic temp = cosptr[j];
				cosptr[j] = cosptr[j + 1];
				cosptr[j + 1] = temp;
			}
		}
	}
	printCosmetic();
	delete[] cosptr;
	cosptr = temp;
	system("pause");
}

void CosmeticManager::TyproCosmrticManager(bool type) {
	cout << "���\tƷ��\t����\t����\t����\t����\n";
	for (int i = 0; i < cosNum; i++) {
		if (cosptr[i].getType() == type) {
			cosptr[i].printCos();
		}
	}
	system("pause");
}

void CosmeticManager::save() {
	ofstream ofs;
	ofs.open("Cosmetic.txt");
	ofs << "���\tƷ��\t����\t����\t����\t����\t����\n";
	for (int i = 0; i < cosNum; i++) {
		ofs << cosptr[i].getNum() << "\t" << cosptr[i].getName() << "\t" << cosptr[i].getPrice() << "\t" << cosptr[i].getType() << "\t" << cosptr[i].getQuantity() << "\t" << cosptr[i].getTypeP() << "\t" << cosptr[i].getDate() << endl;
	}
	ofs.close();
}

void CosmeticManager::delCosmetic(string name) {
	for (int i = 0; i < cosNum; i++) {
		if (cosptr[i].getName() == name) {
			cosptr[i].printCos();
			cout << endl;
			cout << "�Ƿ�ɾ����" << endl;
			cout << "1����" << endl;
			cout << "2����" << endl;
			int a;
			cin >> a;
			if (a == 1) {
				for (int j = i; j < cosNum - 1; j++) {
					this->cosptr[j] = cosptr[j + 1];
				}
				cosNum--;
				cout << "ɾ���ɹ�";
				system("pause");
				save();
				break;
			}
			if (i == cosNum - 1) {
				cout << "�޴˻�ױƷ��" << endl;
				system("pause");
			}
		}
	}
}

void CosmeticManager::modifyCosmetic(string name) {
	int i;
	for (i = 0; i < cosNum; i++) {
		if (cosptr[i].getName() == name) {
			cout << "�������޸ĺ�ױƷ��Ʒ�ƣ�";
			string cname;
			cin >> cname;
			cout << "�������޸ĺ�ױƷ�ĵ��ۣ�";
			double price;
			cin >> price;
			cout << "�Ƿ�Ϊ������(�� 1 �� 0 )";
			bool type;
			cin >> type;
			cout << "�Ƿ�Ϊ������(�� 1 �� 0 )";
			bool typeP;
			cin >> typeP;
			cout << "�������޸ĺ�ױƷ��������";
			int quantity;
			cin >> quantity;
			SYSTEMTIME time;
			GetLocalTime(&time);
			string ntime;
			ntime = to_string(time.wYear) + "/" + to_string(time.wMonth) + "/" + to_string(time.wDay);
			cosptr[i] = Cosmetic(i, quantity, cname, type, price, ntime,typeP);
			break;
		}
	}
	if (i == cosNum) {
		cout << "�鲻���û�ױƷ��" << endl;
	}
	system("pause");
	save();
}

void CosmeticManager::printByPriceCondition(int price) {
	for (int i = 0; i < cosNum; i++) {
		if (cosptr[i].getPrice() >= price) {
			cosptr[i].printCos();
		}
	}
	system("pause");
}

void CosmeticManager::printByName(string name) {
	int count = 0;
	int i;
	for (i = 0; i < cosNum; i++) {
		if (cosptr[i].getName() == name) {
			cosptr[i].printCos();
			count++;
		}
	}
	if (count == 0) {
		cout<<"û���ҵ��û�ױƷ��"<<endl;
	}
	system("pause");
}

void CosmeticManager::showRepertory(const string& date) {
	bool flag = 0;
	node* p = nullptr;
	while (head) {
		p = head;
		head = head->next;
		delete p;
		p = nullptr;
	}
	for (int i = 0; i < cosNum; i++) {
		flag = 0;
		if (gettm(cosptr[i].getDate()) <= gettm(date)) {
			if (head == nullptr) {
				head = new node;
				head->name = cosptr[i].getName();
				if (cosptr[i].getTypeP()) {
					head->num += cosptr[i].getQuantity();
				}
				else {
					head->num -= cosptr[i].getQuantity();
				}
				head->next = nullptr;
			}
			else {
				node* p2 = head;
				while (p2 != nullptr) {
					if (p2->name == cosptr[i].getName()) {
						flag = 1;
						if (cosptr[i].getTypeP()) {
							p2->num += cosptr[i].getQuantity();
						}
						else {
							p2->num -= cosptr[i].getQuantity();
						}
					}
					p2 = p2->next;
				}
				if (flag) { continue; }
				p2 = head;
				while (p2->next != nullptr) {
					if (p2->name == cosptr[i].getName()) {
						flag = 1;
						if (cosptr[i].getTypeP()) {
							p2->num += cosptr[i].getQuantity();
						}
						else {
							p2->num -= cosptr[i].getQuantity();
						}
					}
					p2 = p2->next;
				}
				p2->next = new node;
				p2->next->name = cosptr[i].getName();
				if (cosptr[i].getTypeP()) {
					p2->next->num += cosptr[i].getQuantity();
				}
				else {
					p2->next->num -= cosptr[i].getQuantity();
				}
				p2->next->next = nullptr;
			}
		}
	}
	cout << "Ʒ��\t���\n";
	node* p1 = head;
	while (p1) {
		cout << p1->name << "\t" << p1->num << "\n";
		p1 = p1->next;
	}
	system("pause");
}

void CosmeticManager::showMenu() {
	cout << "-----------------------------------------" << endl;
	cout << "|     ��ӭ������ױƷ����ϵͳ            |" << endl;
	cout << "|                                       |" << endl;
	cout << "|     1�����                           |" << endl;
	cout << "|                                       |" << endl;
	cout << "|     2����ʾ��ױƷ                     |" << endl;
	cout << "|                                       |" << endl;
	cout << "|     3���޸�                           |" << endl;
	cout << "|                                       |" << endl;
	cout << "|     4��ɾ��                           |" << endl;
	cout << "|                                       |" << endl;
	cout << "|     0���˳�ϵͳ                       |" << endl;
	cout << "|                                       |" << endl;
	cout << "-----------------------------------------" << endl;
}

void CosmeticManager::showSonMenu() {
	cout << "-----------------------------------------" << endl;
	cout << "|                                       |" << endl;
	cout << "|     1�������۽�����ʾ���л�ױƷ       |" << endl;
	cout << "|                                       |" << endl;
	cout << "|     2����������ʾ��ױƷ               |" << endl;
	cout << "|                                       |" << endl;
	cout << "|     3����ʾ���л�ױƷ                 |" << endl;
	cout << "|                                       |" << endl;
	cout << "|     4����ʾ���۱����뵥�۸ߵĻ�ױƷ   |" << endl;
	cout << "|                                       |" << endl;
	cout << "|     5����Ʒ����ʾ��ױƷ               |" << endl;
	cout << "|                                       |" << endl;
	cout << "|     6����ʾ���                       |" << endl;
	cout << "|                                       |" << endl;
	cout << "|     0��������һ��                     |" << endl;
	cout << "-----------------------------------------" << endl;
}


void CosmeticManager::exitsystem() {
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}


