#include <bits/stdc++.h>
using namespace std;

#define V 5

bool graph[V][V] = {{0, 1, 0, 1, 0},
                    {1, 0, 1, 1, 1},
                    {0, 1, 0, 0, 1},
                    {1, 1, 0, 0, 1},
                    {0, 1, 1, 1, 0}};

void printSolution(int path[]);

bool isSafe(int v, int path[], int pos)
{
    if (graph[path[pos - 1]][v] == 0)
        return false;
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;
    return true;
}

bool hamCycleUtil(int path[], int pos)
{
    if (pos == V)
    {
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }
    for (int v = 1; v < V; v++)
    {
        if (isSafe(v, path, pos))
        {
            path[pos] = v;
            if (hamCycleUtil(path, pos + 1) == true)
                return true;
            path[pos] = -1;
        }
    }
    return false;
}

bool hamCycle()
{
    int *path = new int[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;
    path[0] = 0;
    if (hamCycleUtil(path, 1) == false)
    {
        cout << "\nSolution does not exist";
        return false;
    }
    printSolution(path);
    return true;
}

void printSolution(int path[])
{
    cout << "Solution Exists:"
         << " Following is one Hamiltonian Cycle \n";
    for (int i = 0; i < V; i++)
        cout << path[i] << " ";
    cout << path[0] << " ";
    cout << endl;
}

int main()
{
    hamCycle();
    return 0;
}
