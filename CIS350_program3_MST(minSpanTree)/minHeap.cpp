#include "minHeap.h"

int minHeap::getLeftChildIndex(int parentIndex)
{
	return 2 * parentIndex + 1;
}
int minHeap::getRightChildIndex(int parentIndex)
{
	return 2 * parentIndex + 2;
}
int minHeap::getParentIndex(int childIndex)
{
	return (childIndex - 1) / 2;
}
bool minHeap::hasLeftChild(int index)
{
	if (getLeftChildIndex(index) < heap.size())
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool minHeap::hasRightChild(int index)
{
	if (getRightChildIndex(index) < heap.size())
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool minHeap::hasParent(int index)
{
	if (getParentIndex(index) >= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
minHeap::node* minHeap::leftChild(int index)
{
	return heap.at(getLeftChildIndex(index));
}
minHeap::node* minHeap::rightChild(int index)
{
	return heap.at(getRightChildIndex(index));
}
minHeap::node* minHeap::parent(int index)
{
	return heap.at(getParentIndex(index));
}


void minHeap::swap(node* a, node* b)
{
	node* temp = a;
	a = b;
	b = temp;
}

//returns the first element (root/min element) of vector
minHeap::node* minHeap::peek()
{
	if (heap.size() == 0)
	{
		cout << "heap is empty" << endl;
		return NULL;
	}
	else
	{
		return heap.at(0);
	}
}

//return the vertex of our minimum value node
int minHeap::getMin()
{
	node* min = poll();

	if (min != NULL)
	{
		return min->v;
	}
	else
	{
		cout << "can't pull queue is empty" << endl;
		return NULL;
	}
	
}

//extract the min element and remove it from array
//call heapify down to reorganize
minHeap::node* minHeap::poll()
{
	if (heap.size() == 0)
	{
		cout << "heap is empty" << endl;
		return NULL;
	}
	else
	{
		node* item = heap.at(0);
		heap.at(0) = heap.at(heap.size() - 1);
		heapifyDown();
		heap.erase(heap.begin());
		return item;
	}
}

int minHeap::extractMin()
{
	if (heap.size() == 0)
	{
		cout << "heap is empty" << endl;
		return NULL;
	}
	else
	{
		node* item = heap.at(0);
		heap.at(0) = heap.at(heap.size() - 1);
		heap.pop_back();

		int vertex = item->v;
		heapifyDown();
		return vertex;
	}
}

int minDist(vector<int> dist, vector<bool> visited)
{
	int min = 999;
	int minIndex;
	int vertexNum = dist.size();
	
	for (int i = 0; i < dist.size(); i++)
	{
		if (visited.at(i) == false && dist.at(i) <= min)
		{
			min = dist.at(i);
			minIndex = i;
		}
	}
	return minIndex;
}

void minHeap::add(int v, int dist)
{
	node* newNode;
	newNode = new node();
	newNode->v = v;
	newNode->dist = dist;


	heap.push_back(newNode);
	
	cout << "add node (" << v << ", " << dist << ")" << endl;
	
	heapifyUp();
}

void minHeap::heapifyDown()
{
	int index = heap.size() - 1;
	
	while (hasParent(index) && parent(index) > heap.at(index))
	{
		swap(heap.at(getParentIndex(index)), heap.at(index));
		index = getParentIndex(index);
	}
}

void minHeap::heapifyUp()
{
	int index = 0;
	while(hasLeftChild(index))
	{
		int smallerChildIndex = getLeftChildIndex(index);
		if (hasRightChild(index) && rightChild(index) < leftChild(index))
		{
			smallerChildIndex = getRightChildIndex(index);
		}

		if (heap.at(index) < heap.at(smallerChildIndex))
		{
			break;
		}
		else
		{
			swap(heap.at(index), heap.at(smallerChildIndex));
		}
		index = smallerChildIndex;
	}
}

bool minHeap::isEmpty()
{
	if(heap.size() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//check if a value is in our heap
bool minHeap::check(int pos)
{
	if (heap.at(pos)->v < heap.size())
	{
		return true;
	}
	else
	{
		return false;
	}
}
//int minHeap::getLeftChildIndex(int index)
//{
//	return (2 * index + 1);
//}
//int minHeap::getRightChildIndex(int index)
//{
//	return 2 * index + 2;
//}
//int minHeap::getParentIndex(int index)
//{
//	return (index - 1) / 2;
//}
//
//bool minHeap::hasLeftChild(int index)
//{
//	if (getLeftChildIndex(index) < size)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//	
//}
//bool minHeap::hasRightChild(int index)
//{
//	if (getRightChildIndex(index) < size)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//bool minHeap::hasParent(int index)
//{
//	if (getParentIndex(index) >= size)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//node* minHeap::leftChild(int index)
//{
//	return items.at(getLeftChildIndex(index));
//}
//node* minHeap::rightChild(int index)
//{
//	return items.at(getRightChildIndex(index));
//}
//node* minHeap::parent(int index)
//{
//	return items.at(getParentIndex(index));
//}
//
//void minHeap::swap(int one, int two, vector<node>& items)
//{
//	//swap 2 elements
//	node temp = items.at(one);
//	items.at(one) = items.at(two);
//	items.at(two) = temp;
//}
////if we're at capacity copy everything and double size of our array
//void minHeap::checkCapacity()
//{
//	/*if(item.size() == item.capacity())
//	{
//		vector<int> temp;
//		for(int i = 0; i < item.capacity; i)
//	}*/
//
//}
//
////returns the first (smallest) element in the vec 
//int minHeap::peek()
//{
//	return items.at(0).dist;
//}
//
////removes min element
//minHeap::node minHeap::pull()
//{
//	if (items.size() == 0)
//	{
//		node temp = NULL;
//		cout << "heap empty" << endl;
//		return temp;
//	}
//	else
//	{
//		node temp = items.at(0);
//		items.at(0) = items.at(items.size() - 1);
//		size = items.size();
//		items.resize(size - 1);
//		heapifyDown();
//		return temp;
//	}
//
//}
//
//void minHeap::add(int v, int dist)
//{
//	node newNode;
//
//	newNode.vertex = v;
//	newNode.dist = dist;
//
//	items.push_back(newNode);
//
//	heapifyUp();
//}
//
////call if we need to move element up
////start with last element added, walk up heap as long as we have a parent and we are out of order
////swap the values and walk up to heapify
//void minHeap::heapifyUp()
//{
//	int index = item.size() - 1;
//
//	while (hasParent(index) && parent(index) > item.at(index))
//	{
//		swap(getParentIndex(index), index);
//		index = getParentIndex(index);
//	}
//}
//
////call if we need to move element down
////start with our root, as long as we have children continue walking down and fixing our heap
//void minHeap::heapifyDown()
//{
//	int index = 0;
//	while (hasLeftChild(index) == true)
//	{
//		int smallerChild = getLeftChildIndex(index);
//		if (hasRightChild(index) && rightChild(index) < leftChild(index))
//		{
//			smallerChild = getRightChildIndex(index);
//		}
//
//		if (item.at(index) >= item.at(smallerChild))
//		{
//			swap(index, smallerChild);
//		}
//
//		index = smallerChild;
//	}
//}
//
//bool minHeap::isEmpty()
//{
//	if (item.empty() == true)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}




//}
