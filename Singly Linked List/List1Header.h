
struct list
{
    int* arr;
    int arrsize;
    int noe;
};
typedef struct list List;

void createList(List* lptr, int listsize);
void insert_ele(List* lptr, int ele, int pos);
void delete_ele(List* lptr, int pos);       // Element deleted at a given position
void display(List* lptr);
void search(List* lptr, int ele);