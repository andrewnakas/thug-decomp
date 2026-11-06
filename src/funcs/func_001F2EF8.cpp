struct Heap_001F2EF8 {
    char pad[0xEC];
    void* mEC;
};

struct Obj_001F2EF8 {
    char pad[0x20];
    void* m20;
};

extern Heap_001F2EF8* D_00388A70;

extern "C" int func_0010CAC0(void* region);
extern "C" void func_001F2EA0(Obj_001F2EF8* o, void* p);
extern "C" int func_001F3628();

extern "C" void func_001F2EF8(Obj_001F2EF8* o, int need)
{
    for (;;) {
        if (func_0010CAC0(D_00388A70->mEC) - 0x80 >= need) {
            while (func_001F3628() >= 100 && o->m20)
                func_001F2EA0(o, o->m20);
            return;
        }
        func_001F2EA0(o, o->m20);
    }
}
