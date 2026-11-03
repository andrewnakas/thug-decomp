extern "C" int func_001E8398(void* params, unsigned int id, int* out, int req);
extern "C" int func_001E7EB0(void* params, unsigned int id, float* out, int req);
extern "C" int func_001E7DE8(void* params, unsigned int id, int* out, int req);
extern "C" void func_001198D0(void* o, int a, float f0, float f1, int type, float f2, float f3);
extern "C" void func_00144CB0(void* o, int a);
extern "C" void func_00144CE8(void* o, int a);

struct Owner11B348 {
    char pad[0x18];
    float m18;
    float m1C;
    float m20;
};

struct C_0011B348 {
    int m0;
    Owner11B348* m4;
    char pad[0x10];
    float m18;
    float m1C;
    float m20;
    float m24;
    float m28;
    float m2C;
    void* m30;
    int m34;
    int Handle(unsigned int id, void* params);
};

int C_0011B348::Handle(unsigned int id, void* params)
{
    switch (id) {
    case 0x5F495AE0:
        func_00144CB0(m30, 0);
        return 2;
    case 0xAF2FAE19: {
        int a;
        float f0;
        float f1;
        int type;
        float f2;
        float f3;
        func_001E8398(params, 0x6C2BFB7F, &a, 1);
        func_001E7EB0(params, 0xD16B61E6, &f0, 1);
        func_001E7EB0(params, 0xAB81BB3D, &f1, 1);
        func_001E7DE8(params, 0xCD8D7C1B, &type, 1);
        func_001E7EB0(params, 0x8F0D24ED, &f2, 1);
        func_001E7EB0(params, 0xF0D90109, &f3, 1);
        func_001198D0(m4, a, f0, f1, type, f2, f3);
        func_00144CE8(m30, m34 + a);
        break;
    }
    case 0xD0209498: {
        float t;
        if (func_001E7EB0(params, 0x4D747FA0, &t, 0)) {
            if (t < 0.0f) t = 0.0f;
            if (t > 1.0f) t = 1.0f;
            m2C = m4->m18 + (m4->m20 - m4->m18) * t;
        }
        break;
    }
    case 0xEA6D0EFD: {
        float a;
        float b;
        float c;
        float d;
        float e;
        if (func_001E7EB0(params, 0xFD266A26, &a, 0)
            && func_001E7EB0(params, 0x642F3B9C, &b, 0)
            && func_001E7EB0(params, 0x0F43FD49, &c, 0)
            && func_001E7EB0(params, 0x964AACF3, &d, 0)
            && func_001E7EB0(params, 0xF90B0824, &e, 0)) {
            m18 = a;
            m1C = b;
            m20 = c;
            m24 = d;
            m28 = e;
        }
        break;
    }
    default:
        return 2;
    }
    return 1;
}
