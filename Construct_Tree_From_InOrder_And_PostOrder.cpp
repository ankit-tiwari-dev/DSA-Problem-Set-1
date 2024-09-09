//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL)
        return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution {
  public:

    // Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int n, int in[], int post[]) {
        map<int, int>mpp;
        for(int i = 0; i < n; i++)  mpp[in[i]] = i;
        Node* root = BuildTree(in, 0, n-1, post, 0, n-1, mpp);
        return root;
    }
    Node* BuildTree(int inOrder[], int inStart, int inEnd, int postOrder[], int postStart, int postEnd, map<int, int> &mpp)
    {
        if(postStart > postEnd || inStart > inEnd) return NULL;
        
        Node* root = new Node(postOrder[postEnd]);
        int inRoot = mpp[postOrder[postEnd]];
        int numsLeft = inRoot - inStart;
        root->left = BuildTree(inOrder, inStart, inRoot-1, postOrder, postStart, postStart+numsLeft-1, mpp);
        root->right = BuildTree(inOrder, inRoot+1, inEnd, postOrder, postStart+numsLeft, postEnd-1, mpp);
        return root; 
    }
};


//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++)
            cin >> in[i];
        for (int i = 0; i < n; i++)
            cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(n, in, post);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends