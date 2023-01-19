struct Poly
{
    int coeff;
    int px;
    int py;
    int flag;
    struct Poly *next;
};
typedef struct Poly poly;

poly* createList(poly* head);
poly* getList(poly* head,int x, int y,int coeff);
void displayList(poly* head);
poly* addPoly(poly* head1, poly* head2);
void freeList(poly *head);