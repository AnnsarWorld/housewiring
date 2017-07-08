#ifndef H_STUDENT_HH  //���û�ж���H_STUDENT_HH,����ִ��
#define H_STUDENT_HH//����H_STUDENT_HH,�ɱ����ظ�����
#include <iostream>
#include <algorithm>
#include <math.h>
#include<cstdio>
#include<cstring>
using namespace std;


/******  һЩ��ر����Ķ��� ******/

// �������������Ϊ20�������ԣ������ֻ��400��
#define MAX 401
// ��Ľṹ��
typedef	struct Node
{
	double x,y,z;
};
extern Node nd[21];
extern Node door[4];
// ��Ȩֵ�ıߵĽṹ��
typedef	struct Edge
{
	int u;
	int v;
	double quan;
};
extern Edge eg[MAX];
// N - ����������len,wid,hei - ����ĳ������ߣ�pos_door������λ��
extern int N,len,wid,hei,pos_door;
extern int father[21];

bool isTogether( Node a , Node b );
bool isBeside( Node a , Node b );
bool isAcross( Node a , Node b );
double Min( double a,double b);
int judge_d( Node d[] );
bool judge_crossdoor( Node n1, Node n2 );
double find_togcost( Node a,Node b );
double find_acrcost( Node a,Node b );
double find_bescost( Node a , Node b );
bool cmp(Edge e1,Edge e2);
void Init( int m );
int Find(int x);
void Combine(int a,int b);
double Kruskal( int n );


#endif // H_STUDENT_HH