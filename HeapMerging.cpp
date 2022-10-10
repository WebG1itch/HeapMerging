#include <iostream>
#include <stack>
#include <vector>

struct node { // create node struct
    int key;
    node* left = NULL;
    node* right = NULL;
};

node* largeTree(){ // manually create the trees
    node* root = new node;
    root->key = 4;
    root->left = new node;
    root->left->key = 19;
    root->left->left = new node;
    root->left->left->key = 27;
    root->left->left->left = new node;
    root->left->left->left->key = 43;
    root->left->right = new node;
    root->left->right->key = 20;
    root->right = new node;
    root->right->key = 8;
    root->right->left = new node;
    root->right->left->key = 12;
    root->right->left->left = new node;
    root->right->left->left->key = 15;
    root->right->left->right = new node;
    root->right->left->right->key = 25;
    return root;
}

node* smallTree(){ // manually create the trees
    node* root = new node;
    root->key = 6;
    root->left = new node;
    root->left->key = 8;
    root->left->left = new node;
    root->left->left->key = 14;
    root->right = new node;
    root->right->key = 7;
    return root;
}

void merge(node* main, node* small, std::stack<node*>* stack){
    if(main->key > small->key){ // check which node has a smaller key
        stack->push(small); // push the smaller key onto the stack

        if(small->right != NULL) { // check if right node exists
            merge(main, small->right, stack); // recursion

        } else if(small->right == NULL) { // if right node doesn't exist
            small->right = main; // actually start merging

            if(small->left == NULL){ // make leftist
                small->left = small->right;
                small->right = NULL;
            }
            return;
        }

    } else if( main->key < small->key){ // same as above but inverse
        stack->push(main);

        if(main->right != NULL) {
            merge(main->right, small, stack);

        } else if(main->right == NULL) {
            main->right = small;

            if(main->left == NULL) {
                main->left = main->right;
                main->right = NULL;
            }
            return;
        }
    }
    if(!stack->empty()) { // take top of stack and make child of next on stack
        node *stackTop = stack->top();
        stack->pop();
        stack->top()->right = stackTop;
    }
}

int main() {

    node* mainRoot = largeTree(); // create the trees
    node* smallRoot = smallTree();
    std::stack<node*> * stack = new std::stack<node*>; // create the stack
    merge(mainRoot, smallRoot, stack); // call first merge function

    std::vector<node*> nodesArray; // crate a vector for the array representation
    nodesArray.push_back(NULL); // first one is null
    nodesArray.push_back(mainRoot); // pos 1 is main
    for(int i = 1; i < 14; i++) { // loop through the heap and add parent, then children, then children's children etc.
        if (nodesArray[i] != NULL) {
            if (nodesArray[i]->left != NULL) {
                nodesArray.push_back(nodesArray[i]->left);
            }
            if (nodesArray[i]->right != NULL) {
                nodesArray.push_back(nodesArray[i]->right);
            }
        }
    }
    for(int j = 1; j < nodesArray.size(); j++){ // loop and print.
        if(nodesArray[j] != NULL) {
            std::cout << nodesArray[j]->key << " ";
        }
    }
    return 0;
}



