#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
public:
    Node* root;

    AVLTree() : root(nullptr) {}

    // Function to calculate the sum of all leaves in the AVL tree
    int sumOfLeaves(Node* node) {
        if (!node) {
            return 0;
        }
        if (!node->left && !node->right) {
            return node->key;
        }
        return sumOfLeaves(node->left) + sumOfLeaves(node->right);
    }

    // Function to perform level order traversal of the AVL tree
    void levelOrderTraversal(Node* root) {
        queue<Node*> q;
        
        if (!root) {
            return;
        }
        
        q.push(root);
        
        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            
            if (!node->left && !node->right) {
                cout << node->key << " ";
            }
            
            if (node->left) {
                q.push(node->left);
            }
            
            if (node->right) {
                q.push(node->right);
            }
        }
    }
};

int main() {
    AVLTree avlTree;

    int n, element;

    cout << "Enter the number of nodes in the AVL tree: ";
    cin >> n;

    cout << "Enter the elements in level order traversal:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> element;
        if (i == 0) {
            avlTree.root = new Node(element);
        } else {
            queue<Node*> q;
            q.push(avlTree.root);

            while (!q.empty()) {
                Node* curr = q.front();
                q.pop();

                if (!curr->left) {
                    curr->left = new Node(element);
                    break;
                } else {
                    q.push(curr->left);
                }

                if (!curr->right) {
                    curr->right = new Node(element);
                    break;
                } else {
                    q.push(curr->right);
                }
            }
        }
    }

    cout  << avlTree.sumOfLeaves(avlTree.root) << endl;

    

    return 0;
}
