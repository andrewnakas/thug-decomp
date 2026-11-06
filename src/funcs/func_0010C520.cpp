struct Node_0010C520 {
    int m0;
    void* m4;
    int m8;
    Node_0010C520* prev;
    Node_0010C520* next;
};

struct Link_0010C520 {
    int m0;
    Node_0010C520 node;
};

extern "C" void* func_001046B0(int size);
extern "C" Link_0010C520* func_0010C280(void* mem);

struct Heap_0010C520 {
    char pad0[0x40];
    Link_0010C520* m40;
    int m44;
    Node_0010C520 m48;
    void AddLink();
};

void Heap_0010C520::AddLink()
{
    Link_0010C520* l = func_0010C280(func_001046B0(0x20));
    Node_0010C520* n = &l->node;
    Node_0010C520* head = &m48;
    n->next = head;
    n->prev = head->prev;
    head->prev->next = n;
    head->prev = n;
    m40 = l;
}
