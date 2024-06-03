#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct {
    int key;
    int value;
} HashItem;

typedef struct {
    HashItem* table[TABLE_SIZE];
} HashTable;

int hashFunction1(int key) {
    return key % TABLE_SIZE;
}

int hashFunction2(int key) {
    return 7 - (key % 7);
}

HashTable* createHashTable() {
    HashTable* hashTable = (HashTable*) malloc(sizeof(HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable->table[i] = NULL;
    }
    return hashTable;
}

void insert(HashTable* hashTable, int key, int value) {
    int index1 = hashFunction1(key);
    int index2 = hashFunction2(key);
    int i = 0;

    while (hashTable->table[(index1 + i * index2) % TABLE_SIZE] != NULL) {
        i++;
        if (i == TABLE_SIZE) {
            printf("Hash table is full\n");
            return;
        }
    }

    HashItem* item = (HashItem*) malloc(sizeof(HashItem));
    item->key = key;
    item->value = value;
    hashTable->table[(index1 + i * index2) % TABLE_SIZE] = item;
}

int search(HashTable* hashTable, int key) {
    int index1 = hashFunction1(key);
    int index2 = hashFunction2(key);
    int i = 0;

    while (hashTable->table[(index1 + i * index2) % TABLE_SIZE] != NULL) {
        if (hashTable->table[(index1 + i * index2) % TABLE_SIZE]->key == key) {
            return hashTable->table[(index1 + i * index2) % TABLE_SIZE]->value;
        }
        i++;
        if (i == TABLE_SIZE) {
            return -1;
        }
    }
    return -1;
}

void delete(HashTable* hashTable, int key) {
    int index1 = hashFunction1(key);
    int index2 = hashFunction2(key);
    int i = 0;

    while (hashTable->table[(index1 + i * index2) % TABLE_SIZE] != NULL) {
        if (hashTable->table[(index1 + i * index2) % TABLE_SIZE]->key == key) {
            free(hashTable->table[(index1 + i * index2) % TABLE_SIZE]);
            hashTable->table[(index1 + i * index2) % TABLE_SIZE] = NULL;
            return;
        }
        i++;
        if (i == TABLE_SIZE) {
            printf("Key not found\n");
            return;
        }
    }
    printf("Key not found\n");
}

int main() {
    HashTable* hashTable = createHashTable();

    insert(hashTable, 1, 10);
    insert(hashTable, 2, 20);
    insert(hashTable, 12, 30);

    printf("Value for key 1: %d\n", search(hashTable, 1));
    printf("Value for key 2: %d\n", search(hashTable, 2));
    printf("Value for key 12: %d\n", search(hashTable, 12));

    delete(hashTable, 1);
    printf("Value for key 1 after deletion: %d\n", search(hashTable, 1));

    return 0;
}
