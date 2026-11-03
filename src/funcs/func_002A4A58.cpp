struct Info_002A4A58 {
    char pad[0x20];
    int m20;
    char pad24[0x180 - 0x24];
    int m180;
};

struct CompBase_002A4A58 {
    int m0;
    unsigned int m_type;
    int m8;
    int mC;
    int m10;
    int m14;
};

struct CompV_002A4A58 : CompBase_002A4A58 {
    virtual ~CompV_002A4A58();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void SetActive(int on);
};

struct Component_002A4A58 : CompV_002A4A58 {
    int m1C;
    char pad20[0x14];
    Info_002A4A58* m34;
};

struct Sk_002A4A58 {
    char pad[0x18];
    void* m18;
};

extern void* D_0038C608;
extern void* D_00392068;
extern "C" void* func_00187B48(void* p, unsigned int id);
extern "C" Component_002A4A58* func_00185578(void* p, unsigned int id);
extern "C" Sk_002A4A58* func_002A56E0(void* m);
extern "C" void func_001BA430(Component_002A4A58* c, void* obj);
extern "C" void func_001CDFB0(Component_002A4A58* c, void* obj);
extern "C" void func_001CDF70(Component_002A4A58* c);

struct Obj_002A4A58 {
    char pad[0x1A8];
    Sk_002A4A58* m1A8;
    void SetHost(Sk_002A4A58* s);
};

void Obj_002A4A58::SetHost(Sk_002A4A58* s)
{
    void* obj = func_00187B48(D_0038C608, 0x967C138C);
    Component_002A4A58* c1 = func_00185578(obj, 0x5E43A604);
    Component_002A4A58* c2 = func_00185578(obj, 0xC7D37EC2);
    if (!s || !s->m18) {
        func_001BA430(c1, 0);
        func_001CDFB0(c2, 0);
        c2->m1C = 3;
        m1A8 = 0;
        return;
    }
    if (s != func_002A56E0(D_00392068)) {
        func_001BA430(c1, s->m18);
        func_001CDFB0(c2, 0);
        c2->m1C = 3;
        c1->SetActive(0);
        c2->SetActive(1);
    } else {
        Component_002A4A58* c3 = func_00185578(s->m18, 0xD9151D4D);
        func_001BA430(c1, s->m18);
        func_001CDFB0(c2, s->m18);
        c2->m1C = 3;
        Info_002A4A58* in = c3->m34;
        bool idle = in->m180 == 0 && in->m20 == 0;
        if (idle) {
            c1->SetActive(0);
            c2->SetActive(1);
        } else {
            c1->SetActive(1);
            c2->SetActive(0);
            func_001CDF70(c2);
        }
    }
    m1A8 = s;
}
