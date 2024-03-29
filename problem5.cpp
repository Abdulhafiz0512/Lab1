#include <iostream>
#include <unordered_set>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = nullptr;
    }

    void insert(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void deleteDuplicates() {
        unordered_set<int> seen;
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr) {
            if (seen.find(current->data) != seen.end()) {
                prev->next = current->next;
                delete current;
                current = prev->next;
            } else {
                seen.insert(current->data);
                prev = current;
                current = current->next;
            }
        }
    }

    void sortAscending() {
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        Node* current = head;
        while (current != nullptr) {
            Node* index = current->next;
            while (index != nullptr) {
                if (current->data > index->data) {
                    int temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
};

int main() {
    LinkedList list;
    int n, data;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> data;
        list.insert(data);
    }

    list.display();
    list.sortAscending();
    list.deleteDuplicates();
    list.display();
    return 0;
}