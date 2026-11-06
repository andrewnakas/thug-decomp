/* fuzzy: 94.6 */
typedef int qword __attribute__((mode(TI)));
extern "C" float sqrtf(float);

struct Vec_00205F70 {
    union {
        qword q;
        float c[4];
    };
    Vec_00205F70& operator-=(const Vec_00205F70& o)
    {
        c[0] -= o.c[0];
        c[1] -= o.c[1];
        c[2] -= o.c[2];
        c[3] -= o.c[3];
        return *this;
    }
    Vec_00205F70() {}
    Vec_00205F70(float x, float y, float z, float w)
    {
        c[0] = x;
        c[1] = y;
        c[2] = z;
        c[3] = w;
    }
    Vec_00205F70 operator-() const { return Vec_00205F70(-c[0], -c[1], -c[2], -c[3]); }
    Vec_00205F70 operator*(float s) const { return Vec_00205F70(c[0] * s, c[1] * s, c[2] * s, c[3] * s); }
    float Length() const { return sqrtf(c[0] * c[0] + c[1] * c[1] + c[2] * c[2]); }
    void Normalize(float n)
    {
        float l = Length();
        if (l > 0.0f) {
            float k = n / l;
            c[0] *= k;
            c[1] *= k;
            c[2] *= k;
        }
    }
};

struct Mat_00205F70 {
    Vec_00205F70 r[4];
    const Vec_00205F70& operator[](int i) const { return r[i]; }
    void Identity()
    {
        r[0].c[0] = 1.0f;
        r[0].c[1] = 0.0f;
        r[0].c[2] = 0.0f;
        r[0].c[3] = 0.0f;
        r[1].c[0] = 0.0f;
        r[1].c[1] = 1.0f;
        r[1].c[2] = 0.0f;
        r[1].c[3] = 0.0f;
        r[2].c[0] = 0.0f;
        r[2].c[1] = 0.0f;
        r[2].c[2] = 1.0f;
        r[2].c[3] = 0.0f;
        r[3].c[0] = 0.0f;
        r[3].c[1] = 0.0f;
        r[3].c[2] = 0.0f;
        r[3].c[3] = 1.0f;
    }
    Mat_00205F70& operator=(const Mat_00205F70& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
        return *this;
    }
};

struct Body_00205F70 {
    char pad0[0x70];
    Mat_00205F70 m70;
    char padB0[0x164 - 0xB0];
    int m164;
};

struct State_00205F70 {
    char pad0[0x34];
    bool m34;
};

struct Phys_00205F70 {
    char pad0[0xC];
    Body_00205F70* mC;
    char pad10[0x20 - 0x10];
    Mat_00205F70 m20;
    Vec_00205F70 m60;
    Vec_00205F70 m70;
    Vec_00205F70 m80;
    char pad90[0xA0 - 0x90];
    Vec_00205F70 mA0;
    char padB0[0x5B0 - 0xB0];
    State_00205F70* m5B0;
};

struct Ctrl_00205F70 {
    char pad0[0x20];
    int m20;
    char pad24[0x180 - 0x24];
    int m180;
};

struct Input_00205F70 {
    char pad0[0x34];
    Ctrl_00205F70* m34;
};

struct Script_00205F70 {
    char pad0[0x18];
    void* m18;
    char pad1C[0xB8 - 0x1C];
    void* mB8;
};

struct Net_00205F70 {
    char pad0[0xAC];
    unsigned int mAC;
};

extern Net_00205F70* D_00392808;
extern void* D_0038FC78;
extern char D_00366E78[];

extern "C" int func_001E8618(void* params, unsigned int name);
extern "C" bool func_001E8398(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E7C80(void* params, unsigned int name, int* out, int required);
extern "C" int func_00105520(int s);
extern "C" int func_00229CC8(int id, Vec_00205F70* pos);
extern "C" int func_00229668(int id, int a);
extern "C" int func_00229EB0(void* list);
extern "C" int func_00229F48(void* list, int i);
extern "C" bool func_002584E0(int obj);
extern "C" void func_0022CF08(void* game, void* obj, int a, int b);
extern "C" void func_001F0210(unsigned int name, void* params, void* obj, int a, int b);
extern "C" bool func_001E87B8(void* params, char* name);
extern "C" int func_001E8870(void* params, unsigned int name, void* out, int required);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" void func_00186398(void* obj, int a);
extern "C" void func_001B6BC0(void* p, Vec_00205F70* v);
extern "C" void func_001B6BD0(void* p, Vec_00205F70* v);
extern "C" bool func_001E88D8(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E89F0(void* params, unsigned int name, int* out, int required);
extern "C" void func_001E72B0(void* s, unsigned int name, float v);
extern "C" void func_001E7200(void* s, unsigned int name, int v);
extern "C" void* func_00203EC0(void* obj);
extern "C" Vec_00205F70* func_00114E18(void* p);
extern "C" Mat_00205F70* func_00114E48(void* p);
extern "C" void func_00203EA0(void* obj, int a);

class Obj_00205F70 {
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
    virtual void V11();
    virtual void V12();
    virtual void V13(int a, int b);
};

class Skater_00205F70 : public Obj_00205F70 {
public:
    char padC[0x50 - 0xC];
    Vec_00205F70 m50;
    Vec_00205F70 m60;
    Mat_00205F70 m70;
    Vec_00205F70 mB0;
    char padC0[0x160 - 0xC0];
    unsigned int m160;
    char pad164[0x238 - 0x164];
    int m238;
    int m23C;
    char pad240[0x2B8 - 0x240];
    void* m2B8;
    char pad2BC[0x2E0 - 0x2BC];
    Phys_00205F70* m2E0;
    Input_00205F70* m2E4;
    char pad2E8[0x31C - 0x2E8];
    int m31C;
    int m320;
    char pad324[0x330 - 0x324];
    Vec_00205F70 m330;
    Mat_00205F70 m340;
    bool m380;
    bool m384;

    bool CallMemberFunction(unsigned int name, void* params, Script_00205F70* script);
    float Func_00203868(float v);
    float Func_00203B20(int v);
    void SyncPhys(Vec_00205F70* pos, Vec_00205F70* up)
    {
        Phys_00205F70* p = m2E0;
        p->m20 = p->mC->m70;
        qword v;
        m2E0->m70.q = v = m70.r[1].q;
        m2E0->m80.q = v;
        m2E0->m60.q = v;
        func_001B6BC0(m2B8, pos);
        func_001B6BD0(m2B8, up);
    }
};

extern "C" bool func_00258098(Skater_00205F70* self, unsigned int name, void* params, Script_00205F70* script);
extern "C" float func_00203868(Skater_00205F70* self, int v);
extern "C" float func_00203B20(Skater_00205F70* self, int v);

bool Skater_00205F70::CallMemberFunction(unsigned int name, void* params, Script_00205F70* script)
{
    switch (name) {
    case 0x1B572ABF: {
        int flags = func_001E8618(params, 0xD6F06BF6);
        int id;
        int str;
        str = 0;
        id = 0;
        if (!func_001E8398(params, 0x6C4E7971, &id, 0)) {
            if (func_001E7C80(params, 0x6C4E7971, &str, 0)) id = func_00105520(str);
        }
        if (id) {
            int target = func_00229CC8(id, &m50);
            V13(target, flags);
        } else {
            int node = 0;
            if (!func_001E8398(params, 0x7A8017BA, &node, 0)) goto search;
            int target = func_00229668(node, 1);
            V13(target, flags);
        }
        break;
    search:
        {
            void* list = script->mB8;
            int i;
            int n = func_00229EB0(list);
            for (i = 0; i < n; i++) {
                int o = func_00229F48(list, i);
                if (func_002584E0(o)) {
                    V13(o, flags);
                    break;
                }
            }
            if (i == n) {
                if (D_00392808->mAC != 0xD443A2BC) func_0022CF08(D_0038FC78, this, -1, flags);
            }
        }
        break;
    }
    case 0xE62F94A2:
        func_001F0210(0xAF4475DE, params, this, 0, 0);
        m238 = 1;
        m23C = 1;
        if (func_001E87B8(params, D_00366E78)) m238 = 0;
        break;
    case 0x5436A335:
        func_001F0210(0x0DCCF5C3, params, this, 0, 0);
        m238 = 1;
        m23C = 0;
        break;
    case 0xC67C18D7: {
        int v;
        if (!func_001E8870(params, 0xCAB94088, &v, 0)) return false;
        break;
    }
    case 0x3E8EB713:
        if (!m31C) return false;
        switch (m160) {
        case 0x16C6DF0B:
            return true;
        case 0x0CDBA4F9:
            return m2E0->mC->m164 ? m2E0->m5B0->m34 : !m2E0->m5B0->m34;
        }
        return false;
    case 0x42832375:
        if (func_001E8708(params, 0x19EBDA23)) {
            m330 = m50;
            m384 = true;
            m340 = m70;
            Ctrl_00205F70* c = m2E4->m34;
            m380 = c->m180 == 0 && c->m20 == 1;
        } else {
            if (func_001E8708(params, 0x1A4E0EF9)) {
                m384 = false;
                break;
            }
            return m384;
        }
    case 0x5A3C19E9: {
        Vec_00205F70* pos = &m50;
        Vec_00205F70* up = &m70.r[1];
        V13(-1, m380);
        m50 = m330;
        m70 = m340;
        m2E0->mA0 = m50;
        m60 = m50;
        func_00186398(this, 1);
        SyncPhys(pos, up);
        break;
    }
    case 0x7915AA31: {
        int v;
        func_001E88D8(params, 0xDF4700DE, &v, 1);
        void* s = script->m18;
        func_001E72B0(s, 0x8EAF7ADD, func_00203868(this, v));
        break;
    }
    case 0x9ABE8A21: {
        int v = 0;
        func_001E89F0(params, 0, &v, 1);
        void* s = script->m18;
        func_001E72B0(s, 0x8EAF7ADD, func_00203B20(this, v));
        break;
    }
    case 0xF4C52F72:
        func_001E7200(script->m18, 0xF3CF5755, m320);
        break;
    case 0xC6870028:
        break;
    case 0xD38E8B6C: {
        if (!func_00203EC0(this)) break;
        Vec_00205F70* up = &m70.r[1];
        Vec_00205F70* p = func_00114E18(func_00203EC0(this));
        Mat_00205F70* mat = func_00114E48(func_00203EC0(this));
        m70.Identity();
        m50 = *p;
        m50 -= Vec_00205F70(mat->r[2].c[0] * 144.0f, mat->r[2].c[1] * 144.0f, mat->r[2].c[2] * 144.0f, mat->r[2].c[3] * 144.0f);
        m60 = m50;
        m2E0->mA0 = m50;
        m70 = *mat;
        m70.r[2] = Vec_00205F70(-m70.r[2].c[0], -m70.r[2].c[1], -m70.r[2].c[2], -m70.r[2].c[3]);
        m70.r[0] = Vec_00205F70(-m70.r[0].c[0], -m70.r[0].c[1], -m70.r[0].c[2], -m70.r[0].c[3]);
        SyncPhys(&m50, up);
        mB0 = Vec_00205F70(-mat->r[2].c[0], -mat->r[2].c[1], -mat->r[2].c[2], -mat->r[2].c[3]);
        mB0.c[1] = 0.0f;
        mB0.Normalize(10.0f);
        func_00203EA0(this, 1);
        break;
    }
    default:
        return func_00258098(this, name, params, script);
    }
    return true;
}
