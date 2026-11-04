typedef int qword __attribute__((mode(TI)));

struct Vec_0019EBD8 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_0019EBD8() {}
    Vec_0019EBD8(float ax, float ay, float az, float aw = 1.0f) { x = ax; y = ay; z = az; w = aw; }
    Vec_0019EBD8& operator+=(const Vec_0019EBD8& v) { x += v.x; y += v.y; z += v.z; w += v.w; return *this; }
};

inline Vec_0019EBD8 operator*(const Vec_0019EBD8& v, float s)
{
    return Vec_0019EBD8(v.x * s, v.y * s, v.z * s, v.w * s);
}

extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int req);
extern "C" int func_001E7DE8(void* params, unsigned int name, int* out, int req);
extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int req);
extern "C" int func_001E7FA8(void* params, unsigned int name, Vec_0019EBD8* out, int req);
extern "C" int func_001E8248(void* params, unsigned int name, int* out, int req);
extern "C" int func_001E8180(void* params, unsigned int name, void** out, int req);
extern "C" int func_001E8708(void* params, unsigned int name);
extern "C" int func_001E8890(void* params, const char* name, int* out, int req);
extern "C" int func_001E85C0(void* params, const char* name, int* out, int req);
extern "C" void func_001E72B0(void* s, unsigned int name, float v);
extern "C" void func_0011DE18(int a, unsigned int id, int flag);
extern char D_0038CB58[];
extern char D_0038CB60[];

struct Obj_0019EBD8 {
    int m_pad[20];
    Vec_0019EBD8 m50;
    int m60[12];
    Vec_0019EBD8 m90;
};

struct Script_0019EBD8 {
    int m_pad[6];
    void* m18;
};

struct C_0019EBD8 {
    int m_pad[3];
    Obj_0019EBD8* mC;
    int m10[3];
    int m1C;
    int Get(unsigned int id, Vec_0019EBD8* out);
    void Move(Vec_0019EBD8* pos, int f, float t0, float t1, float t2, float t3, int e, int a, int b);
    void Set(unsigned int id, int x, void* y, Vec_0019EBD8* q, Vec_0019EBD8* r, Vec_0019EBD8* p,
             float s);
    int Call(unsigned int name, void* params, Script_0019EBD8* script);
};

int C_0019EBD8::Call(unsigned int name, void* params, Script_0019EBD8* script)
{
    switch (name) {
    case 0x20F7B992: {
        unsigned int id;
        int flag;
        func_001E8398(params, 0xCAB94088, &id, 1);
        func_001E7DE8(params, 0xB4E103FD, &flag, 1);
        func_0011DE18(m1C, id, flag != 0);
        break;
    }
    case 0xBE1C58CA: {
        Vec_0019EBD8 v(0.0f, 0.0f, 0.0f);
        unsigned int id;
        func_001E8398(params, 0xCAB94088, &id, 1);
        int r = Get(id, &v);
        func_001E72B0(script->m18, 0x7323E97C, v.x);
        func_001E72B0(script->m18, 0x0424D9EA, v.y);
        func_001E72B0(script->m18, 0x9D2D8850, v.z);
        return r != 0;
    }
    case 0xB244C9CF:
    case 0xC51CE359: {
        Vec_0019EBD8 pos;
        float t0;
        float t1 = 0.0f;
        float t2 = 5.0f;
        float t3 = 3.0f;
        int e;
        int f;
        float g = 0.0f;
        int a = func_001E8708(params, 0x4D977A70);
        int b = func_001E8708(params, 0x7EE6C892);
        f = 0;
        func_001E7EB0(params, 0x083FDB95, &t0, 0);
        func_001E7EB0(params, 0xC48391A5, &t1, 0);
        func_001E7EB0(params, 0xC218CF77, &t2, 0);
        func_001E7EB0(params, 0x12C62572, &t3, 0);
        func_001E8890(params, D_0038CB58, &e, 0);
        if (!func_001E85C0(params, D_0038CB60, &f, 0)) {
            if (func_001E7EB0(params, 0x186ED079, &g, 0)) {
                Obj_0019EBD8* o = mC;
                pos = o->m50;
                Vec_0019EBD8 d(o->m90.x * g, o->m90.y * g, o->m90.z * g, o->m90.w * g);
                pos += d;
            }
        }
        Move(&pos, f, t0, t1, t2, t3, e, a, b);
        break;
    }
    case 0xF99F9FAF: {
        unsigned int id;
        func_001E8398(params, 0xCAB94088, &id, 1);
        Vec_0019EBD8 p(0.0f, 0.0f, 0.0f);
        func_001E7FA8(params, 0xA6F5352F, &p, 0);
        int x;
        func_001E8248(params, 0x11B70A02, &x, 1);
        void* y;
        func_001E8180(params, 0x7031F10C, &y, 1);
        Vec_0019EBD8 q;
        func_001E7FA8(params, 0x0C4C809E, &q, 1);
        Vec_0019EBD8 r;
        func_001E7FA8(params, 0xFB1A83B2, &r, 1);
        float s = 1.0f;
        func_001E7EB0(params, 0x8C6A6E08, &s, 0);
        Set(id, x, y, &q, &r, &p, s);
        break;
    }
    default:
        return 2;
    }
    return 1;
}
