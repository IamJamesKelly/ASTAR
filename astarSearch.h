#ifndef ASTARSEARCH_H
#define ASTARSEARCH_H
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "Structs.h"

Node * findNode(Node * nodes, char * id,int arrsize)
{
	int i = 0;
	int step = 0;
	for(i = 0; i < arrsize;i++)
	{
		if(strcmp(nodes[i].id,id) == 0)
		{
			step = i;
		}
	}
	return &nodes[step];
};	
void addPath(Path * path,Path * parentPath,Node * node,int cost)
{
	int nodeSize = parentPath->pathLenght + 1;
	path->nodes = malloc(nodeSize * sizeof(Node *));

	int i = 0;
	for(i = 0; i < parentPath->pathLenght;i++)
	{
		path->nodes[i] = parentPath->nodes[i];

	}

	path->nodes[nodeSize-1] = node;
	path->cost = parentPath->cost + cost;
	path->pathLenght = nodeSize;
};
int moveCost(Node * parent,int nodeMove)
{
	int x,y,cost;
	x = parent->pNodes[nodeMove]->x - parent->x;
	y = parent->pNodes[nodeMove]->y - parent->y;
	if(x < 0){
		x = x *-1;
	}
	if(y < 0){ 
		y = y *-1;
	}
	x = x*x;
	y = y*y;
	cost = sqrt((double)(x + y));

	cost = cost * parent->edgesNum[nodeMove];
	return cost;
};
void FindPath(Target target,Node * node)
{
	int i = 0;
	int j = 0;
	int PathFound = 0;
	int numpaths = 1;
	
	Path * paths = malloc(sizeof(Path));
	Path t;
	t.nodes = malloc(sizeof(Node *));
	t.nodes[0] = node;
	t.cost = 0;
	t.pathLenght = 1;
	t.nodes[0]->boolSearched = 1;

	paths[0] = t;

	Path * parentPath = &t;
	Path targetReached;
	targetReached.pathLenght = 0;
	targetReached.cost = -1;

	Node * nodeOn = node;
	int top = t.pathLenght-1;
	int n = -1;
	while(PathFound == 0)
	{

		for(i = 0; i < nodeOn->numPaths;i++)
		{
			int cost = moveCost(nodeOn,i); 
			numpaths++;
			int size = numpaths * sizeof(Path);
			paths = (Path*)realloc(paths,size);
			addPath(&paths[numpaths-1],parentPath,nodeOn->pNodes[i],cost);

		}
		for(j = 0; j < numpaths-1;j++)
		{
			paths[j] = paths[j+1];
			char c = target.Finish[0];
			if(strcmp(paths[j].nodes[parentPath->pathLenght-1]->id,target.Finish) == 0)
			{
				if(targetReached.cost == -1 ||  targetReached.cost > paths[j].cost)
				{
					targetReached.cost = paths[j].cost;
					targetReached.nodes = paths[j].nodes;
					targetReached.pathLenght = paths[j].pathLenght;
				}
			}
		}
		
		if(numpaths != 0)
		{
			paths = (Path*)realloc(paths,(numpaths * sizeof(Path)));
			parentPath = &paths[0];
			numpaths--;
			nodeOn = parentPath->nodes[parentPath->pathLenght - 1];
		}
		else
		{
			PathFound = 1;
		}
	}
	printf("%s\n","///////////////////////");
	printf("%s","Target:");
	printf("%s\n",target.Finish);
	printf("%s","Cost:");
	printf("%i\n",targetReached.cost);
	printf("%s","Order:");
	for(i = 0; i < targetReached.pathLenght;i++)
	{
		printf("%s",targetReached.nodes[i]->id);
		printf("%s",",");
	}
	printf("%s\n"," ");
	printf("%s\n","/////////////////////////");
};
void astarSearch(Target * target,Node * nodes,Edges * edg,int edgNum,int nodeNum, int PathsToSerch)
{

	int i,j,nodeCreated,bool;
	nodeCreated = 0;
	bool = 0;	

	
	for(i = 0; i < edgNum;i++)
	{
		Node * fromNode = findNode(nodes,edg[i].From,nodeNum);
		Node * toNode = findNode(nodes,edg[i].To,nodeNum);

		if(fromNode->numPaths != 0)
		{
			fromNode->numPaths++;
			fromNode->pNodes = realloc(fromNode->pNodes,(fromNode->numPaths *  sizeof(Node *)));
			fromNode->edgesNum = realloc(fromNode->edgesNum,fromNode->numPaths * sizeof(int));
			fromNode->edgesNum[fromNode->numPaths - 1] = edg[i].weight;
			fromNode->pNodes[fromNode->numPaths - 1] = toNode;
			fromNode->boolSearched = 0;
		}
		else
		{	fromNode->numPaths = 0;
			fromNode->pNodes = malloc(sizeof(Node *));
			fromNode->edgesNum =  malloc(sizeof(int));
			fromNode->edgesNum[fromNode->numPaths] = edg[i].weight;
			fromNode->pNodes[fromNode->numPaths] = toNode;
			fromNode->numPaths = 1;
			fromNode->boolSearched = 0;
		}
	}

	for(i = 0; i < PathsToSerch;i++)
	{
		Node * node = findNode(nodes,target[i].Start,nodeNum);
		FindPath(target[i],node);
	}
};
#endif