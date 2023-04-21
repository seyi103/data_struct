#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* next;
    int index;
};

struct LinkedList {
    Node* head;
    int size;

    LinkedList() {
        head = NULL;
        size = 0;
    }

    void push_back(int value) {
        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = NULL;
        newNode->index = size;

        if (head == NULL) {
            head = newNode;
        } else {
            Node* cur = head;
            while (cur->next != NULL) {
                cur = cur->next;
            }
            cur->next = newNode;
        }

        size++;
    }

    Node* operator[](int index) {
        if (index < 0 || index >= size) {
            return NULL;
        }

        Node* cur = head;
        while (cur != NULL && cur->index != index) {
            cur = cur->next;
        }

        return cur;
    }
};

int main() {
    LinkedList list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    Node* node1 = list[0];
    Node* node2 = list[1];
    Node* node3 = list[2];

    cout << node1->value << " " << node2->value << " " << node3->value << endl;

    return 0;
}
