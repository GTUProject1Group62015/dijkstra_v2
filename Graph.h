/*
 * Graph.h
 *
 *  Created on: 12 Kas 2015
 *      Author: Guner
 */

#ifndef GRAPH_H_
#define GRAPH_H_
#include "Edge.h"
#include <vector>
using namespace std;

class Graph {
public:

	/*default constructor*/
	Graph() {
		numV = 0;
		directed = false;
	}

	Graph(bool direct, int num);/*constructor*/
	/** Return the number of vertices.
	 @return The number of vertices
	 */
	inline int getNumV() const {
		return numV;
	}

	/*return vertex list*/
	inline vector<Vertex> getVertexList() {
		return vertexList;
	}

	/** Determine whether this is a directed graph.
	 @return true if this is a directed graph
	 */
	inline bool isDirected() {
		return directed;
	}

	/** Insert a new edge into the graph.
	 @param edge The new edge
	 */
	void insert(Edge edge);

	/** Determine whether an edge exists.
	 @param source The source vertex
	 @param dest The destination vertex
	 @return true if there is an edge from source to dest
	 */
	bool isEdge(int source, int dest) const;

	/** Get the edge between two vertices.
	 @param source The source vertex
	 @param dest The destination vertex
	 @return The Edge between these two vertices
	 */
	Edge getEdge(int source, int dest) const;

	/** insert a new edge into the graph, if given source and dest Coor exist,
	 * no addition
	 * @param source The source coordinate
	 * @param dest The destination coordinate
	 */
	void add(Coor source, Coor dest);

	/** return shortest path from start vertex to finish vertex
	 * @param start
	 * @param finish
	 * @return vertex vector
	 */
	vector<Vertex> shortestPath(Vertex start, Vertex finish);

	/** add vertex*/
	bool addVertex(Coor coor);

	/** set edge */
	bool setEdge(Vertex vSource,Vertex vDest);

private:
	int directed;
	int numV;
	vector<vector<Edge> > data;
	vector<Vertex> vertexList;
};

#endif /* GRAPH_H_ */
