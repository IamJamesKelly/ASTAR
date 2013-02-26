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
	char To[100];
	char From[100];
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
	
	char * p = strtok(line," ");
	while (p != NULL)
	{
		
		if(isdigit(p[0]))
		{
			int cordNum = atoi(p);
			if(boolX == 1)
			{
				newNode->y = cordNum;
				boolX = 0;
			}
			else
			{
				newNode->x = cordNum;
				boolX = 1;
				num[0] = '\0';
			}
		}
		else if(isalpha(p[0]))
		{
			strcpy(newNode->id,p);
		}
		p = strtok (NULL," ");
	}	
};

void addEdges(char * line, Node * nodes,Edges * newPath)
{
	
	int i = 0;
	int bool_secoundId = 0;
	int boolId = 0;
	
	char newId[100];
	char num[100];
	int step = 0;
	int numSize = 0;
	step = 0;
	newId[0] = '\0';
	char * token;
	int boolStep = 0;;
	char * p = strtok(line," ");
	while (p != NULL)
	{
		if( boolStep == 0)
		{
			int i =0;
			strcpy(newPath->From,p );
			boolStep = 1;
		}
		else if(boolStep == 1)
		{
			strcpy(newPath->To,p );
			boolStep = 2;
		}
		else if( boolStep == 2)
		{
			newPath->weight = atoi(p);
			boolStep = 3;
		}
		p = strtok (NULL," ");
	}
};
Path createPath(char * line,Path * newPath)
{
	Path newPath;
	char * p = strtok(line," ");
	int bool = 0;
	while (p != NULL)
	{
		if(bool == 0)
		{
			strcpy(newPath->Start,p);
			bool = 1;
		}
		else if(bool == 1)
		{
			strcpy(newPath->Finish,p);
			bool = 0;
		}
		p = strtok (NULL," ");
	}
}
void loadFile()
{
	char line[100];
	char mode[100];

	Edges newEdge[100];
	Path paths[100];
	int number = 0;
	int step = 0;
	int numEdges = 0;
	int numPaths = 0;
	Path * paths;
	int totalpaths = 0;
	Edges p;
	FILE * data = fopen("test.txt", "rt");
	
	
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
			addEdges(line,nodes,&newEdge[numEdges]);
			numEdges++;
		}
		else if(strncmp(mode, "PATHS", 5) == 0)
		{
			createPath(line,&paths[totalpaths]);
			totalpaths++;
		
		}
		
	}
	
};
