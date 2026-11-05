class Skater_00246DA0 {
public:
    int m0;
    int m4;
    virtual void V0();
    virtual void V1();
    virtual void V2(unsigned int name, int a, int b);
};

struct Obj_00246DA0 {
    char pad0[0x28];
    int m28;
    char pad2C[0x60];
    int m8C;
};

extern void* D_0038FC78;
extern "C" Skater_00246DA0* func_0022DD38(void* m);
extern "C" void* func_00185578(Skater_00246DA0* s, unsigned int name);
extern "C" void func_00290840(void* c);
extern "C" void func_00290858(void* c);

void func_00246DA0(Obj_00246DA0* o, int arg)
{
    o->m8C = 0;
    Skater_00246DA0* s = func_0022DD38(D_0038FC78);
    void* c = func_00185578(s, 0xB1D5A3E1);
    int t = o->m28;
    if (t != 0) {
        if (t == 1) {
            s->V2(0x4C58771E, 0, arg);
            func_00290840(c);
        }
    } else {
        s->V2(0x69A9E37F, 0, arg);
        func_00290858(c);
    }
}
