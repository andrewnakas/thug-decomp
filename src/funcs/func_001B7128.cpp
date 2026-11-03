typedef int qword_001B7128 __attribute__((mode(TI)));

struct Vec_001B7128 {
    union {
        qword_001B7128 q;
        struct {
            float x, y, z, w;
        };
    };
};

extern "C" void* func_001190D0(unsigned int size);

class Struct1E6978 {
public:
    int m_w[2];
    Struct1E6978();
    ~Struct1E6978();
    static void* operator new(unsigned int size) { return func_001190D0(size); }
};

struct Skel_001B7128 {
    char pad[0xF0];
    Vec_001B7128 mF0;
};

struct Model_001B7128 {
    char pad[0x260];
    Skel_001B7128* m260;
};

struct Owner_001B7128 {
    char pad[0x18];
    int m18;
};

extern char D_00362C48[];
extern char D_00362C58[];
extern void* D_0038FC78;
extern "C" void func_001B7288(void* self, int slot);
extern "C" void func_0010BFC0(const char* name);
extern "C" void func_0010BFC8();
extern "C" void* func_0022E040(void* mgr);
extern "C" void* func_00264998(void* factory, void* params);
extern "C" void func_001E73C8(Struct1E6978* s, const char* name, int v);
extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int req);
extern "C" void func_001E7360(Struct1E6978* s, unsigned int name, unsigned int v);
extern "C" void func_001840F8(void* obj, Struct1E6978* s);
extern "C" Model_001B7128* func_00185578(void* obj, unsigned int name);
extern "C" void func_0013EDD0(Skel_001B7128* s, Vec_001B7128* pos);

struct C_001B7128 {
    char pad[0xC];
    Owner_001B7128* mC;
    char pad10[0xC];
    void* m_slots[4];
    void* Spawn(int slot, void* params);
};

void* C_001B7128::Spawn(int slot, void* params)
{
    int off = slot * 4;
    void** slots = m_slots;
    void** p = (void**)((char*)slots + off);
    if (*p)
        func_001B7288(this, slot);
    func_0010BFC0(D_00362C48);
    void* o = func_00264998(func_0022E040(D_0038FC78), params);
    func_0010BFC8();
    *p = o;
    Struct1E6978* s = new Struct1E6978;
    func_001E73C8(s, D_00362C58, mC->m18);
    unsigned int v;
    if (func_001E8398(params, 0x40764820, &v, 0))
        func_001E7360(s, 0x40764820, v);
    func_001840F8(*p, s);
    delete s;
    Skel_001B7128* a = 0;
    Model_001B7128* m = func_00185578(mC, 0x286A8D26);
    if (m)
        a = m->m260;
    m = func_00185578(o, 0x286A8D26);
    Skel_001B7128* b = m ? m->m260 : 0;
    if (a && b) {
        Vec_001B7128 pos = a->mF0;
        func_0013EDD0(b, &pos);
    }
    return o;
}
