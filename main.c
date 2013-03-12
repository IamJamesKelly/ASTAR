#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "astarSearch.h"
#include "Structs.h"
#include "Node.h"

int main( int argc, const char* argv[])
{
	int nodeSize = 0;
	int PathsToSerch = 0;
	int numEdges = 0;

	char line[100];
	Target targets[100];
	FILE * data = fopen("test.txt", "rt");

	if(nodeSize == 0 && fgets(line, 100, data) != NULL)
	{
		nodeSize = atoi(&line[0]);
	}

	Node nodes[nodeSize];
	Edges * ed = malloc(sizeof(Edges));
	

	loadFile(nodes,data,targets,ed,&numEdges,&PathsToSerch);
	astarSearch(targets,nodes,ed,numEdges,nodeSize,PathsToSerch);

};