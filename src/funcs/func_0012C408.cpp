struct Event_0012C408 {
    unsigned int m0;
    char pad4[0xC];
    void* m10;
};

struct Target_0012C408 {
    char pad[0x18];
    int m18;
};

extern "C" int func_00184828(void* o, Event_0012C408* e, int a);
extern "C" void func_00187D28(Event_0012C408* e, int a, int b);
extern "C" void func_00189750(void* mgr, unsigned int type, int target, unsigned int id, void* s, int a);
extern void* D_0038C7B0;

class B_0012C408 {
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
};

class C_0012C408 : public B_0012C408 {
public:
    char padC[0xC];
    int m18;
    char pad1C[0x1A0];
    Target_0012C408* m1BC;
    char pad1C0[0xC];
    int m1CC;
    int m1D0;
    bool Handle(Event_0012C408* e);
};

extern "C" void func_0012C6F8(C_0012C408* o);

bool C_0012C408::Handle(Event_0012C408* e)
{
    if (!func_00184828(this, e, 0))
        return false;
    void* mgr = D_0038C7B0;
    if (e->m0 == 0x3056434F) {
        func_0012C6F8(this);
        m1D0 = 1;
        V10();
        func_00187D28(e, m18, 0);
    }
    if (e->m0 == 0x9D3FB516) {
        if (!m1BC)
            func_0012C6F8(this);
        if (!m1CC) {
            m1CC = 1;
            func_00189750(mgr, 0x9D3FB516, m1BC->m18, 0x36B2EE74, e->m10, 0);
            func_00187D28(e, m18, 0);
        }
    }
    if (e->m0 == 0x4ADF0CD3 && m1CC) {
        func_0012C6F8(this);
        m1CC = 0;
        func_00189750(mgr, 0x4ADF0CD3, m1BC->m18, 0x36B2EE74, 0, 0);
        func_00187D28(e, m18, 0);
    }
    return true;
}
