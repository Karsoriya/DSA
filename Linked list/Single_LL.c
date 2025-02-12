#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *link;
};

struct node *head = NULL;

void create(){
    int i, x;
    printf("How Many Elements You want to add: ");
    scanf("%d", &x);
    for (i = 1; i <= x; i++){
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter data for node %d of the linked list: ", i);
        scanf("%d", &newNode->data);
        newNode->link = NULL;

        if (head == NULL){
            head = temp = newNode;
        }
        else{
            temp = head;
            while (temp->link != NULL)
            {
                temp = temp->link;
            }
            temp->link = newNode;
        }
    }
}

void insertatbeg(){
    int value;
    printf("Enter the value to insert at begining\n");
    scanf("%d", &value);
    struct node *ins = (struct node *)malloc(sizeof(struct node));
    ins->data = value;
    ins->link = head;
    head = ins;
}

void insertatend(){
    int value;
    printf("Enter The Value To be Inserted at the end\n");
    scanf("%d", &value);
    struct node *ins = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    ins->data = value;
    ins->link = NULL;
    while (temp->link != NULL){
        temp = temp->link;
    }
    temp->link = ins;
}

void insertAtPos(){
    int x, pos, i = 1;
    printf("Enter The Value To Be Inserted \n");
    scanf("%d", &x);
    printf("Enter the Position\n");
    scanf("%d", &pos);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    ptr->data = x;
    while (i < pos - 1){
        temp = temp->link;
        i++;
    }
    ptr->link = temp->link;
    temp->link = ptr;
}

void insert_before(){
    int c, d;
    struct node *newNode, *ptr, *preptr;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data:");
    scanf("%d", &d);
    newNode->data = d;
    printf("Enter the value before which the data has to be inserted:");
    scanf("%d", &c);
    ptr = head;
    while (ptr->data != c){
        preptr = ptr;
        ptr = ptr->link;
    }
    preptr->link = newNode;
    newNode->link = ptr;
}

void insert_after(){
    int c, d;
    struct node *newNode, *ptr, *preptr;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data:");
    scanf("%d", &d);
    newNode->data = d;
    printf("Enter the value after which the data has to be inserted:");
    scanf("%d", &c);
    ptr = head;
    preptr = ptr;
    while (preptr->data != c){
        preptr = ptr;
        ptr = ptr->link;
    }
    preptr->link = newNode;
    newNode->link = ptr;
}

void del_at_begin(){
    if (head == NULL){
        printf("Linked List is Already Empty\n");
    }
    else{
        struct node *del = (struct node *)malloc(sizeof(struct node));
        printf("Delete Element is %d\n", head->data);
        del = head;
        head = head->link;
        free(del);
    }
}

void delete_at_end(){
    struct node *del = (struct node *)malloc(sizeof(struct node));
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (head == NULL){
        printf("Linked List is Already Empty\n");
    }
    else if (head->link == NULL){
        del = head;
        head = NULL;
        free(del);
    }
    else{
        del = head;
        temp = head->link;
        while (temp->link != NULL){
            del = temp;
            temp = temp->link;
        }
    }
    printf("Deleted Element is %d\n", temp->data);
    del->link = NULL;
    free(temp);
}

void delete_at_pos(){
    int pos, i = 1;
    printf("Enter the postion to be deleted in linked list\n");
    scanf("%d", &pos);
    struct node *ptr, *ptr1;
    ptr = head;
    while (i < pos - 1)
    {
        ptr = ptr->link;
        i++;
    }
    ptr1 = ptr->link;
    ptr->link = ptr1->link;
    free(ptr1);
    printf("\nDeleted node %d ", pos + 1);
}

void delete_after(){
    int c;
    printf("Enter the value after which the data has to be deleted:");
    scanf("%d", &c);
    struct node *ptr, *preptr, *temp;
    if (head == NULL)
    {
        printf("Linked List is empty\n");
    }
    else{
        ptr = head;
        preptr = ptr;
        while (preptr->data != c)
        {
            preptr = ptr;
            ptr = ptr->link;
        }
        temp = ptr;
        preptr->link = temp->link;

        free(temp);
    }
}

void update_element(){
    int update_ele;
    int element;
    struct node *temp;
    temp = head;
    printf("Enter the element to be updated in the list : ");
    scanf("%d", &element);
    while (temp != NULL)
    {
        if (temp->data == element)
        {
            printf("\nEnter the new data to update the old data : ");
            scanf("%d", &update_ele);
            temp->data = update_ele;
        }
        else
        {
            temp = temp->link;
        }
    }
}

void update_at_beg(){
    int c;
    printf("Enter the element to be updated at beginning: ");
    scanf("%d", &c);
    head->data = c;
}

void update_at_end(){
    int c;
    struct node *temp;
    printf("Enter the element to be updated at end: ");
    scanf("%d", &c);

    while (temp->link != NULL){
        temp = temp->link;
    }
    temp->data = c;
}

void display(){
    printf("Displaying Linked List\n");
    struct node *temp = head;
    while (temp->link != NULL){
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("%d ", temp->data);
}

void sort_list(){
    struct node *ptr1, *ptr2;
    int temp;
    ptr1 = head;
    while (ptr1->link != NULL){
        ptr2 = ptr1->link;
        while (ptr2 != NULL)
        {

            if (ptr1->data > ptr2->data){
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
            ptr2 = ptr2->link;
        }

        ptr1 = ptr1->link;
    }
    display();
}

void reverse(){
    printf("Displaying Reverse Linked List\n");
    struct node *prevNode, *currentNode, *nextNode;
    prevNode = NULL;
    currentNode = head;
    nextNode = head;
    while (nextNode != NULL){
        nextNode = nextNode->link;
        currentNode->link = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    head = prevNode;
    display();
}

void get_length(){
    int count = 0;
    struct node *temp = head;
    while (temp != NULL){
        count++;
        temp = temp->link;
    }
    printf("Length of the Linked List is %d\n", count);
}

void search(){
    int x, i = 1;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode = head;
    if (newNode == NULL){
        printf("Linekd List is empty\n");
    }
    else{
        printf("Enter the data you want to search\n");
        scanf("%d", &x);
        while (newNode->data != x){
            newNode = newNode->link;
            i++;
        }
        printf("node found at %d\n", i);
    }
}

void Concatenate(){
    printf("Enter The Linked List to be concatenated\n");
    create();
    printf("Concatenated Linked list\n");
    display();
}

int main(){
    int opt;
    while (1){
        printf("\nwhich operation do you want to perform?\n");
        printf("1.Create a Linked List\n");
        printf("2.Display\n");
        printf("3.Sort\n");
        printf("4.Insert at beginning\n");
        printf("5.Insert at End\n");
        printf("6.Insert at Position\n");
        printf("7.Insert before Position\n");
        printf("8.Insert after Position\n");
        printf("9.Delete from beginning\n");
        printf("10.Delete from end\n");
        printf("11.Delete at Position\n");
        printf("12.Delete After a node\n");
        printf("13.Update Element\n");
        printf("14.Update Element at beginning\n");
        printf("15.Update Element at end\n");
        printf("16.Reverse\n");
        printf("17.Length of Linked List\n");
        printf("18.Search Elment\n");
        printf("19.Concatenate Linked List\n");
        printf("20.Exit\n");
        scanf("%d", &opt);
        switch (opt){
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                sort_list();
                break;
            case 4:
                insertatbeg();
                break;
            case 5:
                insertatend();
                break;
            case 6:
                insertAtPos();
                break;
            case 7:
                insert_before();
                break;
            case 8:
                insert_after();
                break;
            case 9:
                del_at_begin();
                break;
            case 10:
                delete_at_end();
                break;
            case 11:
                delete_at_pos();
                break;
            case 12:
                delete_after();
                break;
            case 13:
                update_element();
                break;
            case 14:
                update_at_beg();
                break;
            case 15:
                update_at_end();
                break;
            case 16:
                reverse();
                break;
            case 17:
                get_length();
                break;
            case 18:
                search();
                break;
            case 19:
                Concatenate();
                break;
            case 20:
                exit(0);
            default:
                printf("Invalid Choice.\n");
        }
    }
    return 0;
}
