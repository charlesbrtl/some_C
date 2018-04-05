//Charles Letonnellier de Breteuil
//27296592



#ifndef LISTH
#define LISTH
//node struct
struct Node {
    char * string;
    struct Node*next;
}Node;
//linkedlist struct
struct List{
    struct Node*head;
    struct Node*current;
    int size;
}List;
#endif