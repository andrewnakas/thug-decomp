typedef int qword_00129760 __attribute__((mode(TI)));

struct Vec_00129760 {
    union {
        struct { float x, y, z, w; };
        qword_00129760 q;
    };
    Vec_00129760() {}
    Vec_00129760(const Vec_00129760& o) { q = o.q; }
    void Set(float ax, float ay, float az, float aw = 1.0f)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    Vec_00129760(float ax, float ay, float az, float aw = 1.0f)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

struct Array_00129760 {
    int m0;
    int m4;
    int m8;
    unsigned int m_size;
    unsigned int GetSize() const { return m_size; }
};

struct Comp_00129760 {
    char pad0[0x260];
    void* m260;
};

class Obj_00129760 {
public:
    char pad0[0x4C4];
    float m4C4;
    float m4C8;
    float m4CC;
    float m4D0;
    float m4D4;
    float m4D8;
    float m4DC;
    char pad4E0[0x520 - 0x4E0];
    Vec_00129760 m520;
    int m530;
    int m534;
    unsigned int m538;
    float m53C;
    int m540;
    char pad544[0x550 - 0x544];
    Vec_00129760 m550;
    Vec_00129760 m560;
    char pad570[0x584 - 0x570];
    int m584;
    float m588;
    float m58C;
    int m590;
    unsigned int m594;
    int m598;
    unsigned int m59C;
    float m5A0;
    void Init(void* params);
};

extern int D_0038C608;
extern char D_00389898[];
extern char D_0035CE60[];

extern "C" void func_00124328(Obj_00129760* self, void* params);
extern "C" bool func_001E8A30(void* params, unsigned int name, int* out, int required);
extern "C" int func_001E88D8(void* params, unsigned int name, int* out, int req);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" int func_001E8248(void* params, unsigned int name, Array_00129760** out, int req);
extern "C" bool func_001E7C80(void* params, unsigned int name, const char** out, int required);
extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" bool func_001E8180(void* params, unsigned int name, void** out, int required);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E8038(void* params, char* name, Vec_00129760* out, int req);
extern "C" bool func_001E7FA8(void* params, unsigned int name, Vec_00129760* out, int req);
extern "C" void* func_001E9300(Array_00129760* a, int i);
extern "C" void* func_001E9378(Array_00129760* a, int i);
extern "C" void func_00129118(Obj_00129760* self);
extern "C" void* func_00129220(Obj_00129760* self, int a, Vec_00129760 v);
extern "C" void* func_001292D8(Obj_00129760* self, const char* text, int a, Vec_00129760 v, int t);
extern "C" void* func_00129420(Obj_00129760* self, unsigned int key, Vec_00129760 v);
extern "C" void func_00129508(Obj_00129760* self);
extern "C" void* func_0012ABA0(Obj_00129760* self);
extern "C" void* func_00187B48(int mgr, unsigned int id);
extern "C" Comp_00129760* func_00185578(void* obj, unsigned int name);
extern "C" void* func_0013DA40(void* id, void* a);
extern "C" void* func_0013C380(void* a, int b, void* c);
extern "C" void func_0013C568(void* r, int a);
extern "C" void func_0013D518(void* x, void* r, void* a);
extern "C" void* func_00229668(unsigned int name, int a);
extern "C" void* func_00229DF0(void* node);
extern "C" void func_00229FF8(void* params, Vec_00129760* out);

void Obj_00129760::Init(void* params)
{
    int added = 0;
    func_00124328(this, params);
    int a = 0;
    func_001E8A30(params, 0x09794932, &a, 0);
    const char* text = D_00389898;
    Array_00129760* texts = 0;
    Array_00129760* refs = 0;
    int t = 0;
    func_001E88D8(params, 0xF891AC27, &t, 0);
    unsigned int id;
    if (func_001E8398(params, 0x073EC4C8, &id, 0)) {
        func_00129118(this);
        Vec_00129760 pos(0.0f, 0.0f, 0.0f);
        Comp_00129760* comp = func_00185578(func_00187B48(D_0038C608, id), 0x286A8D26);
        Array_00129760* parts = 0;
        if (func_001E8248(params, 0x3CC0910B, &parts, 0)) {
            void* x = func_00129220(this, a, pos);
            for (unsigned int i = 0; i < parts->GetSize(); i++) {
                void* e = func_001E9300(parts, i);
                if (e) {
                    void* r = func_0013C380(func_0013DA40(comp->m260, e), 1, x);
                    func_0013C568(r, 1);
                    func_0013D518(x, r, e);
                }
            }
        }
        func_0012ABA0(this);
        added = 1;
    } else if (func_001E7C80(params, 0x286A8D26, &text, 0)) {
        func_00129118(this);
        Vec_00129760 pos(0.0f, 0.0f, 0.0f);
        func_001292D8(this, text, a, pos, t);
    } else if (func_001E8248(params, 0x1B29CFF6, &texts, 0)) {
        func_00129118(this);
        for (unsigned int i = 0; i < texts->GetSize(); i++) {
            void* e = func_001E9378(texts, i);
            func_001E7C80(e, 0, &text, 0);
            Vec_00129760 pos(0.0f, 0.0f, 0.0f);
            func_001E7FA8(e, 0, &pos, 0);
            func_001292D8(this, text, a, pos, t);
        }
    }
    unsigned int key;
    if (func_001E8398(params, 0xB45C2617, &key, 0)) {
        func_00129118(this);
        Vec_00129760 pos(0.0f, 0.0f, 0.0f);
        func_00129420(this, key, pos);
    } else if (func_001E8248(params, 0x4A6BF967, &refs, 0)) {
        func_00129118(this);
        for (unsigned int i = 0; i < refs->GetSize(); i++) {
            void* e = func_001E9378(refs, i);
            func_001E8398(e, 0, &key, 0);
            Vec_00129760 pos(0.0f, 0.0f, 0.0f);
            func_001E7FA8(e, 0, &pos, 0);
            func_00129420(this, key, pos);
        }
    } else if (a && !added) {
        Vec_00129760 pos(0.0f, 0.0f, 0.0f);
        func_001292D8(this, 0, a, pos, 0);
    }
    func_001E7EB0(params, 0xED7C6031, &m4C4, 0);
    func_001E7EB0(params, 0x0AFFD09D, &m4C8, 0);
    func_001E7EB0(params, 0x7DF8E00B, &m4CC, 0);
    func_001E7EB0(params, 0xE4F1B1B1, &m4D0, 0);
    func_001E7EB0(params, 0xC1608989, &m4D4, 0);
    func_001E7EB0(params, 0xB667B91F, &m4D8, 0);
    func_001E7EB0(params, 0x2F6EE8A5, &m4DC, 0);
    if (func_001E8708(params, 0x233F6B18))
        m534 = 0;
    if (func_001E8708(params, 0x911B6961))
        m534 = 1;
    if (func_001E8708(params, 0x3BE6306E))
        m534 = 2;
    if (func_001E8708(params, 0xE7DE33C0))
        m534 = 3;
    if (func_001E8708(params, 0xA0A9DF8D))
        m534 = 4;
    if (func_001E8708(params, 0xCEB5DE5A))
        m534 = 5;
    if (func_001E8708(params, 0xF01FDCA4))
        m530 = 0;
    unsigned int node = 0;
    if (func_001E8398(params, 0xB2A86EB5, &node, 0)) {
        func_00229FF8(func_00229DF0(func_00229668(node, 1)), &m520);
        m530 = 1;
    }
    m538 = 0;
    if (func_001E8398(params, 0xDAD39B88, &m538, 0))
        m530 = 2;
    m5A0 = 0.0f;
    func_001E7EB0(params, 0xE3C07609, &m5A0, 0);
    m53C = 0.0f;
    m540 = 0;
    void* fade = 0;
    if (func_001E8180(params, 0x00CA1C41, &fade, 0)) {
        func_001E7EB0(fade, 0xC9FDE32C, &m53C, 0);
        float rate = 1.0f;
        func_001E7EB0(fade, 0xA80BEA4A, &rate, 0);
        m540 = (int)(1000.0f / rate);
    }
    m598 = 0;
    m594 = 0;
    m59C = 0;
    m560.Set(0.0f, 0.0f, 0.0f);
    void* spin = 0;
    if (func_001E8180(params, 0x36388933, &spin, 0)) {
        func_001E8398(spin, 0xA1DC81F9, &m594, 0);
        func_001E7FA8(spin, 0, &m560, 0);
        if (func_001E7DE8(spin, 0x5B8AB877, &m598, 0))
            m594 = 0x5B8AB877;
        func_001E8398(spin, 0x7A8017BA, &m59C, 0);
    }
    if (func_001E8708(params, 0x1B399065)) {
        func_00129508(this);
    } else if (func_001E8038(params, D_0035CE60, &m550, 0)) {
        m550.w = 1.0f;
    }
    m584 = func_001E8708(params, 0x4564C8F2);
    m588 = 0.002f;
    func_001E7EB0(params, 0x571F3F3A, &m588, 0);
    m58C = 3.0f;
    func_001E7EB0(params, 0x31E78F98, &m58C, 0);
    int v;
    if (func_001E7DE8(params, 0x655EE08E, &v, 0)) {
        m590 = v;
        func_0012ABA0(this);
    }
}
