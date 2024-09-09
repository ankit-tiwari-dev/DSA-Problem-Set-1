#include <iostream>  
#include <vector>  
#include <bits/stdc++.h>  

using namespace std;  

struct Node   
{  
    int data;  
    struct Node *left;  
    struct Node *right;  

    Node(int val) : data(val), left(NULL), right(NULL) {}  
};  

class Solution   
{  
public:  
    vector<vector<int>> PreInPost(Node *root)  
    {  
        stack<pair<Node *, int>> st;  
        vector<int> PreOrder, InOrder, PostOrder;  
        vector<vector<int>> ans;  

        if (root == NULL) return ans;  

        st.push({root, 1});  

        while (!st.empty())  
        {  
            auto it = st.top();  
            st.pop();  

            if (it.second == 1)  
            {  
                PreOrder.push_back(it.first->data);  
                it.second++;  
                st.push(it);  
                if (it.first->left != NULL)  st.push({it.first->left, 1});  
            }  
            else if (it.second == 2)  
            {  
                InOrder.push_back(it.first->data);  
                it.second++;  
                st.push(it);  
                if (it.first->right != NULL)  st.push({it.first->right, 1});  
            }  
            else   
            {  
                PostOrder.push_back(it.first->data);  
            }  
        }  

        ans.push_back(PreOrder);  
        ans.push_back(InOrder);  
        ans.push_back(PostOrder);  
        return ans;  
    }  
};  

int main()  
{  
    Node *root = new Node(1);  
    root->left = new Node(2);  
    root->right = new Node(3);  
    root->left->left = new Node(4);  
    root->left->right = new Node(5);  
    root->right->left = new Node(6);  
    root->right->right = new Node(7);  

    Solution solution;  
    vector<vector<int>> result = solution.PreInPost(root);  

    cout << "Preorder: ";  
    for (int x : result[0]) {  
        cout << x << " ";  
    }  
    cout << endl;  

    cout << "Inorder: ";  
    for (int x : result[1]) {  
        cout << x << " ";  
    }  
    cout << endl;  

    cout << "Postorder: ";  
    for (int x : result[2]) {  
        cout << x << " ";  
    }  
    cout << endl;  
 
    delete root->left->left;  
    delete root->left->right;  
    delete root->right->left;  
    delete root->right->right;  
    delete root->left;  
    delete root->right;  
    delete root;  

    return 0;  
}