struct Node_001FEAE8 {
    void* m_data;
    unsigned int m_flag;
    int m_pri;
    Node_001FEAE8* m_next;
    Node_001FEAE8* m_prev;
    void InsertBefore(Node_001FEAE8* node)
    {
        node->m_prev = m_prev;
        node->m_next = this;
        m_prev->m_next = node;
        m_prev = node;
    }
};

struct Mgr_001FEAE8;

struct Conn_001FEAE8 {
    char m_pad[0x48];
    int m_id;
    int m_ip;
    unsigned short m_port;
    char m_pad52[0x70 - 0x52];
    Mgr_001FEAE8* m_mgr;
    int m_time;
    char m_pad78[0x4910 - 0x78];
    Node_001FEAE8 m_node;
};

struct Mgr_001FEAE8 {
    char m_pad[0x184C];
    int m_numConns;
    int m_maxConns;
    char m_pad1854[0x42D8 - 0x1854];
    Node_001FEAE8 m_conns;
};

struct Heap_001FEAE8 {
    char m_pad[0xF4];
    void* m_heap;
};

extern Heap_001FEAE8* D_00388A70;

extern "C" void func_0010A950(Heap_001FEAE8* mem, void* heap);
extern "C" void func_0010A9B0(Heap_001FEAE8* mem);
extern "C" void* func_0010A638(Heap_001FEAE8* mem, int size, int a, int b);
extern "C" Conn_001FEAE8* func_00201888(void* mem, int a);
extern "C" int func_001FD968(Mgr_001FEAE8* self);
extern "C" int func_0010FC30();

Conn_001FEAE8* func_001FEAE8(Mgr_001FEAE8* self, int ip, unsigned short port, int flags)
{
    Conn_001FEAE8* conn = 0;
    func_0010A950(D_00388A70, D_00388A70->m_heap);
    if (self->m_numConns < self->m_maxConns) {
        conn = func_00201888(func_0010A638(D_00388A70, 0x493C, 1, 0), flags);
        conn->m_ip = ip;
        conn->m_port = port;
        conn->m_id = func_001FD968(self);
        conn->m_mgr = self;
        conn->m_time = func_0010FC30();
        self->m_conns.InsertBefore(&conn->m_node);
    }
    func_0010A9B0(D_00388A70);
    return conn;
}
