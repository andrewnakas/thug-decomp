/* sym: Fn__12Obj_0025AE60ffi = 0x0025AE30 */
typedef int qword_0025AE60 __attribute__((mode(TI)));

extern int D_00388A70;
extern char D_003755E8[];
extern char D_00375600[];
extern "C" void* func_0010A638(int heap, unsigned int size, int a, int b);
extern "C" void func_0010A8D8(int heap, void* p);

struct Row_0025AE60 {
    union {
        qword_0025AE60 q;
        float c[4];
    };
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
};

struct Vec_0025AE60 : Row_0025AE60 {
    Vec_0025AE60() {}
    Vec_0025AE60(float x, float y, float z, float w)
    {
        c[0] = x;
        c[1] = y;
        c[2] = z;
        c[3] = w;
    }
    static void* operator new[](unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
    static void operator delete[](void* p) { func_0010A8D8(D_00388A70, p); }
};

struct Quat_0025AE60 : Row_0025AE60 {
    Quat_0025AE60()
    {
        c[0] = 0.0f;
        c[1] = 0.0f;
        c[2] = 0.0f;
        c[3] = 1.0f;
    }
    static void* operator new[](unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
    static void operator delete[](void* p) { func_0010A8D8(D_00388A70, p); }
};

struct Mat_0025AE60 {
    Row_0025AE60 r[4];
    Row_0025AE60& operator[](int i) { return r[i]; }
    const Row_0025AE60& operator[](int i) const { return r[i]; }
    Mat_0025AE60() {}
    Mat_0025AE60& operator=(const Mat_0025AE60& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
        return *this;
    }
    void FromQuat(const Row_0025AE60& q, const Row_0025AE60& t)
    {
        Row_0025AE60 s, c, w;
        s[0] = q[0] * q[0];
        s[1] = q[1] * q[1];
        s[2] = q[2] * q[2];
        c[0] = q[1] * q[2];
        c[1] = q[2] * q[0];
        c[2] = q[0] * q[1];
        w[0] = q[3] * q[0];
        w[1] = q[3] * q[1];
        w[2] = q[3] * q[2];
        r[0][0] = 1.0f - (s[1] + s[2]) * 2.0f;
        r[0][1] = (c[2] + w[2]) * 2.0f;
        r[0][2] = (c[1] - w[1]) * 2.0f;
        r[0][3] = 0.0f;
        r[1][0] = (c[2] - w[2]) * 2.0f;
        r[1][1] = 1.0f - (s[0] + s[2]) * 2.0f;
        r[1][2] = (c[0] + w[0]) * 2.0f;
        r[1][3] = 0.0f;
        r[2][0] = (c[1] + w[1]) * 2.0f;
        r[2][1] = (c[0] - w[0]) * 2.0f;
        r[2][2] = 1.0f - (s[0] + s[1]) * 2.0f;
        r[2][3] = 0.0f;
        r[3] = t;
        r[3][3] = 1.0f;
    }
};

struct Comp_0025AE60 {
    char pad0[0x18];
    virtual void Fn08();
    virtual void Refresh();
};

struct Target_0025AE60 {
    char pad0[0x50];
    Row_0025AE60 m50;
    char pad60[0x10];
    Mat_0025AE60 m70;
    char padB0[0x10];
    Mat_0025AE60 mC0;
};

struct Skel_0025AE60 {
    char pad0[8];
    int m_numBones;
    int Count() { return m_numBones; }
};

extern "C" float func_00119768(void* p);
extern "C" void func_001197F0(void* p);
extern "C" int func_00116170(Skel_0025AE60* s, Quat_0025AE60* q, Vec_0025AE60* t, int c, float f);
extern "C" unsigned int func_001180B0(Skel_0025AE60* s, int i);
extern "C" Target_0025AE60* func_00184D70(unsigned int id);
extern "C" bool func_001E5628(unsigned int name, int a);
extern "C" char* func_001E61F0(unsigned int name);
extern "C" double func_0033ECA8(float x);
extern "C" int func_00103F28(char* fmt, ...);
extern "C" void func_00101EA8(Row_0025AE60* v);
extern "C" void func_00100588(Mat_0025AE60* m);
extern "C" Comp_0025AE60* func_00185578(Target_0025AE60* obj, unsigned int name);

struct Obj_0025AE60 {
    char pad0[0x3C];
    Skel_0025AE60* m3C;
    char m40[4];
    bool Fn(float a, float b, int k);
    int NumBones() { return m3C->m_numBones; }
    void Apply();
};

void Obj_0025AE60::Apply()
{
    float a = func_00119768(m40);
    func_001197F0(m40);
    Fn(a, func_00119768(m40), 0);
    Quat_0025AE60* quats = new Quat_0025AE60[m3C->m_numBones];
    Vec_0025AE60* trans = new Vec_0025AE60[m3C->m_numBones];
    func_00116170(m3C, quats, trans, 0, func_00119768(m40));
    for (int i = 0; i < NumBones(); i++) {
        unsigned int id = func_001180B0(m3C, i);
        Target_0025AE60* obj = func_00184D70(id);
        if (obj) {
            Row_0025AE60* pos = &obj->m50;
            Mat_0025AE60 m;
            Vec_0025AE60 one(0.0f, 0.0f, 0.0f, 1.0f);
            quats[i][0] = -quats[i][0];
            quats[i][1] = -quats[i][1];
            quats[i][2] = -quats[i][2];
            m.FromQuat(quats[i], one);
            obj->m70 = m;
            obj->mC0 = m;
            *pos = trans[i];
            if (func_001E5628(0x2F510F45, 1)) {
                func_00103F28(D_003755E8, func_001E61F0(id), func_0033ECA8(func_00119768(m40)));
                func_00101EA8(pos);
                func_00100588(&obj->m70);
            }
            Comp_0025AE60* c = func_00185578(obj, 0x286A8D26);
            if (c)
                c->Refresh();
        } else {
            func_00103F28(D_00375600, func_001E61F0(id));
        }
    }
    delete[] quats;
    delete[] trans;
}
