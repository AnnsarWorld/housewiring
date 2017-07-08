#include "headFile.h"

/****** 主函数 ******/
extern Node nd[21];
extern Node door[4];
extern Edge eg[MAX];
extern int N,len,wid,hei,pos_door;
extern int father[21];
int main()
{
	//freopen("in.txt", "r", stdin);
     //freopen("out.txt", "w", stdout);
	// i,j 为中间变量，k为边的个数
	int i,j,k;
	printf("请输入房间的长、宽、高和插座的个数N（N为一个不超过20的正整数）的数据\n输入数据为4个0：“0 0 0 0”，则退出程序：");
	while( cin>>len>>wid>>hei>>N )
	{
		// 输入数据为4个0，则退出程序
		if( !len && !wid && !hei && !N )	break;

		// 获取数据（插座与门的位置）
		for( i=0 ; i<N ; ++i )
		{
			printf("请输入第%d个插座的位置数据：",i+1);
			cin>>nd[i].x>>nd[i].y>>nd[i].z;
		}
		for( i=0 ; i<4 ; ++i )
		{
			printf("请输入门框第%d个点的位置数据：",i+1);
			cin>>door[i].x>>door[i].y>>door[i].z;
		}
		pos_door=judge_d( door );

		/* 求两点间距离（注意，布线要与墙平行） */
		k=0;
		for( i=0 ; i<N ; ++i )
		{
			for( j=i+1; j<N ; ++j )
			{
				eg[k].u=i;
				eg[k].v=j;
				// 判断两点关系，同墙or相邻墙or相对墙

				// 同墙
				if( isTogether( nd[i] , nd[j] ) )	eg[k].quan=find_togcost(nd[i],nd[j]);
				// 相对墙
				else if( isAcross( nd[i] , nd[j] ) )	eg[k].quan=find_acrcost(nd[i],nd[j]);
				// 相邻墙
				else	eg[k].quan=find_bescost(nd[i],nd[j]);
				++k;
			}
		}

		/* 用Kruscal算法求最小生成树 */
		// 注意最后，无论长度如何，都要向上取整
		double cost;
		cost=Kruskal(k);
		if( cost-int(cost)==0 )	cout<<cost<<endl;
		else	cout<<int(cost+1)<<endl;
	}
	return 0;
}
