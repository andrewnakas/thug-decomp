extern "C" int func_0024F1D8(void* self);
extern "C" void* func_00240850();
extern "C" int func_0023C048(void* p, int v);
extern "C" int func_0023CAE0(void* p);

class Item_0024F050 {
public:
    int m0;
    virtual int V0();
    virtual int V1();
    virtual int V2();
    virtual int V3();
};

struct Node_0024F050 {
    int m0;
    Item_0024F050* m4;
    int m8;
    Node_0024F050* mC;
    Node_0024F050* m10;
    Node_0024F050* Valid() { return (unsigned int)m4 == 0xFFFFFFFF ? 0 : this; }
};

struct List_0024F050 {
    int m0;
    unsigned int m4;
    int m8;
    Node_0024F050* mC;
    Node_0024F050* m10;
    unsigned int Count()
    {
        unsigned int n = 0;
        Node_0024F050* p = mC->Valid();
        while (p) {
            p = p->mC->Valid();
            n++;
        }
        return n;
    }
    Node_0024F050* First()
    {
        if (!~(unsigned int)mC->m4)
            return 0;
        return mC;
    }
    Node_0024F050* Get(unsigned int i)
    {
        Node_0024F050* p = First();
        while (p) {
            if (i-- == 0)
                return p;
            p = p->mC->Valid();
        }
        return 0;
    }
};

struct Obj_0024F050 {
    char pad0[0xC];
    List_0024F050 mC;
    bool Fn();
};

bool Obj_0024F050::Fn()
{
    if (func_0024F1D8(this)) {
        void* x = func_00240850();
        if (func_0023C048(x, 1) > 0 && !func_0023CAE0(x))
            return true;
    }
    int total = 0;
    int ok = 0;
    for (unsigned int i = 0; i < mC.Count(); i++) {
        Node_0024F050* n = mC.Get(i);
        if (n->m4->V2()) {
            total++;
            if (n->m4->V3())
                ok++;
        }
    }
    if (total && ok == total)
        return true;
    return false;
}
