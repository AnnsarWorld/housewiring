#include "headFile.h"
/******  求布线长度  ******/

// 求同墙两插座最短布线
double find_togcost( Node a,Node b )
{

	// 两插座同墙且不穿门
	if( !judge_crossdoor( a , b ) )
		return (fabs(a.x-b.x)+fabs(a.y-b.y)+fabs(a.z-b.z));
	else
	{
		// 两插座布线会穿过门，门的位置不同
		if( pos_door==1 || pos_door==4 )	return Min( (fabs(a.x-b.x)+fabs(door[3].z-a.z)+fabs(door[3].z-b.z) ),(fabs(a.x-b.x)+a.z+b.z) );
		else	return	Min( (fabs(a.y-b.y)+fabs(door[3].z-a.z)+fabs(door[3].z-b.z)),(fabs(a.y-b.y)+a.z+b.z) );
	}
}
// 求相对墙两插座最短布线
double find_acrcost( Node a,Node b )
{
	double cost1,cost2;
	Node temp1,temp2;
	// 插座在1,4面
	if( (a.y==0 && b.y==wid) || (b.y==0 && a.y==wid) )
	{
		// 根据门的位置，求权值
		if( pos_door==1 )	return	Min( Min( (a.y+fabs(door[3].z-a.z)+len+b.y),(a.y+a.z+len+b.y) ),Min( (wid-a.y+len+wid-b.y),(a.z+len+b.z) ) );
		else if( pos_door==2 ) //门处在第二面墙
		{
		    //利用中间节点，将问题转化为同墙连线问题
			temp1=temp2=a;
			temp1.y=0,temp2.y=wid;
			cost1=find_togcost(a,temp1);
			cost2=find_togcost(a,temp2);
			//分别计算通过走第二、三面墙的布线长度，并取最小值
			return	Min( (cost1+len+b.y),(cost2+len+wid-b.y) );
		}
		else if( pos_door==3 )//门处在第三面墙
		{
			//利用中间节点，将问题转化为同墙连线问题
			temp1=temp2=b;
			temp1.y=0,temp2.y=wid;
			cost1=find_togcost(b,temp1);
			cost2=find_togcost(b,temp2);
			//分别计算通过走第二、三面墙的布线长度，并取最小值
			return	Min( (cost1+len+a.y),(cost2+len+wid-a.y) );
		}
		else	return	Min( Min( (a.y+len+b.y),(wid-a.y+wid-b.y+fabs(door[3].z-a.z)+len) ), Min( (wid-a.y+wid-b.y+a.z+len),(a.z+b.z+len) ) );

	}
	else //插座在2,3面
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
// 求相邻墙两插座最短布线
double find_bescost( Node a , Node b )
{
	Node temp=a;
	// 在两平面连接处找一个点（让其中一点x,y为0即可），转化为两个 同墙插座 问题
	if( (a.x==0 && b.y==0) || (b.x==0 && a.y==0) ) //第一、二面墙相邻
	{
		temp.x=temp.y=0;
		return ( find_togcost(a,temp)+find_togcost(b,temp) );
	}
	else if( (a.x==len && b.y==0) || (a.y==0 && b.x==len) ) //第一、三面墙相邻
	{
		temp.x=len,temp.y=0;
		return ( find_togcost(a,temp)+find_togcost(b,temp) );
	}
	else if( (a.x==0 && b.y==wid) || (b.x==0 && a.y==wid) ) //第二、四面墙相邻
	{
		temp.x=0,temp.y=wid;
		return ( find_togcost(a,temp)+find_togcost(b,temp) );
	}
	else //第三、四面墙相邻
	{
		temp.x=len,temp.y=wid;
		return ( find_togcost(a,temp)+find_togcost(b,temp) );
	}
}