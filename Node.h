#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct 
{
	char Start;
	char Finish;
}Path;

typedef struct
{
	char From;
	char to;
	int cost;
}Edges;

typedef struct 
{
	int x;
	int y;
	char id;
	int numPaths;
	Edges * paths;
}Node;
Node createNode(char * line)
{
	Node newNode; 
	char id;
	int step = 0;
	char num[10]
	int idLength = 0
	int i = 0;
	int bool = 0;
	for(i = 0; i < 5; i++)
	{
		if(isdigit(line[i]))
		{
			num[step] = line[i];
		}
		else if(isblank(line[i]))
		{
			if(bool == 0)
			{

			}
			else if(bool == 1)
			{

			}
		}
		else
		{

		}
	}

	return newNode;
};

Node * addEdges(char * line,int NodeNum, Node * nodes)
{
	Edges newPath; 
	int i = 0;
	for(i = 0; i < 5; i+=2)
	{
		if(i == 0)
		{
			newPath.From = line[i];
		}
		else if(i == 2)
		{
			newPath.to = line[i];
		}
		else if(i == 4)
		{
			newPath.cost = atoi(&line[i]);
		}
	}
	for(i = 0; i < NodeNum; i+=2)
	{
		if( nodes[i].id == newPath.From)
		{
			int paths = 1;
			
			paths = paths + nodes[i].numPaths;
			Edges edgeArr[paths];
			int j = 0;
			for(j = 0; j < nodes[i].numPaths; j++)
			{
				 edgeArr[j] = nodes[i].paths[j];
			}
			edgeArr[paths-1] = newPath;

			nodes[i].numPaths++;
			
			nodes[i].paths = edgeArr;
		}
	}
	return  nodes;
};
Path createPath(char * line)
{
	Path newPath;
	int i = 0;
	for(i = 0; i < 3; i=2)
	{
		if(i == 0)
		{
			newPath.Start = line[i];
		}
		else if(i == 2)
		{
			newPath.Finish = line[i];
		}
		
	}
}
void loadFile()
{
	char line[100];
	char mode[100];
	int number = 0;
	int step = 0;
	Path * paths;
	int totalpaths = 0;
	Node * nodes;
	FILE* data = fopen("test.txt", "rt");
	while(fgets(line, 100, data) != NULL)
	{
		if(strncmp(line, "NODES", 5) == 0 ||  strncmp(line, "EDGES", 5) == 0 || strncmp(line, "PATHS", 5) == 0 )
		{
			 strcpy(mode, line);
		}
		else if(strncmp(mode, "NODES", 5) ==0)
		{
			nodes[step] = createNode(line);
			step++;
		}
		else if(strncmp(mode, "EDGES", 5) == 0)
		{
			nodes = addEdges(line,step,nodes);
		}
		else if(strncmp(mode, "PATHS", 5) == 0)
		{
			
			Path pathArr[totalpaths+1];
			Path newPath = createPath(line);
			int j = 0;
			for(j = 0; j < totalpaths; j++)
			{
				 pathArr[j] = paths[j];
			}
			totalpaths++;
			pathArr[totalpaths] = newPath;
			paths =  pathArr;
		}
		else if(number == 0)
		{
			number = atoi(&line[0]);
			Node temp[number];
			nodes = temp;
		}
	}
	
};
