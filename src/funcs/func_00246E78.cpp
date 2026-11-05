extern "C" void* func_0022DD38(void* mgr);
extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" int func_00290810(void* o);
extern "C" int func_00290820(void* o);
extern void* D_0038FC78;

struct Obj_00246E78 {
    char pad0[0x28];
    int m28;
    int Fn();
};

int Obj_00246E78::Fn()
{
    void* o = func_00185578(func_0022DD38(D_0038FC78), 0xB1D5A3E1);
    switch (m28) {
    case 1:
        return func_00290810(o);
    case 0:
        return func_00290820(o);
    }
    return 0;
}
