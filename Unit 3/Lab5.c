#include <stdio.h>
#include <stdlib.h>

int check=0;
int found=0;
//struct for node
struct node {
    char *value;            // all void* types replaced by char*
    struct node *p_left;
    struct node *p_right;
};

int my_strlen(char *s) 
{

}

void my_strcpy(char *str1, char *str2)//str2 is source, str1 is dest
{
    
}

int my_strcmp(const char *a, const char *b)
{
   // if a is lesser than b, return 1. return -1 if a is after b. 0 if equal
   for(int i=0; i<13;i++)
   {
        if(a[i]<b[i])
            return 1;
        if(b[i]<a[i])
            return -1;
   } 
   return 0;
}

struct node* createNode(char* key)
{  
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->value = key;
    newnode->p_left = NULL;
    newnode->p_right = NULL;
    return newnode;
}
//inserts keyments into the tree
void insert(char* key, struct node** leaf)
{
    if(*leaf==NULL)
    {
        struct node* newnode = createNode(key);
        *leaf = newnode;
        return;
    }
    if(my_strcmp(key,(*leaf)->value)==1)
    {
        insert(key,&((*leaf)->p_left));    
        // if key is lesser than its parent node, it checks with the left node. When leftmost node reaches null, it is assigned to newnode
    }
    else if(my_strcmp(key,(*leaf)->value)==-1)
    {
        insert(key,&((*leaf)->p_right));
    }
    else
    {
        check = -1;
    }
}



//recursive function to print out the tree inorder
void asc_order(struct node **leaf)
{
    if(*leaf==NULL)
        return;
    asc_order(&((*leaf)->p_left));
    printf("%s\n",(*leaf)->value);
    asc_order(&((*leaf)->p_right));
}



//searches keyments in the tree
void search(char* key, struct node* leaf)  // no need for **
{
    if(leaf==NULL)
        return;
    if(key==leaf->value)
    {
        found = 1;
        return;
    }
    search(key,leaf->p_left);
    search(key,leaf->p_right); 
}




int main()
{
    struct node *p_leaf = NULL;
    char *value;
    size_t malloc_size = 100;
    int size;
    int temp=100;
    scanf("%d",&size);
    int i;
    //reading the input and inserting in the tree
    char* srn[size];
    for (i = 0; i < size; i++) 
    {
        srn[i] = malloc(malloc_size * sizeof(char)); /* allocates 100 bytes */
        scanf("%99s", srn[i]);
        insert(srn[i],&p_leaf);
    }   
    char searchname[temp];
    scanf("%s",searchname);

    //checking inorder print
    asc_order(&p_leaf);

    //checking for 1 or more duplicate insertions
    printf("%d\n",check);

    //searching a string in the tree
    search(searchname,p_leaf);
    printf("%d\n",found);
    return 0;
}