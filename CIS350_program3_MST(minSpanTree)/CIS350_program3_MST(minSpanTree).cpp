// CIS350_program3_MST(minSpanTree).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "string"
#include "fstream"
#include "Data.h"
#include "vector"
#include "List.h"
#include "Graph.h"

using namespace std;

void readFile(vector<List>&, ofstream&);
void createMatrix(string, vector<vector<int>>&);

int main()
{
	//vector of list representing our adjacency list aka our graph
	vector<List> data;

	ofstream output;
	string fileName;

	vector<bool> visited;
	string operation;
	bool done = false;

	int delimPos;
	string delim = " ";
	int vertex;
	int edge;
	int weight;
	List mylist;

	cout << "Please enter name of output file: " << endl;
	cin >> fileName;
	output.open(fileName, std::ios_base::app);
	
	

	//read in our data and stroe in data vector
	readFile(data, output);
	
	for (int i = 0; i < data.size(); i++)
	{
		cout << endl << "adj[" << i << "]" << "-> ";
		output << endl << "adj[" << i << "]" << "-> ";
		data.at(i).displayForward(output);
		cout << endl;
		output << endl;
	}

	//find MST
	if (data.size() < 10)
	{
		cout << "MST: " << endl;
		output << "MST: ";
		for (int i = 0; i < data.size(); i++)
		{
			visited.push_back(false);
		}
		for (int i = 0; i < data.size(); i++)
		{
			
			/*cout << endl << "adj[" << i << "]" << "-> ";
			output << endl << "adj[" << i << "]" << "-> ";*/
			data.at(i).displayMin(output, visited);
			visited.at(i) = true;
			cout << " ";
			output << " ";
		}
	}


	//while (!done)
	//{
	//	cout << "enter new operations, enter stop to end program: ";
	//	getline(cin, operation);
	//	cin.ignore();

	//	cout << operation;
	//	output << operation;

	//	delimPos = operation.find(delim);

	//	if (operation.at(0) == 'I')
	//	{
	//		
	//		operation = operation.substr(delimPos + 1);
	//		delimPos = operation.find(delim);

	//		cout << operation << endl;
	//		cout << operation.substr(0, delimPos) << endl;

	//		vertex = stoi(operation.substr(0, delimPos));

	//		if (vertex > data.size())
	//		{
	//			cout << "Error vertex out of range of graph" << endl;
	//			output << "Error vertex out of range of graph" << endl;
	//		}
	//		else if (vertex < 0)
	//		{
	//			cout << "Error invalid vertex" << endl;
	//			output << "Error invalid vertex" << endl;
	//		}
	//		else
	//		{
	//			operation = operation.substr(delimPos + 1);
	//			delimPos = operation.find(delim);

	//			edge = stoi(operation.substr(0, delimPos));

	//			operation = operation.substr(delimPos + 1);
	//			delimPos = operation.find(delim);

	//			weight = stoi(operation.substr(0, delimPos));

	//			mylist = data.at(vertex);
	//			mylist.increaseWeight(edge, weight, output);
	//		}
	//	}
	//	else if (operation.at(0) == 'D')
	//	{
	//		cout << "";
	//	}
	//	else if (operation.at(0) == 'E')
	//	{
	//		cout << "";
	//	}
	//	else if (operation.at(0) == 'S')
	//	{
	//		cout << "";
	//	}
	//	else if (operation == "stop")
	//	{
	//		done = true;
	//	}
	//	else
	//	{
	//		cout << "invalid operation" << endl;
	//		output << "invalid operation" << endl;
	//	}
	//}
	
	
	system("pause");
	return 0;
}

void readFile(vector<List>& arr, ofstream& output)
{
	ifstream inputFile;
	string LineOfText;
	string fileName;
	string val;
	List mylist;
	

	int delimPos;
	int numExpressions = 0;
	int lineNum = 0;
	string delim = " ";
	
	int edge;
	int weight;
	int vertex;
	int destinaiton;

	int maxVertex;
	int maxEdge;
	int position;

	bool addEdgeSet = false;
	bool incEdgeSet;
	bool decEdgeSet;
	bool shortestPathSet;

	int counter = 0;


	

	cout << "Please enter input file name: " << endl;
	cin >> fileName;



	inputFile.open(fileName);

	//scan through file and store each expression on each line to element in 'Expression' array
	if (inputFile)
	{
		cout << "file open" << endl;
		//output << "file open" << endl;


		//get data on each line, store LineOfText in element, repeat until last line
		while (getline(inputFile, LineOfText)) {

			cout << LineOfText;
			output << LineOfText;
			//if this is our first iteration that means that we are getting the data for the number of vertices and edges
			//so we take that data and resize our vector
			if (counter == 0)
			{
				
				delimPos = LineOfText.find(delim);

				maxVertex = stoi(LineOfText.substr(0, delimPos));

				LineOfText = LineOfText.substr(delimPos + 1);
				delimPos = LineOfText.find(delim);

				maxEdge = stoi(LineOfText.substr(0, delimPos));

				arr.resize(maxVertex, mylist);
			}

			//if it's not the first iteration then it's time to create our graph
			else
			{
				delimPos = LineOfText.find(delim);
				
				//if fist letter is an E add an edge to the graph
				if ((LineOfText.substr(0, delimPos)) == "E")
				{
					LineOfText = LineOfText.substr(delimPos + 1);
					delimPos = LineOfText.find(delim);

					vertex = stoi(LineOfText.substr(0, delimPos));

					if (vertex > maxVertex)
					{
						cout << "Error vertex out of range of graph" << endl;
						output << "Error vertex out of range of graph" << endl;
					}
					else if (vertex < 0)
					{
						cout << "Error invalid vertex" << endl;
						output << "Error invalid vertex" << endl;
					}
					else
					{
						LineOfText = LineOfText.substr(delimPos + 1);
						delimPos = LineOfText.find(delim);

						edge = stoi(LineOfText.substr(0, delimPos));

						LineOfText = LineOfText.substr(delimPos + 1);
						delimPos = LineOfText.find(delim);

						weight = stoi(LineOfText.substr(0, delimPos));

						mylist = arr.at(vertex);
						mylist.appendNode(edge, weight);
						arr.at(vertex) = mylist;

						mylist = arr.at(edge);
						mylist.appendNode(vertex, weight);
						arr.at(edge) = mylist;
					}
					

				}

				//if the first character is an "I" increase the weight of a specific edge
				if ((LineOfText.substr(0, delimPos)) == "I")
				{
					LineOfText = LineOfText.substr(delimPos + 1);
					delimPos = LineOfText.find(delim);

					vertex = stoi(LineOfText.substr(0, delimPos));

					if (vertex > maxVertex)
					{
						cout << "Error vertex out of range of graph" << endl;
						output << "Error vertex out of range of graph" << endl;
					}
					else if (vertex < 0)
					{
						cout << "Error invalid vertex" << endl;
						output << "Error invalid vertex" << endl;
					}
					else
					{
						LineOfText = LineOfText.substr(delimPos + 1);
						delimPos = LineOfText.find(delim);

						edge = stoi(LineOfText.substr(0, delimPos));

						LineOfText = LineOfText.substr(delimPos + 1);
						delimPos = LineOfText.find(delim);

						weight = stoi(LineOfText.substr(0, delimPos));

						mylist = arr.at(vertex);
						mylist.increaseWeight(edge, weight, output);
					}
					
				}

				//If the first character is a "D" decrease the weight of a specific edge
				if ((LineOfText.substr(0, delimPos)) == "D")
				{
					LineOfText = LineOfText.substr(delimPos + 1);
					delimPos = LineOfText.find(delim);

					vertex = stoi(LineOfText.substr(0, delimPos));

					if (vertex > maxVertex)
					{
						cout << "Error vertex out of range of graph" << endl;
						output << "Error vertex out of range of graph" << endl;
					}
					else if (vertex < 0)
					{
						cout << "Error invalid vertex" << endl;
						output << "Error invalid vertex" << endl;
					}
					else
					{
						LineOfText = LineOfText.substr(delimPos + 1);
						delimPos = LineOfText.find(delim);

						edge = stoi(LineOfText.substr(0, delimPos));

						LineOfText = LineOfText.substr(delimPos + 1);
						delimPos = LineOfText.find(delim);

						weight = stoi(LineOfText.substr(0, delimPos));

						mylist = arr.at(vertex);
						mylist.decreaseWeight(edge, weight, output);
					}
					
				}

				//If the first operator is an S find the shortest path
				if ((LineOfText.substr(0, delimPos)) == "S")
				{
					LineOfText = LineOfText.substr(delimPos + 1);
					delimPos = LineOfText.find(delim);

					edge = stoi(LineOfText.substr(0, delimPos));

					LineOfText = LineOfText.substr(delimPos + 1);
					delimPos = LineOfText.find(delim);

					destinaiton = stoi(LineOfText.substr(0, delimPos));

					mylist.dijkstra(edge, arr, output, destinaiton);
				}

				//if no operators add the edge to the graph
				else
				{
					if (LineOfText.substr(0, delimPos).at(0) < 48 || LineOfText.substr(0, delimPos).at(0) > 57)
					{
						cout << "Invalid Operation" << endl;
						output << "Invalid Operaiton" << endl;
					}
					else
					{
						vertex = stoi(LineOfText.substr(0, delimPos));

						if (vertex > maxVertex)
						{
							cout << "Error vertex out of range of graph" << endl;
							output << "Error vertex out of range of graph" << endl;
						}
						else if (vertex < 0)
						{
							cout << "Error invalid vertex" << endl;
							output << "Error invalid vertex" << endl;
						}
						else
						{
							LineOfText = LineOfText.substr(delimPos + 1);
							delimPos = LineOfText.find(delim);

							edge = stoi(LineOfText.substr(0, delimPos));

							LineOfText = LineOfText.substr(delimPos + 1);
							delimPos = LineOfText.find(delim);

							weight = stoi(LineOfText.substr(0, delimPos));

							mylist = arr.at(vertex);
							mylist.appendNode(edge, weight);
							arr.at(vertex) = mylist;

							mylist = arr.at(edge);
							mylist.appendNode(vertex, weight);
							arr.at(edge) = mylist;
						}
					}
					
					
					
					
				}
				
				
				
			}
			counter++;
			cout << endl;
			output << endl;
		}
		inputFile.close();
	}
	else
	{
		cout << "Error file not found" << endl;
		//output << "Error file not found" << endl;
	}

	if (numExpressions == 0)
	{
		cout << "Error File Empty" << endl;
	}
	//output.close();
}


