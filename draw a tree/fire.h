//#pragma once
#ifndef  FIREWORKS_H_
#define FIREWORKS_H_
#define myrand(m) ((float)rand() * m / 36565)
#include<graphics.h>
#include<conio.h>
#include<Windows.h>
#include<mmsystem.h>

#pragma comment(lib,"winmm.lib")

struct Speed {
	double x, y;
};

struct Pos {
	double x, y;
};

struct Particle
{
	Pos pos;
	Speed speed;
};


#define GROUND 700	//����λ��
class Fireworks//�̻���			
{
private:

	static const int NUM_PARTICLE = 200;
	static const double particleSpeed;
	Particle p[NUM_PARTICLE];

	color_t color;

	int delayTime;		//�ӳ�ʱ��
	int riseTime;		//����ʱ��
	int bloomTime;		//��ըʱ��

	Pos risePos;		//�����׶�λ��
	Speed riseSpeed;	//�����ٶ�

public:
	//��ʼ��
	Fireworks();
	void init();
	//����λ�õ��������
	void update();
	//��������ֵ�滭
	void draw(PIMAGE pimg = NULL);
};

#endif // ! FIREWORKS_H_
#pragma once
