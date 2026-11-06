extern void* D_0038C608;

struct Comp_001A4E10 {
    char pad0[0x14];
    Comp_001A4E10* m14;
    char pad18[0x60 - 0x18];
    int m60;
};

extern "C" Comp_001A4E10* func_00187278(void* reg, unsigned int key);
extern "C" void func_001A47B0(Comp_001A4E10* c);

void func_001A4E10()
{
    for (Comp_001A4E10* c = func_00187278(D_0038C608, 0x5CB5CB7E); c; c = c->m14) {
        if (c->m60)
            func_001A47B0(c);
    }
}
