extern void* D_00388A70;
extern "C" void* func_0010A638(void* pool, unsigned int size, int a, int b);
extern "C" void func_003331D0(char*, const char*);
extern "C" void func_0010BFC0(const char*);
extern "C" void func_0010BFC8();
extern "C" void* func_00115CE0(void*);
extern "C" int func_00115E50(void*, int, int, int);
extern "C" void func_001E53A0(unsigned int, int);
extern "C" void func_00115D58(void*, int);
extern char D_00363AB0[];

struct VtSlot_001D11B0 {
    short delta;
    short pad;
    void (*fn)(void*, void*);
};

struct Obj_001D11B0 {
    char pad[0x20];
    char* m_vt;
    int Load(int a, int b);
};

int Obj_001D11B0::Load(int a, int b)
{
    char buf[256];
    int result = -1;
    func_003331D0(buf, D_00363AB0);
    func_0010BFC0(buf);
    void* f = func_00115CE0(func_0010A638(D_00388A70, 0x44, 1, 0));
    if (!func_00115E50(f, a, b, 1)) {
        func_001E53A0(0x25DC7904, 0);
        if (f)
            func_00115D58(f, 3);
        f = 0;
    } else {
        result = 0;
    }
    VtSlot_001D11B0* s = (VtSlot_001D11B0*)(m_vt + 0x58);
    s->fn((char*)this + s->delta, f);
    func_0010BFC8();
    return result;
}
