
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

    Node* insert(Node* root, int key) {
        if (!root) {
            return new Node(key);
        } else if (key < root->key) {
            root->left = insert(root->left, key);
        } else {
            root->right = insert(root->right, key);
        }

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        int balance = getBalance(root);

        if (balance > 1 && key < root->left->key) {
            return rotateRight(root);
        }

        if (balance < -1 && key > root->right->key) {
            return rotateLeft(root);
        }

        if (balance > 1 && key > root->left->key) {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }

        if (balance < -1 && key < root->right->key) {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }

        return root;
    }

    Node* deleteNode(Node* root, int key) {
        if (!root) {
            return root;
        }

        if (key < root->key) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->key) {
            root->right = deleteNode(root->right, key);
        } else {
            if (!root->left || !root->right) {
                Node* temp = root->left ? root->left : root->right;
                if (!temp) {
                    temp = root;
                    root = nullptr;
                } else {
                    *root = *temp;
                }
                delete temp;
            } else {
                Node* temp = getMinValueNode(root->right);
                root->key = temp->key;
                root->right = deleteNode(root->right, temp->key);
            }
        }

        if (!root) {
            return root;
        }

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        int balance = getBalance(root);

        if (balance > 1 && getBalance(root->left) >= 0) {
            return rotateRight(root);
        }

        if (balance < -1 && getBalance(root->right) <= 0) {
            return rotateLeft(root);
        }

        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }

        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }

        return root;
    }

    int getHeight(Node* node) {
        if (!node) {
            return 0;
        }
        return node->height;
    }

    int getBalance(Node* node) {
        if (!node) {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }

    Node* rotateRight(Node* z) {
        Node* y = z->left;
        Node* T = y->right;

        y->right = z;
        z->left = T;

        z->height = 1 + max(getHeight(z->left), getHeight(z->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));

        return y;
    }

    Node* rotateLeft(Node* z) {
        Node* y = z->right;
        Node* T = y->left;

        y->left = z;
        z->right = T;

        z->height = 1 + max(getHeight(z->left), getHeight(z->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));

        return y;
    }

    Node* getMinValueNode(Node* node) {
        Node*
current = node;
        while (current && current->left) {
            current = current->left;
        }
        return current;
    }

    void levelOrderTraversal(Node* root) {
        queue<Node*> q;
        
        if (!root) {
            return;
        }
        
        q.push(root);
        
        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            
            cout << node->key << " ";
            
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

    int n, element, valueToDelete;

    cout << "Enter the number of elements to insert: ";
    cin >> n;

    cout << "Enter the elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> element;
        avlTree.root = avlTree.insert(avlTree.root, element);
    }

    cout << "Enter the value to delete: ";
    cin >> valueToDelete;

    avlTree.root = avlTree.deleteNode(avlTree.root, valueToDelete);

    
    avlTree.levelOrderTraversal(avlTree.root);

    return 0;
}


