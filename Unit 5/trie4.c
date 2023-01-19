#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ALPHABET_SIZE 26

struct trienode
{
    struct trienode *children[ALPHABET_SIZE];   // each array element is pointer to another array
    int isEndofWord;
};
typedef struct trienode Trie;

Trie *createroot(void)
{
    Trie *newnode;
    newnode = (Trie*)malloc(sizeof(Trie));
    for(int i = 0; i < ALPHABET_SIZE; i++){
        newnode->children[i] = NULL;
    }
    newnode->isEndofWord = 0;
    return newnode;
}

void insert(Trie *root, char *key)
{
    int len, level, index;
    Trie *cur = root;
    len = strlen(key);  // length of word

    for(level = 0; level < len; level++)    // inserting each letter
    {
        index = (int)key[level] - (int)'a';     // key[level] gives the particular letter from the string
        if(cur->children[index] == NULL)
        {
            cur->children[index] = createroot();
        }
        cur = cur->children[index];     // next level in the trie
    }
    cur->isEndofWord = 1;
}

void search(Trie *root, char *word)
{
    int wordlen = strlen(word);
    int index, level;
    Trie *cur = root;
    for(level = 0; level < wordlen; level++)
    {
        index = (int)(word[level] - 'a');
        if(cur->children[index] == NULL)
        {
            printf("Nope, word doesn't exist\n");
            return;
        }
        cur = cur->children[index];
    }
    printf("Word is present\n");
    return;
}

int isLeafNode(Trie *root)
{
    if(root->isEndofWord == 1)
        return 1;
    return 0;
}

void display(Trie *root, char str[], int level)
{
    Trie *cur = root;
    if(isLeafNode(root))
    {
        str[level] = '\0';
        printf("%s\n", str);
    }

    for(int i = 0; i < ALPHABET_SIZE; i++)
    {
        if(cur->children[i] != NULL)
        {
            str[level] = i + 'a';   
            //printf("%c\n", (char)(i+'a'));
            display(cur->children[i], str, ++level);
            level--;
        }
    }
    return;
}

// displays all strings of given length
void displaylen(Trie *root, char str[], int level, int len)
{
    // level takes current level
    // recursive. Takes new string level (char position in string) in each 
    if(isLeafNode(root))
    {
        str[level] = '\0';
        if(level == len)
        {
            printf("%s\n", str);
        }
    }
    for(int i = 0; i < ALPHABET_SIZE; i++)
    {
        // appending the next character to the string. If length does not match, it comes back in the loop and that position is changed again
        if(root->children[i] != NULL)
        {
            str[level] = i + 'a';
            displaylen(root->children[i], str, level+1, len);
        }
    }

}

int isEmpty(Trie *root)
{
    for(int i =0 ; i < ALPHABET_SIZE; i++)
    {
        if(root->children[i] != NULL)
            return 0;
    }
    return 1;
}

Trie* removeString(Trie *root, char str[], int level, int len)
{
    if(root==NULL)      // previously said root!=NULL
    {
        return NULL;
    }
    if(level == len)
    {
        if(root->isEndofWord == 1)
        {
            root->isEndofWord = 0;
            if(isEmpty(root))
            {                
                free(root);
                return NULL;
            }
        }
        return root;
    }
    int index = str[level] - 'a';
    root->children[index] = removeString(root->children[index], str, level+1, len);
    if(isEmpty(root) && root->isEndofWord == 0)
    {
        free(root);
        root = NULL;
    }
    return root;
}

int main()
{
    Trie *root;
    root = createroot();
    char text[][6] = {"this", "these", "the", "there", "trie", "five"};
    for(int i = 0; i < 6; i++)
    {
        insert(root, text[i]);
    }
    /*    
    char *searchword;
    printf("Enter the word to be searched:");
    scanf("%s", searchword);    //why is this giving segfault?

    try mallocing searchword ptr
    */
    char searchword[] = "these";
    search(root, searchword);

    char str[20];
    display(root, str, 0);  //display all the strings in the Trie

    printf("Strings of length 3:\n");
    displaylen(root, str, 0, 3);

    strcpy(str, "the");
    removeString(root, str, 0, 3);

    return 0;
}