//
// Created by Mike on 2021/8/16.
//

/*
 * 114. 二叉树展开为链表
 * 给你二叉树的根结点 root ，请你将它展开为一个单链表：
 * - 展开后的单链表应该同样使用 TreeNode ，
 *   其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
 * - 展开后的单链表应该与二叉树 先序遍历 顺序相同.
 */

/*
        1
       / \
      2   5
     / \   \
    3   4   6

 1) 将 1 的左子树插入到右子树的地方:
       1
         \
          2         5
         / \         \
        3   4         6

2) 将原来的右子树接到左子树的最右边节点:
        1
         \
          2
         / \
        3   4
             \
              5
               \
                6

3) 将 2 的左子树插入到右子树的地方:
    1
     \
      2
       \
        3       4
                 \
                  5
                   \
                    6

4) 将原来的右子树接到左子树的最右边节点:
    1
     \
      2
       \
        3
         \
          4
           \
            5
             \
              6
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        while (root) {
            if(!root->left) {
                root = root->right;
            } else {
                // 找左子树最右边的节点
                TreeNode* pre = root->left;
                while(pre->right) {
                    pre = pre->right;
                }
                // 将原来的右子树接到左子树的最右边节点
                pre->right = root->right;
                // 将左子树插入到右子树的地方
                root->right = root->left;
                // 原来左子🌲置空
                root->left = nullptr;
                // 遍历下一个节点
                root = root->right;
            }
        }
    }
};