#include "headFile.h"
/******  求最小生成树(Kruscal)  ******/

// 比较函数
bool cmp(Edge e1,Edge e2)
{
    return e1.quan<e2.quan;
}
// 并查集 初始化函数
void Init( int m )
{
    int i;
    for(i=1;i<=m;i++)
        father[i]=i;
}
// 并查集 查找函数
int Find(int x)
{
    while(father[x]!=x)
        x=father[x];
    return x;
}
// 并查集 合并函数
void Combine(int a,int b)
{
    int temp_a,temp_b;
    temp_a=Find(a);
    temp_b=Find(b);

    if(temp_a!=temp_b)
        father[temp_a]=temp_b;
}
// 最小生成树 Kruskal 算法
double Kruskal( int n )
{
    Edge e;
    int i;
	double res;
    sort(eg,eg+n,cmp);
    // 并查集 初始化
    Init(N);

    // 构建最小生成树
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