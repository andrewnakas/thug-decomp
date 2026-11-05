struct Flags_0025ED38 {
    char m_pad[0x1B0];
    long m_lo : 2;
    long m_flags : 32;
    long m_hi : 30;
    int GetFlags() const { return m_flags; }
    bool IsHidden() const { return GetFlags() & 1; }
};

struct Model_0025ED38 {
    char m_pad[0x18];
    void* m18;
};

struct Obj_0025ED38 {
    char m_pad[0xC];
    Model_0025ED38* mC;
    char m_pad10[0x14 - 0x10];
    Obj_0025ED38* m_next;
    char m_pad18[0x260 - 0x18];
    Flags_0025ED38* m260;
};

struct Heap_0025ED38;
extern Heap_0025ED38* D_00388A70;
extern void* D_0038C608;
extern char D_003757D8[];

extern "C" void func_001F0210(unsigned int name, int a, int b, int c, int d);
extern "C" Obj_0025ED38* func_00187278(void* mgr, unsigned int type);
extern "C" void* func_0010A638(Heap_0025ED38* heap, int size, int a, int b);
extern "C" void func_0013D910(Flags_0025ED38* f, int a);
extern "C" void func_00103F28(const char* fmt, ...);

struct List_0025ED38 {
    char m_pad[0x60];
    void** m_items;
    int m_count;
    void Build();
};

void List_0025ED38::Build()
{
    func_001F0210(0x722D9CA7, 0, 0, 0, 0);
    int n = 0;
    Obj_0025ED38* o;
    for (o = func_00187278(D_0038C608, 0x286A8D26); o; o = o->m_next) {
        Flags_0025ED38* f = o->m260;
        if (o->mC->m18 && !f->IsHidden())
            n++;
    }
    if (!n)
        return;
    m_items = (void**)func_0010A638(D_00388A70, n * 4, 1, 0);
    m_count = 0;
    for (o = func_00187278(D_0038C608, 0x286A8D26); o; o = o->m_next) {
        void* m = o->mC->m18;
        Flags_0025ED38* f = o->m260;
        if (m && !f->IsHidden()) {
            m_items[m_count] = m;
            func_0013D910(f, 1);
            m_count++;
        }
    }
    func_00103F28(D_003757D8, m_count);
}
