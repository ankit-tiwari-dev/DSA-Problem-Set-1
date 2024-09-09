//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printPostOrder(Node *root)
{
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution
{
public:
    Node *buildTree(int in[], int pre[], int n)
    {
        map<int, int> mpp;
        for (int i = 0; i < n; i++)
            mpp[in[i]] = i;

        Node *node = BuildTree(pre, 0, n - 1, in, 0, n - 1, mpp);
        return node;
    }
    Node *BuildTree(int preOrder[], int preStart, int preEnd, int inOrder[], int inStart, int inEnd, map<int, int> &mpp)
    {
        if (preStart > preEnd || inStart > inEnd)
            return NULL;

        Node *root = new Node(preOrder[preStart]);
        int inRoot = mpp[root->data];
        int numsLeft = inRoot - inStart;
        root->left = BuildTree(preOrder, preStart + 1, preStart + numsLeft, inOrder, inStart, inRoot - 1, mpp);
        root->right = BuildTree(preOrder, preStart + numsLeft + 1, preEnd, inOrder, inRoot + 1, inEnd, mpp);

        return root;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int inorder[n], preorder[n];
        for (int i = 0; i < n; i++)
            cin >> inorder[i];
        for (int i = 0; i < n; i++)
            cin >> preorder[i];
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder, n);
        printPostOrder(root);
        cout << endl;
    }
}

// } Driver Code Ends