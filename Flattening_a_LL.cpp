//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

void printList(Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
    printf("\n");
}


// } Driver Code Ends
/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
public:
    Node* merge(Node* l1, Node* l2) {
        Node* dummy = new Node(-1);
        Node* temp = dummy;
        
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->data < l2->data) {
                temp->bottom = l1;
                l1 = l1->bottom;
            } else {
                temp->bottom = l2;
                l2 = l2->bottom;
            }
            temp = temp->bottom;
        }
        if (l1 != nullptr) {
            temp->bottom = l1;
        } else {
            temp->bottom = l2;
        }

        return dummy->bottom;
    }

    Node* flatten(Node* root) {
        if (root == nullptr || root->next == nullptr) {
            return root;
        }

        root->next = flatten(root->next);
        root = merge(root, root->next);

        return root;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        vector<int> work;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            work.push_back(number);
        }
        n = work.size();

        Node *head = NULL;
        Node *pre = NULL;

        for (int i = 0; i < n; i++) {
            int m = work[i] - 1;
            int data;
            cin >> data;
            Node *temp = new Node(data);
            if (head == NULL) {
                head = temp;
                pre = temp;
            } else {
                pre->next = temp;
                pre = temp;
            }

            Node *preB = temp;
            for (int j = 0; j < m; j++) {
                int temp_data;
                cin >> temp_data;
                Node *tempB = new Node(temp_data);
                preB->bottom = tempB;
                preB = tempB;
            }
        }

        Solution ob;
        Node *root = ob.flatten(head);
        printList(root);
    }
    return 0;
}

// } Driver Code Ends