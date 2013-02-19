#include <stdio.h> 
#include <stdlib.h>
#include <conio.h>  
#include <dos.h>
struct Path
{
	char Start;
	char Finish;
};
struct Edges
{
	char From;
	char to;
	int cost;
};
struct Node
{
	int x = 0;
	int y = 0;
	char id = ""[0];
	int numPaths = 0;;
	Edges * paths;
};

void loadFile()
{
	char line[5];
	char mode[5];
	int number = 0;
	int step = 0;
	struct Path * paths;
	int totalpaths = 0;
	struct Node * nodes;
	FILE* data = fopen("test.txt", "rt");
	STEP s;
	while(fgets(line, 5, data) != NULL)
	{

		if(line == "NODES" || line == "EDGES" || line == "EDGES" )
		{
			mode = line;
		}
		else if(mode == "NODES")
		{
			nodes[step] = createNode(line);
			step++;
		}
		else if(mode == "EDGES")
		{
			nodes = addEdges(line,step,nodes);
		}
		else if(mode == "PATHS")
		{
			
			struct Path pathArr[totalpaths+1];
			struct Path newPath = createPath(line);
			for(int j = 0; j < totalpaths; j++)
			{
				 pathArr[j] = paths[j];
			}
			totalpaths++;
			pathArr[totalpaths] = newPath;
			paths =  pathArr;
		}
		else if(number == 0)
		{
			number = atoi(line[0]);
			nodes = Node[number];
		}
	}
	
};
struct Node createNode(char * line)
{
	struct Node newNode;  
	for(int i = 0; i < 5; i+=2)
	{
		if(i == 0)
		{
			newNode.id = line[i];
		}
		else if(i == 2)
		{
			newNode.x = atoi(line[i]);
		}
		else if(i == 4)
		{
			newNode.y = atoi(line[i]);
		}
	}

	return newNode;
};
struct Node * addEdges(char * line,int NodeNum, struct Node * nodes)
{
	struct Edges newPath;  
	for(int i = 0; i < 5; i+=2)
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
			newPath.cost = atoi(line[i]);
		}
	}

	for(int i = 0; i < NodeNum; i+=2)
	{
		if( nodes[i].id == newPath.From)
		{
			int paths = 1;
			
			int paths += nodes[i].numPaths;
			struct Edges edgeArr[paths];

			for(int j = 0; j < nodes[i].numPaths; j++)
			{
				 edgeArr[j] = nodes[i].paths[j];
			}
			 edgeArr[paths-1] = newPath

			nodes[i].numPaths++;
			
			nodes[i].paths = edgeArr;
		}
	}
	return  nodes;
};
struct Path createPath(char * line)
{
	struct Path newPath;
	for(int i = 0; i < 3; i=2)
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