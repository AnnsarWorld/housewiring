#include "headFile.h"
/******  ���߳���  ******/

// ��ͬǽ��������̲���
double find_togcost( Node a,Node b )
{

	// ������ͬǽ�Ҳ�����
	if( !judge_crossdoor( a , b ) )
		return (fabs(a.x-b.x)+fabs(a.y-b.y)+fabs(a.z-b.z));
	else
	{
		// ���������߻ᴩ���ţ��ŵ�λ�ò�ͬ
		if( pos_door==1 || pos_door==4 )	return Min( (fabs(a.x-b.x)+fabs(door[3].z-a.z)+fabs(door[3].z-b.z) ),(fabs(a.x-b.x)+a.z+b.z) );
		else	return	Min( (fabs(a.y-b.y)+fabs(door[3].z-a.z)+fabs(door[3].z-b.z)),(fabs(a.y-b.y)+a.z+b.z) );
	}
}
// �����ǽ��������̲���
double find_acrcost( Node a,Node b )
{
	double cost1,cost2;
	Node temp1,temp2;
	// ������1,4��
	if( (a.y==0 && b.y==wid) || (b.y==0 && a.y==wid) )
	{
		// �����ŵ�λ�ã���Ȩֵ
		if( pos_door==1 )	return	Min( Min( (a.y+fabs(door[3].z-a.z)+len+b.y),(a.y+a.z+len+b.y) ),Min( (wid-a.y+len+wid-b.y),(a.z+len+b.z) ) );
		else if( pos_door==2 ) //�Ŵ��ڵڶ���ǽ
		{
		    //�����м�ڵ㣬������ת��Ϊͬǽ��������
			temp1=temp2=a;
			temp1.y=0,temp2.y=wid;
			cost1=find_togcost(a,temp1);
			cost2=find_togcost(a,temp2);
			//�ֱ����ͨ���ߵڶ�������ǽ�Ĳ��߳��ȣ���ȡ��Сֵ
			return	Min( (cost1+len+b.y),(cost2+len+wid-b.y) );
		}
		else if( pos_door==3 )//�Ŵ��ڵ�����ǽ
		{
			//�����м�ڵ㣬������ת��Ϊͬǽ��������
			temp1=temp2=b;
			temp1.y=0,temp2.y=wid;
			cost1=find_togcost(b,temp1);
			cost2=find_togcost(b,temp2);
			//�ֱ����ͨ���ߵڶ�������ǽ�Ĳ��߳��ȣ���ȡ��Сֵ
			return	Min( (cost1+len+a.y),(cost2+len+wid-a.y) );
		}
		else	return	Min( Min( (a.y+len+b.y),(wid-a.y+wid-b.y+fabs(door[3].z-a.z)+len) ), Min( (wid-a.y+wid-b.y+a.z+len),(a.z+b.z+len) ) );

	}
	else //������2,3��
	{
		if( pos_door==1 )
		{
			temp1=temp2=a;
			temp1.x=0,temp2.x=len;
			cost1=find_togcost(a,temp1);
			cost2=find_togcost(a,temp2);
			return	Min( (cost1+wid+b.x),(cost2+wid+len-b.x) );
		}
		else if( pos_door==2 )	return Min( Min( (a.x+b.x+wid+fabs(door[3].z-a.z)),(a.x+b.x+wid+a.z) ),Min( (len-a.x+len-b.x+wid),(a.z+b.z+wid) ) );
		else if( pos_door==4 )
		{
			temp1=temp2=b;
			temp1.x=0,temp2.x=len;
			cost1=find_togcost(b,temp1);
			cost2=find_togcost(b,temp2);
			return Min( (cost1+wid+a.x),(cost2+wid+len-a.x) );
		}
		else return Min( Min( (a.x+b.x+wid),(a.z+b.z+wid) ),Min( (len-a.x+len-b.x+fabs(door[3].z-a.z)+wid),(len-a.x+len-b.x+a.z+wid) ) );
	}
}
// ������ǽ��������̲���
double find_bescost( Node a , Node b )
{
	Node temp=a;
	// ����ƽ�����Ӵ���һ���㣨������һ��x,yΪ0���ɣ���ת��Ϊ���� ͬǽ���� ����
	if( (a.x==0 && b.y==0) || (b.x==0 && a.y==0) ) //��һ������ǽ����
	{
		temp.x=temp.y=0;
		return ( find_togcost(a,temp)+find_togcost(b,temp) );
	}
	else if( (a.x==len && b.y==0) || (a.y==0 && b.x==len) ) //��һ������ǽ����
	{
		temp.x=len,temp.y=0;
		return ( find_togcost(a,temp)+find_togcost(b,temp) );
	}
	else if( (a.x==0 && b.y==wid) || (b.x==0 && a.y==wid) ) //�ڶ�������ǽ����
	{
		temp.x=0,temp.y=wid;
		return ( find_togcost(a,temp)+find_togcost(b,temp) );
	}
	else //����������ǽ����
	{
		temp.x=len,temp.y=wid;
		return ( find_togcost(a,temp)+find_togcost(b,temp) );
	}
}