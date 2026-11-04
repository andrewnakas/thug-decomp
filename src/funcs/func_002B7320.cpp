extern void* D_00388A70;
extern "C" void func_0010A8D8(void* pool, void* p);

struct Elem_002B7320 {
    char pad[0x280];
    virtual ~Elem_002B7320();
};

struct Sub_002B7320 {
    int m0;
    ~Sub_002B7320();
};

struct Obj_002B7320 {
    char pad0[0x14];
    Elem_002B7320* m14;
    Elem_002B7320* m18;
    char pad1[0x2C - 0x1C];
    Sub_002B7320 m2C;
    char pad2[0x64 - 0x30];
    Sub_002B7320 m64;
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
    ~Obj_002B7320();
};

Obj_002B7320::~Obj_002B7320()
{
    if (m18) delete m18;
    if (m14) delete m14;
}
