#include <bits/stdc++.h>
#include "solvers.h"
using namespace std;

int dfs(unordered_map<int, Node> &tree, int node, int par, int k, int k_max, map<pair<int, int>, int> &dp)
{
    if (dp.find({node, k}) != dp.end())
    {
        return dp[{node, k}];
    }
    int ans = 0;
    bool has_children = false;
    int temp1, temp2, temp3 = INT_MIN;
    for (int child : tree[node].children)
    {
        if (child != par)
        {
            temp2 = dfs(tree, child, node, k_max, k_max, dp);
            if (k > 1)
            {
                temp1 = dfs(tree, child, node, k - 1, k_max, dp);
                if (temp1 != -1)
                {
                    has_children = true;
                    temp3 = max(temp3, temp1 - max(temp2, 0));
                }
            }
            if (temp2 != -1)
            {
                ans += temp2;
            }
        }
    }

    if (k > 1)
    {
        if (!has_children && k == k_max)
            return dp[{node, k}] = 0;
        if (!has_children && k != k_max)
            return dp[{node, k}] = -1;
        if (k == k_max)
        {
            return dp[{node, k}] = max(ans, tree[node].reward + ans + temp3);
        }
        return dp[{node, k}] = tree[node].reward + ans + temp3;
    }
    else
    {
        return dp[{node, k}] = tree[node].reward + ans;
    }
}

int optimalMaxReward(unordered_map<int, Node> tree, int root, int k)
{
    map<pair<int, int>, int> dp;
    return dfs(tree, root, -1, k, k, dp);
}