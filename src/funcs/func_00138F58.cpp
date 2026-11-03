struct Item_00138F58 {
    int m0;
    int m4;
};

extern "C" void func_0010BFC0(void* ctx);
extern "C" void func_0010BFC8();
extern "C" int func_00138918(Item_00138F58* x);
extern "C" void func_00139968(void* table, int* key, Item_00138F58* x);

class B_00138F58 {
public:
    int m0;
    int m4;
    void* m8;
    int mC;
    virtual Item_00138F58* V0(void* a, int b, int c);
    virtual Item_00138F58* V1(void* a, int b, int c);
};

class C_00138F58 : public B_00138F58 {
public:
    Item_00138F58* Create(void* a, int b, int c, int flags);
};

Item_00138F58* C_00138F58::Create(void* a, int b, int c, int flags)
{
    func_0010BFC0(a);
    Item_00138F58* x = V1(a, b, c);
    if (x) {
        x->m4 = flags;
        int key = func_00138918(x);
        func_00139968(m8, &key, x);
    }
    func_0010BFC8();
    return x;
}
