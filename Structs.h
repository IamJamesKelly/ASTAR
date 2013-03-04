#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct 
{
	char Start[100];
	char Finish[100];
}Target;

typedef struct
{
	char To[100];
	char From[100];
	int weight;
}Edges;

typedef struct Node Node;
struct Node{

	int x;
	int y;
	char id[100];
	int numPaths;
	int * edgesNum;
	int boolSearched = 0;
	Node ** pNodes;
};

typedef struct 
{
	Node ** nodes;
	char onid[100];
	int pathLenght;
	int cost;
}Path;

#endif