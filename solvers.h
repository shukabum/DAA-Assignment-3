
#ifndef SOLVERS_H
#define SOLVERS_H

#include <string>
#include <unordered_map>

struct Node
{
    int id;
    int reward;
    std::vector<int> children;

    Node()
    {
        id = 0;
        reward = 0;
    }

    Node(int id, int reward)
    {
        this->id = id;
        this->reward = reward;
    }
};

int greedyPathCount(std::unordered_map<int, Node> tree, int root, int k);
int greedyMaxReward(std::unordered_map<int, Node> tree, int root, int k);
int optimalMaxReward(std::unordered_map<int, Node> tree, int root, int k);

#endif