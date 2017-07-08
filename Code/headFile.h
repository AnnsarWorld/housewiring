#ifndef H_STUDENT_HH  //如果没有定义H_STUDENT_HH,继续执行
#define H_STUDENT_HH//定义H_STUDENT_HH,可避免重复编绎
#include <iostream>
#include <algorithm>
#include <math.h>
#include<cstdio>
#include<cstring>
using namespace std;


/******  一些相关变量的定义 ******/

// 插座个数，最多为20个，所以，边最多只有400个
#define MAX 401
// 点的结构体
typedef	struct Node
{
	double x,y,z;
};
extern Node nd[21];
extern Node door[4];
// 含权值的边的结构体
typedef	struct Edge
{
	int u;
	int v;
	double quan;
};
extern Edge eg[MAX];
// N - 插座个数，len,wid,hei - 房间的长、宽、高，pos_door门所在位置
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