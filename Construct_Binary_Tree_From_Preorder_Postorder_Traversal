struct TreeNode* buildList(int* pre, int preStart, int preEnd, 
                          int* post, int postStart, int postEnd){
    
    if(preStart > preEnd) return NULL;  
    
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode -> val = pre[preStart];
    newNode -> left = NULL; 
    newNode -> right = NULL; 
    
    if(preEnd == preStart) return newNode; 
    
    int LeftLength, i;
    for(i = postStart; i <= postEnd; i++)
        if(post[i] == pre[preStart + 1]){
            LeftLength = i - postStart + 1;
            break; 
        }
    
    newNode -> left = buildList(pre, preStart + 1,  preStart + LeftLength, 
                                post, postStart, postStart + LeftLength - 1);
    newNode -> right = buildList(pre, preStart + LeftLength + 1, preEnd, 
                                 post, postStart + LeftLength, postEnd - 1);
    return newNode; 
}



struct TreeNode* Construct_Binary_Tree_From_Preorder_Postorder_Traversal(int* pre, int preSize, int* post, int postSize){
    return buildList(pre, 0, preSize - 1, 
                     post, 0, postSize - 1); 
}
