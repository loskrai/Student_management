//      dataDataSetK-Means demo02
/*
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<ctime>
#include<algorithm>
#include<math.h>

#define K 3
#define SIZE 4
#define EPOCH 50
#define threshold 0.01
#define OK 1
#define ERROR 0

using namespace std;

class dataset {
public:
	float flower[SIZE];          //�洢�β�����ĸ�����ֵ
	int ground;                  //�β������ʵ����
	int pred;                    //����������
	float distance[K];           //ÿ���������������ĵľ���
	void show() {
		cout << flower[0] << "\t" << flower[1] << "\t" << flower[2] << "\t"
			<< flower[3] << "\t" << ground << endl;
	}
};

class kmeans {
private:
	vector<dataset> Data;          //�β�����ݼ�
	float core[K][SIZE];           //K��������λ��
	float gap;                     //����һ�������ĵľ���
	float accuracy;                //��ȷ��

public:
	void readdata();
	void genstartcore();
	void gennewcore();
	int updatekmean();
	void count_acc();
	void show(int condition, int generation);
};

int get_truthvalue(string s) {

	string s1, s2, s3;
	s1 = "setosa";
	s2 = "versicolor";
	s3 = "virginica";
	if (s == s1) return 0;
	if (s == s2) return 1;
	if (s == s3) return 2;
	return -1;
}

void kmeans::readdata() {


	ifstream infile;
	float temp = 0;
	string s;
	int count = 0;
	dataset individual;

	infile.open("iris.txt");
	if (!infile.is_open()) {

		cout << "Open file failure" << endl;
	}

	while (infile.good() && !infile.eof()) {


		count++;

		if (count % (SIZE + 1) == 0) {

			infile >> s;
			individual.ground = get_truthvalue(s);
			Data.push_back(individual);
		}
		else {

			infile >> temp;
			individual.flower[count % (SIZE + 1) - 1] = temp;
		}
	}
	cout << "len=" << Data.size() << endl;
	infile.close();

}

void kmeans::genstartcore() {


	srand((int)time(NULL));
	size_t length = Data.size();
	int x, y, z;
	int i = 0;
	x = rand() % length;
	y = rand() % length;
	z = rand() % length;
	cout << "length=" << length << endl;
	for (i = 0; i < SIZE; i++) {

		core[0][i] = Data[x].flower[i];
	}
	for (i = 0; i < SIZE; i++) {

		core[1][i] = Data[y].flower[i];
	}
	for (i = 0; i < SIZE; i++) {

		core[2][i] = Data[z].flower[i];
	}

}

void kmeans::gennewcore() {


	size_t length = Data.size();
	int count1 = 0, count2 = 0, count3 = 0;
	int i, j, k;
	float cores[K][SIZE];
	for (k = 0; k != length; k++) {

		if (Data[k].pred == 0) {

			count1++;
			for (i = 0; i < SIZE; i++) {

				cores[0][i] += Data[k].flower[i];
			}
		}
		if (Data[k].pred == 1) {

			count2++;
			for (i = 0; i < SIZE; i++) {

				cores[1][i] += Data[k].flower[i];
			}
		}
		if (Data[k].pred == 2) {

			count3++;
			for (i = 0; i < SIZE; i++) {

				cores[2][i] += Data[k].flower[i];
			}
		}
	}
	for (i = 0; i < SIZE; i++) {

		cores[0][i] /= count1;
	}
	for (i = 0; i < SIZE; i++) {

		cores[1][i] /= count2;
	}
	for (i = 0; i < SIZE; i++) {

		cores[2][i] /= count3;
	}
	for (i = 0; i < K; i++) {

		for (j = 0; j < SIZE; j++) {

			gap = abs(cores[i][j] - core[i][j]);
			core[i][j] = cores[i][j];
		}
	}

	/*if(gap<threshold) return OK;       //��������ֹ����
	else return ERROR;
}

int kmeans::updatekmean() {


	int i, j, k;
	int count = 0;
	size_t length = Data.size();
	for (k = 0; k != length; k++) {
		//����ÿ�������������ĵľ��루ŷ�Ͼ��룩
		for (i = 0; i != K; i++) {

			for (j = 0; j < SIZE; j++) {

				//ŷʽ����
				Data[k].distance[i] += sqrt(
					(core[i][j] - Data[k].flower[j])
					* (core[i][j] - Data[k].flower[j]));
				//�����پ���
			/*  Data[k].distance[i] += abs(core[i][j]-Data[k].flower[j]);
			}
		}
		//Ѱ����С����
		float shortest = (Data[k].distance[0] < Data[k].distance[1])
			? Data[k].distance[0] : Data[k].distance[1];
		shortest = (shortest < Data[k].distance[2])
			? shortest : Data[k].distance[2];
		for (i = 0; i < K; i++) {

			if (Data[k].distance[i] == shortest) {

				if (Data[k].pred == i) count++;
				else Data[k].pred = i;
			}
		}
	}
	if (length == count) return OK;
	else return ERROR;

}

void kmeans::count_acc() {


	int i, j, success = 0;
	size_t length = Data.size();
	int flower[K][K] = { 0 };
	int key[K];

	for (i = 0; i != length; i++) {

		if (Data[i].ground == 0) {

			if (Data[i].pred == 0) flower[0][0]++;
			if (Data[i].pred == 1) flower[0][1]++;
			if (Data[i].pred == 2) flower[0][2]++;
		}
		else if (Data[i].ground == 1) {

			if (Data[i].pred == 0) flower[1][0]++;
			if (Data[i].pred == 1) flower[1][1]++;
			if (Data[i].pred == 2) flower[1][2]++;
		}
		else if (Data[i].ground == 2) {

			if (Data[i].pred == 0) flower[2][0]++;
			if (Data[i].pred == 1) flower[2][1]++;
			if (Data[i].pred == 2) flower[2][2]++;
		}
	}
	for (i = 0; i != K; i++) {

		if (flower[i][0] > flower[i][1] && flower[i][0] > flower[i][2])
			key[i] = 0;
		else if (flower[i][1] > flower[i][0] && flower[i][1] > flower[i][2])
			key[i] = 1;
		else if (flower[i][2] > flower[i][0] && flower[i][2] > flower[i][0])
			key[i] = 2;
	}

	for (j = 0; j != length; j++) {

		if (Data[j].pred == key[Data[j].ground]) success++;
	}
	accuracy = (float)success / length;

}

void kmeans::show(int condition, int generation) {


	size_t length = Data.size();
	int i, j;
	cout << "\t���೤\t�����\t���곤\t�����\t��ʵֵ\tԤ��ֵ\n";
	for (i = 140; i != length; i++) {

		for (j = 0; j != SIZE; j++) {

			cout << "\t" << Data[i].flower[j];
		}
		cout << "\t" << Data[i].ground << "\t" << Data[i].pred << endl;
	}

	if (condition == OK) {

		cout << "����Ԥ��!" << endl;
		cout << "������ " << generation + 1 << " ��." << endl;
		cout << "׼ȷ��: " << accuracy * 100 << "%\n\n\n";
	}
	if (condition == ERROR) {

		cout << "Not Convergence!" << endl;
		cout << "Sucess_rate: " << accuracy;
	}
}

int main() {


	kmeans clusters;
	int generation = 0, condition = 0;

	clusters.readdata();                          //��ȡ����
	clusters.genstartcore();                   //���ȡ������

	for (generation = 0; generation < EPOCH; generation++) {
		//����
		condition = clusters.updatekmean(); //���ݴ��������·ִ�
		clusters.gennewcore();                 //�����´ػ���µĴ�����
		clusters.count_acc();                  //����ɹ��ִصİٷֱ�
		if (condition == OK) break;             //����ز��ٸı�������ѭ��
	}
	clusters.show(condition, generation);          //��ʾ���
}*/