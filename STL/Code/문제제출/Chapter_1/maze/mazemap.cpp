#include<iostream>
#include<vector>
#include <fstream>
using namespace std;


void main()
{

	int width, height,temp;

	ifstream file("Maze.txt", ios::in);
	file >> width >> height;
	
		vector<vector<int>> maze(height, vector<int>(width, 0));
		for (vector<int>::size_type i = 0; i < maze.size(); i++)
		{
			for (vector<int>::size_type j = 0; j < maze[i].size(); j++)
			{
				file >> temp;
				maze[i][j] = temp;
			}
		}

		for (vector<int>::size_type i = 0; i < maze.size(); i++) {
			for (vector<int>::size_type j = 0; j < maze[i].size(); j++) {
				if (maze[i][j] == 0)
				{
					cout << "¢Ë";
				}
				else 
				{
				cout << "  ";
				}
			}
		cout << endl;
		}
}