//
// Created by Zeno on 2020/6/21.
//

/*
 * 解法一
 * 中序遍历用vector存储所有的node，之后再遍历vector，对node进行改动
 * time complexity:O(n)
 * space complexity:O(n)
 */
class Solution {
public:
    Node *treeToDoublyList(Node *root) {
        inorderTraversal(root);
        int size = nodes.size();
        for (int i = 0; i < size - 1; i++) {
            Node *cur = nodes[i];
            Node *next = nodes[i + 1];
            cur->right = next;
            next->left = cur;
        }
        if (size == 0) {
            return nullptr;
        } else if (size == 1) {
            return root;
        }
        nodes[size - 1]->left = nodes[size - 2];
        return nodes[0];
    }

private:
    vector<Node *> nodes;

    void inorderTraversal(Node *root) {
        if (root == nullptr) {
            return;
        }

        if (root->left) {
            inorderTraversal(root->left);
        }
        nodes.push_back(root);
        if (root->right) {
            inorderTraversal(root->right);
        }
    }
};

/*
 * 解法二
 * 在中序遍历的过程中改变节点的left和right指针
 * 用head保存链表的头，用prev保存链表的上一个节点
 * time complexity:O(n)
 * space complexity:O(1)
 */
class Solution {
public:
    Node *treeToDoublyList(Node *root) {
        if (root == nullptr) {
            return nullptr;
        }
        Node *head = nullptr, *prev = nullptr;
        helper(root, head, prev);
        head->left = prev;
        prev->right = head;
        return head;
    }

    void helper(Node *root, Node *&head, Node *&prev) {
        if (root == nullptr) {
            return;
        }
        helper(root->left, head, prev);
        if (head == nullptr) {
            head = root; // 找到head
            prev = root; // 对prev进行初始化
        } else {
            prev->right = root;
            root->left = prev;
            prev = root;
        }
        helper(root->right, head, prev);
    }
};