struct Node_0017F6A0;

struct Obj_0017F6A0 {
    int m0;
    char pad4[0x3C];
    Node_0017F6A0* m40;
};

extern "C" void func_0017EBE8(Node_0017F6A0* n);
extern "C" void func_0017EC48(Node_0017F6A0* n, int on);

extern "C" void func_0017F6A0(Obj_0017F6A0* o, Node_0017F6A0* n)
{
    if (n && o->m40 != n) {
        func_0017EBE8(n);
        if (!o->m0) {
            func_0017EC48(n, 1);
            if (o->m40) {
                func_0017EC48(o->m40, 0);
            }
        }
    }
    o->m40 = n;
}
