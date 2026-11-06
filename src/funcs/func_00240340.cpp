struct Arr_00240340 {
    char pad[0xC];
    int m_count;
};

struct Link_00240340 {
    unsigned int m_id;
};

struct GoalBase_00240340 {
    char pad[0x14];
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
    virtual int V17();
};

struct Goal_00240340 : GoalBase_00240340 {
    char pad18[0x30 - 0x18];
    Link_00240340* m_30;
};

extern void* D_0038FC78;
extern char D_00373870[];
extern "C" void* func_0022E358(void* self);
extern "C" bool func_0024F908(void* p, unsigned int id);
extern "C" Arr_00240340* func_001E55B8(unsigned int name, int a);
extern "C" Arr_00240340* func_001E93A0(void* p, int i);
extern "C" int func_001E9270(void* arr, int i);
extern "C" void* func_001E9378(void* a, int i);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E8180(void* params, unsigned int name, void** out, int required);
extern "C" bool func_001E7E58(void* params, const char* name, int* out, int required);

struct Mgr_00240340;
extern "C" Goal_00240340* func_0023BAD8(Mgr_00240340* self, unsigned int id, int create);
extern "C" void func_0023C3D8(Mgr_00240340* self);
extern "C" void func_0023C588(Mgr_00240340* self);

struct Mgr_00240340 {
    char pad[0x1C];
    void* m_1C;
    char pad20[0x48 - 0x20];
    int m_48;
    int m_4C;
    bool Advance(int force, unsigned int id);
};

bool Mgr_00240340::Advance(int force, unsigned int id)
{
    if (func_0024F908(func_0022E358(D_0038FC78), 0x353961D7)) {
        return false;
    }
    Arr_00240340* levels = func_001E55B8(0xB892776F, 1);
    Arr_00240340* needs = func_001E55B8(0x846F65F5, 1);
    if (!(m_48 < levels->m_count)) {
        return false;
    }
    Arr_00240340* goals = func_001E93A0(func_001E93A0(levels, m_48), m_4C);
    Arr_00240340* req = func_001E93A0(needs, m_48);
    int need = func_001E9270(req, m_4C);
    int steps = req->m_count;
    if (id) {
        Link_00240340* l = func_0023BAD8(this, id, 1)->m_30;
        while (l && l->m_id) {
            id = l->m_id;
            l = func_0023BAD8(this, id, 1)->m_30;
        }
    }
    int n = goals->m_count;
    int got = 0;
    for (int i = 0; i < n; i++) {
        unsigned int name;
        if (!func_001E8398(func_001E9378(goals, i), 0x9982E501, &name, 0)) {
            continue;
        }
        Goal_00240340* g = func_0023BAD8(this, name, 0);
        if (g) {
            Link_00240340* l = g->m_30;
            while (l && l->m_id) {
                name = l->m_id;
                g = func_0023BAD8(this, l->m_id, 1);
                l = g->m_30;
            }
        }
        if (g) {
            if ((name == id && !g->V17()) || g->V17()) {
                got++;
            }
        } else {
            void* info;
            if (func_001E8180(m_1C, name, &info, 0)) {
                int done = 0;
                func_001E7E58(info, D_00373870, &done, 1);
                if (done) {
                    got++;
                }
            }
        }
    }
    if (got >= need || force) {
        if (m_4C + 1 == steps) {
            m_4C = 0;
            m_48++;
        } else {
            m_4C++;
        }
        func_0023C3D8(this);
        func_0023C588(this);
        return true;
    }
    return false;
}
