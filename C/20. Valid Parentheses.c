typedef struct Node{    /* 栈结点结构*/
    char c;
    struct Node *next;
}Node, *pNode;
typedef struct LinkStack{   /* 栈结构 */
    pNode top;
    int count;
}LinkStack, *pStack;

bool isValid(char *);
bool push(pStack, char);
bool pop(pStack);


bool isValid(char* s) {
    int len = strlen(s);
    if(!len){   /* 空串，符合要求 */
        return true;
    }
    if(len % 2 == 1){   /* 奇数，必定不符合要求 */
        return false;
    }

    /* 数量为偶数 */
    pStack Stack = (pStack) malloc(sizeof(LinkStack));  /* 新建栈 */
    Stack->top = NULL;
    Stack->count = 0;

    int i;
    for(i = 0; i < len; ++i){
        if((Stack->top != NULL) && \
            ((s[i] - Stack->top->c == 1) || (s[i] - Stack->top->c == 2)))   /* 相等则top出栈 */

            pop(Stack);
        else{
            push(Stack, s[i]);  /* 不相等，则新元素入栈 */
        }
}
    if(Stack->top == NULL)
        return true;
    else
        return false;
}

bool push(pStack Stack, char c){
    pNode pNew = (pNode) malloc(sizeof(Node));     /* 新建结点 */

    pNew->c = c;
    pNew->next = Stack->top;
    Stack->top = pNew;
    ++Stack->count;

    return true;
}

bool pop(pStack Stack){
    if(Stack->top == NULL){
        printf("Stack is empty...\n");
        return false;
    }
    pNode pDel = Stack->top;

    Stack->top = Stack->top->next;
    free(pDel);
    pDel = NULL;
    --Stack->count;

    return true;
}