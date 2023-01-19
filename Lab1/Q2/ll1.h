struct node{
    int data;
    struct node* link;
};
typedef struct node Node;

Node *createlist(Node *head);
Node *InsertFront(Node *head,int ele);
Node *InsertRear(Node *head,int ele);
Node *Insertatpos(Node *head,int ele,int pos);
void DestroyList(Node* head);
void Display(Node* head);
Node* deleteFront(Node* head);
void deleteRear(Node* head);
void deletePos(Node* head,int pos);
void deleteAlt(Node* head);
void destroyList(Node* head);