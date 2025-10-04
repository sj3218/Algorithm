#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>
#include <map>

using namespace std;

int robot_cnt;
int info_cnt;
string food_info;

struct TrieNode
{
    bool is_end;
    map<string, TrieNode*> children;
    TrieNode() 
    {
        is_end = false;
    }
    ~TrieNode()
    {
        map<string, TrieNode*>::iterator it;
        it = children.begin();
        for (it; it != children.end(); ++it)
        {
            delete it->second;
        }
    }
};

class Trie {
    TrieNode* root;

public:
    Trie()
    {
        root = new TrieNode();
    }
    ~Trie()
    {
        delete root;
    }

    void Insert(vector<string>& path)
    {
        TrieNode* node = root;
        for (string& food : path)
        {
            if (node->children.find(food) == node->children.end())
            {
                node->children[food] = new TrieNode();
                node->is_end = true;
            }

            node = node->children[food];
        }
    }

    void dfs(int depth, TrieNode* node)
    {
        string key;
        TrieNode* child;
        map<string, TrieNode*>::iterator it;
        for (it = node->children.begin(); it != node->children.end(); ++it)
        {
            key = it->first;

            for (int i = 0; i < depth; ++i)
            {
                cout << "--";
            }
            cout << key <<"\n";

            child = it->second;
            dfs(depth + 1, child);
        }
    }

    void Print(int depth)
    {
        dfs(depth, root);
    }
};

void Init(Trie& root)
{
    cin >> robot_cnt;

    for (int i = 0; i < robot_cnt; ++i)
    {
        cin >> info_cnt;
        vector<string> path(info_cnt);
        for (int j = 0; j < info_cnt; ++j)
        {
            cin >> path[j];
        }

        root.Insert(path);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Trie root;
    
    Init(root);
    root.Print(0);

    return 0;
}