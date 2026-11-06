/* sym: __15Params_002795B0 = 0x001E6978 */
/* sym: _$_15Params_002795B0 = 0x001E6AE8 */
extern "C" float sqrtf(float);
extern "C" void* memcpy(void*, const void*, unsigned int);

typedef int qword __attribute__((mode(TI)));

struct Vec_002795B0 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
    Vec_002795B0() {}
    Vec_002795B0(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    float Length() const { return sqrtf(x * x + y * y + z * z); }
    void Normalize()
    {
        float l = Length();
        if (l < 0.0001f) {
            x = 1.0f;
            y = 0.0f;
            z = 1.0f;
            w = 1.0f;
        } else {
            float inv = 1.0f / l;
            x *= inv;
            y *= inv;
            z *= inv;
            w *= inv;
        }
    }
};

static inline Vec_002795B0 operator*(const Vec_002795B0& v, float s)
{
    return Vec_002795B0(v.x * s, v.y * s, v.z * s, v.w * s);
}

struct Params_002795B0 {
    int m0;
    int m4;
    Params_002795B0();
    ~Params_002795B0();
};

struct Body_002795B0 {
    char pad0[0x50];
    Vec_002795B0 m_pos;
};

struct Player_002795B0 {
    char pad0[0x18];
    Body_002795B0* m_body;
};

struct Phys_002795B0 {
    char pad0[0x20];
    int m20;
    char pad24[0x180 - 0x24];
    int m180;
    bool Idle() const { return m180 == 0 && m20 == 0; }
};

struct Comp_002795B0 {
    char pad0[0x34];
    Phys_002795B0* m34;
};

struct Holder_002795B0 {
    char pad0[0x1C];
    void* m1C;
};

struct Skater_002795B0 {
    char pad0[0x50];
    Vec_002795B0 m_pos;
    char pad60[0xB0 - 0x60];
    Vec_002795B0 m_vel;
    char padC0[0x2D8 - 0xC0];
    Holder_002795B0* m2D8;
};

struct Data_002795B0 {
    char m0;
    char pad1[3];
    int m4;
};

struct Msg_002795B0 {
    Data_002795B0* m_data;
    unsigned char m_type;
    char pad5[0x1C - 0x5];
    Skater_002795B0* m_skater;
};

extern void* D_00392068;
extern char D_00376A60[];

extern "C" void func_003315B8(void* p, int c, unsigned int n);
extern "C" Player_002795B0* func_002A52F0(void* net, unsigned short id);
extern "C" char* func_00206A08(Body_002795B0* b);
extern "C" void func_00332088(char* dst, char* src, int n);
extern "C" void func_001E70C0(Params_002795B0* p, unsigned int crc, char* s);
extern "C" void func_001E7360(Params_002795B0* p, int a, unsigned int crc);
extern "C" void func_001848F0(Skater_002795B0* s, unsigned int crc, Params_002795B0* p);
extern "C" Comp_002795B0* func_00185578(Skater_002795B0* s, unsigned int crc);
extern "C" void func_0027C9E0(Comp_002795B0* c, Body_002795B0* b);
extern "C" void func_001BF0D8(Comp_002795B0* c, Body_002795B0* b);
extern "C" int func_002A1A38(void* net);
extern "C" int func_002392B8(void* o);
extern "C" void func_00239198(void* o, int v);

int func_002795B0(Msg_002795B0* msg)
{
    Skater_002795B0* sk = msg->m_skater;
    Data_002795B0* d = msg->m_data;
    switch (msg->m_type) {
    case 0x85: {
        char name[32];
        memcpy(name, D_00376A60, 8);
        func_003315B8(name + 8, 0, 0x18);
        Player_002795B0* p = func_002A52F0(D_00392068, d->m0);
        if (p)
            func_00332088(name, func_00206A08(p->m_body), 0x20);
        Params_002795B0 prm;
        func_001E70C0(&prm, 0xA4B08520, name);
        func_001E7360(&prm, 0, 0xD039432C);
        func_001848F0(sk, 0xA1021AF0, &prm);
        break;
    }
    case 0x84: {
        char name[32];
        memcpy(name, D_00376A60, 8);
        func_003315B8(name + 8, 0, 0x18);
        Player_002795B0* p = func_002A52F0(D_00392068, d->m0);
        if (p) {
            void* net = D_00392068;
            Body_002795B0* b = p->m_body;
            Vec_002795B0 dir(sk->m_pos.x - b->m_pos.x, sk->m_pos.y - b->m_pos.y, sk->m_pos.z - b->m_pos.z, sk->m_pos.w - b->m_pos.w);
            dir.Normalize();
            sk->m_vel = dir * 300.0f * 1.5f;
            sk->m_vel.y = 200.0f;
            Phys_002795B0* ph = func_00185578(sk, 0xD9151D4D)->m34;
            if (ph->Idle())
                func_0027C9E0(func_00185578(sk, 0x5BD63B29), p->m_body);
            else
                func_001BF0D8(func_00185578(sk, 0x726E85AA), p->m_body);
            func_00332088(name, func_00206A08(p->m_body), 0x20);
            if (!func_002A1A38(net)) {
                void* o = sk->m2D8->m1C;
                if (func_002392B8(o) - d->m4 < 0)
                    func_00239198(o, 0);
                else
                    func_00239198(o, func_002392B8(o) - d->m4);
            }
        }
        Params_002795B0 prm;
        func_001E70C0(&prm, 0xA4B08520, name);
        func_001E7360(&prm, 0, 0xD039432C);
        func_001848F0(sk, 0x915E5E39, &prm);
        break;
    }
    }
    return 3;
}
