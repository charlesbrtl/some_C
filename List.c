//Charles Letonnellier de Breteuil
//27296592

#include<stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <stdbool.h>
#include "List.h"
//list 'constructor', allocates memory to the pointer
//initializes the values of head, current and size
struct List * construct(struct List *list) {
    list=(struct List*)malloc(sizeof(struct List));
    list->head =NULL;
    list->current=NULL;
    list->size=0;
    return list;
}
//function to add a Node to the end of the list
void add_(struct List *list, char *word){
    struct Node *node_ptr;
    //allocate memory for a new node
    node_ptr = (struct Node*) malloc(sizeof(struct Node));
    node_ptr->string = malloc(strlen(word)+1);
    strcpy(node_ptr->string, word);
    node_ptr->next=NULL;

        if(list->head==NULL)
        {
            //if list is empty, set the new node as head and current, increment size
                list->head = node_ptr;
                list->current= node_ptr;
                list->size++;
        }
        else {
            //if list is not empty, add it to the end of the list, increment size
                list->current->next=node_ptr;
                list->current=node_ptr;
                list->size++;
        }
}
//iterates through all elements of the list to print them
void printList(struct List*list) {
   struct Node* node_ptr =list->head;
    while(node_ptr) {
        printf("%s ", node_ptr->string);
        node_ptr = node_ptr->next;
    }
    printf("\n");

}
//function to delete a node
void delete_(struct List*list) {
   struct  Node* node_ptr = list->head;
    while(node_ptr) {
        //free the memory from head to tail
        free(node_ptr->string);
        free(node_ptr);
        node_ptr = node_ptr->next;
    }
}
//function to add a node after a given one if it exists
void add_after(struct List *list, char a_word[], char word_after[]){
    struct  Node* node_ptr = list->head;
    while(node_ptr){
        //here we used strcmp as the method TwoStrComp of question 4 is a binary operator that can't check equality
        if(strcmp(node_ptr->string,a_word)==0){
            //if the node to add after exists, insert it after the first occurrence
            struct Node *new_node_ptr;
            new_node_ptr = (struct Node*) malloc(sizeof(struct Node));
            new_node_ptr->string = malloc(strlen(word_after)+1);
            strcpy(new_node_ptr->string, word_after);
            new_node_ptr->next=node_ptr->next;
            node_ptr->next=new_node_ptr;
            list->size++;
            break;
        }
     node_ptr=node_ptr->next;
    }
}
//function to delete a node
void delete_node(struct List*list, char a_word[]) {

    struct Node * temp, *prev;
    temp=list->head;
    prev=NULL;

    if (temp != NULL && strcmp(temp->string,a_word)==0)
    {
        list->head = temp->next;
        free(temp);
        list->size--;
        return;
    }

    while (temp != NULL && strcmp(temp->string,a_word)!=0)
    {
        prev = temp;
        temp = temp->next;
    }


    if (temp == NULL) return;

    prev->next = temp->next;

    free(temp);
    list->size--;
}
//function from question 3 used to sort the linkedlist
_Bool twoStrgCompr(char* str1, char* str2){
    while(*str1!= '\0' && *str2 != '\0'){
        if(*str1<*str2){
            return true;
        }
        else if (*str1>*str2){
            return false;
        }
        else {
            str1++;
            str2++;
        }
    }
    return *str1=='\0'? true:  false;
}
//selection sort implementation for this linkedlist
void selection_sort(struct List*list){

    int size=list->size;
    if(size==0)
    {return;}
    struct Node **arrayhead;
    arrayhead=malloc(size * sizeof(struct Node*));
    struct Node * node_ptr=list->head;
    int count=0;
    //storing the elements in a pointer array to make the sorting process easier
    while(node_ptr){
        arrayhead[count]=node_ptr;
        node_ptr=node_ptr->next;
        count++;
    }
    //value to store the index in array of the Node with the smallest string value;
   int minIndex=0;
    //selection sort double loop;
    for (int j=0;j<size;j++ ){
        minIndex=j;
        for(int i=j;i<size;i++){
            if(minIndex!=i){
                if(twoStrgCompr(arrayhead[i]->string,arrayhead[minIndex]->string)){
                minIndex=i;
                 }
            }
        }
        if(minIndex!=j){
           node_ptr=arrayhead[j];
            arrayhead[j]=arrayhead[minIndex];
            arrayhead[minIndex]=node_ptr;
        }
    }
    //re linking the list in sorted order
    for(int k=0;k<size-1;k++) {
        arrayhead[k]->next = arrayhead[k + 1];
    }
    //setting head, current and next to current of the list;
    list->head=arrayhead[0];
    list->current=arrayhead[size-1];
    list->current->next=NULL;

    //freeing the space allocated for the array
    free(arrayhead);
}
