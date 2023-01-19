#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define Alphabet 26

struct trienode
{
    struct trienode *children[Alphabet];
    int isEow;
};
typedef struct trienode Trie;

Trie* createRoot()
{
    Trie* newnode;
    newnode = (Trie*)malloc(sizeof(Trie));
    for(int i=0;i<Alphabet;i++)
    {
        newnode->children[i] = NULL;
    }
    newnode->isEow = 0;
}

void insert(Trie* root, char* key)
{
    int len, level;
    int pos;
    if(key[0]=='\0')
    {
        root->isEow = 1;
        return;
    }
    Trie* cur = root;
    len = strlen(key);
    pos = key[0]-'a';
    Trie* newnode = createRoot();
    root->children[pos] = newnode;
    root->isEow = 0;
    insert(newnode,key+1);
}

int main()
{
    Trie* root;
    root = createRoot();
    char text[][5] = {"this","these","the","there","trie"};
    for(int i=0;i<5;i++)
    {
        insert(root,text[i]);
    }
}