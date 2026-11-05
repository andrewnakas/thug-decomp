extern "C" int func_002502F8(void* item);

class Item_0024F628 {
public:
    int m0;
    virtual int V0();
    virtual int V1();
    virtual int V2();
    virtual int V3();
};

struct Node_0024F628 {
    int m0;
    Item_0024F628* m4;
    int m8;
    Node_0024F628* mC;
    Node_0024F628* m10;
    Node_0024F628* Valid() { return (unsigned int)m4 == 0xFFFFFFFF ? 0 : this; }
};

struct List_0024F628 {
    int m0;
    unsigned int m4;
    int m8;
    Node_0024F628* mC;
    Node_0024F628* m10;
    unsigned int Count()
    {
        unsigned int n = 0;
        Node_0024F628* p = mC->Valid();
        while (p) {
            p = p->mC->Valid();
            n++;
        }
        return n;
    }
    Node_0024F628* First()
    {
        if (!~(unsigned int)mC->m4)
            return 0;
        return mC;
    }
    Node_0024F628* Get(unsigned int i)
    {
        Node_0024F628* p = First();
        while (p) {
            if (i-- == 0)
                return p;
            p = p->mC->Valid();
        }
        return 0;
    }
};

struct Obj_0024F628 {
    char pad0[0xC];
    List_0024F628 mC;
    int Fn();
};

int Obj_0024F628::Fn()
{
    for (unsigned int i = 0; i < mC.Count(); i++) {
        Item_0024F628* it = mC.Get(i)->m4;
        if (it)
            return func_002502F8(it);
    }
    return 0;
}
