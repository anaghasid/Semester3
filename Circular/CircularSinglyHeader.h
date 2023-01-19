struct scircular
{
    int data;
    struct scircular* link;
};
typedef struct scircular circ;


circ* insertFront(circ* head, int ele);
void displayList(circ* head);
circ* deleteRear(circ* head);
