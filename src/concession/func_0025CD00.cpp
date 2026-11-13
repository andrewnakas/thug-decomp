/* force: {"kind": "sched", "pass": 2, "block": 6, "clock": 3, "first": [137, 1621]} */
typedef int qword_0025CD00 __attribute__((mode(TI)));

struct Vec_0025CD00 {
    union {
        qword_0025CD00 q;
        struct {
            float x, y, z, w;
        } f;
    };
    Vec_0025CD00() {}
    Vec_0025CD00(float x, float y, float z, float w)
    {
        f.x = x;
        f.y = y;
        f.z = z;
        f.w = w;
    }
};

/* One placed piece: its id, flags, attached object and links. */
struct Ent_0025CD00 {
    int m_id;
    int m_flags;
    int m_8;
    int m_special;
    void* m_10;
    void* m_obj;
    void* m_prevObj;
    int m_index;
};

struct Mesh_0025CD00 {
    char pad0[0x1B0];
    unsigned long m1B0;
};

/* Model component (0x286A8D26); vptr at 0x18 like every component. */
class ModelBase_0025CD00 {
public:
    char pad0[0x18];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void Show(int on);
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void RunScript(void* prof, int a, int b, unsigned int name);
};

class Model_0025CD00 : public ModelBase_0025CD00 {
public:
    char pad1C[0x260 - 0x1C];

    Mesh_0025CD00* m260;
    char pad264[0x288 - 0x264];
    int m288;
};

struct Obj_0025CD00 {
    char pad0[0x50];
    Vec_0025CD00 m50;
};

struct Builder_0025CD00 {
    char pad0[0x4];
    void* m4;
    char pad8[0x10 - 0x8];
    void* m10;
    char pad14[0x20 - 0x14];
    Vec_0025CD00 m20;
    int m30;
    int m34;
    char pad38[0x40 - 0x38];
    Vec_0025CD00 m40;
    int m50;
    Ent_0025CD00 m54[64];
    int m_count;
    bool Build(int* data);
};

extern char D_00390C00[];
extern void* D_0038FC78;

extern "C" int func_001F0D78(char* a);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" void func_001E7360(void* params, unsigned int name, int v);
extern "C" void func_001E7200(void* params, unsigned int name, int v);
extern "C" void func_001E6AE8(void* params, int how);
extern "C" int func_0010F7C0(void* tab, unsigned int a, unsigned int b);
extern "C" char* func_0022E3C8(void* mgr, int a);
extern "C" void* func_001200E0(char* p);
extern "C" int func_00123420(void* p);
extern "C" int func_001E7DE8(void* params, unsigned int name, int* out, int req);
extern "C" void* func_0011FE18(char* prof, unsigned int name);
extern "C" int func_001E8708(void* s, unsigned int name);
extern "C" void func_001F0210(unsigned int script, void* params, void* o, int a, int b);
extern "C" Obj_0025CD00* func_0025CBC8(void* params);
extern "C" Model_0025CD00* func_00185578(void* obj, unsigned int name);
extern "C" void func_0013F010(Mesh_0025CD00* m, const Vec_0025CD00& v);
extern "C" void* func_0018DF68(Model_0025CD00* c);
extern "C" Obj_0025CD00* func_00184D70(void* p);
extern "C" Vec_0025CD00 func_0013EF90(Mesh_0025CD00* m);
extern "C" void func_0013D910(Mesh_0025CD00* m, int a);
extern "C" void func_0013EE48(Mesh_0025CD00* m, int a);
extern "C" void func_0018CAF0(Model_0025CD00* c);
extern "C" void func_00183E90(void* obj, int id);
extern "C" void* func_0025CB80(Builder_0025CD00* self, int id);
extern "C" Ent_0025CD00* func_0025CB38(Builder_0025CD00* self, int id);
extern "C" void* func_0019EBD0(void* p);
extern "C" void func_0025CC88(void* obj, void* a);
extern "C" int func_0013D648(Mesh_0025CD00* m);
extern "C" void func_0013D720(Mesh_0025CD00* m, int flags);
extern "C" void func_0011FE10(char* prof, int a);
extern "C" void* func_0011FE68(char* prof, unsigned int name);
extern "C" bool func_001E88D8(void* s, unsigned int name, int* out, int req);
extern "C" void func_0013E278(Mesh_0025CD00* m, void* params, float h, float s, float v);
extern "C" int func_00144D90(void* list);
extern "C" int func_00144DD0(void* list, int i);

static inline Obj_0025CD00* Owner_0025CD00(void* obj)
{
    return func_00184D70(func_0018DF68(func_00185578(obj, 0x286A8D26)));
}

static inline void* Item_0025CD00(void* obj)
{
    return func_0019EBD0(func_00185578(Owner_0025CD00(obj), 0x222756D5));
}

/* Creates the pieces described by a packed list (id, type, index, colour, link, flags each),
   then links each piece to the one with the previous id and copies tint and colours across. */
bool Builder_0025CD00::Build(int* data)
{
    int* p = data;
    p++;
    int n = *p++;
    for (int k = 0; k < n; k++) {
        int id = *p++;
        unsigned int type = *p;
        int index = *p++ + func_001F0D78(D_00390C00);
        int colour = *p++;
        int link = *p++;
        int flags = *p++;
        int special = 0;

        void* params = func_001E6978(func_001190D0(8));
        if (type == 0x5B8AB877 || type == 0x67E6859A)
            special = 1;
        unsigned int top;
        if (special) {
            func_001E7360(params, 0x153A84DE, 0);
            top = (unsigned int)flags >> 31;
        } else {
            if (!func_0010F7C0(m4, type, 0xFD8697E1)) {
                colour = 0;
                link = 0;
            }
            top = (unsigned int)flags >> 31;
            if (((flags >> 30) & 1) && top) {
                char* prof = func_0022E3C8(D_0038FC78, 0);
                void* v = func_001200E0(prof + 4);
                if (v && func_00123420(v))
                    index++;
                int on = 0;
                func_001E7DE8(prof + 0x5C, 0x3F813177, &on, 1);
                if (!on)
                    index += 2;
                func_001E7200(params, 0x92B43E79, on);
            }
            func_001E7360(params, 0x86BD5B8F, index);
        }
        if (((flags >> 30) & 1) && top) {
            char* prof = func_0022E3C8(D_0038FC78, 0) + 4;
            void* s = func_0011FE18(prof, 0x650FAB6D);
            if (!s)
                s = func_0011FE18(prof, 0x0FC85BAE);
            if ((s && func_001E8708(s, 0xC4C5B2CC)) ||
                ((s = func_0011FE18(prof, 0x6DF453B6)) && func_001E8708(s, 0xC4C5B2CC))) {

                func_001F0210(0xF37D9F53, 0, 0, 0, 0);
                if (params)
                    func_001E6AE8(params, 3);
                continue;
            }
        }
        if (colour) {
            func_001E7360(params, 0x09794932, colour);
            func_001E7200(params, 0xD3982061, 0);
        }
        Ent_0025CD00* e = &m54[m_count];
        e->m_obj = func_0025CBC8(params);
        Model_0025CD00* c = func_00185578(e->m_obj, 0x286A8D26);
        if (c) {
            Mesh_0025CD00* cm = c->m260;
            func_0013F010(cm, Vec_0025CD00(0.0f, 0.0f, 0.0f, 50000.0f));
            if (c->m288) {
                Obj_0025CD00* owner = func_00184D70(func_0018DF68(c));
                Model_0025CD00* oc = func_00185578(owner, 0x286A8D26);
                Mesh_0025CD00* mesh = oc->m260;
                if (!m50) {
                    m20 = func_0013EF90(mesh);
                    m30 = (int)(mesh->m1B0 >> 2) & 1;
                    m34 = (int)(mesh->m1B0 >> 3) & 1;
                    m40 = owner->m50;
                    m50 = 1;
                }
                func_0013F010(mesh, Vec_0025CD00(0.0f, 0.0f, 0.0f, 50000.0f));

                func_0013D910(mesh, 0);
                func_0013EE48(mesh, 0);
                func_0018CAF0(oc);
            }
            c->Show(1);
        }
        e->m_id = id;
        func_00183E90(e->m_obj, id);
        e->m_8 = colour;
        e->m_special = special;
        e->m_flags = flags;
        e->m_index = -1;
        e->m_10 = 0;
        e->m_prevObj = 0;
        if (link)
            e->m_10 = func_0025CB80(this, link);
        m_count++;
        if (params)
            func_001E6AE8(params, 3);
    }

    for (int i = 0; i < m_count; i++) {
        Ent_0025CD00* e = &m54[i];
        if (e->m_special)
            func_0025CC88(e->m_obj, Item_0025CD00(e->m_obj));
        Ent_0025CD00* prev = func_0025CB38(this, e->m_id - 1);
        if (prev && prev->m_special)
            func_0025CC88(e->m_obj, Item_0025CD00(prev->m_obj));
    }

    for (int i = 0; i < m_count; i++) {
        Ent_0025CD00* e = &m54[i];
        Model_0025CD00* c = func_00185578(e->m_obj, 0x286A8D26);
        if (c) {
            Mesh_0025CD00* mesh = c->m260;
            int f = func_0013D648(mesh);
            Ent_0025CD00* prev = func_0025CB38(this, e->m_id - 1);
            if (prev && prev->m_special)
                f |= func_0013D648(func_00185578(Owner_0025CD00(prev->m_obj), 0x286A8D26)->m260);
            func_0013D720(mesh, f);
        }
    }

    for (int i = 0; i < m_count; i++) {
        Ent_0025CD00* e = &m54[i];
        Ent_0025CD00* prev = func_0025CB38(this, e->m_id - 1);
        if (prev) {
            e->m_prevObj = prev->m_obj;
            if (prev->m_special) {
                Model_0025CD00* c = func_00185578(e->m_obj, 0x286A8D26);
                char* prof = func_0022E3C8(D_0038FC78, 0) + 4;
                c->RunScript(prof, 0, 0, 0x8FB01036);
                func_0011FE10(prof, 0);
                void* s = func_0011FE68(prof, 0x650FAB6D);
                if (!s)
                    s = func_0011FE68(prof, 0x0FC85BAE);
                if (s) {
                    Mesh_0025CD00* mesh = c->m260;
                    int skip = 1;
                    func_001E7DE8(s, 0x97DBDDE6, &skip, 0);
                    int h, sat, val;
                    if (!skip && func_001E88D8(s, 0x6E94F918, &h, 0) && func_001E88D8(s, 0xE4F130F4, &sat, 0) &&
                        func_001E88D8(s, 0x949BC47B, &val, 0)) {
                        void* params = func_001E6978(func_001190D0(8));
                        func_001E7360(params, 0xB6F08F39, 0);
                        func_001E7360(params, 0x83418A6A, 0xAA2206EF);
                        func_001E7200(params, 0x318F2BDB, 0);
                        func_0013E278(mesh, params, (float)h, (float)sat * 0.01f, (float)val * 0.01f);
                        if (params)
                            func_001E6AE8(params, 3);
                    }
                }
            }
        }
        for (int j = 0; j < func_00144D90(m10); j++) {
            if (e->m_id == func_00144DD0(m10, j)) {
                e->m_index = j;
                break;
            }
        }
    }
    return true;
}
