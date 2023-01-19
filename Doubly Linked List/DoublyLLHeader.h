struct DLL
{
    int n;
    struct DLL* left;
    struct DLL* right;
};
typedef struct DLL dll;

void displayList(dll* head);
dll* addNumbers(dll* head1, dll* head2);
dll* insertRear(dll* head, int num);
dll* mergeLists(dll* head1, dll* head2, dll* merged);
