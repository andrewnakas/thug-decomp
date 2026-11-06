/* sym: _vt$13Node_00208AA0 = 0x0035D5C8 */

extern "C" void* func_001046B0(unsigned int size);

struct Node_00208AA0 {
    int m0;
    int m_value;
    int m8;
    Node_00208AA0* m_next;
    Node_00208AA0* m_prev;

    static void* operator new(unsigned int size) { return func_001046B0(size); }
    Node_00208AA0(int value) : m_value(value), m8(0)
    {
        m_next = this;
        m_prev = this;
    }
    virtual void V0();
    void InsertBefore(Node_00208AA0* at)
    {
        m_prev = at->m_prev;
        m_next = at;
        at->m_prev->m_next = this;
        at->m_prev = this;
    }
};
struct Table_00208AA0 {
    char m_pad0[0x24];
    int m_base;
    char m_pad28[4];
    int* m_slots;
};

struct Obj_00208AA0 {
    int Add(int value, Table_00208AA0* table, Node_00208AA0* list, int idx);
};

int Obj_00208AA0::Add(int value, Table_00208AA0* table, Node_00208AA0* list, int idx)
{
    if (idx < 0) {
        table->m_slots[table->m_base + idx] = value;
    } else {
        Node_00208AA0* n = new Node_00208AA0(value);
        n->InsertBefore(list);
    }
    return idx + 1;
}
