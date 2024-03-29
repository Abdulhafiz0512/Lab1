#include  <iostream>

using namespace std;

class Leaf{
public:
    string msg;
    Leaf(string msg){
        this->msg=msg;
    }
};
class Node{
public:
    int value;
    Node *left;
    Node *right;
    Leaf *leftL;
    Leaf *rightL;
    Node(int val){
        value=val;
        left=NULL;
        right=NULL;
        leftL=NULL;
        rightL=NULL;
    }
};


int main() {
    Node *root = new Node(80);


    Node *left54 = new Node(54);
    root->left=left54;
    Node * right60 = new Node(60);
    Node *left49 = new Node(49);
    Leaf *leafFlower = new Leaf("Flower");
    Leaf *leaf55 = new Leaf("55");
    Leaf *leafHappy = new Leaf("Happy");
    Leaf *leafVictory = new Leaf("Victory");
    left54 ->right=right60;
    left54 -> left = left49;
    right60 ->rightL=leafFlower;
    right60 -> leftL = leaf55;
    left49 ->rightL =leafHappy;
    left49 -> leftL =leafVictory;


    Node *right140 = new Node(140);
    root ->right=right140;
    Leaf *leafNet = new Leaf("Net");
    right140->rightL=leafNet;
    Node *left104 = new Node(104);
    right140->left=left104;
    Leaf *leafVision = new Leaf("Vision");
    left104->rightL = leafVision;
    Leaf *leafPower = new Leaf("Power");
    left104->leftL = leafPower;

    int val;
    cin>> val;
    bool check = false;
    Node *tmp =root;
    while (!check) {

        if (val > tmp->value) {
            if (tmp-> right == NULL) {
                cout << tmp->rightL->msg;
                check = 1;
                break;
            }
            tmp= tmp->right;
        }
        else {
            if (tmp -> left== NULL) {
                cout << tmp->leftL ->msg;
                check=1;
                break;
            }
            tmp= tmp->left;

        }
    }





    return 0;
}