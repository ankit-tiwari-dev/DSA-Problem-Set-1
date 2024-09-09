//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:
    Node* markParent(Node* root, unordered_map<Node*, Node*> &parent_track, int target)
    {
        Node* FindTargetNode = nullptr;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node* node = q.front();
            q.pop();
            if(node->data == target) FindTargetNode = node; 
            if(node->left)
            {
                parent_track[node->left] = node;
                q.push(node->left);
            }
            if(node->right)
            {
                parent_track[node->right] = node;
                q.push(node->right);
            }
        }
        return FindTargetNode;
    }
public:
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        unordered_map<Node*,Node*> parent_track;
        Node* TargetNode = markParent(root, parent_track, target);
        
        unordered_map<Node*, bool> visited;
        queue<Node*> q;
        q.push(TargetNode);
        visited[TargetNode] = true;
        
        int curr = 0;
        while(!q.empty())
        {
            int size = q.size();
            if(curr++ == k) break;
            for(int i = 0; i < size; i++)
            {
                Node* node = q.front();
                q.pop();
                if(node -> left && !visited[node->left])
                {
                    visited[node->left] = true;
                    q.push(node->left);
                }
                if(node -> right && !visited[node->right])
                {
                    visited[node->right] = true;
                    q.push(node->right);
                }
                if(parent_track[node] && !visited[parent_track[node]])
                {
                    visited[parent_track[node]] = true;
                    q.push(parent_track[node]);
                }
            }
        }
        vector<int> res;
        while(!q.empty())
        {
            Node* node =  q.front(); q.pop();
            res.push_back(node->data);
        }
        sort(res.begin(), res.end());
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends

// Leet code solution 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
class Solution {
public:
    void markParentNode(TreeNode* root,
                        unordered_map<TreeNode*, TreeNode*>& parent_track) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left) {
                parent_track[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parent_track[node->right] = node;
                q.push(node->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        markParentNode(root, parent_track);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);

        visited[target] = true;
        int curr = 0;
        while (!q.empty()) {
            int size = q.size();
            if (curr++ == k)
                break;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left && !visited[node->left]) {
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if (node->right && !visited[node->right]) {
                    q.push(node->right);
                    visited[node->right] = true;
                }
                if (parent_track[node] && !visited[parent_track[node]]) {
                    q.push(parent_track[node]);
                    visited[parent_track[node]] = true;
                }
            }
        }

        vector<int> res;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            res.push_back(node->val);
        }
        return res;
    }
};

*/
