#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node {
   int data;
   struct node *next;
   struct node *prev;
};
struct node *head = NULL;
struct node *current = NULL;

void insertatbegin(int d){

    struct node *newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data=d;
    newnode->next=head;
    if(head!=NULL){
        head->prev=newnode;
    }
    head=newnode;
    newnode->prev=NULL;

}

void insertatend(int d){

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=d;
    newnode->next=NULL;

    struct node *p=head;

    //if no linked list present
    if (p == NULL) {
        head = newnode;
        return;
    }

    while(p->next!=NULL){
        p=p->next;
    }
    //newnode is alone now find end of list and point the last one (p now) next as a newnode position and its previous as p ok.
    p->next=newnode;
    newnode->prev=p;
}

void insertatpos(int pos, int d){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=d;
    newnode->next=NULL;
    newnode->prev=NULL;

    if(head==NULL && pos==0){
        head=newnode;
        return;
    }
    if(pos==0){
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
        return;

    }
    struct node *p=head;
    int currentpos=0;

    while(p!=NULL && currentpos<pos-1){
        p=p->next;
        currentpos++;
    }
    // if reached end
    if(p==NULL){
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=newnode;
        newnode->prev=p;

    }
    else{
        newnode->next=p->next;
        newnode->prev=p;
        if(p->next!=NULL){
            p->next->prev=newnode;

        }
        p->next=newnode;
    }

}

void insertatbeforepos(int pos, int d) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = d;
    newnode->next = NULL;
    newnode->prev = NULL;

    if (head == NULL && pos == 0) {
        head = newnode;
        return;
    }

    if (pos == 0) {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
        return;
    }

    struct node *p = head;
    int currentpos = 0;

    while (p->next != NULL && currentpos < pos) {
        p = p->next;
        currentpos++;
    }

    if (p == NULL) {
        p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = newnode;
        newnode->prev = p;
    }
    else {
        newnode->next = p;
        newnode->prev = p->prev;
        if (p->prev != NULL) {
            p->prev->next = newnode;
        }
        p->prev = newnode;
        if (p == head) {
            head = newnode;
        }
    }
}

void deletebegin(){
    if(head==NULL){
        printf("nothing to delete\n");
        return;
    }
    struct node *temp=head;
    head=head->next;
    if(head!=NULL){
        head->prev=NULL;
    }
    free(temp);
}

void deleteatend(){
    if(head==NULL){
        printf("nothing to delete\n");
        return;
    }

    struct node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->prev->next=NULL; // kadesi vanthachu athuku munadi iruka node oda next ah null akura ie the end.
    free(temp);

}

void deleteatpos(int pos){
    if(pos==0){
        deletebegin();
    }

    struct node *p=head;
    int currentpos=0;


    while(p!=NULL && currentpos<pos){
        p=p->next;
        currentpos++;
    }
    if (p == NULL) {
        printf("Invalid position. The linked list has fewer nodes than the specified position.\n");
        return;
    }
    p->prev->next = p->next;
    if(p->next!=NULL){
        p->next->prev = p->prev;

    }
    free(p);

}

void updateatbegin(int d){
    if(head!=NULL){
        head->data=d;
    }
}

void updateatend(int d){
    struct node *p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->data=d;

}

void print(){

    struct node *p=head;

    printf("Linked list [");
    while(p!=NULL){
        printf("%d ->", p->data);
        p=p->next;
    }
    printf("]\n");

}

void countlist(){
    struct node *p=head;
    int count=0;
    while(p!=NULL){
        p=p->next;
        count++;
    }
    printf("length of the ll is %d \n", count);
}

void reverse(){

    struct node *p=head;
    struct node *temp=NULL;
    while(p!=NULL){
        temp=p->prev;
        p->prev=p->next;
        p->next=temp;
        p=p->prev;
    }
    if (temp != NULL) {
        head = temp->prev;
    }
    p=head;
    while(p!=NULL){
        printf("%d ->", p->data);
        p=p->next;
    }

}

void search(int x){
    struct node *p=head;
    int count=0;
    while(p!=NULL){
        if(p->data==x){
            printf("Element found at pos %d", count);
            return;
        }
        else{
            printf("element not found");
            return;
        }
        p=p->next;
    }

}
void sort(){

    if(head==NULL && head->next==NULL){
        return;
    }
    struct node *p=head;
    struct node *tail=NULL;
    int swapped;
    do{
        swapped=0;
        p=head;
        while(p->next!=tail){
            if(p->data > p->next->data){
                int temp=p->data;
                p->data=p->next->data;
                p->next->data=temp;
                swapped=1;
            }
            p=p->next;
        }
            p=tail;


    } while(swapped);
}


int main(){

    int num;int pos;
    int ch;
    printf("0.display\n 1.Insert at beg\n 2.insert at end\n 3.insert at position\n 4.insert before pos\n 5.insert after pos\n 6.delete from begin\n 7.delete at end\n 8.delete at pos\n 9.delete after pos\n");
    printf("10.update\n 11.update at begin \n 12.update at end\n 13.reverse\n 14.Length\n 15.search\n 16.concat\n 18.sort\n 19.exit\n");
    while(true){
        printf("enter choice : ");
        scanf("%d", &ch);
        switch(ch){
            case 0:{
                print();
                break;
            }
            case 1:{
                scanf("%d", &num);
                insertatbegin(num);
                break;
            }
            case 2:{
                scanf("%d", &num);
                insertatend(num);
                break;

            }
            case 3:{

                scanf("%d", &num);
                printf("enter position");
                scanf("%d", &pos);
                insertatpos(pos,num);
                break;
            }
            case 4:{
                scanf("%d", &num);
                printf("enter position");
                scanf("%d", &pos);
                insertatbeforepos(pos,num);
                break;

            }

            case 6:{
                deletebegin();
                break;

            }
            case 7:{
                deleteatend();
                break;
            }
            case 8:{
                printf("enter position");
                scanf("%d", &pos);
                deleteatpos(pos);
                break;
            }

            case 11:{
                printf("enter thing to be updated:");
                scanf("%d", &num);
                updateatbegin(num);
                break;
            }
            case 12:{
                printf("enter thing to be updated:");
                scanf("%d", &num);
                updateatend(num);
                break;
            }

            case 13:{
                reverse();
                break;
            }
            case 14:{
                countlist();
                break;
            }
            case 15:{
                printf("Enter number to search");
                scanf("%d", &num);
                search(num);
                break;
            }

            case 18:{
                sort();
                print();
                break;
            }

            case 19:{
                return 0;
            }
        }
    }
    return 0;
}
