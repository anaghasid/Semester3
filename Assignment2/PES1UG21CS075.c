#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include<stdbool.h>
#define MAX 100

typedef struct node 
{
    int id; //ID of user
    int numfren; //number of friends of user
    char name[MAX]; //name of user
    int* friends; //friends of user as an array
    struct node* right;  //user to the right
    struct node* left; //user to the left
} node;

struct node* retUser(char str[MAX])
{
    char name[MAX];
    char ID[MAX];
    char strfriends[MAX];

    //copied ID
    char* token=strtok(str,",");
    strcpy(ID,token);

    //copied Name
    token=strtok(NULL,",");
    strcpy(name,token);

    //copied friends' ID
    token=strtok(NULL,",");
    strcpy(strfriends,token);
    //printf("%s\n",(strfriends));

    //creating user nodes
    int id=atoi(ID);
    struct node *user = malloc(sizeof(struct node));
    user->id=id;
    user->friends=(int*)malloc(MAX * sizeof(int));
    strcpy(user->name,name);


    //adding user's friend's IDs
    token = strtok(strfriends,"|");  
    int i=0;
    while( token != NULL ) 
    {

        int temp=atoi(token);
        user->friends[i]=temp;
        i++;
        token = strtok(NULL,"|");
    }
    user->numfren=i;
    if(i==0){user->friends[i]=-1;}
    return user;
}


//search for user with id=key
struct node* search(int key, struct node *users)
{
    if(users==NULL)
        return NULL;
    if(users->id==key)
        return users;
    else if(key<users->id)    
    {
        return search(key,users->left);
    }
    else
        return search(key, users->right);
}

void deleteAFriend(struct node* user, int friend)
{
    int pos=0;
    for(;pos<user->numfren;pos++)
    {
        if(user->friends[pos]==friend)
            break;
    }
    for(int i=pos;i<(user->numfren)-1;i++)
    {
        user->friends[i] = user->friends[i+1];
    }
    user->numfren--;
}

//see document for explanattion
struct node* refineUser(struct node* user, struct node *root)
{
    user->left = NULL;
    user->right = NULL;
    // increment id 
    while(search(user->id,root)!=NULL)
    {
        user->id++;
    }
    
    if(root==NULL)
    {
        user->friends[0] = -1;  // first node to be inserted cannot have any frenz
        user->numfren = 0;
    }
   for(int i=0;i<user->numfren;i++)
    {
        if(search(user->friends[i],root)==NULL && root!=NULL)
        {
            deleteAFriend(user,user->friends[i]);
            i--;         
        }
        else
        {
            struct node* adding_node = search(user->friends[i],root);   // making the user a friend of other firends
            if(user->numfren!=0)
            {
                adding_node->friends[adding_node->numfren] = user->id;
                adding_node->numfren++;
            }
        }
    }
    if(user->numfren==0)
    {
        user->friends[0] = -1;
    }
    return user;
}

//insert user with id
struct node* insertUser(struct node* root,int id,struct node* user)
{
   if(root==NULL)
    {
        root = user;
    }
    else if(id<root->id) 
    {
        root->left = insertUser(root->left,id,user);
    }
    else
    {
        // duplicate data handled by refine
        root->right = insertUser(root->right,id,user);
    }
    
    return root;

}

//prints friends list
void friends(int id, struct node *root) 
{
    node* user = search(id,root);
    if(user==NULL)
        return;
   for(int i=0;i<user->numfren;i++)
   {
    printf("%d\n", user->friends[i]);
   }
   if(user->numfren==0)
    printf("-1\n");
}

//find child node with minimum value (inorder successor) - helper to delete node
struct node *minValueNode(struct node *root) 
{
  node* cur = root;
    if(root==NULL)
        return 0;
    while(cur->left!=NULL)
    {
        cur = cur->left;
    }
    return cur;
}

//deletes itself from its friend's nodes
void deleteFriends(int key, struct node* root)
{
    struct node* rem_node = search(key,root);
    if(rem_node==NULL)
        return;
    for(int i=0;i<rem_node->numfren;i++)
    {
        // search for all of its friends 
        struct node* friend = search(rem_node->friends[i],root);
        deleteAFriend(friend,rem_node->id);
    }   
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) 
{    
    node* temp = NULL;
    if(root==NULL)  // also handles invalid data condition
        return NULL;
    if(key<root->id)
    {
        root->left = deleteNode(root->left,key);
    }
    else if(key>root->id)
        root->right = deleteNode(root->right,key);
    else
    {
       // node to be deleted
        if(root->left==NULL)  // one child
        {
            temp = root->right;
            free(root);
            return temp;    // also handles leaf node condition
        }
        else if(root->right==NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }

        else
        {
            // find inordered succesor. It either is a leaf node or has only the right child

            // copy all contents of inorder successor to root without changing the pointer
            struct node* temp = minValueNode(root->right);
            root->id = temp->id;
            strcpy(root->name,temp->name);
            for(int i=0;i<temp->numfren;i++)
            {
                root->friends[i] = temp->friends[i];
            }
            root->right = deleteNode(root->right, root->id); // delete the inorder successor, which is a leaf node
        }
    }
    return root;
}

//Print USER's IDs in ascending order
void printInOrder(node* myusers) 
{
    if(myusers==NULL)
        return;
    printInOrder(myusers->left);
    printf("%d %s\n",myusers->id,myusers->name);
    printInOrder(myusers->right);
}


int main(int argc, char **argv)
{
    node *users=NULL;   
    while(1)
    {

        int opt, id;
        fflush(stdin);
        scanf("%d",&opt);
        char str[MAX];
        switch (opt)
        {
            case 1:
      
                scanf("%s",str);
                struct node*tbins=retUser(str);
                tbins=refineUser(tbins, users);
                users=insertUser(users,tbins->id,tbins);
                break;

            case 2:
                scanf("%d", &id);
                deleteFriends(id, users);
                users=deleteNode(users, id);
                break;

            case 3:
                scanf("%d", &id);
                node* result=search(id,users);
                if(result==NULL) 
                    printf("USER NOT IN TREE.\n");
                else{
                    printf("%d\n",result->id);
                }
                break;

            case 4:
                scanf("%d", &id);
                friends(id, users);
                break;

            case 5:
                printInOrder(users);
                break;

            case 6:
                exit(0);
                break;

            default: 
                printf("Wrong input! \n");
                break;
        }

    }
    return 0;
}


/*
1: refine and insert
2: delete given node
3: search for id and return id else USER NOT IN TREE
4: print friends of given id
5: print inorder
6: exit
*/
