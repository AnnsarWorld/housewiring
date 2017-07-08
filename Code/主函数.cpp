#include "headFile.h"

/****** ������ ******/
extern Node nd[21];
extern Node door[4];
extern Edge eg[MAX];
extern int N,len,wid,hei,pos_door;
extern int father[21];
int main()
{
	//freopen("in.txt", "r", stdin);
     //freopen("out.txt", "w", stdout);
	// i,j Ϊ�м������kΪ�ߵĸ���
	int i,j,k;
	printf("�����뷿��ĳ������ߺͲ����ĸ���N��NΪһ��������20����������������\n��������Ϊ4��0����0 0 0 0�������˳�����");
	while( cin>>len>>wid>>hei>>N )
	{
		// ��������Ϊ4��0�����˳�����
		if( !len && !wid && !hei && !N )	break;

		// ��ȡ���ݣ��������ŵ�λ�ã�
		for( i=0 ; i<N ; ++i )
		{
			printf("�������%d��������λ�����ݣ�",i+1);
			cin>>nd[i].x>>nd[i].y>>nd[i].z;
		}
		for( i=0 ; i<4 ; ++i )
		{
			printf("�������ſ��%d�����λ�����ݣ�",i+1);
			cin>>door[i].x>>door[i].y>>door[i].z;
		}
		pos_door=judge_d( door );

		/* ���������루ע�⣬����Ҫ��ǽƽ�У� */
		k=0;
		for( i=0 ; i<N ; ++i )
		{
			for( j=i+1; j<N ; ++j )
			{
				eg[k].u=i;
				eg[k].v=j;
				// �ж������ϵ��ͬǽor����ǽor���ǽ

				// ͬǽ
				if( isTogether( nd[i] , nd[j] ) )	eg[k].quan=find_togcost(nd[i],nd[j]);
				// ���ǽ
				else if( isAcross( nd[i] , nd[j] ) )	eg[k].quan=find_acrcost(nd[i],nd[j]);
				// ����ǽ
				else	eg[k].quan=find_bescost(nd[i],nd[j]);
				++k;
			}
		}

		/* ��Kruscal�㷨����С������ */
		// ע��������۳�����Σ���Ҫ����ȡ��
		double cost;
		cost=Kruskal(k);
		if( cost-int(cost)==0 )	cout<<cost<<endl;
		else	cout<<int(cost+1)<<endl;
	}
	return 0;
}
