//C++ menu-driven program to implement List ADT using a Singly Linked List
#include "sll.h"
#include<stdlib.h>

int main(){
    int choice;
    list l1;
    list l2;
    list list3;
    int value;
    while(1){
        printf("Enter 1 for insertion of element into first list\n");
        printf("Enter 2 for insertion of element into second list\n");
        printf("Enter 3 for merging lists\n");
        printf("Enter 4 for display\n");
        printf("Enter 5 for exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the value to insert:");
            scanf("%d",&value);
            l1.insert(value);
            break;
            case 2:
            printf("Enter the value to insert:");
            scanf("%d",&value);
            l2.insert(value);
            break;
            case 3:
            list3 = list3.merge(l1,l2);
            break;
            case 4:
            printf("list1\n");
            l1.display();
            printf("list2\n");
            l2.display();
            printf("list 3\n");
            list3.display();
            break;
            case 5:
            printf("Exiting..");
            default:
            printf("Enter valid choice\n");
        }
    }
}
//Function to insert elements in ascending order in linked list
int list ::insert(int value){
    struct node* newnode = (struct node*)malloc(sizeof(struct node*));
    newnode->data = value;
    newnode->next = nullptr;
    struct node *temp = head;
    if (head == nullptr){
        newnode->next = nullptr;
        head = newnode;
        return 1;
    }
    if (temp->data>=value){
        newnode->next = head;
        head = newnode;
    }
    while(temp->next!=nullptr && temp->next->data<value ){
        temp = temp->next;
    } 
    newnode->next = temp->next;
    temp->next = newnode;
    return 1;
}
//Function to merge two lists
list list ::merge(list lst1,list lst2){
    struct node *list1 = lst1.gethead();
    struct node *list2 = lst2.gethead();
    list list3;
    while(list1!=nullptr && list2!=nullptr){
        if (list1->data > list2->data){
            list3.insert(list2->data);
            list2= list2->next;
        }
        else{
            list3.insert(list1->data);
            list1=list1->next;
        }
    }
    while(list1!=nullptr){
        list3.insert(list1->data);
        list1=list1->next; 
    }
    while(list2!=nullptr){
        list3.insert(list2->data);
        list2= list2->next;
    }
    list3.display();
    return list3;
}
//Function to display lists
void list :: display(){
    struct node *temp = head;
    while(temp!=nullptr){
        printf("%d   ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
