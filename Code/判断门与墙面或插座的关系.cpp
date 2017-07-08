#include "headFile.h"
/******  一系列判断  ******/

// 求最小值
double Min( double a,double b)
{
	return a<b?a:b;
}
// 判断门在哪个墙面
int judge_d( Node d[] )
{
	if( d[0].y==0 && d[3].y==0 )	return 1;
	else if( d[0].x==0 && d[3].x==0 )	return 2;
	else if( d[0].x==len && d[3].x==len )	return 3;
	else if( d[0].y==wid && d[3].y==wid )	return 4;
}
// 判断两个同墙插座间连线是否穿门
bool judge_crossdoor( Node n1, Node n2 )
{
	// 如果插座在最下面，或者插座位置高于门的位置，则不穿过门（无论墙和插座位置关系如何）
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