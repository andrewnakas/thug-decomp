extern void* D_0038DB38;
extern "C" int func_001D0058(void* mgr, int name, int type, int a3, int t0, int t1, int t2);

struct Obj_0025CA48 {
    char pad[0xA5C];
    int mA5C[64];
    int mB5C;
    void Fn(int name, int a, int b);
};

void Obj_0025CA48::Fn(int name, int a, int b)
{
    func_001D0058(D_0038DB38, name, 5, a, b, 0, 0);
    mA5C[mB5C] = name;
    mB5C++;
}
