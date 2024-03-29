#include <iostream>
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
    list.display();

    return 0;
}
