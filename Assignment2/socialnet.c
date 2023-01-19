#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include<stdbool.h>
#define MAX 100


// MINOR PROBLEM: PRINTS NON ADDED FRIENDS TOO
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
    char*token=strtok(str,",");
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

        int t=atoi(token);
        user->friends[i]=t;
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
/*user passed . match its id with the key . if matched then return the user ,else null*/

    if(users==NULL)
    {
        return NULL;
    }
    if(users->id==key)
    {
        return users;
    }
    if(users->id>key)
        return search(key,users->left);
    return search(key,users->right);
}

//see document for explanattion
struct node*refineUser(struct node*user, struct node *users)
{  
   /*check for id of the user,if yes increment by 1
   update friends*/
    user->left = NULL;
    user->right = NULL;
   int count=0;
   if(users==NULL)
    return user;

   while(search(user->id,users))
        (user->id)++;
    for(int i=0;i<user->numfren;i++){
        node *t=search(user->friends[i],users);
        if(t!=NULL){
            t->friends[(t->numfren)++]=user->id;
            count=1;
        }
        else{
            for(int j=i;j<(user->numfren)-1;j++){
                user->friends[j]=user->friends[j+1];
            }
            i--;
            user->numfren--;
        }
    }
if(count==0){
    for(int i=0;i<user->numfren;i++){
        user->friends[i]=-1;
    }
    user->numfren=0;
}
user->left=NULL;
user->right=NULL;
return user;

}

//insert user with id
struct node* insertUser(struct node*root,int id,struct node*user)
{   node *r=root;
    node *t;
   if(root==NULL){
    root=user;
   }
   else{
    while(r!=NULL){
        t=r;
        if(user->id>r->id){
            r=r->right;
        }
        else{r=r->left;}
    }
   if(user->id>t->id){t->right=user;}
   else{t->left=user;}
   }
return root; 
}

//prints friends list
void friends(int id, struct node *users) 
{
    if(users==NULL)
        return;
   /*id of the user is passed, search for the user with given id(call search) 
   print friends list, if no friends then -1*/
   if(users->id==id){
    if(users->numfren!=0){
for(int i=0;i<users->numfren;i++){
printf("%d\n",users->friends[i]);
}
}
else{
printf("-1\n");
}
}
friends(id,users->left);
friends(id,users->right);
}

//find child node with minimum value (inorder successor) - helper to delete node
struct node *minValueNode(struct node *node) {
  struct node* c=node;

  while(c->left!=NULL){
    c=c->left;
  }
  return c;
}

int *delete(int *a, int key,int size){
    int j=0;
    // printf("inside delete\n");

    for(int i=0;i<size;i++){
        
        if(a[i]!=key){
            j++;
        }
        else
        break;
    }

          for (int c = j; c < size - 1; c++)
         {a[c] = a[c+1];}
         return a;
}


//deletes itself from its friend's nodes

void deleteFriends(int key, struct node* users)
{/*id=key remove that id from all the friends*/
    if(users==NULL)
        return;
    for(int i=0;i<users->numfren;i++){
    if(users->friends[i]==key){
    users->friends = delete(users->friends,key,users->numfren);//delete key from array
    users->numfren--;
    }
}
deleteFriends(key,users->left);
deleteFriends(key,users->right);
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  if (root== NULL)
		return root;
	node *t = NULL;
	if (key< root->id)
		root->left = deleteNode(root->left,key);
	else if (key > root->id)
		root->right = deleteNode(root->right,key);
	else if (root->left == NULL) //single right child case and leaf node case
	{
		t = root->right;
		free(root);
		return t;
	}   
	else if (root->right == NULL) //single left child case
	{
		t = root->left;
		free(root);
		return t;
	}
	else //replacing with inorder successor
	{
		t = root->right;
        if(t!=NULL)
        {
		while (t->left != NULL) // minimum value
			t = t->left;
        }
		root->id = t->id;
        strcpy(root->name,t->name);
		root->right = deleteNode(root->right, t->id);
	}   
    return root;
}

//Print USER's IDs in ascending order
void printInOrder(node* myusers) 
{   
    if(myusers!=NULL){
       
    printInOrder(myusers->left);
    printf("%d %s\n",myusers->id, myusers->name);
    printInOrder(myusers->right);
    }
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