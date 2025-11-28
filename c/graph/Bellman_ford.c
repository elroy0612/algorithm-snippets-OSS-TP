/*
 * Title    : Bellman-Ford Algorithm
 * Problem  : Implement the Bellman-Ford algorithm to compute the shortest paths
 *            from a single source vertex in a weighted directed graph, including
 *            negative edge weights. Detects negative-weight cycles.
 * Category : graph
 * Language : C
 * Author   : YeongWoong Kim
 * Note     :
 *			- Supports users to input their own graph (adjacency matrix format).
 *			- Displays shortest distances and reconstructed paths from the source.
 *			- Detects negative cycles.
 *			- Infinite edge weight (disconnected edge weight) is 9999(INFINITY).
 *			- Example input of a weighted graph (adjacency matrix format):
 *				0 6 9999 7 9999
 *				9999 0 5 8 -4
 *				9999 9999 0 9999 9999
 *				9999 9999 -3 0 9
 *				2 9999 7 9999 0
 */

#include <stdio.h>
#include <stdlib.h>
#define INFINITY 9999

void minimize_distance(int* graph, int* weight, int path[], int vertices_number) { //Implements the edge relaxation.
	for (int i = 0; i < vertices_number; i++) { //i is for previous vertex.
		if (weight[i] == INFINITY) continue;  //If this vertex is not reachable, skip
		for (int j = 0; j < vertices_number; j++) { //j is for next vertex.
			int edge_weight = *(graph + i * vertices_number + j);
			if (edge_weight == INFINITY) continue;  //If there is no edge, skip
			if (weight[i] + edge_weight < weight[j]) {
				weight[j] = weight[i] + edge_weight;
				path[j] = i;  //Tracks path. The elemenet of the array path[] is previous vertex, it's index is next vertex.
			}
		}
	}
}

void display_result(int weight[], int path[], int vertices_number, int source_vertex) { //Displays shortest distances and paths.
	printf("Vertex\tDistance from source\tPath\n");
	for (int i = 0; i < vertices_number; i++) {
		//Print destination vertex
		printf("%d\t", i);

		//Print distance
		if (weight[i] != INFINITY) 
			printf("%d\t\t\t", weight[i]);
		else 
			printf("INFINITE\t\t");

		//Print path
		if (weight[i] != INFINITY) {
			int destination = i;
			if (i != source_vertex) {
				int j = i;
				int* temp = (int*)malloc(vertices_number * sizeof(int));
				int k = 0;
				if (temp == NULL) {
					printf("Error: Memory allocation failed while printing path.\n");
					printf("%d\n", destination);
					continue;
				}
				do {
					j = path[j]; //The elements of the array path[] and their indexes are compatible. With this assignment, exposing the shortest paths is possible.
					temp[k++] = j; //Inserts the path into array temp, reversely.
				} while (j != source_vertex);
				for (int l = k - 1; l >= 0; l--) {
					printf("%d-", temp[l]);
				}
				free(temp);
			}
			printf("%d", destination);
		}
		else {
			printf("No path.");
		}
		printf("\n");
	}
	printf("\n");
}

int bellman_ford(int* graph, int vertices_number, int source_vertex) { //Finds shortest distances from source and paths by using the Bellman-Ford Algorithm.
	int* weight = (int*)malloc(vertices_number * sizeof(int));
	int* path = (int*)malloc(vertices_number * sizeof(int));
	if (weight == NULL || path == NULL) {
		fprintf(stderr, "Error: Memory allocation failed in bellman_ford.\n");
		free(weight);
		free(path);
		exit(1);
	}

	//Initialize predecessor of all vertices to source (default)
	for (int i = 0; i < vertices_number; i++)
		path[i] = source_vertex;
	
	//Initialize distances
	for (int i = 0; i < vertices_number; i++) { //Beginning of the Bellman-Ford Algorithm.
		if (i == source_vertex) weight[i] = 0;
		else weight[i] = INFINITY;
	}

	//Relaxation phase
	for (int i = 0; i < vertices_number - 1; i++)  //Main of bellman_ford function.
		minimize_distance(graph, weight, path, vertices_number);

	//Check for negative cycles
	for (int i = 0; i < vertices_number; i++) {
		for (int j = 0; j < vertices_number; j++) {
			int edge_weight = *(graph + i * vertices_number + j);
			if (edge_weight != INFINITY && weight[i] != INFINITY) {
				if (weight[i] + edge_weight < weight[j]) {
					// Negative cycle detected
					free(weight);
					free(path);
					return -1;
				}
			}
		}
	}
	display_result(weight, path, vertices_number, source_vertex);

	free(weight);
	free(path);
	return 1;
}

int main() {
	printf("Bellman-Ford Algorithm\n");
	printf("Make a new graph.\n");
	
	//Read number of vertices
	printf("\nEnter the number of vertices (positive integer): ");
	int vertices_number;
	while (scanf_s("%d", &vertices_number) != 1 || vertices_number <= 0) {
		while (getchar() != '\n');   //If user enters characters instead of integers, this getchar() discards characters.
		printf("Error: Please enter a positive integer: ");
	}
	 //Allocate graph matrix
	int* graph_new = (int*)malloc(vertices_number * vertices_number * sizeof(int));
	if (graph_new == NULL) {
		fprintf(stderr, "Memory allocation failed.\n");
		return 1;
	}
	
	//Read adjacency matrix
	printf("Enter the vertices (integer) (for infinite value (disconnected edge weight), enter 9999):\n");
	for (int i = 0; i < vertices_number; i++)
		for (int j = 0; j < vertices_number; j++)
			while (scanf_s("%d", (graph_new + i * vertices_number + j)) != 1) getchar(); //If user enters characters instead of integers, this getchar() discards characters.
	
	//Read source vertex with validation
	printf("Enter the source vertex (0~%d): ", vertices_number - 1);
	int source_vertex;
	while (scanf_s("%d", &source_vertex) != 1 || source_vertex < 0 || source_vertex >= vertices_number) {
		while (getchar() != '\n');  //If user enters characters instead of integers, this getchar() discards characters.
		printf("Error: Enter a valid source vertex (0~%d): ", vertices_number - 1);
	}
	printf("\n");

	//Run Bellman-Ford
	if (bellman_ford((int*)graph_new, vertices_number, source_vertex) == -1) {  //If the graph has not any negative cycle, skip this block and system works successfully.
		printf("WARNING: This graph has negative cycle.\n");  //If the graph has negative cycle, system alerts user.
	}

	free(graph_new);
	return 0;
}
