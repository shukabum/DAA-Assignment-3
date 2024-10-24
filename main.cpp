#include <bits/stdc++.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "solvers.h"
using namespace std;

string filename = "sample_input_1.txt";
int k = 2;

vector<int> split(const string &s, char delimiter)
{
    vector<int> result;
    stringstream ss(s);
    string token;
    while (getline(ss, token, delimiter))
    {
        result.push_back(stoi(token));
    }
    return result;
}

void printTree(unordered_map<int, Node> &tree)
{
    for (auto node : tree)
    {
        cout << node.first << " " << node.second.reward << "  {";
        for (int child : node.second.children)
        {
            cout << child << ",";
        }
        cout << "}" << endl;
    }
}

int main()
{
    // take input from file to get nodes of tree
    ifstream file(filename);
    unordered_map<int, Node> tree;
    string line;
    int root;

    while (getline(file, line))
    {

        stringstream ss(line);
        string type;
        ss >> type;
        int id, reward;

        if (type == "Root")
        {
            ss >> id >> reward;
            tree[id] = Node(id, reward);
            root = id;
        }
        else if (type == "R")
        { // Node with reward
            ss >> id >> reward;
            tree[id] = Node(id, reward);
        }
        else if (type == "E")
        { // Edge between two nodes
            string edge;
            ss >> edge;
            int parent = stoi(edge.substr(0, edge.find('-')));
            int child = stoi(edge.substr(edge.find('-') + 1));
            tree[parent].children.push_back(child);
        }
    }

    cout << "Maximum Disjoints Paths (Greedy) : " << greedyPathCount(tree, root, k) << endl;
    cout << "Maximum Reward (Greedy) : " << greedyMaxReward(tree, root, k) << endl;
    cout << "Maximm Reward (Optimal): " << optimalMaxReward(tree, root, k) << endl;
}
