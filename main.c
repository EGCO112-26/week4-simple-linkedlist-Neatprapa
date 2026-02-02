//
//  main.c
//  simple linkedlist
//
//  Created by Mingmanas Sivaraksa on 4/2/2566 BE.
//

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main(int argc, const char * argv[]) {
    int c=5;
    struct node a,b,*head ;
    a.value = c;
    a.next=&b;
    head=&a;
    b.value=head->value+3;
/*  Exercise I
    1. Add 1 more than at the end
    2. Add value(11)
    3. Make next become NULL
 */
    
    struct node d;
    b.next=&d;
    d.value=11;
    d.next=NULL;

    printf("%d\n", head ->value ); //what value for 5
    printf("%d\n", head ->next->value );//what value for 8
    printf("%d\n", head ->next->next->value );

/*  Exercise II
        1. Add 1 more than at the begining!!!!
        2. Add value (2)
        
*/
    printf("next exercie\n");

    struct node e;
    e.value=2;
    e.next=&a;
    head=&e;
    //b.next = &d; //การadddไปข้างหลัง
    //d.value = 11;
    //b.next->value = 11 //b.next is behide the b
    //a.next->next->value = 11
    d.next=NULL; //NULLPtr
    
    printf("%d\n", head ->value ); //what value for 5
    printf("%d\n", head ->next->value );//what value for 8
    printf("%d\n", head ->next->next->value );
    printf("%d\n", head ->next->next->next->value );
    
//Exercise III
    typedef struct node* NodePtr;
    NodePtr tmp=head; //add temp value to faciliate
        printf("print using loop\n");
        int i,n=4;
        for(i=0;i<n;i++){
            printf("%3d", tmp->value);
            tmp=tmp->next;
          // What is missing???
        }

    
    
   //Exercise IV change to while loop!! (you can use NULL to help)
       tmp=head;
         while(tmp){
            printf("%3d", tmp->value);
            tmp=tmp->next;
           // What is missing???
        }
    printf("\n");
    printf("create node by malloc \n");
    NodePtr temp;
    head=(NodePtr) malloc (sizeof(struct node));
    temp=head;
    head->value=7;
    head->next=(NodePtr) malloc (sizeof(struct node));
    head->next->value=9;
    head->next->next=(NodePtr) malloc(sizeof(struct node));

    
 /*  Exercise V Use malloc to create all nodes, instead of create a struct!!*/
         //use a loop to help
        temp=head;
        n=10;
        for(i=0;i<n;i++)
        {
            temp->value=7+(i*2);
            temp->next=(NodePtr) malloc (sizeof(struct node));
            temp=temp->next;
        }
        temp->value = 7+(i*2);
        temp->next=NULL;
        temp=head;
        while(temp)
        {
            printf("%-5d",temp->value);
            temp=temp->next;
        }
        printf("\n");
     

    /*  Exercise VI Free all node !!*/
         //use a loop to help
        printf("Freeing all node\n");
        while(head != NULL)
        {
            temp=head;
            head=head->next;
            printf("Freeing %d\n",temp->value);
            free(temp);
        }          
    
    return 0;
}
