#include<iostream>
#include<string.h>
#include<math.h>
#define IN 99
#define N 5
using namespace std;

int dijkstra(int cost[][N],int source,int target)
{
	int dist[N],prev[N],selected[N]={0},i,m,min,start,d,j;
	char path[N];
	for(i=1;i<N;i++)
	{
		dist[i]=IN;
		prev[i]=-1;
	}
	start=source;
	selected[start]=1;
	dist[start]=0;
	while(selected[target]==0)
	{
		min=IN;
		m=0;
		for(i=1;i< N;i++)
		{
			d = dist[start] +cost[start][i];
			if(d<dist[i]&&selected[i]==0)
			{
				dist[i] = d;
				prev[i] = start;
			}
			if(min>dist[i] && selected[i]==0)
			{
				min = dist[i];
				m = i;
			}
		}
		start = m;
		selected[start] = 1;
	}
	start = target;
	j = 0;
	while(start != -1)
	{
		path[j++] = start+64;
		start = prev[start];
	}
	path[j]='\0';
	for(i=strlen(path)-1;i>0;i--)
		cout<<path[i]<<"--->";
	cout<<path[0];
	return dist[target];
}
int main()
{
	int cost[N][N],i,j,w,ch,co;
	int source, target,x,y;
	cout<<"\tShortest Path Algorithm using Dijkstra's Algorithm\n\n";
	for(i=1;i< N;i++)
		for(j=1;j< N;j++)
			cost[i][j] = IN;
	for(x=1;x< N;x++)
	{
		for(y=x+1;y< N;y++)
		{
			cout<<"Enter the weight of the path between node "<<char(x+64)<<" --> "<<char(y+64)<<":";
			cin>>w;
			cost [x][y] = cost[y][x] = w;
		}
		cout<<"\n";
	}
	cout<<"\nEnter The Source:";
	cin>>source;
	cout<<"\nEnter The target:";
	cin>>target;
	co = dijkstra(cost,source,target);
	cout<<"\nShortest Path is "<<co<<endl;
}

/*
OUTPUT:
Shortest Path Algorithm using Dijkstra's Algorithm

Enter the weight of the path between node A --> B:8
Enter the weight of the path between node A --> C:2
Enter the weight of the path between node A --> D:15

Enter the weight of the path between node B --> C:12
Enter the weight of the path between node B --> D:6

Enter the weight of the path between node C --> D:11



Enter The Source:1

Enter The target:4
A--->C--->D
Shortest Path is 13
*/
