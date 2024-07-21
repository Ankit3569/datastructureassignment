#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linked List node
struct node {
    // key is string
    char* key;
    // value is also string
    char* value;
    struct node* next;
};

// like constructor
void setNode(struct node* node, const char* key, const char* value) {
    node->key = malloc(strlen(key) + 1);
    strcpy(node->key, key);
    node->value = malloc(strlen(value) + 1);
    strcpy(node->value, value);
    node->next = NULL;
}

// HashMap structure
struct hashMap {
    int numOfElements, capacity;
    struct node** arr;
};

// like constructor
void initializeHashMap(struct hashMap* mp) {
    mp->capacity = 100;
    mp->numOfElements = 0;
    mp->arr = (struct node**)malloc(sizeof(struct node*) * mp->capacity);
    memset(mp->arr, 0, sizeof(struct node*) * mp->capacity); // Initialize all pointers to NULL
}

// Hash function
int hashFunction(struct hashMap* mp, const char* key) {
    int sum = 0, factor = 31;
    for (int i = 0; i < strlen(key); i++) {
        sum = ((sum % mp->capacity) + (((int)key[i]) * factor) % mp->capacity) % mp->capacity;
        factor = ((factor % __INT16_MAX__) * (31 % __INT16_MAX__)) % __INT16_MAX__;
    }
    return sum;
}

// Insert function
void insert(struct hashMap* mp, const char* key, const char* value) {
    int bucketIndex = hashFunction(mp, key);
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    setNode(newNode, key, value);

    if (mp->arr[bucketIndex] == NULL) {
        mp->arr[bucketIndex] = newNode;
    } else {
        newNode->next = mp->arr[bucketIndex];
        mp->arr[bucketIndex] = newNode;
    }
}

// Delete function
void delete(struct hashMap* mp, const char* key) {
    int bucketIndex = hashFunction(mp, key);
    struct node* prevNode = NULL;
    struct node* currNode = mp->arr[bucketIndex];

    while (currNode != NULL) {
        if (strcmp(key, currNode->key) == 0) {
            if (currNode == mp->arr[bucketIndex]) {
                mp->arr[bucketIndex] = currNode->next;
            } else {
                prevNode->next = currNode->next;
            }
            free(currNode->key);
            free(currNode->value);
            free(currNode);
            break;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }
}

// Search function
const char* search(struct hashMap* mp, const char* key) {
    int bucketIndex = hashFunction(mp, key);
    struct node* bucketHead = mp->arr[bucketIndex];

    while (bucketHead != NULL) {
        if (strcmp(key, bucketHead->key) == 0) {
            return bucketHead->value;
        }
        bucketHead = bucketHead->next;
    }

    return "Oops! No data found.\n";
}

// Main function
int main() {
    struct hashMap* mp = (struct hashMap*)malloc(sizeof(struct hashMap));
    initializeHashMap(mp);

    insert(mp, "Yogaholic", "Anjali");
    insert(mp, "pluto14", "Vartika");
    insert(mp, "elite_Programmer", "Manish");
    insert(mp, "GFG", "BITS");
    insert(mp, "decentBoy", "Mayank");

    printf("%s\n", search(mp, "elite_Programmer"));
    printf("%s\n", search(mp, "Yogaholic"));
    printf("%s\n", search(mp, "pluto14"));
    printf("%s\n", search(mp, "decentBoy"));
    printf("%s\n", search(mp, "GFG"));
    printf("%s\n", search(mp, "randomKey"));

    printf("\nAfter deletion : \n");
    delete(mp, "decentBoy");
    printf("%s\n", search(mp, "decentBoy"));

    // Freeing memory
    for (int i = 0; i < mp->capacity; i++) {
        struct node* bucketHead = mp->arr[i];
        while (bucketHead != NULL) {
            struct node* temp = bucketHead;
            bucketHead = bucketHead->next;
            free(temp->key);
            free(temp->value);
            free(temp);
        }
    }
    free(mp->arr);
    free(mp);

    return 0;
}
