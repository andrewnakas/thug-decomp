extern char D_00366CE0[];
extern char D_00366CC8[];
extern char D_00366CB0[];
extern char D_00366C98[];
extern char D_00366C68[];
extern void* D_00388A70;

extern "C" void* func_001FE340(void* p);
extern "C" void* func_001F9480(void* p);
extern "C" void* func_0010A638(void* mem, int size, int count, int flags);
extern "C" void* func_003315B8(void* p, int c, int n);

struct Node_00201888 {
    int m0;
    unsigned int m_key;
    int m8;
    Node_00201888* m_prev;
    Node_00201888* m_next;
    void* m_vt;
};

struct Obj_00201888 {
    Node_00201888 m_node;
    Node_00201888 m_list18;
    Node_00201888 m_list30;
    char pad48[0x54 - 0x48];
    void* m54;
    void* m58;
    void* m5C;
    void* m60;
    char pad64[0x68 - 0x64];
    int m68;
    int m6C;
    char pad70[0x78 - 0x70];
    int m78;
    int m7C;
    char m80[0x400];
    char m480[0x400];
    int m880;
    Node_00201888 m_nodes[256];
    Node_00201888 m_list2084;
    Node_00201888 m_list209C;
    char m20B4[0x20EC - 0x20B4];
    char m20EC[0x34FC - 0x20EC];
    char m34FC[0x490C - 0x34FC];
    int m490C;
    Node_00201888 m_link;
    int m4928;
    char pad492C[4];
    int m4930;
    int m4934;
    int m4938;
};

static inline void InitNode(Node_00201888* n, void* vt)
{
    n->m_key = 0xFFFFFFFF;
    n->m8 = 0;
    n->m_prev = n;
    n->m_next = n;
    n->m_vt = vt;
}

static inline void InitLink(Node_00201888* n, void* owner)
{
    n->m_vt = D_00366C68;
    n->m_key = (unsigned int)owner;
    n->m8 = 0;
    n->m_prev = n;
    n->m_next = n;
}

static inline void SetCount(Obj_00201888* self, const unsigned int& n)
{
    self->m68 = 1;
    self->m6C = n;
}

Obj_00201888* Construct_00201888(Obj_00201888* self, int arg)
{
    InitNode(&self->m_node, D_00366CE0);
    InitNode(&self->m_list18, D_00366CC8);
    InitNode(&self->m_list30, D_00366CB0);
    self->m68 = 0;
    self->m6C = 0;
    Node_00201888* n = self->m_nodes;
    int i = 255;
    do {
        InitNode(n, D_00366CB0);
        i--;
        n++;
    } while (i != -1);
    InitNode(&self->m_list2084, D_00366C98);
    InitNode(&self->m_list209C, D_00366C98);
    func_001FE340(self->m20B4);
    func_001F9480(self->m20EC);
    func_001F9480(self->m34FC);
    InitLink(&self->m_link, self);
    SetCount(self, arg);
    void* p = func_0010A638(D_00388A70, 0xA28, 1, 0);
    self->m5C = p;
    self->m60 = p;
    void* q = func_0010A638(D_00388A70, 0x514, 1, 0);
    self->m7C = 0;
    self->m78 = 0;
    self->m490C = 0;
    self->m4928 = 0;
    self->m4930 = 0;
    self->m4934 = 0;
    self->m880 = 0;
    self->m4938 = 0x1068;
    self->m54 = q;
    self->m58 = q;
    func_003315B8(self->m80, 0, 0x100);
    func_003315B8(self->m480, 0, 0x100);
    return self;
}
