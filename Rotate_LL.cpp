//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

// } Driver Code Ends

class Solution {  
public:  
    Node* rotate(Node* head, int k) {  
        if (head == NULL || head->next == NULL || k == 0) return head;  

        Node* tail = head;  
        int length = 1;  
        
        while (tail->next) {  
            tail = tail->next;  
            length++;  
        }  
 
        k = k % length;  
        if (k == 0) return head; 
        
        tail->next = head;  

        Node* newHead = head;  
        for (int i = 0; i < k; i++) {  
            newHead = newHead->next;  
        }  
        
        Node* newTail = newHead;  
        for (int i = 0; i < length - 1; i++) {  
            newTail = newTail->next;  
        }  

        newTail->next = NULL;  

        return newHead;  
    }  
};  



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }

        Node* head = nullptr;

        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node* tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.rotate(head, k);
        printList(head);
    }
    return 1;
}

// } Driver Code Ends