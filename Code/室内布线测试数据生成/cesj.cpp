#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <windows.h>

struct Node
{
	int x,y,z;
}nd[21],door[4];
int len,wid,hei,pos_door;

// 判断门在哪个墙面
int judge_d( Node d[] )
{
	if( d[0].y==0 && d[3].y==0 )	return 1;
	else if( d[0].x==0 && d[3].x==0 )	return 2;
	else if( d[0].x==len && d[3].x==len )	return 3;
	else if( d[0].y==wid && d[3].y==wid )	return 4;
}

// 是否在同一墙面
bool isTogether( Node a , Node b )
{
	if( (a.x==b.x && (a.x==0||a.x==len) ) || (a.y==b.y && (a.y==0||a.y==wid) ) )	return true;
	return false;
}


// 判断两个同墙插座间连线是否穿门
bool judge_ondoor( Node b) //a为门，b为插座
{
if (!isTogether(door[3],b)) return false;
int pos_door=judge_d( door );
	if( pos_door==1 || pos_door==4)
	{
		if( door[0].x<b.x<door[3].x && door[0].z<b.z<door[3].z )	return true;
		return false;
	}
	else if( pos_door==2 || pos_door==3)
	{
		if( door[0].y<b.y<door[3].y && door[0].z<b.z<door[3].z )	return true;
		return false;
	}

}


int main()
{
	int i,a,b,n,k;
    freopen("in.txt","w",stdout);
    srand((int)time(NULL)); //刷新随机数种子
    for(int t=0;t<50;t++) //t为产生的测试用数据的组数
    {
        Sleep(500); //间隔500ms以保证有足够的时间产生随机数所需要的seed
        a = 5;
        b = 21;              //n的范围： [a,b-1]
        //生成长宽高数据
        len = a+rand()%(b-a);      //生成[a,b-1]
        wid = a+rand()%(b-a);      //生成[a,b-1]
        hei = a+rand()%(b-a);      //生成[a,b-1]
        printf("%d %d %d ",len,wid,hei);
        srand((int)time(NULL)); //刷新随机数种子
        //因为门是长方形，所以只需要生成对角的两个坐标，但对角必须在同一象限
            door[0].x =  rand()%len;
            door[0].y =  rand()%wid;
            door[0].z =  1+rand()%(hei-1);
            door[3].x =  rand()%len;
            door[3].y =  rand()%wid;
            door[3].z =  1+rand()%(hei-1);
            while(!( (door[0].x==door[3].x && (door[0].x==0||door[0].x==len) ) || (door[0].y==door[3].y && (door[0].y==0||door[0].y==wid) ) ))
            {
                door[0].x =  rand()%len;
                door[0].y =  rand()%wid;
                door[0].z =  1+rand()%(hei-1);
                door[3].x =  rand()%len;
                door[3].y =  rand()%wid;
                door[3].z =  1+rand()%(hei-1);
            }
            door[1].x =  door[0].x;
            door[1].y =  door[0].y;
            door[1].z =  door[3].z;
            door[2].x =  door[3].x;
            door[2].y =  door[3].y;
            door[2].z =  door[0].z;
        //生成插座个数
        a = 2;
        b = 20;
        int num;
        num = a+rand()%(b-a);      //生成[a,b-1]
        printf("%d\n",num); //输出插座个数
        srand((int)time(NULL));
        n=num;
        while(n--)
        {
            //以下三行代码用以生成浮点型随机数，精度为1位小数
            float x =  rand()%(len*10)/10.0;
            float y =  rand()%(wid*10)/10.0;
            float z =  (1+rand()%(hei-1))*10/10.0;
            //以下三行代码用以生成整数型随机数
            //int x =  rand()%len;
           //int y =  rand()%wid;      //生成[a,b-1]
            //int z =  1+rand()%(hei-1);      //生成[a,b-1]
            nd[0].x=x;
            nd[0].y=y;
            nd[0].z=z;
            while(judge_ondoor(nd[0])) //保证插座不在门上
            {
            float x =  rand()%(len*10)/10.0;
            float y =  rand()%(wid*10)/10.0;      //生成[a,b-1]
            float z =  (1+rand()%(hei-1))*10/10.0;      //生成[a,b-1]
            //int x =  rand()%len;
            //int y =  rand()%wid;      //生成[a,b-1]
            //int z =  1+rand()%(hei-1);      //生成[a,b-1]
            nd[0].x=x;
            nd[0].y=y;
            nd[0].z=z;
            }
            printf("%.1f %.1f %.1f\n",x,y,z);
            //printf("%d %d %d\n",x,y,z);
        }
        for(i=0;i<3;i++)
        {
            printf("%d %d %d ",door[i].x,door[i].y,door[i].z);
        }
            printf("%d %d %d\n",door[3].x,door[3].y,door[3].z);
    }
    printf("0 0 0 0\n");

	return 0;
}
