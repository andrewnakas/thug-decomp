extern "C" void* func_0022DD38(void* mgr);
extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" int func_00290830(void* o);
extern void* D_0038FC78;

struct Obj_00246EE8 {
    char pad0[0x28];
    int m28;
    char pad2C[0x8C - 0x2C];
    int m8C;
    int Fn();
};

int Obj_00246EE8::Fn()
{
    void* o = func_00185578(func_0022DD38(D_0038FC78), 0xB1D5A3E1);
    switch (m28) {
    case 1:
        return func_00290830(o);
    case 0:
        return m8C;
    }
    return 0;
}
