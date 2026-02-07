#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void f(TreeNode* root){

    stack<pair<TreeNode*,int>> st;

    st.push({root,1});
    vector<int> pre,in,post;
    if(root==NULL)  return;
    while(!st.empty()){
        auto it = st.top();
        st.pop();

        if(it.second==1){
            pre.push_back(it.first->val);
            it.second++;
            st.push(it);

            if(it.first->left){
                st.push({it.first->left,1});
            }
        }
        else if(it.second==2){
            in.push_back(it.first->val);
            it.second++;
            st.push(it);

            if(it.first->right){
                st.push({it.first->right,1});
            }
        }else{
            post.push_back(it.first->val);
        }
    }

    for(int i:pre)  cout<<i;
    cout<<'\n';
    for(int i:in)  cout<<i;
    cout<<'\n';
    for(int i:post)  cout<<i;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    f(root);
    return 0;
}