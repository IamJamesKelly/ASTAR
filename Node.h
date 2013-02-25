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
	char id[100];
	int numPaths;
	Edges * paths;
}Node;

void createNode(char * line, Node * newNode)
{
	int step = 0;
	char num[100];
	char nodeid[100];
	int boolX = 0;
	int strlenght = 0;
	int bool = 0;
	int j = 0;
	
	for(j = 0; j <= 100; j++)
	{
		nodeid[j] = ' ';
		num[j] = ' ';
		newNode->id[j] = ' ';
	}
	int i = 0;
	for(i = 0; i < strlen(line); i++)
	{
		if(isspace(line[i]))
		{
		
			if(bool == 1) 
			{
				int cordNum = atoi(num);
				if(boolX == 1)
				{
					newNode->y = cordNum;
					boolX = 0;
				}
				else
				{
					newNode->x = cordNum;
					boolX = 1;
					for(j = 0; j <= step; j++)
					{
						num[j] = ' ';
					}
				}
				bool = 0;
			}
			else
			{
				
				strncpy(newNode->id,nodeid,strlenght);
				strlenght = 0;
			}
			step = 0;
		}
		else if(isdigit(line[i]))
		{
			num[step]  = line[i];
			printf("%s\n",  num);
			step++;
			bool = 1;
		}
		else if(isalpha(line[i]))
		{
			nodeid[strlenght] = line[i];
			strlenght++;
		}
	}
	
	
	
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
		if(strcmp(nodes[i].id,&newPath.From) == 0)
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
	
	FILE* data = fopen("test.txt", "rt");
	
	
	if(number == 0 && fgets(line, 100, data) != NULL)
	{
		number = atoi(&line[0]);
	}
	Node nodes[number];
	while(fgets(line, 100, data) != NULL)
	{

		if(strncmp(line, "NODES", 5) == 0 ||  strncmp(line, "EDGES", 5) == 0 || strncmp(line, "PATHS", 5) == 0 )
		{
			strcpy(mode, line);
		}
		else if(strncmp(mode, "NODES", 5) ==0)
		{
			
			createNode(line,&nodes[step]);
			step++;
		}
		else if(strncmp(mode, "EDGES", 5) == 0)
		{
			//nodes = addEdges(line,step,nodes);
		}
		else if(strncmp(mode, "PATHS", 5) == 0)
		{
			
		//  Path pathArr[totalpaths+1];
		//	Path newPath = createPath(line);
		//	int j = 0;
		//	for(j = 0; j < totalpaths; j++)
		//	{
		//		 pathArr[j] = paths[j];
		//	}
		//	totalpaths++;
		//	pathArr[totalpaths] = newPath;
		//	paths =  pathArr;
		}
		
	}
	
};
