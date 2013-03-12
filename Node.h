#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Structs.h"

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
		int len = strlen(p);
		if(p[len-1] == '\n' )
		   p[len-1] = 0;
		
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
	
	newNode->numPaths = 0;
};
void createEdge(char * line,Edges * newTarget)
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
		int len = strlen(p);
		if(p[len-1] == '\n' )
		   p[len-1] = 0;

		if( boolStep == 0)
		{
			int i = 0;
			strcpy(newTarget->From,p);
			boolStep = 1;
		}
		else if(boolStep == 1)
		{
			strcpy(newTarget->To,p);
			boolStep = 2;
		}
		else if( boolStep == 2)
		{
			newTarget->weight = atoi(p);
			boolStep = 3;
		}
		p = strtok (NULL," ");
	}
};
Target createTarget(char * line,Target * newTarget)
{
	char * p = strtok(line," \n");
	char ptr[strlen(p)+1];
	int i,j=0;
	
	int bool = 0;
	char temp;
	while (p != NULL)
	{
		int len = strlen(p);
		if(p[len-1] == '\n' )
		   p[len-1] = 0;
		
		if(bool == 0)
		{
			strcpy(newTarget->Start,p);
			bool = 1;
		}
		else if(bool == 1)
		{
			strcpy(newTarget->Finish,p);
			bool = 0;
		}

		p = strtok(NULL," \n");
	}
};
void loadFile(Node * nodes, FILE * data,Target * targets,Edges * p,int * numEdges,int * PathsToSerch)
{
	char line[100];
	char mode[100];
	Edges newEdge[100];
	int number = 0;
	int numNodes = 0;

	while(fgets(line, 100, data) != NULL)
	{
		if(strncmp(line, "NODES", 5) == 0 ||  strncmp(line, "EDGES", 5) == 0 || strncmp(line, "PATHS", 5) == 0 )
		{
			strcpy(mode, line);
		}
		else if(strncmp(mode, "NODES", 5) ==0)
		{
			createNode(line,&nodes[numNodes]);
			numNodes++;
		}
		else if(strncmp(mode, "EDGES", 5) == 0)
		{
			(*numEdges)++;
			p =  realloc(p, (*numEdges)*sizeof(Edges));
			createEdge(line,&p[(*numEdges)-1]);
		}
		else if(strncmp(mode, "PATHS", 5) == 0)
		{
			(*PathsToSerch)++;
			createTarget(line,&targets[(*PathsToSerch)-1]);
		}
	}
};
 