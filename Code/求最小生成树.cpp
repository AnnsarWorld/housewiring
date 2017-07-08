#include "headFile.h"
/******  ����С������(Kruscal)  ******/

// �ȽϺ���
bool cmp(Edge e1,Edge e2)
{
    return e1.quan<e2.quan;
}
// ���鼯 ��ʼ������
void Init( int m )
{
    int i;
    for(i=1;i<=m;i++)
        father[i]=i;
}
// ���鼯 ���Һ���
int Find(int x)
{
    while(father[x]!=x)
        x=father[x];
    return x;
}
// ���鼯 �ϲ�����
void Combine(int a,int b)
{
    int temp_a,temp_b;
    temp_a=Find(a);
    temp_b=Find(b);

    if(temp_a!=temp_b)
        father[temp_a]=temp_b;
}
// ��С������ Kruskal �㷨
double Kruskal( int n )
{
    Edge e;
    int i;
	double res;
    sort(eg,eg+n,cmp);
    // ���鼯 ��ʼ��
    Init(N);

    // ������С������
    res=0;
    for( i=0;i<n;++i )
    {
        e=eg[i];
        if( Find(e.u)!=Find(e.v) )
        {
            Combine(e.u,e.v);
            res+=e.quan;
        }
    }
    return res;
}