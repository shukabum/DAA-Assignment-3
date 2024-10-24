#include <bits/stdc++.h>
#include "solvers.h"
using namespace std;

int findLevels(unordered_map<int, Node> &tree, unordered_map<int, int> &level, int node, int par)
{
    int height = 1;
    for (auto child : tree[node].children)
    {
        if (child != par)
        {
            height = max(height, findLevels(tree, level, child, node));
        }
    }
    return level[node] = height;
}
int findMaxPaths(unordered_map<int, Node> &tree, unordered_map<int, int> &level, int node, int par, int k, int k_max)
{
    int ans = 0;
    if (k == 1)
        ans++;
    int min_child = -1;
    int min_child_value = INT_MAX;
    for (auto child : tree[node].children)
    {
        if (child != par)
        {
            if (level[child] >= k - 1 && level[child] < min_child_value)
            {
                min_child_value = level[child];
                min_child = child;
            }
        }
    }
    if (min_child == -1)
    {
        return ans;
    }
    for (auto child : tree[node].children)
    {
        if (child != par && child != min_child)
        {
            ans += findMaxPaths(tree, level, min_child, node, k_max, k_max);
        }
    }
    if (k == 1)
    {
        ans += findMaxPaths(tree, level, min_child, node, k_max, k_max);
    }
    else
    {
        ans += findMaxPaths(tree, level, min_child, node, k - 1, k_max);
    }
    return ans;
}

int greedyPathCount(unordered_map<int, Node> tree, int root, int k)
{
    unordered_map<int, int> level;
    findLevels(tree, level, root, -1);
    return findMaxPaths(tree, level, root, -1, k, k);
}