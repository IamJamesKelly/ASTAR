#ifndef ASTARSEARCH_H
#define ASTARSEARCH_H
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
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
void FindPath(char * target,Node * node)
{
	int i = 0;
	for(i = 0; i < node->numPaths;i++)
	{

	}

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
			fromNode->edgesNum =  realloc(fromNode->edgesNum,fromNode->numPaths *sizeof(int));
			fromNode->edgesNum[fromNode->numPaths - 1] = edg[i].weight;
			fromNode->pNodes[fromNode->numPaths - 1] = toNode;
		}
		else
		{	fromNode->numPaths = 0;
			fromNode->pNodes = malloc(sizeof(Node *));
			fromNode->edgesNum =  malloc(sizeof(int));
			fromNode->edgesNum[fromNode->numPaths] = edg[i].weight;
			fromNode->pNodes[fromNode->numPaths] = toNode;
			fromNode->numPaths = 1;
		}
	}
	for(i = 0; i < PathsToSerch;i++)
	{
		Node * node = findNode(nodes,target[i].Start,nodeNum);
		FindPath(target[i].Finish,node);
	}
};
#endif