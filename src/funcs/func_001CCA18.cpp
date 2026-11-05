typedef int qword_001CCA18 __attribute__((mode(TI)));

struct Vec_001CCA18 {
    union {
        struct {
            float x, y, z, w;
        };
        qword_001CCA18 q;
    };
    Vec_001CCA18() {}
    Vec_001CCA18(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

struct Pair_001CCA18 {
    int a;
    int b;
};

struct Walk_001CCA18 {
    char pad0[0x30];
    Vec_001CCA18 m_pos;
    char pad40[0x60 - 0x40];
    Vec_001CCA18 m_vel;
    char pad70[0x90 - 0x70];
    int m_state;
    char pad94[0xC4 - 0x94];
    float m_C4;
    char padC8[0xA50 - 0xC8];
    Vec_001CCA18 m_A50;
    char padA60[0xA70 - 0xA60];
    Vec_001CCA18 m_A70;
    char padA80[0xB20 - 0xA80];
    Vec_001CCA18 m_B20;
    char padB30[0xB50 - 0xB30];
    int m_B50;
    char padB54[0xBD0 - 0xB54];
    Vec_001CCA18 m_BD0;
    char padBE0[4];
    float m_BE4;
    char padBE8[0xC10 - 0xBE8];
    Vec_001CCA18 m_C10;
    char padC20[0xC30 - 0xC20];
    Vec_001CCA18 m_C30;
    float m_C40;
    int m_C44;
    char padC48[0xC80 - 0xC48];
    int m_C80;
    Pair_001CCA18 m_C84;
    void Jump();
};

extern Pair_001CCA18 D_0038D820[];

extern "C" void* func_001E5548(unsigned int key, int create);
extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);
extern "C" int func_001C6458(Walk_001CCA18* self, Vec_001CCA18* a, Vec_001CCA18* b, Vec_001CCA18* c);
extern "C" void func_001C4210(Walk_001CCA18* self, Vec_001CCA18* v, float f);
extern "C" void func_001BF130(Walk_001CCA18* self, int state);

void Walk_001CCA18::Jump()
{
    Vec_001CCA18* vel = &m_vel;
    float t;
    func_001E7EB0(func_001E5548(0x6775E538, 0), 0xCAF2831B, &t, 1);
    Vec_001CCA18 p;
    Vec_001CCA18 d(m_vel.x * t, m_vel.y * t, m_vel.z * t, m_vel.w * t);
    p.x = m_pos.x - d.x;
    p.y = m_pos.y - d.y;
    p.z = m_pos.z - d.z;
    p.w = m_pos.w - d.w;
    float h;
    func_001E7EB0(func_001E5548(0x6775E538, 0), 0x5296E3FD, &h, 1);
    p.y -= h;
    m_B50 = func_001C6458(this, &p, &p, &m_A70);
    if (m_B50) {
        m_A50.q = m_B20.q;
    }
    m_C10.q = m_pos.q;
    m_C30.q = p.q;
    m_C84 = D_0038D820[0];
    m_C44 = 0;
    m_C40 = m_C4;
    func_001C4210(this, vel, 1.0f);
    m_C80 = 1;
    m_BD0.q = m_vel.q;
    m_BE4 = m_pos.y;
    func_001BF130(this, 4);
    m_state = 0x4DB1BBB1;
}
