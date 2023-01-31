#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct Node {
    int data;
    struct Node *next;
};


/* Given a reference (pointer to pointer) to the head of a list and an int, inserts a new node on the front of the list. */
void push(struct Node** head_ref, int new_data)
{
    /* 1. allocate node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    /* 2. put in the data  */
    new_node->data  = new_data;

    /* 3. Make next of new node as head */
    new_node->next = (*head_ref);

    /* 4. move the head to point to the new node */
    (*head_ref)    = new_node;
}

/* Given a node prev_node, insert a new node after the given prev_node */
void insertAfter(struct Node* prev_node, int new_data) {

    /*1. check if the given prev_node is NULL */
    if (prev_node == NULL) {
        printf("The given previous node cannot be NULL.");
        return;
    }

    /* 2. allocate new node */
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    /* 3. put in the data */
    new_node->data = new_data;

    /* 4. Make next of new node as next of prev_node */
    new_node->next = prev_node->next;

    /* 5. move the next of prev_node as new_node */
    prev_node->next = new_node;

}

/* Given a reference (pointer to pointer) to the head of a list and an int, appends a new node at the end  */
void append(struct Node** head_ref, int new_data) {

    /* 1. allocate node */
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    struct Node *last = *head_ref;

    /* 2. put in the data  */
    new_node->data = new_data;

    /* 3. This new node is going to be the last node, so make next of it as NULL*/
    new_node->next = NULL;

    /* 4. If the Linked List is empty, then make the new node as head */
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;

    /* 6. Change the next of last node */
    last->next = new_node;
    return;
}

// This function prints contents of linked list starting from head
void printList(struct Node *node) {

    while(node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

void reverse(struct Node** head_ref, int new_data){
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
    struct Node* next = NULL;

    while(current != NULL) {
        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
    }
    *head_ref = prev;
}


/* Driver program to test above functions*/
int main() {

    /* Start with the empty list */
    struct Node* head = NULL;

    int N, n;
    char option;

    /* Do while loop to loop through the case switches*/
    do {

    printf("\n--------------------------------------------------------------\n");
    printf("\n1. Append\n2. Push\n3. InsertAfter\n4. PrintList\n5. ReverseList\n6. Exit \n");
    printf("\n--------------------------------------------------------------\n");
    printf("\nChoose an option: ");
    scanf(" %c", &option);

        switch(option) {
            case '1':
                printf("\nInsert an amount to append: ");
                scanf("%d", &N);

                int i = 0;
                while (i < N) {
                    printf("Insert an a number to append tp the end of the list: ");
                    scanf("%d", &n);
                    append(&head, n);
                    i++;
                } break;

            case '2':
                printf("Insert a number to push to the front of the list: ");
                scanf("%d", &n);
                push(&head, n);
                break;

            case '3':
                printf("Insert an a number to insert after the previous node: ");
                scanf("%d", &n);
                insertAfter(head->next, n);
                break;

            case '4':
                printf("\nLinked list: ");
                printList(head);
                printf("\n");
                break;

            case '5':
                reverse(&head, &n);
                printf("\nReversed List: ");
                printList(head);
                printf("\n");
                break;

            }

        } while(option != '6'); // If option == '6', exit program

    return 0;
}
