class ObjBase_00246518 {
public:
    char pad0[0x14];
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
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void Refresh();
};

struct Link_00246518 {
    int m_id;
    Link_00246518* m_next;
};

extern void* D_0038FC78;
extern void* D_00392068;
extern "C" int func_002A19A8(void* net);
extern "C" void* func_0022E358(void* g);
extern "C" unsigned int func_0024F938(void* p);
extern "C" void* func_00240850();
extern "C" ObjBase_00246518* func_0023BAD8(void* mgr, int id, int a);

struct Self_00246518 {
    char pad0[0x30];
    Link_00246518* m30;
    char pad34[0x78 - 0x34];
    int m78;
    int m7C;

    void Start();
};

void Self_00246518::Start()
{
    void* g = D_0038FC78;
    if (func_002A19A8(D_00392068) && func_0024F938(func_0022E358(g)) == 0xEC200EAA)
        m7C = 1;
    else
        m78 = 1;
    void* mgr = func_00240850();
    for (Link_00246518* l = m30; l && l->m_id; l = l->m_next)
        func_0023BAD8(mgr, l->m_id, 1)->Refresh();
}
