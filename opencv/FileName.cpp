//��Ҫ���Ż������������ݼ�
//����������ʹ��ȷ���½�
//���ɴ˵õ��Ľ�������ձ���

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
    string s1 = "setosa", s2 = "versicolor", s3 = "virginica";
    if (s == s1) return 0;
    if (s == s2) return 1;
    if (s == s3) return 2;
    return -1;
}

void kmeans::readdata() {
    ifstream infile("iris.txt");
    if (!infile.is_open()) {
        cout << "Open file failure" << endl;
        return;
    }
    float temp;
    string s;
    int count = 0;
    dataset individual;
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
    if (length < K) {
        cout << "K������" << endl;
        return;
    }
    vector<int> indices(length);
    for (int i = 0; i < length; ++i) indices[i] = i;
    random_shuffle(indices.begin(), indices.end());
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            core[i][j] = Data[indices[i]].flower[j];
        }
    }
}

void kmeans::gennewcore() {
    size_t length = Data.size();
    float cores[K][SIZE] = { 0 };
    int counts[K] = { 0 };
    for (size_t k = 0; k < length; ++k) {
        counts[Data[k].pred]++;
        for (int i = 0; i < SIZE; ++i) {
            cores[Data[k].pred][i] += Data[k].flower[i];
        }
    }
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            core[i][j] = cores[i][j] / counts[i];
        }
    }
}

int kmeans::updatekmean() {
    size_t length = Data.size();
    int count = 0;
    for (size_t k = 0; k < length; ++k) {
        fill(Data[k].distance, Data[k].distance + K, 0); //�������
        for (int i = 0; i < K; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                Data[k].distance[i] += sqrt(pow(core[i][j] - Data[k].flower[j], 2));
            }
        }
        float shortest = *min_element(Data[k].distance, Data[k].distance + K);
        for (int i = 0; i < K; ++i) {
            if (Data[k].distance[i] == shortest) {
                if (Data[k].pred == i) count++;
                else Data[k].pred = i;
            }
        }
    }
    return (length == count) ? OK : ERROR;
}

void kmeans::count_acc() {
    size_t length = Data.size();
    int flower[K][K] = { 0 };
    int key[K];
    int success = 0;
    for (size_t i = 0; i < length; ++i) {
        if (Data[i].ground == 0) flower[0][Data[i].pred]++;
        else if (Data[i].ground == 1) flower[1][Data[i].pred]++;
        else if (Data[i].ground == 2) flower[2][Data[i].pred]++;
    }
    for (int i = 0; i < K; ++i) {
        key[i] = distance(flower[i], max_element(flower[i], flower[i] + K));
    }
    for (size_t j = 0; j < length; ++j) {
        if (Data[j].pred == key[Data[j].ground]) success++;
    }
    accuracy = (float)success / length;
}

void kmeans::show(int condition, int generation) {
    size_t length = Data.size();
    cout << "\t���೤\t�����\t���곤\t�����\t��ʵֵ\tԤ��ֵ\n";
    for (size_t i = 0; i < length; ++i) {
        for (int j = 0; j < SIZE; ++j) {
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
    clusters.readdata();
    clusters.genstartcore();
    for (generation = 0; generation < EPOCH; generation++) {
        condition = clusters.updatekmean();
        clusters.gennewcore();
        clusters.count_acc();
        if (condition == OK) break;
    }
    clusters.show(condition, generation);
    return 0;
}
