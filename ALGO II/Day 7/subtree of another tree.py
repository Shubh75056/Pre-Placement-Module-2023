class Solution(object):
    def isSubtree(self, root, subRoot):
        """
        :type root: TreeNode
        :type subRoot: TreeNode
        :rtype: bool
        """
        if root==None and subRoot==None:
            return True
        if subRoot==None:
            return True
        if root == None:
            return False
        if root.val == subRoot.val and self.match(root,subRoot):
            return True
        if self.isSubtree(root.left,subRoot):
            return True
        if self.isSubtree(root.right,subRoot):
            return True
        return False
    def match(self,r1,r2):
        if r1==None and r2==None:
            return True
        if r1==None or r2==None:
            return False
        if r1.val != r2.val:
            return False
        return self.match(r1.left,r2.left) and self.match(r1.right,r2.right)