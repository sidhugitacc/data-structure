#include <stdio.h>
#include <stdlib.h>

// Structure for the tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a BST
struct TreeNode* insert(struct TreeNode* root, int value) {
    if (root == NULL) {
        struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        newNode->data = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to search for a value in BST
struct TreeNode* search(struct TreeNode* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }

    if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

// Function to find the minimum value node in a BST
struct TreeNode* findMin(struct TreeNode* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from BST
struct TreeNode* deleteNode(struct TreeNode* root, int value) {
    if (root == NULL) {
        return root;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children, get the inorder successor (smallest in the right subtree)
        struct TreeNode* temp = findMin(root->right);

        // Copy the inorder successor's data to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Function to calculate the height of the BST
int height(struct TreeNode* root) {
    if (root == NULL) {
        return -1; // Height of an empty tree is -1
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Function for inorder traversal
void inorderTraversal(struct TreeNode* root) {
    if (root) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function for preorder traversal
void preorderTraversal(struct TreeNode* root) {
    if (root) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function for postorder traversal
void postorderTraversal(struct TreeNode* root) {
    if (root) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Function to display the tree structure
void displayTree(struct TreeNode* root, int level) {
	int i;
    if (root == NULL)
        return;

    displayTree(root->right, level + 1);
    for (i = 0; i < level; i++)
        printf("\t");
    printf("%d\n", root->data);
    displayTree(root->left, level + 1);
}

// User Input for Binary Tree
struct TreeNode* getUserInput(int size) {
    int i;
    struct TreeNode* bstRoot = NULL;

    printf("Enter values for the binary tree (BST):\n");
    for (i = 0; i < size; i++) {
        int value;
        scanf("%d", &value);
        bstRoot = insert(bstRoot, value);
    }

    return bstRoot;
}

// Main menu function
void showMenu() {
    printf("\n*** Bus Booking System (BST) ***\n");
    printf("1. Insert into BST\n");
    printf("2. Delete from BST\n");
    printf("3. Search in BST\n");
    printf("4. Calculate Height of BST\n");
    printf("5. Perform Inorder Traversal\n");
    printf("6. Perform Preorder Traversal\n");
    printf("7. Perform Postorder Traversal\n");
    printf("8. Display BST Structure\n");
    printf("9. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;
    int size;
    struct TreeNode* bstRoot = NULL;

    do {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of nodes to insert into BST: ");
                scanf("%d", &size);
                bstRoot = getUserInput(size);
                printf("BST created with %d nodes.\n", size);
                break;

            case 2:
                if (bstRoot == NULL) {
                    printf("BST is empty. Insert nodes first.\n");
                    break;
                }
                printf("Enter the value to delete from BST: ");
                int deleteValue;
                scanf("%d", &deleteValue);
                bstRoot = deleteNode(bstRoot, deleteValue);
                printf("Value %d deleted from BST.\n", deleteValue);
                break;

            case 3:
                if (bstRoot == NULL) {
                    printf("BST is empty. Insert nodes first.\n");
                    break;
                }
                printf("Enter the value to search in BST: ");
                int searchValue;
                scanf("%d", &searchValue);
                struct TreeNode* searchResult = search(bstRoot, searchValue);
                if (searchResult != NULL) {
                    printf("Value %d found in BST.\n", searchValue);
                } else {
                    printf("Value %d not found in BST.\n", searchValue);
                }
                break;

            case 4:
                if (bstRoot == NULL) {
                    printf("BST is empty. Insert nodes first.\n");
                    break;
                }
                printf("Height of BST: %d\n", height(bstRoot));
                break;

            case 5:
                if (bstRoot == NULL) {
                    printf("BST is empty. Insert nodes first.\n");
                    break;
                }
                printf("Inorder Traversal: ");
                inorderTraversal(bstRoot);
                printf("\n");
                break;

            case 6:
                if (bstRoot == NULL) {
                    printf("BST is empty. Insert nodes first.\n");
                    break;
                }
                printf("Preorder Traversal: ");
                preorderTraversal(bstRoot);
                printf("\n");
                break;

            case 7:
                if (bstRoot == NULL) {
                    printf("BST is empty. Insert nodes first.\n");
                    break;
                }
                printf("Postorder Traversal: ");
                postorderTraversal(bstRoot);
                printf("\n");
                break;

            case 8:
                if (bstRoot == NULL) {
                    printf("BST is empty. Insert nodes first.\n");
                    break;
                }
                printf("BST Structure:\n");
                displayTree(bstRoot, 0);
                break;

            case 9:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 9);

    return 0;
}

