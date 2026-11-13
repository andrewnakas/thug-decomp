/* fuzzy: 96.8 */
typedef int qword __attribute__((mode(TI)));

union Vec_0029B8C0 {
    qword q;
    struct {
        float x, y, z, w;
    } f;
    void Set(float x, float y, float z, float w) { f.x = x; f.y = y; f.z = z; f.w = w; }
};

struct Game_0029B8C0 {
    char pad[0xB4];
    float mB4;
};

extern "C" Game_0029B8C0* func_002C4970(int v);
extern "C" void func_002C49C0();

struct Ref_0029B8C0 {
    int m0;
    Game_0029B8C0* m4;
    Ref_0029B8C0(Game_0029B8C0* p) { m4 = p; }
};

class Ctx_0029B8C0 {
public:
    int m0;
    Ref_0029B8C0 m4;
    Ctx_0029B8C0() : m4(func_002C4970(0)) {}
    Ref_0029B8C0* GetRef() { return &m4; }
    bool Busy() { return GetRef()->m4->mB4 >= 1.0f; }
    virtual void Dummy();
    virtual ~Ctx_0029B8C0() { func_002C49C0(); }
};
/* sym: _vt$12Ctx_0029B8C0 = 0x00367170 */

struct Node_0029B8C0 {
    char pad[0x10];
    Vec_0029B8C0 pos;
    unsigned int m20;
    char pad24[4];
    float m28;
};

struct Grp_0029B8C0 {
    char pad[0xC];
    Node_0029B8C0* mC;
    unsigned int id;
};

struct Cam_0029B8C0 {
    char pad[0x7C];
    float m7C;
};

struct Script_0029B8C0 {
    char pad[0x18];
    void* params;
};

struct Obj_0029B8C0;

extern "C" void func_001E7FA8(void* params, unsigned int name, Vec_0029B8C0* out, int required);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" void func_001E7410(void* params, unsigned int name, float x, float y, float z);
extern "C" void func_001E72B0(void* params, unsigned int name, float v);
extern "C" void func_001E7360(void* params, unsigned int name, unsigned int value);
extern "C" int func_001E7200(void* params, unsigned int name, int value);
extern "C" void* func_001190D0(int n);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AE8(void* o, int n);
extern "C" void func_001F0210(unsigned int id, void* s, int a, int b, int c);
extern "C" bool func_002CADB8(Vec_0029B8C0* p, float margin);
extern "C" bool func_00298378(Vec_0029B8C0* a, Vec_0029B8C0* b);
extern "C" Node_0029B8C0* func_00299830(Grp_0029B8C0* g);
extern "C" float func_00298CC8(Node_0029B8C0* n);
extern "C" void func_00298508(Node_0029B8C0* n, Vec_0029B8C0* a, Vec_0029B8C0* b, float f);
extern "C" void func_002987C8(Node_0029B8C0* n, Vec_0029B8C0* a, Vec_0029B8C0* b, float f);
extern "C" void func_0029B108(Obj_0029B8C0* o, Vec_0029B8C0* v, float* a, float* b);
extern "C" int func_0029C020(Obj_0029B8C0* o);
extern "C" void func_0029B378(Obj_0029B8C0* o);
extern "C" void func_0029B290(Obj_0029B8C0* o);
extern "C" void func_0029B748(Obj_0029B8C0* o, Vec_0029B8C0* v);
extern "C" void func_0029B6E0(Obj_0029B8C0* o);
extern "C" Grp_0029B8C0* func_0029B3D0(Obj_0029B8C0* o, unsigned int id);
extern "C" bool func_00299C78(Grp_0029B8C0* g, int n, Vec_0029B8C0* v, bool flag);
extern "C" Node_0029B8C0* func_00299B80(Grp_0029B8C0* g, int n);
extern "C" int func_00298E80(Node_0029B8C0* n, bool a, bool b);
extern "C" void func_0029A770(Obj_0029B8C0* o, Grp_0029B8C0* g, Node_0029B8C0* n);
extern "C" void func_0029B400(Obj_0029B8C0* o);
extern "C" void func_0029A730(Obj_0029B8C0* o);
extern "C" int func_00299898(Grp_0029B8C0* g);
extern "C" int func_0029B2F8(Obj_0029B8C0* o, Grp_0029B8C0* g);
extern "C" void func_0029A678(Obj_0029B8C0* o);
extern "C" void func_0029A6B8(Obj_0029B8C0* o);
extern Vec_0029B8C0 D_00453140;
extern int D_00391ED8;

static inline bool InBounds_0029B8C0(Vec_0029B8C0 v) { return func_002CADB8(&v, 10.0f); }

struct Obj_0029B8C0 {
    char pad[0x20];
    Cam_0029B8C0* m20;
    char pad24[4];
    Grp_0029B8C0* m28;
    unsigned int m2C;
    int CallMember(unsigned int name, void* params, Script_0029B8C0* script);
};

int Obj_0029B8C0::CallMember(unsigned int name, void* params, Script_0029B8C0* script)
{
    Vec_0029B8C0 v;
    switch (name) {
    case 0x8F3E0B97: {
        v.Set(0.0f, 0.0f, 0.0f, 1.0f);
        float a = 0.0f;
        float b = 0.0f;
        func_0029B108(this, &v, &a, &b);
        v.f.y += a;
        func_001E7410(script->params, 0x7F261953, v.f.x, v.f.y, v.f.z);
        func_001E72B0(script->params, 0xFF7EBAF6, m20->m7C * 57.295776f);
        return 1;
    }
    case 0xD2C98192:
        if (!func_0029C020(this))
            return 0;
        func_0029B378(this);
        return 1;
    case 0x31F66E6B:
        return !func_0029C020(this);
    case 0x5828E852: {
        v.Set(0.0f, 0.0f, 0.0f, 1.0f);
        func_001E7FA8(params, 0x7F261953, &v, 0);
        if (!m28)
            return 0;
        Node_0029B8C0* first = m28->mC;
        if (first && !func_00298378(&first->pos, &v))
            return 1;
        if (!InBounds_0029B8C0(v))
            return first != 0;
        Ctx_0029B8C0 ctx;
        if (ctx.Busy()) {
            return 0;
        } else {
            Node_0029B8C0* n = func_00299830(m28);
            if (!n)
                return 0;
            n->pos = v;
            n->m28 = v.f.y - func_00298CC8(n);
            n->m20 = func_001E8708(params, 0xCB4B4880);
            func_00298508(n, &D_00453140, &D_00453140, 0.0f);
            func_002987C8(n, &D_00453140, &D_00453140, 0.0f);
            return 1;
        }
    }
    case 0x9C0762C4:
        func_0029B290(this);
        return 1;
    case 0x1CC3A173: {
        func_001E8398(params, 0x6835B854, &m2C, 0);
        void* s = func_001E6978(func_001190D0(8));
        func_001E7360(s, 0x6835B854, 0xFFD81C08);
        func_001F0210(0x9DB065AD, s, 0, 0, 0);
        if (s)
            func_001E6AE8(s, 3);
        break;
    }
    case 0x63DD1204:
        func_001E7360(script->params, 0x6835B854, m2C);
        return 1;
    case 0xAA438D71:
        func_001E7FA8(params, 0x7F261953, &v, 0);
        func_0029B748(this, &v);
        return 1;
    case 0x9386DCD9:
        func_0029B6E0(this);
        return 1;
    case 0x6D2EEE1B: {
        unsigned int id = 0;
        func_001E8398(params, 0xA61E7CD9, &id, 0);
        int n = 0;
        func_001E7DE8(params, 0x00AB3C14, &n, 0);
        func_001E7FA8(params, 0x7F261953, &v, 0);
        Grp_0029B8C0* g = func_0029B3D0(this, id);
        if (!g)
            break;
        if (!func_00299C78(g, n, &v, func_001E8708(params, 0xDDF9A2BB)))
            return 0;
        break;
    }
    case 0x8798E959: {
        unsigned int id = 0;
        func_001E8398(params, 0xA61E7CD9, &id, 0);
        int n = 0;
        func_001E7DE8(params, 0x00AB3C14, &n, 0);
        Grp_0029B8C0* g = func_0029B3D0(this, id);
        if (!g)
            break;
        Node_0029B8C0* node = func_00299B80(g, n);
        bool a = func_001E8708(params, 0x5031A0FC);
        func_00298E80(node, a, func_001E8708(params, 0x1A52E4B8));
        return 1;
    }
    case 0x6716227C: {
        unsigned int id = 0;
        func_001E8398(params, 0xA61E7CD9, &id, 0);
        Grp_0029B8C0* g = func_0029B3D0(this, id);
        if (!g)
            return 0;
        int n = 0;
        func_001E7DE8(params, 0x00AB3C14, &n, 0);
        Node_0029B8C0* node = func_00299B80(g, n);
        if (!node)
            return 0;
        func_0029A770(this, g, node);
        func_0029B400(this);
        return 1;
    }
    case 0xD5A87EEE:
        func_0029A730(this);
        return 1;
    case 0xFB6A0888: {
        unsigned int id = 0;
        func_001E8398(params, 0xA61E7CD9, &id, 0);
        Grp_0029B8C0* g = func_0029B3D0(this, id);
        if (func_001E8708(params, 0xE234F2B2))
            g = m28;
        if (!g)
            return 0;
        func_001E7360(script->params, 0xA61E7CD9, g->id);
        void* p = script->params;
        func_001E7200(p, 0x6164266E, func_00299898(g));
        return 1;
    }
    case 0x353EA2A9: {
        unsigned int id = 0;
        func_001E8398(params, 0xA61E7CD9, &id, 0);
        Grp_0029B8C0* g = func_0029B3D0(this, id);
        if (!g)
            break;
        func_0029B2F8(this, g);
        return 1;
    }
    case 0xD70781C3:
        D_00391ED8 = 1;
        if (func_001E8708(params, 0x23A11CBC))
            D_00391ED8 = 0;
        func_0029A678(this);
        func_0029A6B8(this);
        D_00391ED8 = 1;
        break;
    default:
        return 2;
    }
    return 1;
}
