//Name : Sharvil Sunil Patil
//Roll No : 2001
//Class : CSE SY A
//Batch : S1

#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* next;
};
typedef struct Node node;

node* create(node* start) {
    node* p = (node*)malloc(sizeof(node));  
    printf("Enter the data of the vertex: ");
    scanf(" %c", &p->data);  

    p->next = start;  
    start = p;        

    return start;
}

int main() {
    int n = 0;
    printf("How many vertices do you want to enter: ");
    scanf("%d", &n);  
    node* adj[n];
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;  
    }

    for (int i = 0; i < n; i++) {
        int k = 0;
        printf("Enter the number of neighbors for vertex %d: ", i + 1);
        scanf("%d", &k);  

        getchar(); 

        for (int j = 0; j < k; j++) {
            adj[i] = create(adj[i]);  
        }
    }

    for (int i = 0; i < n; i++) {
        printf("Adjacency list for vertex %d: ", i + 1);
        node* temp = adj[i];
        while (temp != NULL) {
            printf("%c -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }

    return 0;
}
//OUTPUT : 
//How many vertices do you want to enter: 3
//Enter the number of neighbors for vertex 1: 3
//Enter the data of the vertex: a
//Enter the data of the vertex: b
//Enter the data of the vertex: c
//Enter the number of neighbors for vertex 2: 2
//Enter the data of the vertex: e
//Enter the data of the vertex: f
//Enter the number of neighbors for vertex 3: 0
//Adjacency list for vertex 1: c -> b -> a -> NULL
//Adjacency list for vertex 2: f -> e -> NULL
//Adjacency list for vertex 3: NULL
