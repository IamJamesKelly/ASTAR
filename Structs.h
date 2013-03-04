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
	Node ** pNodes;
};

typedef struct 
{
	Node ** nodePath;
	int lenght;
	int cost;
}Path;

#endif