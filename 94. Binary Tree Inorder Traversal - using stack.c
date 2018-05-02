/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */


typedef struct TreeNode TreeNode, *pTreeNode;
typedef struct Stack
{
    pTreeNode tnode;
    struct Stack *next;
}Stack, *pStackNode;


/* a stack */
pStackNode stack = NULL;


bool push(pTreeNode);
bool pop();
void array_append(int *, int, int *);
bool stack_empty ();


int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if (!root)
        return NULL;
    /* creat a new stack */
    stack = (pStackNode) malloc (sizeof(Stack));
    stack->tnode = NULL;
    stack->next = NULL;


    pTreeNode t = root;
    /* result array for return*/
    int *result = (int *) calloc(1000, sizeof(int));

    // push(stack, t);
    /* if tree and stack both not empty*/
    int i = 0;
    while (t || !stack_empty()) {
        if (t) {
            push(t);     /* push parent node into stack */
            t = t->left;
        }
        else {
            t = stack->tnode;      /* operate left child node */
            pop();
            array_append(result, t->val, returnSize);
            t = t->right;

        }
    }
    free(stack);
    return result;
}


/* push tnode into stack*/
bool push (pTreeNode tnode) {
    pStackNode p = (pStackNode) calloc(1, sizeof(Stack));
    if (!p){
        stack->tnode = 0;
        free(p);
        return false;
    }
    p->tnode = tnode;
    p->next = stack;
    stack = p;
    return true;
}


/* pop element on the top of the stack */
bool pop () {
    if (!stack->next) {
        printf("stack is empty. exiting...\n");
        return false;
    }
    pStackNode p = stack;
    stack = stack->next;
    free(p);
    p = NULL;
    return true;
}

bool stack_empty () {
    if(stack->next == NULL)
        return true;
    else
        return false;
}


void array_append(int *array, int val, int *index) {
    *(array + *index) = val;
    *index += 1;
    return;
}