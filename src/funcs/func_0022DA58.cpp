struct Del08_0022DA58 {
    int m0;
    int m4;
    virtual ~Del08_0022DA58();
};

struct Del0C_0022DA58 {
    int m0;
    int m4;
    int m8;
    virtual ~Del0C_0022DA58();
};

struct Del18_0022DA58 {
    char m_pad[0x18];
    virtual ~Del18_0022DA58();
};

struct Del18c_0022DA58 {
    char m_pad[0x18];
    virtual void V0_0022DA58();
    virtual void V1_0022DA58();
    virtual ~Del18c_0022DA58();
};

struct Del24_0022DA58 {
    char m_pad[0x24];
    virtual ~Del24_0022DA58();
};

struct Del3C_0022DA58 {
    char m_pad[0x3C];
    virtual ~Del3C_0022DA58();
};

struct Del670_0022DA58 {
    char m_pad[0x670];
    virtual ~Del670_0022DA58();
};

struct Node_0022DA58 {
    void* m0;
    int m4;
    int m8;
    Node_0022DA58* m_next;
    Node_0022DA58* m_prev;
    void* m_vtbl;
};

struct Game_0022DA58 {
    char m_pad0[0x14];
    void* m_vtbl;
    Del18c_0022DA58* m18;
    char m_pad1C[0x24 - 0x1C];
    Del670_0022DA58* m24;
    void* m28;
    char m_pad2C[0x30 - 0x2C];
    Node_0022DA58 m_list;
    char m_pad48[0x74 - 0x48];
    Del24_0022DA58* m74;
    Del3C_0022DA58* m78;
    void* m7C;
    void* m80;
    void* m84;
    Del0C_0022DA58* m88;
    char m_pad8C[0x394 - 0x8C];
    void* m394;
    void* m398;
    Del08_0022DA58* m39C;
    Del08_0022DA58* m3A0;
    char m_pad3A4[0x3BC - 0x3A4];
    Del18_0022DA58* m3BC;
    void* m3C0;
};

extern char D_00373018[];
extern char D_00366F50[];
extern void* D_00388A70;

extern "C" void func_0026ED98(void* p, int flags);
extern "C" void func_00250BA0(void* p, int flags);
extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" void func_002683A0(void* p, int flags);
extern "C" void func_002309D8(Game_0022DA58* self);
extern "C" void func_0023B540(void* p, int flags);
extern "C" void func_002626A0(void* p, int flags);
extern "C" void func_00182A10(Game_0022DA58* self, int flags);

void func_0022DA58(Game_0022DA58* self, int flags)
{
    self->m_vtbl = D_00373018;
    if (self->m84) {
        func_0026ED98(self->m84, 3);
    }
    if (self->m394) {
        func_00250BA0(self->m394, 3);
    }
    func_0010A8D8(D_00388A70, self->m398);
    delete self->m39C;
    delete self->m3A0;
    if (self->m28) {
        func_002683A0(self->m28, 3);
    }
    delete self->m24;
    func_002309D8(self);
    delete self->m3BC;
    delete self->m74;
    if (self->m3C0) {
        func_0023B540(self->m3C0, 3);
    }
    if (self->m80) {
        func_002626A0(self->m80, 3);
    }
    delete self->m18;
    delete self->m88;
    func_0010A8D8(D_00388A70, self->m7C);
    delete self->m78;
    Node_0022DA58* node = &self->m_list;
    node->m_vtbl = D_00366F50;
    node->m_prev->m_next = node->m_next;
    node->m_next->m_prev = node->m_prev;
    node->m_next = node;
    node->m_prev = node;
    func_00182A10(self, flags);
}
