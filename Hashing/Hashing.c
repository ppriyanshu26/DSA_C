#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

struct KeyValue {
    char *key;
    int value;
};

struct HashTableEntry {
    struct KeyValue *data;
    struct HashTableEntry *next;
};

struct HashTable {
    struct HashTableEntry *table[TABLE_SIZE];
};

struct KeyValue *createKeyValue(const char *key, int value) {
    struct KeyValue *kv = (struct KeyValue *)malloc(sizeof(struct KeyValue));
    kv->key = strdup(key);
    kv->value = value;
    return kv;
}

struct HashTable *createHashTable() {
    struct HashTable *ht = (struct HashTable *)malloc(sizeof(struct HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = NULL;
    }
    return ht;
}

int hash(const char *key) {
    unsigned int hash = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hash = (hash * 31) + key[i];
    }
    return hash % TABLE_SIZE;
}

void insert(struct HashTable *ht, const char *key, int value) {
    int index = hash(key);
    struct KeyValue *kv = createKeyValue(key, value);
    struct HashTableEntry *entry = (struct HashTableEntry *)malloc(sizeof(struct HashTableEntry));
    entry->data = kv;
    entry->next = ht->table[index];
    ht->table[index] = entry;
}

int search(struct HashTable *ht, const char *key) {
    int index = hash(key);
    struct HashTableEntry *entry = ht->table[index];
    while (entry != NULL) {
        if (strcmp(entry->data->key, key) == 0) {
            return entry->data->value;
        }
        entry = entry->next;
    }
    return -1;
}

void freeHashTable(struct HashTable *ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        struct HashTableEntry *entry = ht->table[i];
        while (entry != NULL) {
            struct HashTableEntry *temp = entry;
            entry = entry->next;
            free(temp->data->key);
            free(temp->data);
            free(temp);
        }
    }
    free(ht);
}

int main() {
    struct HashTable *ht = createHashTable();

    insert(ht, "apple", 5);
    insert(ht, "banana", 10);
    insert(ht, "cherry", 15);
    insert(ht, "pear", 10);
    insert(ht, "pear", 5);

    printf("\nValue for 'apple': %d\n", search(ht, "apple"));
    printf("Value for 'banana': %d\n", search(ht, "banana"));
    printf("Value for 'cherry': %d\n", search(ht, "cherry"));
    printf("Value for 'grape': %d\n", search(ht, "grape"));
    printf("Value for 'pear': %d\n\n", search(ht, "pear"));

    freeHashTable(ht);

    return 0;
}
