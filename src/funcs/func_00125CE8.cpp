class Struct1E6978 {
public:
    int m_w[4];
    Struct1E6978();
    ~Struct1E6978();
};

struct Event_00125CE8 {
    unsigned int m_type;
};

extern "C" int func_00184828(void* o, Event_00125CE8* e, int a);
extern "C" int func_00187D68(Event_00125CE8* e);
extern "C" void func_00187D28(Event_00125CE8* e, int a, int b);
extern "C" void func_001E7200(Struct1E6978* s, unsigned int id, int v);
extern "C" void func_00189750(void* mgr, unsigned int type, int target, unsigned int id, Struct1E6978* s, int a);

extern void* D_0038C7B0;

struct C_00125CE8 {
    char pad[0x18];
    int m18;
    char pad1C[0x184];
    int m1A0;
    bool Handle(Event_00125CE8* e);
};

bool C_00125CE8::Handle(Event_00125CE8* e)
{
    if (!func_00184828(this, e, 0))
        return false;
    if (e->m_type == 0x9D3FB516 || e->m_type == 0x4ADF0CD3) {
        if (m1A0) {
            int v = func_00187D68(e);
            Struct1E6978 s;
            func_001E7200(&s, 0xB30D9965, v);
            func_00189750(D_0038C7B0, e->m_type, m1A0, 0x36B2EE74, &s, 0);
        }
        func_00187D28(e, m18, 0);
    }
    return true;
}
