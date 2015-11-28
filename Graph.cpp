/*
 * Graph.cpp
 *
 *  Created on: 12 Kas 2015
 *      Author: Guner
 */

#include "Graph.h"
#include "Edge.h"
#include "DijkstrasAlgorithm.h"
Graph::Graph(bool direct = true, int num = 0) :
		directed(direct), numV(num) {
	vector<Edge> e;
	for (int i = 0; i < numV; ++i) {
		data.push_back(e);
		++numV;
	}
}
/*
 void Graph::insert(Edge edge) {
 if (edge.getSource() > numV) {
 vector<Edge> e;
 data.push_back(e);
 ++numV;
 }
 data[edge.getSource()].push_back(edge);
 if (!directed) {
 data[edge.getDest()].push_back(
 Edge(edge.getDest(), edge.getSource(), edge.getWeight()));
 }
 }
 */
bool Graph::isEdge(int source, int dest) const {
	if (source < 0 || dest < 0 || source > numV || dest > numV) {
		return false;
	}
	for (unsigned int i = 0; i < data[source].size(); ++i) {
		if (data[source][i].getDest() == dest) {
			return true;
		}
	}
	return false;
}

Edge Graph::getEdge(int source, int dest) const {
	for (unsigned int i = 0; i < data[source].size(); ++i) {
		if (data[source][i].getDest() == dest) {
			return data[source][i];
		}
	}
	return Edge(Vertex(), Vertex());
}

//not finished....
void Graph::add(Coor source, Coor dest) {
	int source_coor_index = -1;
	int dest_coor_index = -1;
	for (unsigned int i = 0; i < vertexList.size(); ++i) {
		if (source_coor_index == -1 && vertexList[i].getX() == source.x
				&& vertexList[i].getY() == source.y) {
			source_coor_index = i;
		}
		if (dest_coor_index == -1
				&& data[i][0].getSourceVertex().getX() == dest.x
				&& data[i][0].getSourceVertex().getY() == dest.y) {
			dest_coor_index = i;
		}

		if (source_coor_index != -1 && dest_coor_index != -1) {
			break;
		}
	}

	if (source_coor_index == -1) {
		vector<Edge> e;
		data.push_back(e);
		source_coor_index = numV;
		vertexList.push_back(Vertex(source_coor_index, source));
		++numV;

	}
	if (dest_coor_index == -1) {
		vector<Edge> e;
		data.push_back(e);
		dest_coor_index = numV;
		vertexList.push_back(Vertex(dest_coor_index, dest));

		++numV;

	}

	data[source_coor_index].push_back(
			Edge(Vertex(source_coor_index, source),
					Vertex(dest_coor_index, dest)));

	if (!directed) {
		data[dest_coor_index].push_back(
				Edge(Vertex(dest_coor_index, dest),
						Vertex(source_coor_index, source)));
	}
}

vector<Vertex> Graph::shortestPath(Vertex start, Vertex finish) {
	int pred[numV];
	double dist[numV];
	vector<Vertex> result;
	int index = start.getNo();
	DijkstrasAlgorithm::dijkstrasAlgorithm(*this, finish.getNo(), pred, dist);
	for (int i = 0; i < numV; ++i) {
		result.push_back(vertexList[index]);
		index = pred[index];
		if (index == finish.getNo()) {
			result.push_back(vertexList[index]);
			break;
		}
	}
	return result;
}

/** add vertex*/
bool Graph::addVertex(Coor coor) {
	int source_coor_index = -1;
	for (unsigned int i = 0; i < vertexList.size(); ++i) {
		if (source_coor_index == -1 && vertexList[i].getX() == coor.x
				&& vertexList[i].getY() == coor.y) {
			source_coor_index = i;
		}
		if (source_coor_index != -1) {
			return false;
		}
	}
	source_coor_index = numV;
	vertexList.push_back(Vertex(source_coor_index, coor));
	++numV;
	return true;
}

/** set edge */
bool Graph::setEdge(Vertex vSource, Vertex vDest) {
	if (isEdge(vSource.getNo(), vDest.getNo())) {
		return false;
	}

	vector<Edge> e;
	data.push_back(e);

	data[vSource.getNo()].push_back(
			Edge(Vertex(vSource.getNo(),vSource.getX(),vSource.getY()),
					Vertex(vDest.getNo(),vDest.getX(),vDest.getY())));

	if (!directed) {
		data[vDest.getNo()].push_back(
				Edge(Vertex(vDest.getNo(),vDest.getX(),vDest.getY()),
						Vertex(vSource.getNo(),vSource.getX(),vSource.getY())));
	}
	return true;
}
