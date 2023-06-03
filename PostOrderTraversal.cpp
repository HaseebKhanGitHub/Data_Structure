#include <iostream>
#include <stack>

using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
  Node(int x) : data(x), left(NULL), right(NULL) {}
};

void replaceNode(Node* root) {
  if (root == NULL)
   return;

  replaceNode(root->left);
  replaceNode(root->right);

  if (root->data == 6) root->data = 0;
}

void postorderTraversal(Node* root) {
  stack<Node*> s;
  Node* current = root;

  while (current != NULL || !s.empty()) {
    if (current != NULL) {
      s.push(current);
      current = current->left;
    }
    else {
      Node* temp = s.top()->right;
      if (temp == NULL) {
        temp = s.top();
        s.pop();
        cout << temp->data << " ";
        while (!s.empty() && temp == s.top()->right) {
          temp = s.top();
          s.pop();
          cout << temp->data << " ";
        }
      }
      else {
        current = temp;
      }
    }
  }
}

int main() {
  // Construct the following tree:
  //         1
  //        / \
  //       2   3
  //      /   / \
  //     4   5   6    //427589631  //left,right,root	
  //        /   / \
  //       7   8   9
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->right->left = new Node(5);
  root->right->right = new Node(6);
  root->right->left->left = new Node(7);
  root->right->right->left = new Node(8);
  root->right->right->right = new Node(9);

  cout << "Original tree values: ";
  postorderTraversal(root);
  cout << endl;

  
  replaceNode(root);

  cout << "Modified tree values: ";
  postorderTraversal(root);
  cout << endl;

  return 0;
}
