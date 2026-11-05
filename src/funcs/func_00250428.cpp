struct Node_00250428 {
    int m0;
    unsigned int m4;
    int m8;
    Node_00250428* mC;
    Node_00250428* m10;
    Node_00250428* Valid() { return m4 == 0xFFFFFFFF ? 0 : this; }
};

struct List_00250428 {
    int m0;
    unsigned int m4;
    int m8;
    Node_00250428* mC;
    Node_00250428* m10;
    Node_00250428* First()
    {
        if (!~mC->m4)
            return 0;
        return mC;
    }
    unsigned int Count()
    {
        unsigned int n = 0;
        for (Node_00250428* p = First(); p; p = p->mC->Valid())
            n++;
        return n;
    }
};

struct Skate_00250428 {
    char pad0[0x30];
    List_00250428 m30;
};

struct Player_00250428 {
    char pad0[0x18];
    int m18;
};

struct Info_00250428 {
    int m0;
};

class Base_00250428 {
public:
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual int V18(int v);
};

class Obj_00250428 : public Base_00250428 {
public:
    char pad18[0x30 - 0x18];
    Info_00250428* m30;
};

extern Skate_00250428* D_0038FC78;
extern void* D_00392068;

extern "C" void* func_00240850();
extern "C" void* func_0022E358(void* p);
extern "C" int func_0024F540(void* p);
extern "C" int func_0023C128(void* p);
extern "C" int func_002B0FB8(void* m, int team);
extern "C" int func_0024F590(void* p);
extern "C" unsigned int func_0023C040(void* self);
extern "C" Player_00250428* func_0022DE70(void* game, unsigned int i);
extern "C" Obj_00250428* func_0023BB50(void* p, unsigned int idx);
extern "C" int func_002463A0(Obj_00250428* obj);

bool func_00250428()
{
    Skate_00250428* sk = D_0038FC78;
    void* net = D_00392068;
    void* g = func_00240850();
    if (func_0024F540(func_0022E358(sk))) {
        int lim = func_0023C128(g);
        for (int i = 0; i < func_0024F590(func_0022E358(sk)); i++) {
            if (func_002B0FB8(net, i) >= lim)
                return true;
        }
        return false;
    }
    unsigned int n = func_0023C040(g);
    for (unsigned int j = 0; j < sk->m30.Count(); j++) {
        Player_00250428* p = func_0022DE70(sk, j);
        bool all = true;
        unsigned int k = 0;
        if (n) {
            do {
                Obj_00250428* o = func_0023BB50(g, k);
                if (o->m30->m0 == 0 && func_002463A0(o) && !o->V18(p->m18)) {
                    all = false;
                    break;
                }
            } while (++k < n);
        }
        if (all)
            return true;
    }
    return false;
}
