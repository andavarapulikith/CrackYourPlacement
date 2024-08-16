//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

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
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    // Function to find and map parents of all nodes
    void find_parent(Node* root, map<Node*, Node*>& parent) {
        if (!root) return;
        if (root->left) parent[root->left] = root;
        if (root->right) parent[root->right] = root;
        find_parent(root->left, parent);
        find_parent(root->right, parent);
    }


    Node* find(Node* root, int a) {
        if (!root) return NULL;
        if (root->data == a) return root;
        
        Node* left_search = find(root->left, a);
        if (left_search) return left_search;
        
        Node* right_search = find(root->right, a);
        return right_search;
    }


    int findDist(Node* root, int a, int b) {
       
        map<Node*, Node*> parent;
        find_parent(root, parent);

       
        Node* a_val = find(root, a);
        if (!a_val) return -1; 
        
        
        queue<Node*> q;
        map<Node*, int> visited;
        visited[a_val] = 1;
        q.push(a_val);

        int cnt = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();

               
                if (node->data == b) return cnt;

                if (node->left && visited.find(node->left) == visited.end()) {
                    visited[node->left] = 1;
                    q.push(node->left);
                }

                if (node->right && visited.find(node->right) == visited.end()) {
                    visited[node->right] = 1;
                    q.push(node->right);
                }

                if (parent.find(node) != parent.end() && visited.find(parent[node]) == visited.end()) {
                    visited[parent[node]] = 1;
                    q.push(parent[node]);
                }
            }
            cnt++;
        }
        return -1; 
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
     
    }
    return 0;
}

// } Driver Code Ends