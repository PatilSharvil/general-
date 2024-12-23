//Name : Sharvil Sunil Patil
//Roll No : 2001
//Class : SY CSE A
//Batch : S1

#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    int data;
    struct NODE *left;
    struct NODE *right;
};
typedef struct NODE Node;

Node *CreateNode(Node *node, int data)
{
    if (node == NULL)
    {
        node = (Node *)malloc(sizeof(Node));
        if (node == NULL)
        {
            printf("Memory allocation failed!\n");
            return NULL;
        }
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        return node;
    }

    if (data < node->data)
    {
        node->left = CreateNode(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = CreateNode(node->right, data);
    }

    return node;
}

void Inorder(Node *node)
{
    if (node == NULL)
        return;

    Inorder(node->left);
    printf("%d ", node->data);
    Inorder(node->right);
}

void Preorder(Node *node)
{
    if (node == NULL)
        return;

    printf("%d ", node->data);
    Preorder(node->left);
    Preorder(node->right);
}

void Postorder(Node *node)
{
    if (node == NULL)
        return;

    Postorder(node->left);
    Postorder(node->right);
    printf("%d ", node->data);
}

void search(Node* node,int key)
{
    if(node == NULL)
    {
        printf("Search Unsuccessful!\n");
        return;
    }

    if(key == node->data)
    {
        printf("Search Successful!\n");
    }
    else if(key < node->data)
    {
        search(node->left,key);
    }
    else
    {
        search(node->right,key);
    }
}

int main()
{
    Node *root = NULL;
    int choice, data,key;

    while (1)
    {
        printf("-----------MENU-----------\n");
        printf("1. Create Node in Tree\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Search Element\n");
        printf("6.Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &data);
            root = CreateNode(root, data);
            break;
        case 2:
            printf("Inorder Traversal: ");
            Inorder(root);
            printf("\n");
            break;
        case 3:
            printf("Preorder Traversal: ");
            Preorder(root);
            printf("\n");
            break;
        case 4:
            printf("Postorder Traversal: ");
            Postorder(root);
            printf("\n");
            break;
        case 5:
            printf("Enter the key : ");
            scanf("%d",&key);
            search(root,key);
            break;
        case 6 : 
            printf("Exiting program.\n");
            return 0;    
        default:
            printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

//---------OUTPUT---------
// -----------MENU-----------
// 1. Create Node in Tree
// 2. Inorder Traversal
// 3. Preorder Traversal
// 4. Postorder Traversal
// 5. Search Element
// 6.Exit
// Enter the choice: 1
// Enter the data: 5
// -----------MENU-----------
// 1. Create Node in Tree
// 2. Inorder Traversal
// 3. Preorder Traversal
// 4. Postorder Traversal
// 5. Search Element
// 6.Exit
// Enter the choice: 1
// Enter the data: 4
// -----------MENU-----------
// 1. Create Node in Tree
// 2. Inorder Traversal
// 3. Preorder Traversal
// 4. Postorder Traversal
// 5. Search Element
// 6.Exit
// Enter the choice: 1
// Enter the data: 6
// -----------MENU-----------
// 1. Create Node in Tree
// 2. Inorder Traversal
// 3. Preorder Traversal
// 4. Postorder Traversal
// 5. Search Element
// 6.Exit
// Enter the choice: 2
// Inorder Traversal: 4 5 6 
// -----------MENU-----------
// 1. Create Node in Tree
// 2. Inorder Traversal
// 3. Preorder Traversal
// 4. Postorder Traversal
// 5. Search Element
// 6.Exit
// Enter the choice: 3
// Preorder Traversal: 5 4 6 
// -----------MENU-----------
// 1. Create Node in Tree
// 2. Inorder Traversal
// 3. Preorder Traversal
// 4. Postorder Traversal
// 5. Search Element
// 6.Exit
// Enter the choice: 4
// Postorder Traversal: 4 6 5 
// -----------MENU-----------
// 1. Create Node in Tree
// 2. Inorder Traversal
// 3. Preorder Traversal
// 4. Postorder Traversal
// 5. Search Element
// 6.Exit
// Enter the choice: 5
// Enter the key : 5
// Search Successful!
// -----------MENU-----------
// 1. Create Node in Tree
// 2. Inorder Traversal
// 3. Preorder Traversal
// 4. Postorder Traversal
// 5. Search Element
// 6.Exit
// Enter the choice: 5
// Enter the key : 4
// Search Successful!
// -----------MENU-----------
// 1. Create Node in Tree
// 2. Inorder Traversal
// 3. Preorder Traversal
// 4. Postorder Traversal
// 5. Search Element
// 6.Exit
// Enter the choice: 5
// Enter the key : 6
// Search Successful!
// -----------MENU-----------
// 1. Create Node in Tree
// 2. Inorder Traversal
// 3. Preorder Traversal
// 4. Postorder Traversal
// 5. Search Element
// 6.Exit
// Enter the choice: 5
// Enter the key : 1
// Search Unsuccessful!
// -----------MENU-----------
// 1. Create Node in Tree
// 2. Inorder Traversal
// 3. Preorder Traversal
// 4. Postorder Traversal
// 5. Search Element
// 6.Exit
// Enter the choice: 6
// Exiting program.