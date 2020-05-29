# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        self.diameter = 0
        self.compute(root)
        return self.diameter
    
    def compute(self, root):
        if not root: return 0
        right_depth = self.compute(root.right)
        left_depth = self.compute(root.left)
        length = right_depth + left_depth
        if length > self.diameter: self.diameter = length 
        return max(right_depth, left_depth) + 1
