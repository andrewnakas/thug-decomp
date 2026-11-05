extern "C" void* func_001046B0(int size);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" void func_00229FF8(void* params, void* out);

struct Node_0026B538 {
    char pad[0x10];
    char m_data[0x10];
    Node_0026B538* m_next;
    short m_id;
    char m_flag;
    char m_27;
};

struct List_0026B538 {
    int m_0;
    Node_0026B538* m_head;

    void Add(int id, void* params);
};

void List_0026B538::Add(int id, void* params)
{
    Node_0026B538* n = (Node_0026B538*)func_001046B0(0x30);
    n->m_next = m_head;
    m_head = n;
    n->m_id = id;
    n->m_flag = func_001E8708(params, 0x7C2552B9);
    n->m_27 = 0;
    func_00229FF8(params, n->m_data);
}
