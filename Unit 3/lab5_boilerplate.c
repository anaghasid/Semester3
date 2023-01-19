#include <stdio.h>
#include <stdlib.h>

int check=0;
int found=0;
//struct for node
struct node {
    char value;            // all void types replaced by char*
    struct node *p_left;
    struct node *p_right;
};

int my_strlen(char * s) 
{
    int i=0;
    while (s[i]!='0')
        i++;
    return i;  
}

void my_strcpy(char *str1, char *str2)//str2 is source, str1 is dest
{
    
}
int my_strcmp(const char *a, const char *b)
{
    for(int i=0;i<13;i++){
        if(a[i]<b[i]){
            return -1;
        }
        if(a[i]>b[i]){
            return 1;
        }
    }
    return 0;
}
//inserts elements into the tree
void insert(char* key, struct node** leaf)
{
    
    if(*leaf==NULL)
    {
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->value=key;
    newnode->p_left=NULL;
    newnode->p_right=NULL;
        *leaf=newnode;
        return;
    }
    int ans=my_strcmp((*leaf)->value,key);
    if(ans==1)
        insert(key,&(*leaf)->p_left);
    else
        if(ans==0)
                check=1;
                
                
        else{
            insert(key,&(*leaf)->p_right);
        }      
        
}

//recursive function to print out the tree inorder
void asc_order(struct node *root)
{
    if(root==NULL){
        return;
    }  
    asc_order(root->p_left);
    printf("%s\n",root->value);
    asc_order(root->p_right);
}

//searches elements in the tree
void search(char* key, struct node* leaf)  // no need for **
{
    if(leaf==NULL)
        return;
    
    int ans=my_strcmp(key,leaf->value);
    if(ans==-1)
        search(key,leaf->p_left);
    else
        if(ans==1)
            search(key,leaf->p_right);
    else
        found=1;
}
int main()
{
    struct node *p_root = NULL;
    char *value;
    size_t malloc_size = 100;
    int size;
    int k=100;
    scanf("%d",&size);
    int i;
    //reading the input and inserting in the tree
    char *srn[size];
    for (i = 0; i < size; i++) 
    {
        srn[i] = malloc(malloc_size * sizeof(char)); /* allocates 100 bytes */
        scanf("%99s", srn[i]);
        insert(srn[i],&p_root);
    }   
    char searchname[k];
    scanf("%s",searchname);

    //checking inorder print
    asc_order(p_root);

    //checking for 1 or more duplicate insertions
    printf("%d\n",check);

    //searching a string in the tree
    search(searchname,p_root);
    printf("%d\n",found);
    return 0;
}