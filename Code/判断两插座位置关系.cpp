#include "headFile.h"

/******  �ж�������λ�ù�ϵ  ******/
Node nd[21];
Node door[4];
Edge eg[MAX];
int N,len,wid,hei,pos_door;
int father[21];
// �Ƿ���ͬһǽ��
bool isTogether( Node a , Node b )
{
	if( (a.x==b.x && (a.x==0||a.x==len) ) || (a.y==b.y && (a.y==0||a.y==wid) ) )	return true;
	return false;
}


// �ж��Ƿ�������ǽ��
bool isBeside( Node a , Node b )
{
	if( a.x==0 || a.x==len )
	{
		if( b.y==0 || b.y==wid )
			return true;
		else
			return false;
	}
	else if( a.y==0 || a.y==wid )
	{
		if( b.x==0 || b.x==len )
			return true;
		else
			return false;
	}
}


// �Ƿ������ǽ��
bool isAcross( Node a , Node b )
{
	if( (a.x==0 && b.x==len) || (a.y==0 && b.y==wid) || (a.x==len && b.x==0) || (a.y==wid && b.y==0) )
		return true;
	else
		return false;
}







