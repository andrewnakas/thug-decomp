struct Vec_001404F8 {
    float x, y, z, w;
};

static inline bool IsUp_001404F8(float a, float b, float c)
{
    return a == 0.0f && b == 1.0f && c == 0.0f;
}

extern "C" int func_001E7FA8(void* params, unsigned int name, Vec_001404F8* out, int req);
extern "C" int func_001E8038(void* params, char* name, Vec_001404F8* out, int req);
extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int req);
extern "C" int func_001E7F50(void* params, char* name, float* out, int req);
extern "C" int func_001E7E58(void* params, char* name, int* out, int req);

extern char D_0038A368[];
extern char D_0035EC58[];
extern char D_0038A370[];
extern char D_0038A378[];
extern char D_0038A380[];
extern char D_0038A388[];
extern char D_0038A390[];
extern char D_0038A398[];
extern char D_0038A3A0[];
extern char D_0038A3A8[];
extern char D_0038A3B0[];
extern char D_0038A3B8[];
extern char D_0038A3C0[];
extern char D_0038A3C8[];
extern char D_0038A3D0[];
extern char D_0038A3D8[];
extern char D_0038A3E0[];
extern char D_0038A3E8[];
extern char D_0038A3F0[];
extern char D_0038A3F8[];
extern char D_0038A400[];
extern char D_0038A408[];
extern char D_0038A410[];
extern char D_0038A418[];
extern char D_0038A420[];
extern char D_0038A428[];
extern char D_0038A430[];
extern char D_0038A438[];
extern char D_0038A440[];
extern char D_0038A448[];

class B_001404F8 {
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
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual int Count();
    virtual void S17(int i, unsigned char v);
    virtual void S18(int i, unsigned char v);
    virtual void S19(int i, unsigned char v);
    virtual void S20(int i, unsigned char v);
    virtual void S21(int i, unsigned char v);
    virtual void S22(int i, unsigned char v);
    virtual void S23(int i, unsigned char v);
    virtual void S24(int i, unsigned char v);
    virtual void S25(int i, unsigned char v);
    virtual void S26(int i, unsigned char v);
    virtual void S27(int i, unsigned char v);
    virtual void S28(int i, unsigned char v);
    virtual void V29();
    virtual void V30();
};

class C_001404F8 : public B_001404F8 {
public:
    char padC[0x44];
    float m50;
    float m54;
    float m58;
    char pad5C[0x104];
    float m160;
    int m164;
    int m168;
    float m16C;
    float m170;
    float m174;
    float m178;
    float m17C;
    int m180;
    int m184;
    float m188;
    float m18C;
    float m190;
    float m194;
    float m198;
    float m19C;
    float m1A0;
    float m1A4;
    float m1A8;
    float m1AC;
    float m1B0;
    float m1B4;
    float m1B8;
    float m1BC;
    float m1C0;
    char pad1C4[0x20];
    float m1E4;
    int m1E8;
    int m1EC;
    int CallMember(unsigned int id, void* params, void* script);
};

extern "C" int func_00258098(C_001404F8* self, unsigned int id, void* params, void* script);
extern "C" void func_0013FD08(C_001404F8* self, int v);

int C_001404F8::CallMember(unsigned int id, void* params, void* script)
{
    switch (id) {
    case 0x099CD17B: {
        float x = 0.0f, y = 0.0f, z = 0.0f;
        Vec_001404F8 t;
        if (func_001E7FA8(params, 0x7F261953, &t, 0)) {
            x = t.x;
            y = t.y;
            z = t.z;
        } else {
            func_001E7EB0(params, 0x7323E97C, &x, 0);
            func_001E7EB0(params, 0x0424D9EA, &y, 0);
            func_001E7EB0(params, 0x9D2D8850, &z, 0);
        }
        m50 = x;
        m54 = y;
        m58 = z;
        break;
    }
    case 0x63274395: {
        float a = 0.0f;
        func_001E7EB0(params, 0x5E84E22F, &a, 0);
        float b = a;
        func_001E7EB0(params, 0x6289DD76, &b, 0);
        m16C = a;
        m170 = b;
        break;
    }
    case 0x8FFDEF38: {
        float a = 0.0f;
        func_001E7EB0(params, 0x73E5BAD0, &a, 0);
        float b = a;
        func_001E7EB0(params, 0x0AB21AF0, &b, 0);
        m174 = a;
        m178 = b;
        break;
    }
    case 0x7911855B: {
        float a = 0.0f;
        func_001E7EB0(params, 0x834A5F87, &a, 0);
        m17C = a;
        break;
    }
    case 0xDB8621F7: {
        int v = 0;
        func_001E7E58(params, D_0038A368, &v, 0);
        m180 = v > 0;
        break;
    }
    case 0xE985A9A6: {
        int v = 0;
        func_001E7E58(params, D_0035EC58, &v, 0);
        m184 = v > 0;
        break;
    }
    case 0xA075EE45: {
        float x = 0.0f, y = 0.0f, z = 0.0f;
        Vec_001404F8 t;
        if (func_001E8038(params, D_0038A370, &t, 0)) {
            x = t.x;
            y = t.y;
            z = t.z;
        } else {
            func_001E7F50(params, D_0038A378, &x, 0);
            func_001E7F50(params, D_0038A380, &y, 0);
            func_001E7F50(params, D_0038A388, &z, 0);
        }
        m188 = x;
        m18C = y;
        m190 = z;
        break;
    }
    case 0x2A479569: {
        float a = 0.0f;
        func_001E7F50(params, D_0038A390, &a, 0);
        float b = a;
        func_001E7F50(params, D_0038A398, &b, 0);
        m194 = a;
        m198 = b;
        float c = a;
        float d = func_001E7F50(params, D_0038A3A0, &c, 0) ? c : b;
        func_001E7F50(params, D_0038A3A8, &d, 0);
        m19C = c;
        m1A0 = d;
        break;
    }
    case 0xD3F1D333: {
        float a = 0.0f;
        func_001E7F50(params, D_0038A3B0, &a, 0);
        float b = a;
        func_001E7F50(params, D_0038A3B8, &b, 0);
        m1A4 = a;
        m1A8 = b;
        m1E8 = 1;
        break;
    }
    case 0xB373FB6E: {
        float x = 0.0f, y = 0.0f, z = 0.0f;
        Vec_001404F8 t;
        if (func_001E8038(params, D_0038A3C0, &t, 0)) {
            x = t.x;
            y = t.y;
            z = t.z;
        } else {
            func_001E7F50(params, D_0038A378, &x, 0);
            func_001E7F50(params, D_0038A380, &y, 0);
            func_001E7F50(params, D_0038A388, &z, 0);
        }
        float ux = x;
        float uy = y;
        float uz = z;
        if (ux != 0.0f || uy != 1.0f || uz != 0.0f) {
            m1AC = x;
            m1B0 = uy;
            m1B4 = uz;
        }
        break;
    }
    case 0x1CFBF078: {
        float x = 0.0f, y = 0.0f, z = 0.0f;
        Vec_001404F8 t;
        if (func_001E8038(params, D_0038A3C8, &t, 0)) {
            x = t.x;
            y = t.y;
            z = t.z;
        } else {
            func_001E7F50(params, D_0038A378, &x, 0);
            func_001E7F50(params, D_0038A380, &y, 0);
            func_001E7F50(params, D_0038A388, &z, 0);
        }
        m1B8 = x;
        m1BC = y;
        m1C0 = z;
        break;
    }
    case 0x514B2584: {
        int a;
        int first, last;
        if (func_001E7E58(params, D_0038A3D0, &a, 0)) {
            last = a;
            first = a;
        } else {
            first = 0;
            last = Count() - 1;
        }
        if (first < Count() && last < Count()) {
            for (int i = first; i < last + 1; i++) {
                if (i < Count()) {
                    int v;
                    if (func_001E7E58(params, D_0038A3D8, &v, 0)) {
                        S25(i, v);
                        m1EC = 1;
                    }
                    if (func_001E7E58(params, D_0038A3E0, &v, 0)) {
                        S26(i, v);
                        m1EC = 1;
                    }
                    if (func_001E7E58(params, D_0038A3E8, &v, 0)) {
                        S27(i, v);
                        m1EC = 1;
                    }
                    if (func_001E7E58(params, D_0038A3F0, &v, 0)) {
                        S28(i, v);
                        m1EC = 1;
                    }
                    if (func_001E7E58(params, D_0038A3F8, &v, 0))
                        S21(i, v);
                    if (func_001E7E58(params, D_0038A400, &v, 0))
                        S22(i, v);
                    if (func_001E7E58(params, D_0038A408, &v, 0))
                        S23(i, v);
                    if (func_001E7E58(params, D_0038A410, &v, 0))
                        S24(i, v);
                    if (func_001E7E58(params, D_0038A418, &v, 0)) {
                        S17(i, v);
                        if (!m1EC)
                            S25(i, v);
                    }
                    if (func_001E7E58(params, D_0038A420, &v, 0)) {
                        S18(i, v);
                        if (!m1EC)
                            S26(i, v);
                    }
                    if (func_001E7E58(params, D_0038A428, &v, 0)) {
                        S19(i, v);
                        if (!m1EC)
                            S27(i, v);
                    }
                    if (func_001E7E58(params, D_0038A430, &v, 0)) {
                        S20(i, v);
                        if (!m1EC)
                            S28(i, v);
                    }
                }
            }
        }
        func_001E7F50(params, D_0038A438, &m1E4, 0);
        break;
    }
    case 0x711B1A6A: {
        int v = 1;
        func_001E7E58(params, D_0038A440, &v, 0);
        func_0013FD08(this, v);
        break;
    }
    case 0x35B65BD4: {
        float s = 1.0f;
        func_001E7F50(params, D_0038A448, &s, 0);
        m160 = s;
        break;
    }
    case 0xA8699E0E:
        V30();
        break;
    case 0x482482C6:
        m168 = 0;
        break;
    default:
        return func_00258098(this, id, params, script);
    }
    return 1;
}
