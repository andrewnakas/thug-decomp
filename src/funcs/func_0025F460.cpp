extern "C" int func_0025F128(void* self, int a);
extern "C" void func_0025F248(void* self, int v);

struct Node_0025F460 {
    int m0;
    void* data;
    int m8;
    Node_0025F460* m_next;
    Node_0025F460* m_prev;
    virtual ~Node_0025F460();
    Node_0025F460* Valid() { return (int)data != -1 ? this : 0; }
};

struct Obj_0025F460 {
    char pad0[0x48];
    Node_0025F460 m_list;
    void Clear();
};

void Obj_0025F460::Clear()
{
    Node_0025F460* h = &m_list;
    if (h->m_prev != h) {
        func_0025F248(this, func_0025F128(this, 0));
    }
    Node_0025F460* n = h->m_next->Valid();
    while (n) {
        Node_0025F460* next = n->m_next->Valid();
        delete n;
        n = next;
    }
}
