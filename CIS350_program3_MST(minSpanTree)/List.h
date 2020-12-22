#pragma once
#include "iostream"
#include "string"
#include "vector"
#include "minHeap.h"
#include "fstream"

using namespace std;

class List
{
private:
	struct Node
	{
		//vector<int> edge;
		int edge;
		int weight;
		Node* next;
	};

	int maxVertex;
	minHeap queue;
	Node* head;
	Node* tail;
public:
	void appendNode(int, int);
	void const displayForward(ofstream&);
	void insertNode(int, int);
	void increaseWeight(int, int, ofstream&);
	void decreaseWeight(int, int, ofstream&);
	void dijkstra(int, vector<List>, ofstream&, int);
	int getWeight(int edge);
	void printSolution(vector<int>, int, vector<int>);
	void printShortestPath(vector<int>, int, ofstream&);
	void displayMin(ofstream&, vector <bool>);

	List();
	~List();
};

