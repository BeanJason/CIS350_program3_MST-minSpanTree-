#include "List.h"
#include "iomanip"


List::List()
{
}


List::~List()
{
}

void List::appendNode(int edge, int weight)
{
	Node* node;
	Node* curNode;
	

	if (!head)
	{
		//set node values
		node = new Node();
		//node->edge.push_back(edge);
		//node->edge.push_back(weight);
		node->edge = edge;
		node->weight = weight;
		node->next = nullptr;
		//node->prev = nullptr;
		head = node;
		tail = node;


	}
	else {
		node = new Node();
		//node->edge.push_back(edge);
		//node->edge.push_back(weight);
		node->edge = edge;
		node->weight = weight;
		node->next = nullptr;
		//node->prev = tail;
		tail->next = node;
		tail = node;
	}


}

void const List::displayForward(ofstream& output)
{

	Node* curNode;
	curNode = head;


	while (curNode != nullptr)
	{
		cout << "(" << curNode->edge<< ", " << curNode->weight << ")";
		output << "(" << curNode->edge << ", " << curNode->weight << ")";

		curNode = curNode->next;
	}
}

void List::displayMin(ofstream& output, vector<bool> visited)
{
	int minIndex = 0;
	Node* curNode;
	curNode = head;

	Node* minNode = curNode;


	//check if any nodes have a smaller weight
	
		while (curNode != nullptr)
		{

			if ((minNode->weight > curNode->weight) && (visited.at(curNode->edge) == false))
			{
				minNode = curNode;
			}
			curNode = curNode->next;
		}
		cout << "(" << minNode->edge << ", " << minNode->weight << ")";
		output << "(" << minNode->edge << ", " << minNode->weight << ")";
	
	
	

	
}

void List::increaseWeight(int edge, int weight, ofstream& output)
{
	Node* curNode;
	curNode = head;

	while (curNode != nullptr)
	{
		if (curNode->edge == edge)
		{
			curNode->weight += weight;
			cout << "Increase edge " << edge << " weight by " << weight << " = (" << edge << ", " << curNode->weight << ")";
			output << "Increase edge " << edge << " weight by " << weight << " = (" << edge << ", " << curNode->weight << ")";
		}

		curNode = curNode->next;
	}
}

int List::getWeight(int edge)
{
	Node* curNode;
	curNode = head;

	int curWeight = 0;

	while (curNode != nullptr)
	{
		if (curNode->edge == edge)
		{
			curWeight = curNode->weight;
		}
	}

	return curWeight;
}

int max(vector<int> dist)
{
	int max = dist.at(0);
	for (int i = 0; dist.size(); i++)
	{
		if (dist.at(i) > max)
		{
			max = dist.at(i);
		}
	}
	return max;
}

int minDistance(vector<int> dist, vector<bool> visited)
{
	int min = 999;
	int index = 0;
	for (int i = 0; i < dist.size(); i++)
	{
		if (dist.at(i) <= min && visited.at(i) == false)
		{
			min = dist.at(i);
			index = i;
		}	
	}
	return index;
}

void List::printSolution(vector<int> dist, int graph, vector<int> path)
{
	int src = 0;
}

//prints the shortest distance to all nodes from source
void List::printShortestPath(vector<int> dist, int n, ofstream& output)
{
	for (int i = 0; i < n; i++)
	{
		cout << "vertex " << i << " " << dist.at(i);
		output << "vertex " << i << " " << dist.at(i);
	}
}

//calculate the distance from our source to all verticies
void List::dijkstra(int source, vector<List> graph, ofstream& output, int end)
{
	
	minHeap distQueue;
	vector<bool> visited;

	vector<int> distVec;
	string MST = "";

	vector<int> endPath;

	for (int i = 0; i < graph.size(); i++)
	{
		//each node in the distance queue set to infinity
		distQueue.add(i, 999);
		visited.push_back(false);
		distVec.push_back(999);
	}

	//set distance from the source to 0
	distQueue.add(source, 0);
	distVec.at(source) = 0;


	//min heap contains all nodes that do not have shortest path yet
	while (!distQueue.isEmpty())
	{
		//find the vertex with the minimum distance value
		int min = distQueue.getMin();

		//scan through all adjacent nodes of min and get change their distance values
		Node* curNode = graph.at(min).head;

		while (curNode != NULL)
		{
		
			int dist = curNode->edge;

			//If the shortest distance to dist isn't updated and the distance to dist through our min
			//is < the previous distance 
			if (distVec.at(min) != 999 && curNode->weight + distVec.at(min) < distVec.at(dist))
			{
				distVec.at(dist) = distVec.at(min) + curNode->weight;
				distQueue.add(dist, distVec.at(dist));
				
				//shortest path from source to end
				//could be made much more efficient if we broke after this was found
				if (dist == end)
				{
					endPath.push_back(curNode->weight);
				}
				
				
			}
			curNode = curNode->next;
		}

	}
	cout << "path to " << end << " = ";
	output << "shortest path to " << end << " from " << source << " = ";
	for (int i = 0; i < endPath.size(); i++)
	{
		if (i == 0)
		{
			cout << endPath.at(i);
			output << endPath.at(i);
		}
		else if (i == endPath.size())
		{
			cout << endPath.at(i);
			output << endPath.at(i);
		}
		else
		{
			cout << " + " << endPath.at(i);
			output << " + " << endPath.at(i);
		}
	}
	cout << endl;
	output << endl;
	//printShortestPath(distVec, graph.size(), output);
	
}


void List::decreaseWeight(int edge, int weight, ofstream& output)
{
	Node* curNode;
	curNode = head;

	while (curNode != nullptr)
	{
		if (curNode->edge == edge && curNode->weight > weight)
		{
			curNode->weight -= weight;
			cout << "Decrease edge " << edge << " weight by " << weight << " = (" << edge << ", " << curNode->weight << ")";
			output << "Decrease edge " << edge << " weight by " << weight << " = (" << edge << ", " << curNode->weight << ")";
		}
		else if (curNode->edge == edge && curNode->weight < weight)
		{
			cout << "Decreasing weight would make weight invalid" << endl;
		}

		curNode = curNode->next;
	}
}

void List::insertNode(int edge, int weight)
{
	/*Node* node;
	Node* curNode;
	Node* prevNode = nullptr;

	node = new Node();
	node->edge.push_back(edge);
	node->edge.push_back(weight);

	if (!head)
	{
		head = node;
		node->next = nullptr;
	}

	else
	{
		curNode = head;

		while (curNode != nullptr && curNode->edge.at(0) < id)
		{
			prevNode = curNode;

			curNode = curNode->next;
		}

		if (prevNode == nullptr)
		{
			head = node;
			node->next = curNode;
			curNode->prev = head;
		}
		else
		{
			prevNode->next = node;
			node->next = curNode;
			node->prev = prevNode;
			curNode->prev = node;
		}
	}*/

}

