#include "headFile.h"
/******  һϵ���ж�  ******/

// ����Сֵ
double Min( double a,double b)
{
	return a<b?a:b;
}
// �ж������ĸ�ǽ��
int judge_d( Node d[] )
{
	if( d[0].y==0 && d[3].y==0 )	return 1;
	else if( d[0].x==0 && d[3].x==0 )	return 2;
	else if( d[0].x==len && d[3].x==len )	return 3;
	else if( d[0].y==wid && d[3].y==wid )	return 4;
}
// �ж�����ͬǽ�����������Ƿ���
bool judge_crossdoor( Node n1, Node n2 )
{
	// ��������������棬���߲���λ�ø����ŵ�λ�ã��򲻴����ţ�����ǽ�Ͳ���λ�ù�ϵ��Σ�
	if( n1.z==0 || n2.z==0 || n1.z>=door[3].z || n2.z>=door[3].z )	return false;
	if( pos_door==1 )
	{
		if( n1.y!=0 && n2.y!=0 )	return false;
		if( (n1.x>=door[3].x && n2.x>=door[3].x) || (n1.x<=door[0].x && n2.x<=door[0].x) )	return false;
		return true;
	}
	else if( pos_door==2 )
	{
		if( n1.x!=0 && n2.x!=0 )	return false;
		if( (n1.y<=door[0].y && n2.y<=door[0].y) || (n1.y>=door[3].y && n2.y>=door[3].y) )	return false;
		return true;
	}
	else if( pos_door==3 )
	{
		if( n1.x!=len && n2.y!=len )	return false;
		if( (n1.y<=door[0].y && n2.y<=door[0].y) || (n1.y>=door[3].y && n2.y>=door[3].y) )	return false;
		return true;
	}
	else
	{
		if( n1.y!=wid && n2.y!=wid )	return false;
		if( (n1.x>=door[3].x && n2.x>=door[3].x) || (n1.x<=door[0].x && n2.x<=door[0].x) )	return false;
		return true;
	}
}