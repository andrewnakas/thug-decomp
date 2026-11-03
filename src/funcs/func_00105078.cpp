extern "C" void* func_001046B0(unsigned int size);

struct Link105078 {
    int m0;
    int m4;
    int m8;
    Link105078* m_prev;
    Link105078* m_next;
};

struct Child105078 {
    char pad[0x28];
    Link105078* m_link;
};

// constructor of Child105078 (returns this)
extern "C" Child105078* func_00104E38(void* self);

struct Obj105078 {
    int m0;
    int m4;
    int m8;
    Link105078 m_list;
    char pad[0x3C - 0x20];
    Child105078* m_child;
    int m40;
    int m44;
    void Create();
};

void Obj105078::Create()
{
    Child105078* child = func_00104E38(func_001046B0(0x2C));
    m_child = child;
    Link105078* link = child->m_link;
    Link105078* head = &m_list;
    link->m_next = head;
    link->m_prev = head->m_prev;
    head->m_prev->m_next = link;
    head->m_prev = link;
    m44 = 1;
}
