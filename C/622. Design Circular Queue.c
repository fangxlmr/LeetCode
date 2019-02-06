/*
 * When I submit it, the following issue happens and I don't know why.
 * This may related to malloc and free function.
 * *** Error in `sandbox run': free(): invalid next size (fast): 0x0000000002239b50 ***
 */
typedef struct {
    int *items;
    int n;
    int front, rear;
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */
MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue *queue;
    int *items;

    queue = (MyCircularQueue *) malloc(sizeof(MyCircularQueue));
    if (queue == NULL) {
        return NULL;
    } else {
        items = (int *) malloc(k * sizeof(int));
        if (items == NULL) {
            free(queue);
            return NULL;
        } else {
            queue->items = items;
            queue->n = k + 1;
            queue->front = queue->rear = 0;
            return queue;
        }
    }
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    int n = obj->n;

    if ((obj->rear + 1) % n == obj->front) {
        return false;
    } else {
        obj->items[obj->rear] = value;
        obj->rear = (obj->rear + 1) % n;
        return true;
    }
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    int n = obj->n;

    if (obj->front == obj->rear) {
        return false;
    } else {
        obj->front = (obj->front + 1) % n;
        return true;
    }
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
    int n = obj->n;

    if (obj->front == obj->rear) {
        return -1;
    } else {
        return obj->items[obj->front];
    }
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
    int n = obj->n;

    if (obj->front == obj->rear) {
        return -1;
    } else {
        return obj->items[(obj->rear + n - 1) % n];
    }
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->front == obj->rear;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    int n = obj->n;

    return (obj->rear + 1) % n == obj->front;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->items);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * struct MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 * bool param_2 = myCircularQueueDeQueue(obj);
 * int param_3 = myCircularQueueFront(obj);
 * int param_4 = myCircularQueueRear(obj);
 * bool param_5 = myCircularQueueIsEmpty(obj);
 * bool param_6 = myCircularQueueIsFull(obj);
 * myCircularQueueFree(obj);
 */