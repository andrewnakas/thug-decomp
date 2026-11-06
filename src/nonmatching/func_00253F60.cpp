/* fuzzy: 89.8 */
/* near miss: only $s1/$s2 swapped between 'on' and the node count (16 words); tried decl order, types, loop forms */
struct Node_00253F60 {
    int m0;
    int m4;
    int m8;
    Node_00253F60* mC;
    Node_00253F60* Valid() { if (~m4 == 0) return 0; return this; }
};

struct Game_00253F60 {
    char pad[0x3C];
    Node_00253F60* m3C;
    unsigned int Count()
    {
        unsigned int c = 0;
        for (Node_00253F60* n = m3C->Valid(); n; n = n->mC->Valid()) c++;
        return c;
    }
};

struct Sk_00253F60 {
    int m0;
    int m4;
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V10();
};

struct Cfg_00253F60 {
    char pad[0x10];
    int m10;
};

extern Game_00253F60* D_0038FC78;
extern void* D_00388948;
extern void* D_0038C608;
extern void* D_00389A30;
extern Cfg_00253F60* D_0038C308;
extern "C" void func_0022E338(Game_00253F60* g, int a);
extern "C" void func_00107318(void* p);
extern "C" void func_001073C8(void* p);
extern "C" void func_001F0460(int on);
extern "C" Sk_00253F60* func_0022DE70(Game_00253F60* g, unsigned int i);
extern "C" void func_00187080(void* p, int on);
extern "C" void func_0012DD18(void* p, int on);
extern "C" void func_0010F948();
extern "C" void func_0010F950();

struct Obj_00253F60 {
    char pad[0x38];
    int m38;
    void Fn(int on);
};

void Obj_00253F60::Fn(int on)
{
    if (on == m38) return;
    Game_00253F60* g = D_0038FC78;
    if (on) {
        func_0022E338(g, 1);
        func_00107318(D_00388948);
    } else {
        func_001073C8(D_00388948);
    }
    func_001F0460(on);
    unsigned int n = g->Count();
    for (unsigned int i = 0; i < n; i++) {
        Sk_00253F60* s = func_0022DE70(g, i);
        if (s) {
            if (on) s->V09();
            else s->V10();
        }
    }
    func_00187080(D_0038C608, on);
    func_0012DD18(D_00389A30, on);
    m38 = on;
    if (on) {
        D_0038C308->m10 = 12;
        func_0010F948();
    } else {
        D_0038C308->m10 = 0;
        func_0022E338(D_0038FC78, 0);
        func_0010F950();
    }
}
