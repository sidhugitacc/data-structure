#include <stdio.h>
#include <stdlib.h>

// Binary Tree Node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary tree using level order traversal
struct Node *insertLevelOrder(int arr[], struct Node *root, int i, int n)
{
    if (i < n)
    {
        struct Node *temp = createNode(arr[i]);
        root = temp;

        root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);
        root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
    }
    return root;
}

// Function to perform preorder traversal
void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Function to perform inorder traversal
void inOrder(struct Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Function to perform postorder traversal
void postOrder(struct Node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

// Function to create a binary tree using inorder and preorder traversals
struct Node *buildTree(int inOrder[], int preOrder[], int inStart, int inEnd)
{
    static int preIndex = 0;

    if (inStart > inEnd)
        return NULL;

    struct Node *newNode = createNode(preOrder[preIndex++]);

    if (inStart == inEnd)
        return newNode;

    int inIndex;
    for (inIndex = inStart; inIndex <= inEnd; inIndex++)
        if (inOrder[inIndex] == newNode->data)
            break;

    newNode->left = buildTree(inOrder, preOrder, inStart, inIndex - 1);
    newNode->right = buildTree(inOrder, preOrder, inIndex + 1, inEnd);

    return newNode;
}

// Function to display the bus reservation menu
void displayMenu()
{
    printf("\nBus Reservation Menu:\n");
    printf("1. Display Bus Schedule (Level Order Traversal)\n");
    printf("2. Reserve Seats (Inorder and Preorder Traversal)\n");
    printf("3. Exit\n");
}

int main()
{
    int levelOrder[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(levelOrder) / sizeof(levelOrder[0]);

    // Creating binary tree using level order traversal
    struct Node *rootLevelOrder = insertLevelOrder(levelOrder, NULL, 0, n);

    int inOrderSeq[] = {4, 2, 5, 1, 6, 3, 7};
    int preOrderSeq[] = {1, 2, 4, 5, 3, 6, 7};
    int inStart = 0;
    int inEnd = n - 1;

    struct Node *rootDepthOrder = buildTree(inOrderSeq, preOrderSeq, inStart, inEnd);

    int choice;
    do
    {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nBus Schedule (Level Order Traversal):\n");
            printf("Preorder Traversal: ");
            preOrder(rootLevelOrder);
            printf("\nInorder Traversal: ");
            inOrder(rootLevelOrder);
            printf("\nPostorder Traversal: ");
            postOrder(rootLevelOrder);
            break;

        case 2:
            printf("\nReserve Seats (Inorder and Preorder Traversal):\n");
            printf("Preorder Traversal: ");
            preOrder(rootDepthOrder);
            printf("\nInorder Traversal: ");
            inOrder(rootDepthOrder);
            printf("\nPostorder Traversal: ");
            postOrder(rootDepthOrder);
            // Additional seat reservation logic can be added here
            break;

        case 3:
            printf("Exiting the program\n");
            break;

        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 3);

    return 0;
}

