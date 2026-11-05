typedef int qword __attribute__((mode(TI)));

struct Vec_001BE648 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_001BE648() {}
    void Set(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    Vec_001BE648(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

struct Script_001BE648 {
    char pad0[0x18];
    void* m_params;
};

extern "C" int func_0010FC30();
extern "C" void func_001E72B0(void* s, unsigned int name, float v);
extern "C" void func_001E7360(void* s, unsigned int name, unsigned int v);
extern "C" void func_001E7200(void* s, unsigned int name, int v);
extern "C" int func_001E8708(void* params, unsigned int name);
extern "C" int func_001E7EB0(void* s, unsigned int key, float* out, int flag);
extern "C" void* func_001E5548(unsigned int key, int a);
extern "C" void func_001A18C8(void* p, int a, int b, float c);
extern "C" void func_0026B1B0(Vec_001BE648* out, void* a, void* b);
extern "C" void func_003233B8(Vec_001BE648* out, Vec_001BE648* in);
extern "C" float func_003413F0(float x);
extern unsigned int D_003633D0[];

static inline float Param_001BE648(unsigned int key)
{
    float f;
    func_001E7EB0(func_001E5548(0x6775E538, 0), key, &f, 1);
    return f;
}

struct C_001BE648 {
    char pad0[0x1C];
    int m_state;
    int m_start;
    int m_24;
    char pad1[0x60 - 0x28];
    Vec_001BE648 m_60;
    char pad2[0x950 - 0x70];
    int m_950;
    float m_954;
    char pad3[0xA1C - 0x958];
    void* m_A1C;
    void* m_A20;
    void* m_A24;
    char pad4[0xA2C - 0xA28];
    void* m_A2C;
    char pad5[0xA6C - 0xA30];
    float m_A6C;
    char pad6[0xBFC - 0xA70];
    unsigned int m_BFC;
    char pad7[0xC04 - 0xC00];
    float m_C04;
    int GetMember(unsigned int name, void* params, Script_001BE648* script);
};

extern "C" void func_001C1808(C_001BE648* self);
extern "C" void func_001C4638(C_001BE648* self);

int C_001BE648::GetMember(unsigned int name, void* params, Script_001BE648* script)
{
    switch (name) {
    case 0x893213E5:
        return m_state == 0;
    case 0x5012082E:
        return m_state == 1;
    case 0x9A3CA853:
        return m_state == 2;
    case 0x19702CA8:
        return m_state == 3;
    case 0x8FE2B013:
        return m_state == 4;
    case 0xCE64576C: {
        void* s = script->m_params;
        int start = m_start;
        func_001E7200(s, 0x5AB23CC9, func_0010FC30() - start);
        break;
    }
    case 0x83E4BD70:
        func_001C1808(this);
        break;
    case 0xAF04B983: {
        unsigned int st;
        if (m_954 < Param_001BE648(0xF3649996)) {
            st = 0x1150CABB;
        } else if (m_954 < Param_001BE648(0x6A5805D8)) {
            st = 0x0131F2A2;
        } else if (m_954 < Param_001BE648(0x1C94CC9C)) {
            st = 0x5606D106;
        } else {
            st = 0x4667E91F;
        }
        func_001E7360(script->m_params, 0x092C388F, st);
        break;
    }
    case 0x56112C03:
        if (func_001E8708(params, 0xD443A2BC)) {
            if (m_950) {
                m_950 = 0;
                func_001A18C8(m_A2C, 0, 1, 1.0f);
            }
        } else if (func_001E8708(params, 0xAF895B3F)) {
            m_950 = 1;
        } else if (func_001E8708(params, 0x6384F1DA)) {
            m_950 = 2;
        } else if (func_001E8708(params, 0xA2BFE505)) {
            m_950 = 3;
            m_C04 = -1.0f;
        }
        func_001E7EB0(params, 0xB2D59BAF, &m_A6C, 0);
        break;
    case 0x9D3EEBE8:
        func_001C4638(this);
        break;
    case 0xC6CD659E:
        func_001E7360(script->m_params, 0x85FA9AC4, m_BFC);
        break;
    case 0x55BF1CD6: {
        int start = m_start;
        void* s = script->m_params;
        func_001E72B0(s, 0x4B88E4E4, (float)(unsigned int)(func_0010FC30() - start) * 0.001f);
        break;
    }
    case 0xE9B1CDE8:
        func_001E7360(script->m_params, 0xF78635DA, D_003633D0[m_24]);
        break;
    case 0xAC7B36C8:
        func_001E7360(script->m_params, 0x5C6C2D04, D_003633D0[m_state]);
        break;
    case 0x7E01B923: {
        Vec_001BE648 n;
        Vec_001BE648 d;
        Vec_001BE648 a;
        Vec_001BE648 b;
        func_0026B1B0(&a, m_A24, m_A20);
        func_0026B1B0(&b, m_A24, m_A1C);
        d.Set(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
        func_003233B8(&d, &d);
        n = d;
        float ang = func_003413F0(n.y);
        d.Set(n.y * m_60.z - n.z * m_60.y, n.z * m_60.x - n.x * m_60.z, n.x * m_60.y - n.y * m_60.x, 0.0f);
        if (d.y < d.w) ang = -ang;
        func_001E72B0(script->m_params, 0xEAD7D286, ang * 57.2957764f);
        break;
    }
    default:
        return 2;
    }
    return 1;
}
