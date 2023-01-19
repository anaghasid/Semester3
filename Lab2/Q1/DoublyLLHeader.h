struct DLL
{
    int n;
    struct DLL* left;
    struct DLL* right;
};
typedef struct DLL dll;

void displayList(dll* head);
dll* insertRear(dll* head, int num);
int searchInfo(dll* head,int ele);