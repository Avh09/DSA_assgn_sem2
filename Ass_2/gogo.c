#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* createNode(int data) {
    TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to construct the family tree from the given level order traversal array
TreeNode* constructFamilyTree(int *levelOrder, int n, int index) {
    if (index >= n || levelOrder[index] == 0) {
        return NULL; // Null node
    }
    TreeNode *root = createNode(levelOrder[index]);
    root->left = constructFamilyTree(levelOrder, n, 2 * index + 1);
    root->right = constructFamilyTree(levelOrder, n, 2 * index + 2);
    return root;
}

// Recursive function to compute the minimum number of phones required for the family tree
int minPhones(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int leftMin = minPhones(root->left);
    int rightMin = minPhones(root->right);
    return root->data + leftMin + rightMin - 1;
}

int main() {
    int n;
    printf("Enter the size of level order traversal: ");
    scanf("%d", &n);
    
    int levelOrder[n];
    printf("Enter the level order traversal: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &levelOrder[i]);
    }

    // Construct the family tree from the level order traversal
    TreeNode* root = constructFamilyTree(levelOrder, n, 0);
    
    // Calculate the minimum number of phones required
    int minPhonesRequired = minPhones(root);

    printf("Minimum number of phones required: %d\n", minPhonesRequired);

    return 0;
}
