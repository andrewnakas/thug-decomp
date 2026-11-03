struct Heap_00244620 {
    char pad[0xDC];
    void* m_DC;
};

extern Heap_00244620* D_00388A70;
extern void* D_00392068;
extern float D_00387D60;

class Iter_00244620 {
public:
    void* m_node;
    int m_index;
    Iter_00244620() : m_index(0) {}
    virtual ~Iter_00244620() {}
    virtual void Run();
};

struct GoalBase_00244620 {
    char m_pad[0x14];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual bool IsLocked();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void Refresh();
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
    virtual bool IsActive();
};

struct Link_00244620 {
    unsigned int m_name;
};

struct Goal_00244620 : GoalBase_00244620 {
    int m18;
    unsigned int m_flags;
    void* m_params;
    char pad24[0x30 - 0x24];
    Link_00244620* m_link;
    char pad34[0x48 - 0x34];
    int m_48;
    char pad4C[0x64 - 0x4C];
    int m_64;
    char pad68[0x74 - 0x68];
    int m_74;
    char pad78[0x8C - 0x78];
    int m_8C;
};

struct Obj_00244620 {
    char pad[0x1C];
    void* m_1C;
};

struct Conn_00244620 {
    char pad[0x18];
    void* m_obj;
};

extern "C" void func_0010A950(Heap_00244620* heap, void* a);
extern "C" void func_0010A9B0(Heap_00244620* heap);
extern "C" Conn_00244620* func_002A53F8(void* net, Iter_00244620* it, int a);
extern "C" Conn_00244620* func_002A5490(void* net, Iter_00244620* it, int a);
extern "C" Obj_00244620* func_00185578(void* o, unsigned int id);
extern "C" bool func_00246740(Goal_00244620* g);
extern "C" void func_002381E0(void* p);
extern "C" void* func_00240850();
extern "C" Goal_00244620* func_0023BAD8(void* mgr, unsigned int name, int a);
extern "C" int func_002445F8(Goal_00244620* g);
extern "C" void func_002445E8(Goal_00244620* g, int v);
extern "C" void func_00244530(Goal_00244620* g);
extern "C" void func_00244378(Goal_00244620* g, int a, int b);
extern "C" void func_00243FB0(Goal_00244620* g);
extern "C" void func_001E6D18(void* params, unsigned int name);
extern "C" void func_00248800(Goal_00244620* g, unsigned int name);
extern "C" bool func_002A19A8(void* net);

bool func_00244620(Goal_00244620* self)
{
    if (self->IsLocked())
        return false;
    func_0010A950(D_00388A70, D_00388A70->m_DC);
    Iter_00244620 it;
    void* net = D_00392068;
    self->m_64 = 0;
    self->m_48++;
    for (Conn_00244620* c = func_002A53F8(net, &it, 0); c; c = func_002A5490(net, &it, 0)) {
        void* p = func_00185578(c->m_obj, 0xD262802F)->m_1C;
        if (!func_00246740(self))
            func_002381E0(p);
    }
    if (self->m_link->m_name) {
        Goal_00244620* g = 0;
        void* mgr = func_00240850();
        for (Link_00244620* l = self->m_link; l && l->m_name; l = g->m_link)
            g = func_0023BAD8(mgr, l->m_name, 1);
        if (g) {
            if (self->m_flags & 2)
                func_002445E8(self, (int)(func_002445F8(g) * D_00387D60));
            else
                func_00244530(self);
            if (g->IsActive()) {
                func_00244378(g, 0, 0);
                if (self->IsActive()) {
                    func_00244378(self, 0, 0);
                    func_00243FB0(self);
                }
            }
        } else {
            func_00244530(self);
        }
    } else {
        func_00244530(self);
    }
    if (!self->IsActive())
        func_00243FB0(self);
    self->m_8C = 0;
    func_001E6D18(self->m_params, 0x7100155D);
    func_00248800(self, 0x4999FB52);
    if (!func_002A19A8(net))
        self->m_74 = 1;
    self->Refresh();
    func_0010A9B0(D_00388A70);
    return true;
}
