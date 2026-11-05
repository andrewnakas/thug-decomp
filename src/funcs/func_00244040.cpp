/* sym: __13Link_00244040 = 0x00243D70 */
extern void* D_00388A70;
extern "C" void* func_0010A638(void* heap, unsigned int size, int a, int b);

struct Link_00244040 {
    int m_id;
    Link_00244040* m_next;
    int m8;
    Link_00244040();
    static void* operator new(unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
};

struct Obj_00244040 {
    char pad[0x30];
    Link_00244040* m_30;
    void Push(int id);
};

void Obj_00244040::Push(int id)
{
    if (!m_30->m_id) {
        m_30->m_id = id;
    } else {
        Link_00244040* n = new Link_00244040;
        n->m_id = id;
        n->m_next = m_30;
        m_30 = n;
    }
}
