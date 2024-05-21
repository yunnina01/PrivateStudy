// 자식이 2개 이상인 균형 트리로, 리프 노드가 연결 리스트로 연결된 형태인 B+ 트리 구현
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct record {
    int value;
} Record;

typedef struct node {
    int *keys;
    void **pointers;
    int num_keys;
    bool is_leaf;
    struct node *parent;
    struct node *next;
} Node;

Node *root;
const int order = 4;

// 트리 출력
Node *queue = NULL;
void enqueue(Node *new_node);
Node *dequeue();
int path_to_root(Node *const root, Node *child);
void print_tree(Node *const root);

// 노드 탐색
Node *find_leaf(Node *const root, int key);
Record *find(Node *root, int key, Node **leaf_out);
void find_and_print(Node *const root, int key);

// 노드 삽입
Record *make_record(int value);
Node *make_node();
Node *make_leaf();
Node *start_new_tree(int key, Record *pointer);
Node *insert_into_leaf(Node *leaf, int key, Record *pointer);
int cut(int length);
Node *insert_into_new_root(Node *left, int key, Node *right);
int get_left_index(Node *parent, Node *left);
Node *insert_into_node(Node *root, Node *n, int left_index, int key, Node *right);
Node *insert_into_parent(Node *root, Node *left, int key, Node *right);
Node *insert_into_node_after_splitting(Node *root, Node *old_node, int left_index, int key, Node *right);
Node *insert_into_leaf_after_splitting(Node *root, Node *leaf, int key, Record *pointer);
Node *insert(Node *root, int key);

// 노드 삭제
Node *Remove_entry_from_node(Node *n, int key, Node *pointer);
Node *adjust_root(Node *root);
int get_neighbor_index(Node *n);
Node *coalesce_nodes(Node *root, Node *n, Node *neighbor, int neightbor_index, int k_prime);
Node *redistribute_nodes(Node *root, Node *n, Node *neighbor, int neighbor_index, int k_prime_index, int k_prime);
Node *delete_entry(Node *root, Node *n, int key, void *pointer);
Node *delete(Node *root, int key);

void enqueue(Node *new_node) {
    Node *c;
    if(queue == NULL) {
        queue = new_node;
        queue->next = NULL;
    } else {
        c = queue;
        while(c->next != NULL)
            c = c->next;
        c->next = new_node;
        new_node->next = NULL;
    }
}

Node *dequeue() {
    Node *n = queue;
    queue = queue->next;
    n->next = NULL;
    return n;
}

int path_to_root(Node *const root, Node *child) {
    int length = 0;
    Node *c = child;
    while(c != root) {
        c = c->parent;
        length++;
    }
    return length;
}

void print_tree(Node *const root) {
    if(root == NULL) {
        puts("Empty tree");
        return;
    }
    
    Node *n = NULL;
    int i, rank, new_rank;
    i = rank = new_rank = 0;
    
    queue = NULL;
    enqueue(root);
    while(queue != NULL) {
        n = dequeue();
        if(n->parent != NULL && n == n->parent->pointers[0]) {
            new_rank = path_to_root(root, n);
            if(new_rank != rank) {
                rank = new_rank;
                puts("");
            }
        }
        for(i = 0; i < n->num_keys; i++)
            printf("%d ", n->keys[i]);
        if(!n->is_leaf) {
            for(i = 0; i <= n->num_keys; i++)
                enqueue(n->pointers[i]);
        }
        printf("| ");
    }
    puts("");
}

Node *find_leaf(Node *const root, int key) {
    if(root == NULL)
        return root;
    Node *c = root;
    while(!c->is_leaf) {
        int i = 0;
        while(i < c->num_keys) {
            if(key >= c->keys[i])
                i++;
            else
                break;
        }
        c = (Node*)c->pointers[i];
    }
    return c;
}

Record *find(Node *root, int key, Node **leaf_out) {
    if(root == NULL) {
        if(leaf_out != NULL)
            *leaf_out = NULL;
        return NULL;
    }
    int i = 0;
    Node *leaf = NULL;
    leaf = find_leaf(root, key);

    for(i = 0; i < leaf->num_keys; i++) {
        if(leaf->keys[i] == key)
            break;
    }
    if(leaf_out != NULL)
        *leaf_out = leaf;
    if(i == leaf->num_keys)
        return NULL;
    else
        return (Record*)leaf->pointers[i];
}

void find_and_print(Node *const root, int key) {
    Record *r = find(root, key, NULL);
    if(r == NULL)
        printf("key %d not found.\n", key);
    else
        printf("Key %d found.\n", key);
}

Record *make_record(int value) {
    Record *new_record = (Record*)malloc(sizeof(Record));
    if(new_record == NULL) {
        perror("New Record Allocation Error");
        exit(EXIT_FAILURE);
    }
    new_record->value = value;
    return new_record;
}

Node *make_node() {
    Node *new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL) {
        perror("New Node Allocation Error");
        exit(EXIT_FAILURE);
    }

    new_node->keys = malloc((order - 1) * sizeof(int));
    if(new_node->keys == NULL) {
        perror("New Node keys array Allocation Error");
        exit(EXIT_FAILURE);
    }

    new_node->pointers = malloc(order * sizeof(void*));
    if(new_node->pointers == NULL) {
        perror("New Node pointers array Allocation Error");
        exit(EXIT_FAILURE);
    }

    new_node->num_keys = 0;
    new_node->is_leaf = false;
    new_node->parent = NULL;
    new_node->next = NULL;
    return new_node;
}

Node *make_leaf() {
    Node *leaf = make_node();
    leaf->is_leaf = true;
    return leaf;
}

Node *start_new_tree(int key, Record *pointer) {
    Node *leaf = make_leaf();
    leaf->keys[0] = key;
    leaf->pointers[0] = pointer;
    leaf->num_keys++;
    leaf->pointers[order - 1] = NULL;
    leaf->parent = NULL;
    return leaf;
}

Node *insert_into_leaf(Node *leaf, int key, Record *pointer) {
    int i, insert_point = 0;
    while(insert_point < leaf->num_keys && leaf->keys[insert_point] < key)
        insert_point++;
    for(i = leaf->num_keys; i > insert_point; i--) {
        leaf->keys[i] = leaf->keys[i - 1];
        leaf->pointers[i] = leaf->pointers[i - 1];
    }
    leaf->keys[insert_point] = key;
    leaf->pointers[insert_point] = pointer;
    leaf->num_keys++;
    return leaf;
}

int cut(int length) {
    if(length % 2 == 0)
        return length / 2;
    else
        return length / 2 + 1;
}

Node *insert_into_new_root(Node *left, int key, Node *right) {
    Node *node = make_node();
    node->keys[0] = key;
    node->pointers[0] = left;
    node->pointers[1] = right;
    node->num_keys++;
    node->parent = NULL;
    left->parent = node;
    right->parent = node;
    return node;
}

int get_left_index(Node *parent, Node *left) {
    int left_index = 0;
    while(left_index <= parent->num_keys && parent->pointers[left_index] != left)
        left_index++;
    return left_index;
}

Node *insert_into_node(Node *root, Node *n, int left_index, int key, Node *right) {
    for(int i = n->num_keys; i > left_index; i--) {
        n->keys[i] = n->keys[i - 1];
        n->pointers[i + 1] = n->pointers[i];
    }
    n->keys[left_index] = key;
    n->pointers[left_index + 1] = right;
    n->num_keys++;
    return root;
}

Node *insert_into_parent(Node *root, Node *left, int key, Node *right) {
    int left_index;
    Node *parent = left->parent;

    if(parent == NULL)
        return insert_into_new_root(left, key, right);
    left_index = get_left_index(parent, left);

    if(parent->num_keys < order - 1)
        return insert_into_node(root, parent, left_index, key, right);
    return insert_into_node_after_splitting(root, parent, left_index, key, right);
}

Node *insert_into_node_after_splitting(Node *root, Node *old_node, int left_index, int key, Node *right) {
    int *temp_keys = malloc(order * sizeof(int));
    if(temp_keys == NULL) {
        perror("Temp keys array Allocation Error");
        exit(EXIT_FAILURE);
    }

    Node **temp_pointers;
    temp_pointers = malloc((order + 1) * sizeof(Node*));
    if(temp_pointers == NULL) {
        perror("Temp pointers array Allocation Error");
        exit(EXIT_FAILURE);
    }
    
    int i, j, split, k_prime;
    for(i = 0, j = 0; i < old_node->num_keys; i++, j++) {
        if(j == left_index)
            j++;
        temp_keys[j] = old_node->keys[i];
    }
    for(i = 0, j = 0; i < old_node->num_keys + 1; i++, j++) {
        if(j == left_index + 1)
            j++;
        temp_pointers[j] = old_node->pointers[i];
    }
    temp_keys[left_index] = key;
    temp_pointers[left_index + 1] = right;

    Node *new_node, *child;
    split = cut(order);
    new_node = make_node();
    old_node->num_keys = 0;
    for(i = 0; i < split - 1; i++) {
        old_node->keys[i] = temp_keys[i];
        old_node->pointers[i] = temp_pointers[i];
        old_node->num_keys++;
    }
    old_node->pointers[i] = temp_pointers[i];
    k_prime = temp_keys[split - 1];
    for(++i, j = 0; i < order; i++, j++) {
        new_node->keys[j] = temp_keys[i];
        new_node->pointers[j] = temp_pointers[i];
        new_node->num_keys++;
    }
    new_node->pointers[j] = temp_pointers[i];
    free(temp_keys);
    free(temp_pointers);

    new_node->parent = old_node->parent;
    for(i = 0; i <= new_node->num_keys; i++) {
        child = new_node->pointers[i];
        child->parent = new_node;
    }
    return insert_into_parent(root, old_node, k_prime, new_node);
}

Node *insert_into_leaf_after_splitting(Node *root, Node *leaf, int key, Record *pointer) {
    Node *new_leaf;
    new_leaf = make_leaf();

    int *temp_keys;
    temp_keys = malloc(order * sizeof(int));
    if(temp_keys == NULL) {
        perror("Temp keys array Allocation Error");
        exit(EXIT_FAILURE);
    }

    void **temp_pointers;
    temp_pointers = malloc(order * sizeof(void*));
    if(temp_pointers == NULL) {
        perror("Temp pointers array Allocation Error");
        exit(EXIT_FAILURE);
    }

    int insert_index, split, new_key, i, j;
    insert_index = 0;
    while(insert_index < order - 1 && leaf->keys[insert_index] < key)
        insert_index++;
    for(i = 0, j = 0; i < leaf->num_keys; i++, j++) {
        if(j == insert_index)
            j++;
        temp_keys[j] = leaf->keys[i];
        temp_pointers[j] = leaf->pointers[i];
    }
    temp_keys[insert_index] = key;
    temp_pointers[insert_index] = pointer;

    leaf->num_keys = 0;
    split = cut(order - 1);
    for(i = 0; i < split; i++) {
        leaf->keys[i] = temp_keys[i];
        leaf->pointers[i] = temp_pointers[i];
        leaf->num_keys++;
    }
    for(i = split, j = 0; i < order; i++, j++) {
        new_leaf->keys[j] = temp_keys[i];
        new_leaf->pointers[j] = temp_pointers[i];
        new_leaf->num_keys++;
    }
    free(temp_keys);
    free(temp_pointers);

    new_leaf->pointers[order - 1] = leaf->pointers[order - 1];
    leaf->pointers[order - 1] = new_leaf;
    for(i = leaf->num_keys; i < order - 1; i++)
        leaf->pointers[i] = NULL;
    for(i = new_leaf->num_keys; i < order - 1; i++)
        new_leaf->pointers[i] = NULL;
    new_leaf->parent = leaf->parent;
    new_key = new_leaf->keys[0];
    return insert_into_parent(root, leaf, new_key, new_leaf);
}

Node *insert(Node *root, int key) {
    Record *record_pointer = NULL;
    Node *leaf = NULL;
    record_pointer = find(root, key, NULL);
    if(record_pointer != NULL) {
        record_pointer->value = key;
        return root;
    }

    record_pointer = make_record(key);
    if(root == NULL)
        return start_new_tree(key, record_pointer);
    
    leaf = find_leaf(root, key);
    if(leaf->num_keys < order - 1) {
        leaf = insert_into_leaf(leaf, key, record_pointer);
        return root;
    }
    return insert_into_leaf_after_splitting(root, leaf, key, record_pointer);
}

Node *Remove_entry_from_node(Node *n, int key, Node *pointer) {
    int i, num_pointers;
    i = 0;
    while(n->keys[i] != key)
        i++;
    for(++i; i < n->num_keys; i++)
        n->keys[i - 1] = n->keys[i];
    
    num_pointers = n->is_leaf ? n->num_keys : n->num_keys + 1;
    i = 0;
    while(n->pointers[i] != pointer)
        i++;
    for(++i; i < num_pointers; i++)
        n->pointers[i - 1] = n->pointers[i];
    n->num_keys--;

    if(n->is_leaf) {
        for(i = n->num_keys; i < order - 1; i++)
            n->pointers[i] = NULL;
    } else {
        for(i = n->num_keys + 1; i < order; i++)
            n->pointers[i] = NULL;
    }
    return n;
}

Node *adjust_root(Node *root) {
    Node *new_root;
    if(root->num_keys > 0)
        return root;
    
    if(!root->is_leaf) {
        new_root = root->pointers[0];
        new_root->parent = NULL;
    } else
        new_root = NULL;
    
    free(root->keys);
    free(root->pointers);
    free(root);
    return new_root;
}

int get_neighbor_index(Node *n) {
    for(int i = 0; i <= n->parent->num_keys; i++) {
        if(n->parent->pointers[i] == n)
            return i - 1;
    }
}

Node *coalesce_nodes(Node *root, Node *n, Node *neighbor, int neightbor_index, int k_prime) {
    int i, j, neighbor_insert_index, n_end;
    Node *temp;
    if(neightbor_index == -1) {
        temp = n;
        n = neighbor;
        neighbor = temp;
    }
    neighbor_insert_index = neighbor->num_keys;

    if(!n->is_leaf) {
        neighbor->keys[neighbor_insert_index] = k_prime;
        neighbor->num_keys++;
        n_end = n->num_keys;

        for(i = neighbor_insert_index + 1, j = 0; j < n_end; i++, j++) {
            neighbor->keys[i] = n->keys[j];
            neighbor->pointers[i] = n->pointers[j];
            neighbor->num_keys++;
            n->num_keys--;
        }
        neighbor->pointers[i] = n->pointers[j];
        for(i = 0; i < neighbor->num_keys + 1; i++) {
            temp = (Node*)neighbor->pointers[i];
            temp->parent = neighbor;
        }
    } else {
        for(i = neighbor_insert_index, j = 0; j < n->num_keys; i++, j++) {
            neighbor->keys[i] = n->keys[j];
            neighbor->pointers[i] = n->pointers[j];
            neighbor->num_keys++;
        }
        neighbor->pointers[order - 1] = n->pointers[order - 1];
    }

    root = delete_entry(root, n->parent, k_prime, n);
    free(n->keys);
    free(n->pointers);
    free(n);
    return root;
}

Node *redistribute_nodes(Node *root, Node *n, Node *neighbor, int neighbor_index, int k_prime_index, int k_prime) {
    int i;
    Node *temp;

    if(neighbor_index != -1) {
        if(!n->is_leaf)
            n->pointers[n->num_keys + 1] = n->pointers[n->num_keys];
        for(i = n->num_keys; i > 0; i--) {
            n->keys[i] = n->keys[i - 1];
            n->pointers[i] = n->pointers[i - 1];
        }
        if(!n->is_leaf) {
            n->pointers[0] = neighbor->pointers[neighbor->num_keys];
            temp = (Node*)n->pointers[0];
            temp->parent = n;
            neighbor->pointers[neighbor->num_keys] = NULL;
            n->keys[0] = k_prime;
            n->parent->keys[k_prime_index] = neighbor->keys[neighbor->num_keys - 1];
        } else {
            n->pointers[0] = neighbor->pointers[neighbor->num_keys - 1];
            neighbor->pointers[neighbor->num_keys - 1] = NULL;
            n->keys[0] = neighbor->keys[neighbor->num_keys - 1];
            n->parent->keys[k_prime_index] = n->keys[0];
        }
    } else {
        if(n->is_leaf) {
            n->keys[n->num_keys] = neighbor->keys[0];
            n->pointers[n->num_keys] = neighbor->pointers[0];
            n->parent->keys[k_prime_index] = neighbor->keys[1];
        } else {
            n->keys[n->num_keys] = k_prime;
            n->pointers[n->num_keys + 1] = neighbor->pointers[0];
            temp = (Node*)n->pointers[n->num_keys + 1];
            temp->parent = n;
            n->parent->keys[k_prime_index] = neighbor->keys[0];
        }
        for(i = 0; i < neighbor->num_keys - 1; i++) {
            neighbor->keys[i] = neighbor->keys[i + 1];
            neighbor->pointers[i] = neighbor->pointers[i + 1];
        }
        if(!n->is_leaf)
            neighbor->pointers[i] = neighbor->pointers[i + 1];
    }
    n->num_keys++;
    neighbor->num_keys--;
    return root;
}

Node *delete_entry(Node *root, Node *n, int key, void *pointer) {
    int min_keys;
    Node *neighbor;
    int neighbor_index;
    int k_prime_index, k_prime;
    int volume;

    n = Remove_entry_from_node(n, key, pointer);
    if(n == root)
        return adjust_root(root);
    
    min_keys = n->is_leaf ? cut(order - 1) : cut(order) - 1;
    if(n->num_keys >= min_keys)
        return root;
    
    neighbor_index = get_neighbor_index(n);
    k_prime_index = neighbor_index == -1 ? 0 : neighbor_index;
    k_prime = n->parent->keys[k_prime_index];
    neighbor = neighbor_index == -1 ? n->parent->pointers[1] : n->parent->pointers[neighbor_index];
    volume = n->is_leaf ? order : order - 1;
    if(neighbor->num_keys + n->num_keys < volume)
        return coalesce_nodes(root, n, neighbor, neighbor_index, k_prime);
    else
        return redistribute_nodes(root, n, neighbor, neighbor_index, k_prime_index, k_prime);
}

Node *delete(Node *root, int key) {
    Node *key_leaf = NULL;
    Record *key_record = NULL;
    
    key_record = find(root, key, &key_leaf);
    if(key_record != NULL && key_leaf != NULL) {
        root = delete_entry(root, key_leaf, key, key_record);
        free(key_record);
    }
    return root;
}


int main() {
    for(int i = 1; i <= 50; i++)
        root = insert(root, i);

    print_tree(root);

    find_and_print(root, 15);
    find_and_print(root, 20);
    find_and_print(root, 51);

    root = delete(root, 51);
    print_tree(root);
    root = delete(root, 21);
    print_tree(root);

    return 0;
}