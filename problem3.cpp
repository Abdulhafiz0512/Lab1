#include <iostream>
#include <queue>
#include <vector>
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

    void insert(Node*& node, int key) {
        if (!node) {
            node = new Node(key);
            return;
        }

        if (key < node->key) {
            insert(node->left, key);
        } else {
            insert(node->right, key);
        }

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balance = getBalance(node);

        // Left Left Case
        if (balance > 1 && key < node->left->key) {
            node = rotateRight(node);
        }
        // Right Right Case
        else if (balance < -1 && key > node->right->key) {
            node = rotateLeft(node);
        }
        // Left Right Case
        else if (balance > 1 && key > node->left->key) {
            node->left = rotateLeft(node->left);
            node = rotateRight(node);
        }
        // Right Left Case
        else if (balance < -1 && key < node->right->key) {
            node->right = rotateRight(node->right);
            node = rotateLeft(node);
        }
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

    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));

        return x;
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));

        return y;
    }

    void levelOrderAverage() {
        if (!root) {
            return;
        }

        vector<double> levelSums;
        vector<int> levelCounts;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            double levelSum = 0.0;

            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();

                levelSum += node->key;

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }

            levelSums.push_back(levelSum);
            levelCounts.push_back(size);
        }

        
        
        for (int i = 0; i < levelSums.size(); i++) {
            cout << levelSums[i] / levelCounts[i];
            if (i != levelSums.size() - 1) {
                cout << " ";
            }
        }
        
        
    }
};

int main() {
    AVLTree avlTree;

    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements in the array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        avlTree.insert(avlTree.root, arr[i]);
    }

    avlTree.levelOrderAverage();

    return 0;
}
