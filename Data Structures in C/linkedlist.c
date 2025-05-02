#include <stdio.h>
#include <stdlib.h>


struct Node {
    int value;
    struct  Node * next;
};

struct Node* createNode (int val) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->next = NULL;
    newnode->value = val;
    return newnode;
}
void insert_head(struct Node** head, int val) {
    if ( val == 0)
        return;
    struct Node* node = createNode(val);
    if (*head == NULL) {
        *head = node;
        return;
    }
    node->next = *head;
    *head = node;
    return;
}

void insert_tail(struct Node** head, int val) { 
    if ( val == 0)
        return;
    struct Node* node = createNode(val);
    if (*head == NULL) {
        *head = node;
        return;
    }
    struct Node* temp = *head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = node;
    return;
}

void insert_position(struct Node** head, int val, int position) {
    if ( val == 0)
        return;
    struct Node* node = createNode(val);
    if (*head == NULL) {
        *head = node;
        return;
    }
    if (position == 1) {
        node->next = *head;
        *head = node;
        return;
    }
    int track = 0;
    struct Node* temp = *head;
    while (temp) {
        if (track == position - 1) {
            break;
        }
        temp = temp->next;
        track++;
    };
    if (temp == NULL) {
        printf("Position is out of range\n");
        return;
    }
    node->next = temp->next;
    temp->next = node;
    return;
}

void reverse_list(struct Node** head) {
    struct Node* current = NULL;
    struct Node* prev = NULL;
    struct Node* next = NULL;
    current = *head;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
    return;
}
void print_List(struct Node* head) {
    if(head == NULL) {
        printf("List is Empty\n");
        return;
    }
    struct Node* temp = head;
    while (temp)
    {
        printf("%d ->", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
    return;
}

int cycle_detection(struct Node* head) {
    if (head == NULL)
        return 0;
    struct Node* slow = head;
    struct Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return 1;
    }
    return 0;
    
}


int main() {
    struct Node * head = NULL;
    print_List(head);
    insert_head(&head, 5);
    insert_head(&head,12);
    insert_head(&head, 10);
    insert_head(&head, 20);
    print_List(head);
    insert_tail(&head, 40);
    print_List(head);
    reverse_list(&head);
    print_List(head);
    insert_position(&head,100, 2);
    print_List(head);
    printf("%s", (cycle_detection(head) == 0)?"False":"True"); 
    return 0;
 }