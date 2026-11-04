struct Arr_0025D9F8 {
    char pad0[0xC];
    unsigned int m_size;
};

struct Base_0025D9F8 {
    char pad0[0x18];
    virtual void V0();
    virtual int Refresh();
};

struct Obj_0025D9F8 : Base_0025D9F8 {
    char pad1C[0x260 - 0x1C];
    void* m260;
};

extern "C" Arr_0025D9F8* func_001E55B8(unsigned int name, int a);
extern "C" void* func_001E9300(Arr_0025D9F8* a, unsigned int i);
extern "C" void* func_00184D70(void* p);
extern "C" Obj_0025D9F8* func_00185578(void* p, unsigned int name);
extern "C" void func_0013D950(void* p, int a);

void func_0025D9F8()
{
    Arr_0025D9F8* a = func_001E55B8(0x67F08671, 0);
    if (!a) return;
    for (unsigned int i = 0; i < a->m_size; i++) {
        void* x = func_00184D70(func_001E9300(a, i));
        if (x) {
            Obj_0025D9F8* o = func_00185578(x, 0x286A8D26);
            if (o && o->m260) {
                func_0013D950(o->m260, 1);
                o->Refresh();
            }
        }
    }
}
