struct NodeA_002CD4D8 {
    char pad0[0x18];
    NodeA_002CD4D8* m18;
    ~NodeA_002CD4D8();
};

struct NodeB_002CD4D8 {
    int m0;
    NodeB_002CD4D8* m4;
    ~NodeB_002CD4D8();
};

struct Color_002CD4D8 {
    unsigned char m0;
    unsigned char m1;
    unsigned char m2;
    unsigned char m3;
    unsigned char m4;
    unsigned char m5;
};

struct Inner_002CD4D8 {
    char pad0[0x18];
    void* m18;
};

struct Mgr_002CD4D8 {
    Inner_002CD4D8* m0;
};

extern "C" Mgr_002CD4D8* func_002C0368();
extern "C" void func_00133D48(void* p, int v);

struct Obj_002CD4D8 {
    unsigned char m0;
    Color_002CD4D8 m1;
    unsigned char m7;
    unsigned char m8;
    unsigned char m9;
    unsigned char mA;
    char padB;
    NodeA_002CD4D8* mC;
    NodeB_002CD4D8* m10;
    void Clear();
};

void Obj_002CD4D8::Clear()
{
    NodeA_002CD4D8* n = mC;
    while (n) {
        NodeA_002CD4D8* next = n->m18;
        delete n;
        n = next;
    }
    Color_002CD4D8* c = &m1;
    mC = 0;
    m8 = 0xFF;
    m7 = 0xFF;
    mA = 0;
    m9 = 0;
    c->m0 = 0;
    c->m1 = 0;
    c->m2 = 0;
    c->m3 = 0;
    c->m4 = 0;
    c->m5 = 0;
    func_00133D48(func_002C0368()->m0->m18, 0);
    NodeB_002CD4D8* b = m10;
    while (b) {
        NodeB_002CD4D8* next = b->m4;
        delete b;
        b = next;
    }
    m10 = 0;
}
