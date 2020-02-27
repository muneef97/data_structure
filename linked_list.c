#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
void push(struct Node** head_ref, int new_data) {
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void insertAfter(struct Node* prev_node, int new_data) {
	if (prev_node == NULL)
	{
	printf("the given previous node cannot be NULL");
	return;
	}
    struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}
void append(struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	struct Node *last = *head_ref;
	new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
	    *head_ref = new_node;
	    return;
	}
    while (last->next != NULL)
		last = last->next;
    last->next = new_node;
	return;
}

void printList(struct Node *node) {
    while (node != NULL) {
	    printf(" %d ", node->data);
	    node = node->next;
    }
}
void delete(struct Node **head_ref, int key) {
    struct Node* temp = *head_ref, *prev;
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}

int main() {
    int n,m;
    struct Node* head = NULL;
    while(n!=5){
    printf("\n1.Append\n2.Push\n3.InsertAfter\n4.Delete\n5.Exit");
    printf("\nEnter choice: ");
    scanf("%d",&n);
    if(n==1){
        printf("enter the number : ");
        scanf("%d",&m);
        append(&head, m);
    }
    else if(n==2){
        printf("enter the number : ");
        scanf("%d",&m);
        push(&head, m);
    }
    else if(n==3){
        printf("enter the number : ");
        scanf("%d",&m);
        insertAfter(head->next, m);
    }
    else if(n==4){
        printf("enter the number : ");
        scanf("%d",&m);
        delete(&head, m);
    }
    else
        return 0;
    printf("\n Created Linked list is: ");
    printList(head);
    }
    return 0;
}
