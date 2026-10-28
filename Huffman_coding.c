
#include <stdio.h>
#include <stdlib.h>

struct Node {
    char ch;
    int freq;
    struct Node *left, *right;
};

struct Node* createNode(char ch, int freq) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->ch = ch;
    newNode->freq = freq;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void printCodes(struct Node* root, char code[], int top) {
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL) {
        code[top] = '\0';
        printf("%c : %s\n", root->ch, code);
        return;
    }

    code[top] = '0';
    printCodes(root->left, code, top + 1);

    code[top] = '1';
    printCodes(root->right, code, top + 1);
}

int main() {
    int n, i, j;
    char chars[100], code[100];
    int freq[100];

    struct Node* nodes[200];

    printf("Enter number of characters: ");
    scanf("%d", &n);

    printf("Enter characters:\n");
    for (i = 0; i < n; i++)
        scanf(" %c", &chars[i]);

    printf("Enter frequencies:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &freq[i]);
        nodes[i] = createNode(chars[i], freq[i]);
    }

    int size = n;

    while (size > 1) {
        int min1 = 0, min2 = 1;

        if (nodes[min1]->freq > nodes[min2]->freq) {
            int temp = min1;
            min1 = min2;
            min2 = temp;
        }

        for (i = 2; i < size; i++) {
            if (nodes[i]->freq < nodes[min1]->freq) {
                min2 = min1;
                min1 = i;
            } else if (nodes[i]->freq < nodes[min2]->freq) {
                min2 = i;
            }
        }

        struct Node* left = nodes[min1];
        struct Node* right = nodes[min2];

        struct Node* parent = createNode('-', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        if (min1 > min2) {
            int temp = min1;
            min1 = min2;
            min2 = temp;
        }

        nodes[min1] = parent;

        for (j = min2; j < size - 1; j++)
            nodes[j] = nodes[j + 1];

        size--;
    }

    printf("Huffman Codes:\n");
    printCodes(nodes[0], code, 0);

    return 0;
}
