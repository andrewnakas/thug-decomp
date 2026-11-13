struct Params_001C6888;

extern "C" void* func_001190D0(unsigned int size);
extern "C" Params_001C6888* func_001E6978(void* mem);
extern "C" void func_001E6AE8(Params_001C6888* p, int flags);
extern "C" void func_001E72B0(Params_001C6888* p, unsigned int crc, float f);
extern "C" void* func_001E5548(unsigned int crc, int a);
extern "C" int func_001E7EB0(void* s, unsigned int crc, float* out, int a);
extern "C" int func_002A19A8(void* net);
extern void* D_00392068;

class Anim_001C6888 {
public:
    char pad0[0x18];
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
    virtual int CallScript(unsigned int crc, Params_001C6888* p, int a);
};

extern "C" void func_001A18C8(Anim_001C6888* a, int b, int c, float f);

struct Info_001C6888 {
    char pad0[0x28];
    int m28;
};

struct Self_001C6888 {
    char pad0[0x950];
    int m_mode;
    float m954;
    char pad958[0xA2C - 0x958];
    Anim_001C6888* m_anim;
    char padA30[0xA38 - 0xA30];
    Info_001C6888* mA38;
    char padA3C[0xA6C - 0xA3C];
    float mA6C;
    char padA70[0xC04 - 0xA70];
    float mC04;

    void UpdateSpeed();
};

static inline float fabsf_001C6888(float f) { return __builtin_fabsf(f); }

void Self_001C6888::UpdateSpeed()
{
    float v;
    switch (m_mode) {
    case 1:
        if (mA6C > 0.0f) {
            func_001A18C8(m_anim, 0, 0, m954 / mA6C);
            if (mA38->m28) {
                Params_001C6888* p = func_001E6978(func_001190D0(8));
                func_001E72B0(p, 0xF0D90109, m954 / mA6C);
                m_anim->CallScript(0xBD4EDD44, p, 0);
                if (p)
                    func_001E6AE8(p, 3);
            }
        }
        break;
    case 2: {
        float s;
        func_001E7EB0(func_001E5548(0x6775E538, 0), 0x1A47FFAB, &s, 1);
        v = m954 / s;
        {
            Params_001C6888* p = func_001E6978(func_001190D0(8));
            func_001E72B0(p, 0xF0D90109, v);
            m_anim->CallScript(0xBD4EDD44, p, 0);
            if (p)
                func_001E6AE8(p, 3);
        }
        func_001A18C8(m_anim, 0, 0, v);
        break;
    }
    case 3: {
        float s;
        func_001E7EB0(func_001E5548(0x6775E538, 0), 0x0AB2DB54, &s, 1);
        v = m954 / s;
        {
            Params_001C6888* p = func_001E6978(func_001190D0(8));
            func_001E72B0(p, 0xF0D90109, v);
            m_anim->CallScript(0xBD4EDD44, p, 0);
            if (p)
                func_001E6AE8(p, 3);
        }
        if (!func_002A19A8(D_00392068) || fabsf_001C6888(v - mC04) < 0.1f) {
            func_001A18C8(m_anim, 0, 0, v);
        } else {
            mC04 = v;
            func_001A18C8(m_anim, 1, 0, v);
        }
        break;
    }
    }
}
