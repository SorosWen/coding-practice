struct TreeNode* buildTree_r(int* preorder, int* inorder, 
                             int preStart, int preEnd,
                             int inStart, int inEnd) {
       
	if(preStart > preEnd || inStart > inEnd) return NULL;
    
	struct TreeNode* root = malloc(sizeof(struct TreeNode));
	root->val = preorder[preStart];
	
    // Find root in inorder
	int in_rootID, i; 
	for(i = inStart; i <= inEnd; i++) {
		if(inorder[i] == root->val) {
			in_rootID = i;
			break;
		}
	}
    
    // create left and right node. 
	root->left  = buildTree_r(preorder, inorder, 
                              preStart + 1, preStart + (in_rootID - inStart), 
                              inStart, in_rootID - 1); 
	root->right = buildTree_r(preorder, inorder, 
                              preStart+ (in_rootID - inStart) + 1, preEnd, 
                              in_rootID + 1, inEnd); 
    
	return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) { 
	if(inorder == NULL || preorder == NULL)
		return NULL;

	return buildTree_r(preorder, inorder, 0, preorderSize - 1, 0, inorderSize - 1);
}
