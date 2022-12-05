#include<stdio.h>
#include<stdlib.h>  
#include<windows.h> 
struct node{
    int data;
    struct node* next; 
};
struct node* createnode(int val){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=val;
    ptr->next;
    return ptr;
} 
struct node* display(struct node* head){
    struct node* ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data); 
        ptr=ptr->next;
    }
}
struct node* insertatbegining(struct node* head,int val){
    struct node* ptr=createnode(val);   
    if(head==NULL){
        head=createnode(val);
        printf("%d ",val);
        return head;
    }
    ptr->next=head;
    head=ptr; 
    display(head);
    return head;
    
} 
 struct node* insertatbetween(struct node* head,int val,int index){
     struct node* ptr=createnode(val);   
   struct node* p=head;

    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    } 
    ptr->next=p->next;
    p->next=ptr;
    
    display(head);
    return head; 
 }
struct node* insertatend(struct node* head,int val){
     struct node* ptr=(struct node*)malloc(sizeof(struct node)); 
     struct node* p=head;
     while(p->next!=NULL){
         p=p->next;
     } 
     ptr->data=val;
     p->next=ptr;  
     ptr->next=NULL;
     display(head);
     return head;
} 
 struct node* deleteatbetween(struct node* head,int index){
     struct node* p=head;
     struct node* q=head->next;
     int i=0;
     while(i!=index-1){
         p=p->next;
         q=q->next;
         i++;
     } 
     p->next=q->next;
     free(q);
     display(head);
     return head;
     
 }
struct node* deleteatbegining(struct node* head){
  struct node* ptr=head;
  head=ptr->next;
  free(ptr); 
  display(head);
  return head;
} 
struct node* deleteatend(struct node* head){
    struct node* p=head; 
    struct node* q=head->next;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    } 
    p->next=NULL;
    free(q);
    display(head);
    return head;
}
 
struct node* linearsearch(struct node* head, int val){
    struct node* ptr=head;
    int i=0;
    while(ptr->data!=val || ptr!=NULL){ 
        if(ptr->data==val){
            printf("element found at index %d",i); 
            break;
        }
        ptr=ptr->next;
        i++;
    } 
    if(ptr==NULL){
        printf("element not found\n");
    }  
    
    return head;
}

int main(){  
    
    int choice,choice1,ele,index,n,num;
    
   struct node* head,* prev;
    printf("Enter the no. of nodes:");
    scanf("%d",&n);  
    printf("Enter the element of node 1:"); 
    scanf("%d",&num);  
    
    head=createnode(num); 
    prev=head; 
     
   
    for(int i=2;i<=n;i++){  
        struct node* ptr=(struct node*)malloc(sizeof(struct node));
        if(ptr==NULL){
            printf(" Memory not enough\n"); 
            break;
        }
       
    else{
        printf("Enter the element of node %d:",i); 
    scanf("%d",&num);  
    ptr->data=num; 
    ptr->next=NULL; 
    prev->next=ptr;
    
    prev=ptr; 
   
    }

    }
    while(1){ 
        system("cls");
        printf("\nWelcome to linked list program!\n"); 
        printf("linked list:");
        display(head);
        printf("\nMenu\n1.insert an element\n2.delete an element\n3.search an element\n4.display the linked list\n5.exit\n");
        scanf("%d",&choice);
        if(choice==1){ 
            printf("1.insert at begining\n2.insert at between\n3.insert at end\n");
            scanf("%d",&choice1);
            if(choice1==1){
                printf("Enter the element to inserted:\n") ; 
                scanf("%d",&ele);
                head=insertatbegining(head,ele);
               
        
            }
            else if(choice1==2){
                printf("Enter the element to inserted:\n") ; 
                scanf("%d",&ele); 
                 printf("Enter the index of the inserted node:\n") ; 
                 printf("\n") ; 
                scanf("%d",&index);  
         head= insertatbetween(head,ele,index);
            }
            else if(choice1==3){
                printf("Enter the element to inserted:\n") ; 
                scanf("%d",&ele); 
               head=insertatend(head,ele); 
            } 


        } 
        if(choice==2){ 
            printf("1.delete at begining\n2.delete at between\n3.delete at end\n");
            scanf("%d",&choice1);
            if(choice1==1){
               
           head=deleteatbegining(head);
        
            }
            else if(choice1==2){
               
                 printf("Enter the index of the inserted node:\n") ; 
                scanf("%d",&index);  
               head=deleteatbetween(head,index);
            }
            else if(choice1==3){
              
              head= deleteatend(head); 
            } 


        } 
        else if(choice==3){
            printf("Enter the element to  be searched:\n") ; 
                scanf("%d",&ele); 
               linearsearch(head,ele); 
               Sleep(3000);
 
        } 
        else if(choice==4){
            display(head); 
            Sleep(3000);
        } 
        else if(choice==5){
            exit(0);
        }
    } 
    return 0;
}