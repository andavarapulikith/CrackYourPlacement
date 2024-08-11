//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node* divide(Node* head) {
         Node* evenStart = NULL;
        Node* evenEnd = NULL;
        Node* oddStart = NULL;
        Node* oddEnd = NULL;
        Node* current = head;
        while (current != NULL) {
            int val = current->data;
            if (val % 2 == 0) { 
                if (evenStart == NULL) {
                    evenStart = current;  
                    evenEnd = evenStart;
                } else {
                    evenEnd->next = current; 
                    evenEnd = evenEnd->next;
                }
            } else {  // Odd node
                if (oddStart == NULL) {
                    oddStart = current;  
                    oddEnd = oddStart;
                } else {
                    oddEnd->next = current;  
                    oddEnd = oddEnd->next;
                }
            }
            current = current->next;
        }
        if (evenStart == NULL) {
            return oddStart;
        }
        if (oddStart == NULL) {
            return evenStart;
        }
        

        evenEnd->next = oddStart;
        oddEnd->next = NULL; 
        return evenStart;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty())
            continue;

        int data = arr[0];
        int N = arr.size();
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 1; i < N; ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        Node *ans = ob.divide(head);
        printList(ans);
    }
    return 0;
}

// } Driver Code Ends