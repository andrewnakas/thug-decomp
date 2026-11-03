extern void* D_00388A70;

struct Profile_002626A0 {
    int m0;
    char m4[0x58];
    char m5C[4];
};

struct Table_002626A0 {
    int m0;
    unsigned int m4;
};

extern "C" Profile_002626A0* func_00263320(Table_002626A0* t, const unsigned int& index, int* key);
extern "C" void func_002633D8(Table_002626A0* t, int* key);
extern "C" void func_002632D8(Table_002626A0* t, int flags);
extern "C" void func_001E6AE8(void* p, int flags);
extern "C" void func_0011F8C8(void* p, int flags);
extern "C" void func_0010A8D8(void* heap, void* p);

static inline void Delete_002626A0(Profile_002626A0* p)
{
    if (p) {
        func_001E6AE8(p->m5C, 2);
        func_0011F8C8(p->m4, 2);
        func_0010A8D8(D_00388A70, p);
    }
}

static inline unsigned int Count_002626A0(Table_002626A0* t)
{
    return t->m4;
}

struct Mgr_002626A0 {
    int m0;
    Table_002626A0 m4;
    char m_pad[0x20 - 0xC];
    Profile_002626A0* m20[1];
    char m_pad2[0x2C - 0x24];
    int m2C;
    char m_pad3[0x3C - 0x30];
    Profile_002626A0* m3C[1];
    void Destroy(int flags);
};

void Mgr_002626A0::Destroy(int flags)
{
    unsigned int n = Count_002626A0(&m4);
    for (unsigned int i = 0; i < n; i++) {
        int key;
        Delete_002626A0(func_00263320(&m4, 0, &key));
        func_002633D8(&m4, &key);
    }
    for (int i = 0; i < 1; i++) {
        Delete_002626A0(m20[i]);
        m20[i] = 0;
    }
    for (int i = 0; i < m2C; i++) {
        Delete_002626A0(m3C[i]);
        m3C[i] = 0;
    }
    func_002632D8(&m4, 2);
    if (flags & 1)
        func_0010A8D8(D_00388A70, this);
}
