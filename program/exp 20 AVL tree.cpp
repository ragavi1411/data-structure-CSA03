#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    int height;
    struct Node *left;
    struct Node *right;
};

int height(struct Node *node)
{
    if (node == NULL)
        return 0;

    return node->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

struct Node* createNode(int key)
{
    struct Node *node;

    node = (struct Node*)malloc(sizeof(struct Node));

    node->key = key;
    node->height = 1;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int getBalance(struct Node *node)
{
    if (node == NULL)
        return 0;

    return height(node->left) - height(node->right);
}

struct Node* rightRotate(struct Node *y)
{
    struct Node *x;
    struct Node *T2;

    x = y->left;
    T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

struct Node* leftRotate(struct Node *x)
{
    struct Node *y;
    struct Node *T2;

    y = x->right;
    T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

struct Node* insert(struct Node *node, int key)
{
    int balance;

    if (node == NULL)
        return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left),
                            height(node->right));

    balance = getBalance(node);

    /* Left Left Case */
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    /* Right Right Case */
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    /* Left Right Case */
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    /* Right Left Case */
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

struct Node* minValueNode(struct Node *node)
{
    struct Node *current;

    current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

struct Node* deleteNode(struct Node *root, int key)
{
    struct Node *temp;
    int balance;

    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);

    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else
    {
        if (root->left == NULL || root->right == NULL)
        {
            if (root->left != NULL)
                temp = root->left;
            else
                temp = root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
            {
                *root = *temp;
            }

            free(temp);
        }
        else
        {
            temp = minValueNode(root->right);

            root->key = temp->key;

            root->right = deleteNode(root->right,
                                     temp->key);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left),
                            height(root->right));

    balance = getBalance(root);

    /* Left Left Case */
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    /* Left Right Case */
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    /* Right Right Case */
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    /* Right Left Case */
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int search(struct Node *root, int key)
{
    if (root == NULL)
        return 0;

    if (root->key == key)
        return 1;

    if (key < root->key)
        return search(root->left, key);

    return search(root->right, key);
}

int main()
{
    struct Node *root;
    int choice, key;

    root = NULL;

    while (1)
    {
        printf("\n\n--- AVL TREE ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display Inorder\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &key);

                root = insert(root, key);

                printf("Element inserted successfully.\n");
                break;

            case 2:
                printf("Enter element to delete: ");
                scanf("%d", &key);

                if (search(root, key))
                {
                    root = deleteNode(root, key);
                    printf("Element deleted successfully.\n");
                }
                else
                {
                    printf("Element not found.\n");
                }
                break;

            case 3:
                printf("Enter element to search: ");
                scanf("%d", &key);

                if (search(root, key))
                    printf("Element found.\n");
                else
                    printf("Element not found.\n");

                break;

            case 4:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
