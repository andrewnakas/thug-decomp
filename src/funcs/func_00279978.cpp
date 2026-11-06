/* sym: __15Params_00279978 = 0x001E6978 */
/* sym: _$_15Params_00279978 = 0x001E6AE8 */
extern "C" float sqrtf(float);
extern "C" void* memcpy(void*, const void*, unsigned int);

typedef int qword __attribute__((mode(TI)));

struct Vec_00279978 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
    Vec_00279978() {}
    Vec_00279978(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
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

static inline Vec_00279978 operator*(const Vec_00279978& v, float s)
{
    return Vec_00279978(v.x * s, v.y * s, v.z * s, v.w * s);
}

struct Params_00279978 {
    int m0;
    int m4;
    Params_00279978();
    ~Params_00279978();
};

struct Body_00279978 {
    char pad0[0x50];
    Vec_00279978 m_pos;
};

struct Player_00279978 {
    char pad0[0x18];
    Body_00279978* m_body;
};

struct Phys_00279978 {
    char pad0[0x20];
    int m20;
    char pad24[0x180 - 0x24];
    int m180;
    bool Idle() const { return m180 == 0 && m20 == 0; }
};

struct Comp_00279978 {
    char pad0[0x34];
    Phys_00279978* m34;
};


struct Skater_00279978 {
    char pad0[0x50];
    Vec_00279978 m_pos;
    char pad60[0xB0 - 0x60];
    Vec_00279978 m_vel;
};

struct Data_00279978 {
    unsigned char m0;
    char pad1[0xF];
    Vec_00279978 m10;
};

struct Msg_00279978 {
    Data_00279978* m_data;
    unsigned char m_type;
    char pad5[0x1C - 0x5];
    Skater_00279978* m_skater;
};

extern void* D_00392068;
extern char D_00376A60[];

extern "C" void func_003315B8(void* p, int c, unsigned int n);
extern "C" Player_00279978* func_002A52F0(void* net, unsigned short id);
extern "C" void func_001E7528(Params_00279978* p, unsigned int crc, Vec_00279978* v);
extern "C" char* func_00206A08(Body_00279978* b);
extern "C" void func_00332088(char* dst, char* src, int n);
extern "C" void func_001E70C0(Params_00279978* p, unsigned int crc, char* s);
extern "C" void func_001E7360(Params_00279978* p, int a, unsigned int crc);
extern "C" void func_001848F0(Skater_00279978* s, unsigned int crc, Params_00279978* p);
extern "C" Comp_00279978* func_00185578(Skater_00279978* s, unsigned int crc);
extern "C" void func_0027C9E0(Comp_00279978* c, Body_00279978* b);
extern "C" void func_001BF0D8(Comp_00279978* c, Body_00279978* b);

int func_00279978(Msg_00279978* msg)
{
    Skater_00279978* sk = msg->m_skater;
    switch (msg->m_type) {
    case 0x44: {
        Data_00279978* d = msg->m_data;
        char name[32];
        memcpy(name, D_00376A60, 8);
        func_003315B8(name + 8, 0, 0x18);
        unsigned char id = d->m0;
        bool flag = id >> 7;
        id &= 0x7F;
        d->m0 = id;
        Player_00279978* p = func_002A52F0(D_00392068, id);
        if (p)
            func_00332088(name, func_00206A08(p->m_body), 0x20);
        Params_00279978 prm;
        func_001E70C0(&prm, 0xA4B08520, name);
        if (flag)
            func_001E7360(&prm, 0, 0x7FD0663D);
        func_001848F0(sk, 0xA1021AF0, &prm);
        break;
    }
    case 0x43: {
        Data_00279978* d = msg->m_data;
        char name[32];
        memcpy(name, D_00376A60, 8);
        func_003315B8(name + 8, 0, 0x18);
        unsigned char id = d->m0;
        bool flag = id >> 7;
        id &= 0x7F;
        d->m0 = id;
        Player_00279978* p = func_002A52F0(D_00392068, id);
        if (p) {
            Comp_00279978* c = func_00185578(sk, 0xD9151D4D);
            if (c->m34->m180 == 0) {
                Body_00279978* b = p->m_body;
                Vec_00279978 dir(sk->m_pos.x - b->m_pos.x, sk->m_pos.y - b->m_pos.y, sk->m_pos.z - b->m_pos.z, sk->m_pos.w - b->m_pos.w);
                dir.Normalize();
                sk->m_vel = dir * 300.0f * 1.5f;
                sk->m_vel.y = 200.0f;
                if (c->m34->Idle())
                    func_0027C9E0(func_00185578(sk, 0x5BD63B29), p->m_body);
                else
                    func_001BF0D8(func_00185578(sk, 0x726E85AA), p->m_body);
            }
            func_00332088(name, func_00206A08(p->m_body), 0x20);
        }
        Params_00279978 prm;
        func_001E70C0(&prm, 0xA4B08520, name);
        Vec_00279978 v = d->m10;
        func_001E7528(&prm, 0xA6F5352F, &v);
        if (flag)
            func_001E7360(&prm, 0, 0x2F679251);
        func_001848F0(sk, 0x915E5E39, &prm);
        break;
    }
    }
    return 1;
}
