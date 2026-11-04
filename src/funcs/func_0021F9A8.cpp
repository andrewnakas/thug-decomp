struct Node_0021F9A8 {
    int m0;
    int data;
    int m8;
    Node_0021F9A8* next;
    Node_0021F9A8* Valid() { if (~data == 0) return 0; return this; }
};

class SkBase_0021F9A8 {
public:
    int m0;
    int m4;
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
};

class Skater_0021F9A8 : public SkBase_0021F9A8 {
public:
    char padC[0x310];
    int m31C;
};

struct Mgr_0021F9A8 {
    char pad0[0x3C];
    Node_0021F9A8* m3C;
    unsigned int Count()
    {
        unsigned int n = 0;
        for (Node_0021F9A8* p = m3C->Valid(); p; p = p->next->Valid()) n++;
        return n;
    }
};

extern Mgr_0021F9A8* D_0038FC78;
extern "C" Skater_0021F9A8* func_0022DE70(Mgr_0021F9A8* m, unsigned int i);
extern "C" void func_0022C4A0(Mgr_0021F9A8* m, Skater_0021F9A8* s, int f);

bool func_0021F9A8(void* params, void* script)
{
    for (unsigned int i = 0; i < D_0038FC78->Count(); i++) {
        Skater_0021F9A8* s = func_0022DE70(D_0038FC78, i);
        if (s->m31C) s->V12();
        func_0022C4A0(D_0038FC78, s, 0);
    }
    return true;
}
