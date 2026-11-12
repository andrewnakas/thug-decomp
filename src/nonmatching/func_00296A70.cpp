/* fuzzy: 88.2 */
typedef int qword_00296A70 __attribute__((mode(TI)));
struct Vec_00296A70 {
    union {
        qword_00296A70 q;
        struct { float x, y, z, w; } f;
    };
    Vec_00296A70(float a, float b, float c) { f.x = a; f.y = b; f.z = c; f.w = 1.0f; }
};

class Struct1E6978 {
public:
    int m_w[4];
    Struct1E6978();
    ~Struct1E6978();
};

struct Script_00296A70 {
    char pad0[0x18];
    void* m18;
};

struct Goal_00296A70 {
    unsigned char m0;
    unsigned char m1;
    unsigned char m2;
    unsigned char m3;
};

struct Ent_00296A70 {
    int m0;
    char pad4[0x114 - 0x4];
    unsigned int m114;
    char pad118[0x2A4 - 0x118];
    unsigned char m2A4;
    unsigned char m2A5;
    char pad2A6[0x2B4 - 0x2A6];
    int m2B4;
    char pad2B8[0x350 - 0x2B8];
};

struct Obj_00296A70 {
    char pad0[0x20];
    Ent_00296A70 m20[50];
    Ent_00296A70* mA5C0;
    int CallMember(unsigned int id, void* params, Script_00296A70* script);
};

extern char D_00391E10[];
extern char D_00391E20[];
extern char D_00391E28[];
extern char D_00391E30[];
extern char D_00391DD0[];
extern char D_00377480[];
extern char D_00377490[];

extern "C" Ent_00296A70* func_00295CC8(Obj_00296A70* self, void* params);
extern "C" int func_001E7DE8(void* params, unsigned int id, void* out, int req);
extern "C" int func_001E8708(void* params, unsigned int id);
extern "C" int func_001E84E8(void* params, char* name, unsigned int* out, int req);
extern "C" int func_001E7D18(void* params, char* name, char** out, int req);
extern "C" int func_001E8398(void* params, unsigned int id, unsigned int* out, int req);
extern "C" void func_001E7200(void* s, unsigned int id, int v);
extern "C" void func_001E7360(void* s, unsigned int id, unsigned int v);
extern "C" void func_001E73C8(void* s, char* name, unsigned int v);
extern "C" void func_001E7268(void* s, char* name, int v);
extern "C" void func_001E7788(void* s, char* name, void* v);
extern "C" void func_001E6C28(void* s, char* name);
extern "C" void func_001E7410(Struct1E6978* s, unsigned int name, float x, float y, float z);
extern "C" void func_001E72B0(Struct1E6978* s, unsigned int id, float v);
extern "C" void func_001F0210(unsigned int a, Struct1E6978* b, int c, int d, int e);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AE8(void* o, int n);
extern "C" void* func_001190D0(int size);
extern "C" void* func_00122CF8(int size);
extern "C" void* func_001E8DD0(void* mem);
extern "C" void func_001E8E98(void* arr, int n, int type);
extern "C" void func_001E9170(void* arr, int i, void* v);
extern "C" int func_00291E80(void* params);
extern "C" void func_00293830(Ent_00296A70* e, unsigned char v);
extern "C" void func_002938A0(Ent_00296A70* e, unsigned char v);
extern "C" int func_00293998(Ent_00296A70* e, unsigned char v);
extern "C" void func_002939E0(Ent_00296A70* e, int a, int x, int b, int c);
extern "C" void func_00293A80(Ent_00296A70* e, int v);
extern "C" Goal_00296A70* func_00293B20(Ent_00296A70* e, int v);
extern "C" void func_002947D0(Ent_00296A70* e, void* params);
extern "C" void func_002945E8(Ent_00296A70* e, void* params);
extern "C" bool func_00294888(Ent_00296A70* e);
extern "C" void func_002966C0(Obj_00296A70* self);
extern "C" int func_00292748(Ent_00296A70* e);
extern "C" void func_00296008(Obj_00296A70* self, Ent_00296A70* e);
extern "C" void func_00294C80(Ent_00296A70* e, unsigned int v);
extern "C" void func_00294E68(Ent_00296A70* e, char* s);
extern "C" void func_00294E88(Ent_00296A70* e, char* s);
extern "C" void func_00293380(Ent_00296A70* e, void* s);
extern "C" int func_00295E28(Obj_00296A70* self, int id);
extern "C" void func_00295138(Ent_00296A70* e);
extern "C" void func_00294F50(Ent_00296A70* e, int v);
extern "C" void func_00294EA8(Ent_00296A70* e, char* s);
extern "C" void func_00294EC8(Ent_00296A70* e, char* s);
extern "C" int func_00295DF0(Obj_00296A70* self);
extern "C" void func_00294830(Ent_00296A70* e);
extern "C" void func_00295EB0(Obj_00296A70* self);
extern "C" void func_002959D8(Obj_00296A70* self);
extern "C" void func_002965D8(Obj_00296A70* self);
extern "C" void func_00296550(Obj_00296A70* self);
extern "C" void func_00294EE8(Ent_00296A70* e, int v);
extern "C" void func_00294F48(Ent_00296A70* e, unsigned int v);
extern "C" int func_00294A68(Ent_00296A70* e, Vec_00296A70* v, float* a, float* b);

int Obj_00296A70::CallMember(unsigned int id, void* params, Script_00296A70* script)
{
    switch (id) {
    case 0x0AB710F3: {
        Ent_00296A70* e = func_00295CC8(this, params);
        if (e) {
            int v = 0;
            func_001E7DE8(params, 0x3AC9AB5E, &v, 0);
            func_00293830(e, v);
        }
        break;
    }
    case 0x5C155A29: {
        Ent_00296A70* e = func_00295CC8(this, params);
        if (e) {
            int v = 0;
            func_001E7DE8(params, 0x3AC9AB5E, &v, 0);
            func_002938A0(e, v);
        }
        break;
    }
    case 0xFB279560: {
        Ent_00296A70* e = func_00295CC8(this, params);
        if (!e)
            return 0;
        int v = 0;
        func_001E7DE8(params, 0x3AC9AB5E, &v, 0);
        return func_00293998(e, v) ? 1 : 0;
    }
    case 0xCCA11C78: {
        Ent_00296A70* e = func_00295CC8(this, params);
        if (e) {
            int a = 0;
            func_001E7DE8(params, 0xEB7D6498, &a, 0);
            int b = 0;
            func_001E7DE8(params, 0xEDF5DB70, &b, 0);
            int c = 0;
            func_001E7DE8(params, 0xA4BEE6A1, &c, 0);
            func_002939E0(e, a, func_001E8708(params, 0x687E2C25), b, c);
        }
        break;
    }
    case 0x1D30A7B6: {
        Ent_00296A70* e = func_00295CC8(this, params);
        if (e) {
            int v = 0;
            func_001E7DE8(params, 0xEB7D6498, &v, 0);
            func_00293A80(e, v);
        }
        break;
    }
    case 0xE5ED63B7: {
        Ent_00296A70* e = func_00295CC8(this, params);
        if (e) {
            int v = 0;
            func_001E7DE8(params, 0xEB7D6498, &v, 0);
            Goal_00296A70* g = func_00293B20(e, v);
            if (g) {
                func_001E7200(script->m18, 0xEDF5DB70, g->m2 * 180);
                func_001E7200(script->m18, 0xA4BEE6A1, g->m3);
                if (g->m1)
                    func_001E7360(script->m18, 0, 0x687E2C25);
                break;
            }
            return 0;
        }
        break;
    }
    case 0x03EBD2C9: {
        Ent_00296A70* e = func_00295CC8(this, params);
        if (e)
            func_002947D0(e, params);
        break;
    }
    case 0x47208C6D: {
        Ent_00296A70* e = func_00295CC8(this, params);
        if (e)
            func_002945E8(e, params);
        break;
    }
    case 0x769309E1: {
        Ent_00296A70* e = func_00295CC8(this, params);
        if (e)
            e->m2A4 = 1;
        break;
    }
    case 0x88D54A10: {
        unsigned int type = 0;
        func_001E84E8(params, D_00391E20, &type, 0);
        mA5C0 = 0;
        for (int i = 0; i < 50; i++) {
            Ent_00296A70* e = &m20[i];
            if (e->m2A5 && e->m114 == type && !func_00294888(e))
                mA5C0 = e;
        }
        if (!mA5C0)
            return 0;
        break;
    }
    case 0xFF9E8752:
        if (!func_00295CC8(this, params))
            return 0;
        break;
    case 0x259C59DD:
        func_002966C0(this);
        func_001E73C8(script->m18, D_00391E28, func_00292748(mA5C0));
        break;
    case 0x1F80B5AE: {
        Ent_00296A70* e = func_00295CC8(this, params);
        if (e)
            func_00296008(this, e);
        break;
    }
    case 0x26848221: {
        Ent_00296A70* e = func_00295CC8(this, params);
        if (!e)
            return 0;
        if (!func_00294888(e))
            return 0;
        break;
    }
    case 0xFDB2C514:
        mA5C0 = func_00295CC8(this, params);
        break;
    case 0x98ABBD09: {
        unsigned int type = 0;
        func_001E84E8(params, D_00391E20, &type, 0);
        Ent_00296A70* e = func_00295CC8(this, params);
        if (e)
            func_00294C80(e, type);
        break;
    }
    case 0x66A33157: {
        char* text = D_00391E10;
        func_001E7D18(params, D_00391E30, &text, 0);
        Ent_00296A70* e = func_00295CC8(this, params);
        if (e)
            func_00294E68(e, text);
        break;
    }
    case 0x7AABBC09: {
        char* text = D_00391E10;
        func_001E7D18(params, D_00391E30, &text, 0);
        Ent_00296A70* e = func_00295CC8(this, params);
        if (e)
            func_00294E88(e, text);
        break;
    }
    case 0x69B872E3:
        if (mA5C0)
            func_00293380(mA5C0, script->m18);
        break;
    case 0x96F11BD3: {
        int type = func_00291E80(params);
        int n = func_00295E28(this, type);
        if (n) {
            void* arr = func_001E8DD0(func_00122CF8(0x10));
            func_001E8E98(arr, n, 10);
            int k = 0;
            for (int i = 0; i < 50; i++) {
                Ent_00296A70* e = &m20[i];
                if (e->m2A5 && (!type || e->m0 == type) && func_00294888(e)) {
                    void* s = func_001E6978(func_001190D0(8));
                    func_00293380(e, s);
                    func_001E9170(arr, k++, s);
                }
            }
            func_001E7788(script->m18, D_00377480, arr);
        }
        break;
    }
    case 0x96874358: {
        int type = func_00291E80(params);
        int n = func_00295E28(this, type);
        if (!type && func_001E8708(params, 0xB99F6330))
            n -= func_00295E28(this, 0xE8B4B836);
        func_001E7268(script->m18, D_00377490, n);
        break;
    }
    case 0x5BD8050A:
        func_001E6C28(script->m18, D_00391E28);
        if (mA5C0)
            func_001E73C8(script->m18, D_00391E28, func_00292748(mA5C0));
        break;
    case 0x5408AC04: {
        Ent_00296A70* e = func_00295CC8(this, params);
        if (e)
            func_00295138(e);
        break;
    }
    case 0xB525B113: {
        Ent_00296A70* e = func_00295CC8(this, params);
        if (e)
            func_00294F50(e, func_001E8708(params, 0xC6322A25));
        break;
    }
    case 0x4A569426: {
        char* text = D_00391E10;
        if (mA5C0 && func_001E7D18(params, D_00391DD0, &text, 0)) {
            mA5C0 = func_00295CC8(this, params);
            func_00294EA8(mA5C0, text);
        }
        break;
    }
    case 0x410821DF: {
        char* text = D_00391E10;
        if (mA5C0 && func_001E7D18(params, D_00391DD0, &text, 0)) {
            mA5C0 = func_00295CC8(this, params);
            func_00294EC8(mA5C0, text);
        }
        break;
    }
    case 0x60288ABE:
        if (func_00295DF0(this) == 50)
            return 1;
        {
        int n = func_00295E28(this, func_00291E80(params));
        int max = 9;
        return n > max;
        }
    case 0x831ECA10:
        mA5C0 = func_00295CC8(this, params);
        if (mA5C0) {
            func_00294830(mA5C0);
            func_00295EB0(this);
            func_002959D8(this);
        }
        break;
    case 0xDBA8E3FC:
        if (func_001E8708(params, 0x98439808))
            func_002965D8(this);
        else
            func_00296550(this);
        break;
    case 0xD7258335:
        func_001E7200(script->m18, 0x8BC2E0DB, 10);
        break;
    case 0x9E5A634A:
        mA5C0 = func_00295CC8(this, params);
        if (mA5C0) {
            int v = 0;
            if (func_001E7DE8(params, 0, &v, 0))
                mA5C0->m2B4 = v;
        }
        break;
    case 0x7D5073F6:
        mA5C0 = func_00295CC8(this, params);
        if (mA5C0) {
            int v = 0x78;
            if (func_001E7DE8(params, 0, &v, 0))
                func_00294EE8(mA5C0, v);
        }
        break;
    case 0xEC316A9C:
        mA5C0 = func_00295CC8(this, params);
        if (mA5C0) {
            unsigned int v = 0x54166ACD;
            if (func_001E8398(params, 0, &v, 0))
                func_00294F48(mA5C0, v);
        }
        break;
    case 0x20B566B1:
        if (mA5C0) {
            Vec_00296A70 v(0.0f, 0.0f, 0.0f);
            float b = v.f.x;
            float a = v.f.x;
            func_00294A68(mA5C0, &v, &a, &b);
            Struct1E6978 s;
            func_001E7410(&s, 0x7F261953, v.f.x, v.f.y + a, v.f.z);
            func_001E72B0(&s, 0xFF7EBAF6, b);
            func_001F0210(0xDEA7FE56, &s, 0, 0, 0);
        }
        break;
    default:
        return 2;
    }
    return 1;
}
