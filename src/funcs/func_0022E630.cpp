struct Node_0022E630 {
    int m0;
    int m4;
    int m8;
    Node_0022E630* mC;
    Node_0022E630* Valid() { if (~m4 == 0) return 0; return this; }
    unsigned int Count()
    {
        unsigned int n = 0;
        for (Node_0022E630* p = mC->Valid(); p; p = p->mC->Valid()) n++;
        return n;
    }
};

struct Mgr_0022E630;
extern void* D_00392068;
extern "C" int func_002A19A8(void* p);
extern "C" void* func_0022E358(Mgr_0022E630* self);
extern "C" int func_0024F860(void* p);
extern "C" void func_002638B0(void* p, int a);
extern "C" void* func_0022E048(Mgr_0022E630* self);
extern "C" void func_00266500(void* p);

struct Mgr_0022E630 {
    char pad0[0x24];
    void* m24;
    char pad28[0x8];
    Node_0022E630 m_list;
    char pad40[0x20];
    int m60;
    int m64;
    int m68;

    void Refresh();
};

void Mgr_0022E630::Refresh()
{
    void* mgr = D_00392068;
    m68 = 0;
    if ((m_list.Count() || func_002A19A8(mgr)) && m64) {
        if (func_0024F860(func_0022E358(this))) m60 = 0;
        else m60 = 1;
        func_002A19A8(mgr);
        func_002638B0(m24, -1);
        func_00266500(func_0022E048(this));
    }
}
