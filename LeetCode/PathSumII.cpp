#include<iostream>
#include<vector>
using namespace std;
struct TreeNode{
    int data;
    TreeNode *left, *right;
};

void pathSumRecursive(TreeNode* root, int sum, int checkSum,vector<int> path,vector<vector<int>> &paths){
    if(!root->left && !root->right){
        if(checkSum==root->data){
            path.push_back(root->data);
            paths.push_back(path);
        }
        
        return;
    }
    path.push_back(root->data);
    if(root->left){
        pathSumRecursive(root->left,sum,checkSum-root->data,path,paths);
    }
    if(root->right){
        pathSumRecursive(root->right,sum,checkSum-root->data,path,paths);
    }
}
vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> paths;
        if(!root){
            return paths;
        }
        
        vector<int> current;
        pathSumRecursive(root,sum,sum,current,paths);
        return paths;
    
}


int main(){

    return 0;
}