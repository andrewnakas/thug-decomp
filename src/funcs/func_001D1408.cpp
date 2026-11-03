extern "C" void* func_001046B0(unsigned int size);
extern "C" void func_0010BFC0(const char*);
extern "C" void func_0010BFC8();
extern "C" void* func_0025BF70(void*);
extern "C" int func_00132580();
extern "C" void func_003331D0(char*, const char*, const char*, int);
extern "C" int func_0025D5F0(void*, char*, int, int);
extern char D_0038DC80[];

struct VtSlot_001D1408 {
    short delta;
    short pad;
    void (*fn)(void*, void*);
};

struct Obj_001D1408 {
    char pad[0x20];
    char* m_vt;
    int Load(const char* name, int b);
};

int Obj_001D1408::Load(const char* name, int b)
{
    char buf[256];
    func_0010BFC0(name);
    void* f = func_0025BF70(func_001046B0(0xB90));
    func_003331D0(buf, D_0038DC80, name, func_00132580());
    if (!func_0025D5F0(f, buf, 1, b))
        return -1;
    VtSlot_001D1408* s = (VtSlot_001D1408*)(m_vt + 0x58);
    s->fn((char*)this + s->delta, f);
    func_0010BFC8();
    return 0;
}
