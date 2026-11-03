struct Item_00139008 {
    int m0;
    int m4;
};

extern "C" void func_0010BFC0(void* ctx);
extern "C" void func_0010BFC8();
extern "C" int func_00138918(Item_00139008* x);
extern "C" void func_00139968(void* table, int* key, Item_00139008* x);
extern char D_0035DDE0[];

class B_00139008 {
public:
    int m0;
    int m4;
    void* m8;
    int mC;
    virtual Item_00139008* V0();
    virtual Item_00139008* V1();
    virtual Item_00139008* V2(int a, int b, int c, int d, int e);
};

class C_00139008 : public B_00139008 {
public:
    Item_00139008* Create(int a, int b, int c, int d, int e, int flags);
};

Item_00139008* C_00139008::Create(int a, int b, int c, int d, int e, int flags)
{
    func_0010BFC0(D_0035DDE0);
    Item_00139008* x = V2(a, b, c, d, e);
    if (x) {
        x->m4 = flags;
        int key = func_00138918(x);
        func_00139968(m8, &key, x);
    }
    func_0010BFC8();
    return x;
}
