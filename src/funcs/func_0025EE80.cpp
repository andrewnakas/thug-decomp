struct Obj_0025EE80 {
    char pad0[0x260];
    void* m260;
};

extern void* D_00388A70;
extern "C" void* func_00184D70(int id);
extern "C" Obj_0025EE80* func_00185578(void* p, unsigned int name);
extern "C" void func_0013D910(void* p, int a);
extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" void func_001F0210(unsigned int name, int a, int b, int c, int d);

static inline void Free_0025EE80(void* p)
{
    if (p) func_0010A8D8(D_00388A70, p);
}

struct Owner_0025EE80 {
    char pad0[0x60];
    int* m_ids;
    int m_count;

    void Clear();
};

void Owner_0025EE80::Clear()
{
    if (m_ids) {
        for (int i = 0; i < m_count; i++) {
            void* x = func_00184D70(m_ids[i]);
            if (x) func_0013D910(func_00185578(x, 0x286A8D26)->m260, 0);
        }
        Free_0025EE80(m_ids);
        m_ids = 0;
    }
    m_count = 0;
    func_001F0210(0x94D0D528, 0, 0, 0, 0);
}
