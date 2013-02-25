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
	char * From;
	char * To;
	int weight;
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

void addEdges(char * line,int NodeNum, Node * nodes)
{
	Edges newPath; 
	int i = 0;
	int bool_secoundId = 0;
	int boolId = 0;
	char newId[100];
	char num[100];
	int step = 0;
	int numSize = 0;
	for(i = 0; i < strlen(line); i++)
	{
		if(isalpha(line[i]))
		{
			newId[step] = line[i];
		
			step++;
			boolId = 1;
		}
		else if(isdigit(line[i]))
		{
			num[numSize] = line[i];
			numSize++;
			boolId = 0;
		}
		else if(isspace(line[i]))
		{
			if(boolId == 1)
			{
				if(bool_secoundId == 0)
				{
					strncpy(newPath.From,newId,step);
					step = 0;
					bool_secoundId =1;
				}
				else if(bool_secoundId == 1)
				{
					printf("%s\n", newId);
					strncpy(newPath.To,newId,step);
					printf("%s\n", newPath.To);
					
				}
				step = 0;
				newId[0] = '\0';
			}
			else if(boolId == 0)
			{
				newPath.weight = atoi(num);
			}
		}
	}
	printf("%s\n", "////////////////");
	///printf("%s\n", newPath.From);
	///printf("%i\n", newPath.weight);
	printf("%s\n", "////////////////");
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
			addEdges(line,step,nodes);
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
