struct Comp_0011AE88 {
    int m_0;
    void* m_4;
    char pad8[0x18 - 0x8];
    void* m_18;
    unsigned int m_1C;
};

extern "C" void func_00144CB0(void* p, int);
extern "C" int func_001E8398(void* s, unsigned int name, unsigned int* out, int);
extern "C" int func_001E7EB0(void* s, unsigned int name, float* out, int);
extern "C" int func_001E7DE8(void* s, unsigned int name, int* out, int);
extern "C" void func_001198D0(void* p, unsigned int anim, float a, float b, int c, float d, float e);
extern "C" void func_00144CE8(void* p, unsigned int id);

extern "C" int func_0011AE88(Comp_0011AE88* self, unsigned int crc, void* params)
{
    switch (crc) {
    case 0x5F495AE0:
        func_00144CB0(self->m_18, 0);
        return 2;
    case 0xAF2FAE19: {
        unsigned int anim;
        float a;
        float b;
        int c;
        float d;
        float e;
        func_001E8398(params, 0x6C2BFB7F, &anim, 1);
        func_001E7EB0(params, 0xD16B61E6, &a, 1);
        func_001E7EB0(params, 0xAB81BB3D, &b, 1);
        func_001E7DE8(params, 0xCD8D7C1B, &c, 1);
        func_001E7EB0(params, 0x8F0D24ED, &d, 1);
        func_001E7EB0(params, 0xF0D90109, &e, 1);
        func_001198D0(self->m_4, anim, a, b, c, d, e);
        func_00144CE8(self->m_18, self->m_1C + anim);
        break;
    }
    default:
        return 2;
    }
    return 1;
}
