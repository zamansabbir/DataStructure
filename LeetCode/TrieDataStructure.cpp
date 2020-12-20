#include<iostream>
#include<unordered_map>
using namespace std;

struct TrieNode{
    unordered_map<char, TrieNode*> map;
    bool endOfWord=false;
};

