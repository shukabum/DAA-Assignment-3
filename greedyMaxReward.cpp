#include <iostream>
#include <vector>
#include <unordered_map>
#include "solvers.h"
using namespace std;
#include<climits>
int greedyDFS(unordered_map<int, Node> &tree, int node, int par, int k, int k_max)
{
    int max_child = -1;
    int max_child_val = INT_MIN;
    int ans = 0;
    if (k == 1)
        ans += tree[node].reward;
    int temp1, temp2;
    for (auto child : tree[node].children)
    {
        if (child != par)
        {
            if (tree[child].reward > max_child_val)
            {
                max_child_val = tree[child].reward;
                max_child = child;
            }
        }
    }
    for (auto child : tree[node].children)
    {
        if (child != par && child != max_child)
        {
            temp2 = greedyDFS(tree, child, node, k_max, k_max);
            if (temp2 != -1)
            {
                ans += temp2;
            }
        }
    }
    if (max_child != -1)
    {
        if (k == 1)
        {
            temp1 = greedyDFS(tree, max_child, node, k_max, k_max);
            if (temp1 != -1)
            {
                ans += temp1;
            }
        }
        else
        {
            temp1 = greedyDFS(tree, max_child, node, k - 1, k_max);
            if (temp1 != -1)
            {
                ans += tree[node].reward;
                ans += temp1;
            }
        }
    }
    return ans;
}

int greedyMaxReward(unordered_map<int, Node> tree, int root, int k)
{
    return greedyDFS(tree, root, -1, k, k);
}