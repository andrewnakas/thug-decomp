struct Root_0029B6E0 {
    char pad0[0x18];
    void* m18;
};

struct Holder_0029B6E0 {
    Root_0029B6E0* m0;
};

extern "C" Holder_0029B6E0* func_002C0368();
extern "C" void func_00133418(void* s, void* p);
extern "C" void func_00133D48(void* s, int v);

struct Obj_0029B6E0 {
    char pad0[0x30];
    int m30;
    void* m34;
    void Detach();
};

void Obj_0029B6E0::Detach()
{
    if (m34) {
        void* s = func_002C0368()->m0->m18;
        func_00133418(s, m34);
        m34 = 0;
        m30 = 0;
        func_00133D48(s, 0);
    }
}
