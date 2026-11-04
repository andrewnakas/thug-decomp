extern void* D_0038EB78;
extern char* D_0038C308;

extern "C" int func_001FA1B0(void* p);
extern "C" int func_001F9F50(void* p);
extern "C" void func_001F0210(void* s, int a, int b, int c, int d);
extern "C" int func_001FA648(void* p);
extern "C" void func_00105260(void* p, void* q);

struct Obj_002A7938 {
    char pad[0x90];
    void* m90;
    char pad94[0x180 - 0x94];
    int m180;
    char pad184[0x1A0 - 0x184];
    void* m1A0;
    int m1A4;
    int Connect(void* a, int b);
};

int Obj_002A7938::Connect(void* a, int b)
{
    void* net = D_0038EB78;
    char* mgr = D_0038C308;
    m1A0 = a;
    m1A4 = b;
    int ok;
    if (func_001FA1B0(net)) ok = 1;
    else {
        m180 = -1;
        ok = func_001F9F50(net);
    }
    if (ok) {
        if (m1A0) func_001F0210(m1A0, 0, 0, 0, 0);
        return ok;
    }
    if (func_001FA648(net) == 1 || func_001FA648(net) == 3)
        func_00105260(mgr + 8, m90);
    return ok;
}
