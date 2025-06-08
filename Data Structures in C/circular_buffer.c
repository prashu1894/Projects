#include <stdio.h>
#include <stdlib.h>
#define MAX_BUF_SIZE 5

typedef struct CB_t {
    int head;
    int tail;
    int buffer[MAX_BUF_SIZE];
    int size;
}CB_t;

typedef enum Status {
    EOK,
    BUF_FULL,
    BUF_EMPTY,
    BUF_ERR,
} Status_t;

int check_buffer_status(CB_t* buffer) {
    printf("head: %d, tail: %d, size: %d\n", buffer->head, buffer->tail, buffer->size);
    if (buffer->size == 0) {
        return BUF_EMPTY;
    } else if (buffer->size == MAX_BUF_SIZE) {
        return BUF_FULL;
    } else if (buffer->head > buffer->tail) {
        return BUF_ERR;
    }
}

void insert_node (CB_t *buffer, int value) {
    if (check_buffer_status(&buffer)==BUF_FULL) {
            printf("Buffer FULL\n");
            return;
    }
    buffer->buffer[buffer->tail] = value;
    buffer->tail++;
    buffer->size++;
    return;
}

void remove_node ( CB_t * buffer) {
    if (check_buffer_status(&buffer)==BUF_EMPTY) {
            printf("Buffer EMPTY\n");
            return;
    }
    printf("%d is removed\n", buffer->buffer[buffer->head]);
    buffer->head++;
    if (buffer->head == MAX_BUF_SIZE) {
        buffer->head = 0;
    }
    buffer->size--;
    if (buffer->head == buffer->tail) {
        buffer->head = 0;
        buffer->tail = 0;
    }
    return;
}

void print_buffer(CB_t * buffer) {
    if (check_buffer_status(&buffer)== BUF_EMPTY) {
        printf("Buffer EMPTY\n");
        return;
    }
    for (int i = buffer->head; i < buffer->tail; i++) {
        printf("%d ", buffer->buffer[i]);
    }
    printf("\n");
    return;
}
int main() {
    CB_t buffer;
    buffer.head = 0;
    buffer.tail = 0;
    buffer.size = 0;
    insert_node(&buffer, 10);
    insert_node(&buffer, 20);
    print_buffer(&buffer);
    remove_node(&buffer);
    print_buffer(&buffer);
    remove_node(&buffer);
    print_buffer(&buffer);
    return 0;
}