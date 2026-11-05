struct Inner_00298C60 {
    char pad[0x18];
    void* m18;
};

extern int D_00391ED8;
extern "C" Inner_00298C60** func_002C0368();
extern "C" int func_00133418(void* s, void* p);
extern "C" void func_00133D48(void* s, int v);

struct Obj_00298C60 {
    char pad[0x38];
    void* m38;
    void Release();
};

void Obj_00298C60::Release()
{
    if (m38) {
        void* s = (*func_002C0368())->m18;
        func_00133418(s, m38);
        m38 = 0;
        if (D_00391ED8)
            func_00133D48(s, 0);
    }
}
