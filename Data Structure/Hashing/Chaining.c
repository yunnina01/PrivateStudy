#include <stdio.h>
#include <stdlib.h>
#define BUCKET_SIZE 7

typedef struct HashNode{
    int key;
    struct HashNode *link;
}HashNode;

