#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TrieNode {
    int count;
    struct TrieNode *children[26];
};

typedef struct TrieNode Trie;

void insert(Trie **ppTrie, char *word) {
    if (*ppTrie == NULL) {
        *ppTrie = (Trie*)calloc(1, sizeof(Trie));
    }
    Trie *pTrie = *ppTrie;
    for (int i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';
        if (pTrie->children[index] == NULL) {
            pTrie->children[index] = (Trie*)calloc(1, sizeof(Trie));
        }
        pTrie = pTrie->children[index];
    }
    pTrie->count++;
}

int numberOfOccurrences(Trie *pTrie, char *word) {
    for (int i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';
        if (pTrie->children[index] == NULL) {
            return 0;
        }
        pTrie = pTrie->children[index];
    }
    return pTrie->count;
}

Trie *deallocateTrie(Trie *pTrie) {
    if (pTrie == NULL) {
        return NULL;
    }
    for (int i = 0; i < 26; i++) {
        if (pTrie->children[i] != NULL) {
            deallocateTrie(pTrie->children[i]);
        }
    }
    free(pTrie);
    return NULL;
}

int main(void) {
    // Initialize the Trie data structure
    Trie *trie = NULL;


    char *pWords[] = {"notaword", "ucf", "no", "note", "corg"};
    // Read the number of words in the dictionary

    // Parse each line and insert each word into the Trie
    for (int i = 0; i < 5; i++) {
        insert(&trie, pWords[i]);
    }

    // Print the number of occurrences of each word in the dictionary
    
    for (int i = 0; i < 5; i++) {
        printf("%s : %d\n", pWords[i], numberOfOccurrences(trie, pWords[i]));
    }

    // Deallocate the Trie data structure
    trie = deallocateTrie(trie);
    if (trie != NULL) {
        printf("There is an error in this program\n");
    }

    return 0;
}
