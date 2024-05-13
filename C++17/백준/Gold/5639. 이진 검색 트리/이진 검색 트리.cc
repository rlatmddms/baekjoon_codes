#include <iostream>
#include <vector>

using namespace std;

struct Tree {
    int data;
    Tree* left;
    Tree* right;
};

// 후위순회 함수
void postorder(Tree* root) {
    if (root == nullptr)
        return;

    // 왼쪽 서브트리 방문
    postorder(root->left);

    // 오른쪽 서브트리 방문
    postorder(root->right);

    // 현재 노드 출력
    cout << root->data << " ";
}

// 전위순회 결과를 이용하여 이진 탐색 트리 생성 함수
Tree* buildTree(vector<int>& preorder) {
    Tree* root = nullptr;
    for (int data : preorder) {
        Tree* newNode = new Tree();
        newNode->data = data;
        newNode->left = nullptr;
        newNode->right = nullptr;

        if (root == nullptr) {
            root = newNode;
        } else {
            Tree* current = root;
            while (true) {
                if (data < current->data) {
                    if (current->left == nullptr) {
                        current->left = newNode;
                        break;
                    } else {
                        current = current->left;
                    }
                } else {
                    if (current->right == nullptr) {
                        current->right = newNode;
                        break;
                    } else {
                        current = current->right;
                    }
                }
            }
        }
    }
    return root;
}

int main() {
    vector<int> preorder;

    // 전위순회 결과 입력 받기
    int input;
    while (cin >> input) {
        preorder.push_back(input);
    }

    // 전위순회 결과를 이용하여 이진 탐색 트리 생성
    Tree* root = buildTree(preorder);

    // 후위순회 결과 출력
    postorder(root);
    cout << endl;

    return 0;
}
