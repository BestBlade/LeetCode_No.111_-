/* ------------------------------------------------------------------|
给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明：叶子节点是指没有子节点的节点。

 

示例 1：


输入：root = [3,9,20,null,null,15,7]
输出：2
示例 2：

输入：root = [2,null,3,null,4,null,5,null,6]
输出：5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-depth-of-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	DFS法
*
*	执行用时：428 ms, 在所有 C++ 提交中击败了57.18%的用户
*	内存消耗：141 MB, 在所有 C++ 提交中击败了68.59%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

int minDepth(TreeNode* root) {
    if (!root) {
        return 0;
    }
    queue<TreeNode*> q;
    q.emplace(root);
    int mindep = 1;
    while (!q.empty()) {
        int len = q.size();
        while (len--) {
            TreeNode* curr = q.front();
            q.pop();
            if (!curr->left && !curr->right) {
                return mindep;
            }
            if (curr->left) {
                q.emplace(curr->left);
            }
            if (curr->right) {
                q.emplace(curr->right);
            }
        }
        mindep++;
    }
    return mindep;
}