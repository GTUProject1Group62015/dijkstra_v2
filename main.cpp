/*
 * main.cpp
 *
 *  Created on: 12 Kas 2015
 *      Author: Guner
 */

/* start vertex e hedef vertex girilir,hangi vertex ten baslanilacaksa verilen
 * pred arrayinin ilgili indexindeki contente bakilir. Alinan bu deger yine ayni yontem ile
 * hedef vertex olarak secilen degere ulasilana kadar devam ettirilir.
 *
 *
 */
#include "DijkstrasAlgorithm.h"
#include <iostream>
using namespace std;
/*
int main2()
{
	Graph g;
	Graph g = Graph(false, 5);
	g.insert(Edge(0, 2, 1));
	g.insert(Edge(0, 1, 2));
	g.insert(Edge(1, 4, 2));
	g.insert(Edge(2, 3, 1));
	g.insert(Edge(3, 4, 1));
	g.insert(Edge(2, 4, 3));
	g.insert(Edge(0, 4, 5));

	double d[5];
	int p[5];
	int start=0;
	DijkstrasAlgorithm::dijkstrasAlgorithm(g, start, p, d);
	for (int i = 0; i < 5; ++i) {
		if(i==start)
		{
			cout << "start-vertex" << " -p "<< i <<"\n";
		}
		else
		{
			cout << p[i] << " -p "<< i <<"\n";
		}

	}
	return 0;
}*/

int main()
{
	Graph g;
	vector<Vertex> list,a;
	g.add(Coor(10,10),Coor(10,50));
	g.add(Coor(10,10),Coor(50,50));
	g.add(Coor(10,50),Coor(10,80));
	g.add(Coor(50,80),Coor(80,80));
	g.add(Coor(50,50),Coor(80,10));
	g.add(Coor(80,10),Coor(80,50));
	g.add(Coor(80,50),Coor(80,80));

	list=g.getVertexList();
	for(unsigned int i =0;i<list.size();++i){
		cout << "x: " << list[i].getX() << " y: " << list[i].getY() << endl;
	}
	a=g.shortestPath(list[0],list[5]);
	cerr << "----------------------\n";
	for(unsigned int i =0;i<a.size();++i){
		cout << "x: " << a[i].getX() << " y: " << a[i].getY() << endl;
	}
	return 0;
}
