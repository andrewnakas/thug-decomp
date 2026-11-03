extern char D_0035B5B0[];

struct Pair_0010C3A8 {
    int m0;
    int m4;
    int m8;
    Pair_0010C3A8()
    {
        m4 = 0;
        m8 = 0;
    }
};

struct Link_0010C3A8 {
    int m0;
    unsigned int m_data;
    int m8;
    Link_0010C3A8* m_next;
    Link_0010C3A8* m_prev;
    char* m_vtbl;
};

struct Node_0010C3A8 : Link_0010C3A8 {
    Node_0010C3A8()
    {
        m_data = 0xFFFFFFFF;
        m_vtbl = D_0035B5B0;
        m8 = 0;
        m_next = this;
        m_prev = this;
    }
    void Insert(Link_0010C3A8* n)
    {
        n->m_prev = this;
        n->m_next = m_next;
        m_next->m_prev = n;
        m_next = n;
    }
};

struct Block_0010C3A8 {
    int m0;
    Link_0010C3A8 m_node;
    Block_0010C3A8();
};

class Heap_0010C3A8 {
public:
    int m0;
    Pair_0010C3A8 m_a;
    Pair_0010C3A8 m_b;
    Pair_0010C3A8 m_c;
    Pair_0010C3A8 m_d;
    void* m_region;
    int m_dir;
    int m_3C;
    Block_0010C3A8* m_first;
    int m_name;
    Node_0010C3A8 m_list;
    Block_0010C3A8 m_block;
    int m7C;
    Heap_0010C3A8(void* region, int dir, int name);
    virtual void Key();
};

extern "C" void func_0010C040(void*, Heap_0010C3A8*);

Heap_0010C3A8::Heap_0010C3A8(void* region, int dir, int name)
    : m_region(region), m_dir(dir), m_name(name)
{
    func_0010C040(m_region, this);
    m_list.Insert(&m_block.m_node);
    m_first = &m_block;
}
