#pragma once
#include <iostream>;
#include "items.h";
#include "vector";

using namespace std;

class minHeap
{
private:
	struct node
	{
		int dist;
		int v;
		bool visited;
	};

	vector<node*> heap;

	int getLeftChildIndex(int);
	int getRightChildIndex(int);
	int getParentIndex(int);
	bool hasLeftChild(int);
	bool hasRightChild(int);
	bool hasParent(int);
	node* leftChild(int);
	node* rightChild(int);
	node* parent(int);

public:
	void swap(node*, node*);
	node* peek();
	node* poll();
	void add(int, int);
	void heapifyDown();
	void heapifyUp();
	bool isEmpty();
	int extractMin();
	bool check(int);
	int minDist(vector<int>, vector<bool>);
	int getMin();





};

