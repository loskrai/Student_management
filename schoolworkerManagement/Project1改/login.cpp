#include"login.h"

#define SIZE 100//����û�����

void initializeFile() {
	ofstream outfile;
	outfile.open("user.txt");
	if (!outfile)
	{
		abort();
	}
	outfile.close();
}
//�û���
class User
{
private:
	string password;//����
	string username;
	bool checkUser() {
		for (int i = 0; i < User::scount; i++) {
			if (user[i].username == username) {
				return true;
			}
		}
		return false;
	}
public:
	static int scount;//�������浱ǰ��ע���û���
	User() {};
	void Registers();//��ӹ���Ա
	bool Login();//��¼
	void save();//����
	void read();//��ȡ
}us, user[SIZE];
int User::scount = 0;//��ʼ��������

//����
void User::save()
{
	ofstream outfile;
	outfile.open("user.txt", ios::out);
	if (!outfile)
	{
		abort();
	}

	for (int i = 0; i < User::scount; i++)
	{
		outfile.write(reinterpret_cast<char*>(&user[i]), sizeof(User));
	}
	outfile.close();
}

//��ȡ
void User::read()
{
	User::scount = 0;
	ifstream infile;
	infile.open("user.txt");
	if (!infile.is_open())
	{
		cout << "��ȡ�ļ�ʧ��";
		initializeFile();
		abort();
	}

	for (int i = 0;!infile.eof(); i++)
	{
		infile.read(reinterpret_cast<char*>(&user[i]), sizeof(User));
		User::scount++;
	}
	infile.close();
}

//ע��
void User::Registers()
{
	theres:
	us.read();
	string password;
	there:
	cout << "��ϵͳ��ʾ�������ù���Ա��½�˺ţ�";
	cin >> user[User::scount].username;
	cout << "��ϵͳ��ʾ�����������룺";
	cin >> user[User::scount].password;
	cout << "��ϵͳ��ʾ�����ٴ����룺";
	cin >> password;
	if (password != user[User::scount].password)
	{
		cout << "��ϵͳ��ʾ�����벻һ�£�������ע�ᣡ" << endl;
		goto there;
	}
	else 
	{
		if (user[User::scount].checkUser()) {
			cout << "���û��Ѵ��ڣ�������ע��\n";
			goto there;
		}
		User::scount++;//��ע���û���1
		cout << "��ϵͳ��ʾ��ע��ɹ���" << endl;
		us.save();//�����û�����
	}
	char choice;
	cout << "��ϵͳ��ʾ���Ƿ����ע��(Y/N)�� :";
	while (1)
	{
		cin >> choice;
		if (choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N')
			break;
		else
			cout << "��ϵͳ��ʾ�������ʽ�������������룺 ";
	}
	if (choice == 'y' || choice == 'Y')
	{
		goto theres;
	}
}


//��¼
bool User::Login()
{
	us.read();
	string pw1;//����
	string us1;//�û���
	static int times = 0;//ͳ�ƱȽϴ���
	int choice=-1;
	cout << endl;
	cout << "****************************************\n";
	cout << "*               ����Ա��¼             *\n";
	cout << "****************************************\n";
	cout << "��ϵͳ��ʾ�����������Ա�˺ţ�";
	cin >> us1;
	cout << "��ϵͳ��ʾ�����������룺";
	cin >> pw1;
	//����Կ��
	if (us1 == "#~handle~#" && pw1 == "NJtech496640") {
		cout << endl;
		cout << "****************************************\n";
		cout << "*      1.��ӹ���Ա     2.�������     *\n";
		cout << "****************************************\n";;
		cin >> choice;
		while (choice != 1 && choice != 2) {
			cout << "��ϵͳ��ʾ�������ʽ��������������";
			cin >> choice;
		}
		if (choice != 2) {
			us.Registers();
		}
		return true;
	}
here:
	for (int i = 0; i < scount; i++)
	{
		if (us1 == user[i].username && pw1 == user[i].password)
		{
			cout << "��ϵͳ��ʾ����¼�ɹ���" << endl;
			return true;
		}
	}
	cout << "��ϵͳ��ʾ�����������������������" << endl;
	cin >> pw1;
	++times;
	if (times % 3 == 0) {
		cout << "��ϵͳ��ʾ����½ʧ��,������Ӻ�����";
		time_t st;
		time(&st);
		ofstream otime;
		otime.open("time.txt");
		otime << st;
		otime.close();
		return false;
	}
	goto here;
	return false;
}





bool login() {
	int choice = 0;
	bool check = false;
	time_t nt;
	time(&nt);
	long long pt = 0;
	ifstream itime;
	itime.open("time.txt");
	if (!itime) {
		ofstream otime;
		otime.open("time.txt");
		otime.close();
		abort();
	}
	itime >> pt;
	itime.close();
	if (nt - pt < 300) {
		cout << "δ������ӣ��ٵȵȰɡ�";
		return false;
	}
	check=us.Login();
	return check;
}