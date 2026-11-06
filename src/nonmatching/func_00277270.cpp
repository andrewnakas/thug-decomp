/* fuzzy: 86.4 */
/* NEAR MISS: op sequence identical except game has an extra dead `addiu $v1,$zero,0x14` after the %20 div-check (then a loop-alignment nop), size 0x4c8 vs 0x4d0; registers shift (game: entry ptr in s1, Time* in a1). */
extern void* D_00392068;

struct Entry_00277270 {
    signed char m_type;
    signed char m1;
    signed char m2;
    unsigned char m_flags;
    char pad4[0x4];
    int m8;
    int mC;
    int m10;
    float m14;
    float m18;
    float m1C;
    float m20;
    float m24;
    int m28;
    int m2C;
    float m30[5];
    int m44;
    int m48;
    int m4C;
    float m50;
    float m54;
    int m58;
};

struct Buf_00277270 {
    char pad0[0x1C];
    int m_count;
    char pad20[0xB40];
    int m_head;
    Entry_00277270 m_entries[20];
};

struct Vec_00277270 {
    float x, y, z, w;
    void Set(float a, float b, float c, float d)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }
};

struct Anim_00277270 {
    char pad0[0x30];
    Vec_00277270 m30;
};

struct Obj2_00277270 {
    char pad0[0x18];
    void* m18;
};

struct Base_00277270 {
    char pad0[0x18];
};

class Comp_00277270 : public Base_00277270 {
public:
    virtual void V0();
    virtual void V1();
    virtual void Run(void* params);
};

struct Time_00277270 {
    int m_now;
};

extern "C" Time_00277270* func_002A39E0(void* net, int a);
extern "C" unsigned int func_00279FA0(Entry_00277270* e);
extern "C" void func_001A0F78(void* comp, int anim, int a, int b, float c, float d, float e, float f);
extern "C" void func_001A12B8(void* comp, int a, float f);
extern "C" int func_002918E0(void* self, int a, int b, int c, int d);
extern "C" void func_001A1560(void* comp, float* v, int a);
extern "C" void func_001A1790(void* comp, int a, int b);
extern "C" void func_0018C230(void* comp, int a, int b, int c);
extern "C" void func_001A18C8(void* p, int a, int b, float c);
extern "C" void func_001A2610(void* a, int b, int c, int d, int e);
extern "C" unsigned int func_0010FC30();
extern "C" void func_0018DD00(void* p, unsigned int t, float c, float d, float e, int a, int b);
extern "C" void func_0018DCB0(void* p);
extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" void* func_001E5548(unsigned int key, int create);
extern "C" void* func_001B7128(void* self, int a, void* b);
extern "C" void func_001B7288(void* self, int slot);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E7360(void* params, unsigned int name, unsigned int value);
extern "C" void func_001E6AE8(void* p, int v);

class Player_00277270 {
public:
    char pad0[0xC];
    Obj2_00277270* m0C;
    char pad10[0xC];
    int m1C;
    unsigned int m20;
    unsigned int m24;
    char pad28[0x284];
    Buf_00277270* m2AC;
    char* m2B0;
    char* m2B4;
    char pad2B8[0x8];
    void* m2C0;
    void Update();
};

void Player_00277270::Update()
{
    Time_00277270* t = func_002A39E0(D_00392068, 0);
    if (!t)
        return;
    if (m2AC->m_count < 20)
        return;
    unsigned int end = m20 + (t->m_now - m1C);
    int start = m2AC->m_head % 20;
    int i = start;
    do {
        Entry_00277270* e = &m2AC->m_entries[i];
        if (m24 < func_00279FA0(e) && func_00279FA0(e) <= end) {
            switch (e->m_type) {
            case 0x29:
                func_001A0F78(m2B0, e->m28, 0, e->m2, e->m18, e->m1C, e->m20, e->m24);
                break;
            case 0x2B:
                func_001A12B8(m2B0, 0, e->m14);
                break;
            case 0x2A:
                func_002918E0(m2C0, e->m1, e->mC, 0, 0);
                break;
            case 0x3C: {
                float v[5];
                v[0] = e->m30[0];
                v[1] = e->m30[1];
                v[2] = e->m30[2];
                v[3] = e->m30[3];
                v[4] = e->m30[4];
                func_001A1560(m2B0, v, 0);
                break;
            }
            case 0x3D:
                func_001A1790(m2B0, e->m2, 0);
                break;
            case 0x3E:
                func_0018C230(m2B4, e->m28, e->m10, 0);
                break;
            case 0x41:
                func_001A18C8(m2B0, 0, 0, e->m24);
                break;
            case 0x2C:
                func_001A2610(m2B0, e->m1, e->m8, 0, 0);
                break;
            case 0x76: {
                ((Anim_00277270*)m2B4)->m30.Set(0.0f, 30.0f, 0.0f, 1.0f);
                unsigned int now = func_0010FC30();
                if (e->m_flags & 1)
                    func_0018DD00(m2B4 + 0x40, now, (float)e->m44, e->m50, e->m54, e->m48, e->m58);
                if (e->m_flags & 2)
                    func_0018DD00(m2B4 + 0xEC, now, (float)e->m44, e->m50, e->m54, e->m48, e->m58);
                if (e->m_flags & 4)
                    func_0018DD00(m2B4 + 0x198, now, (float)e->m44, e->m50, e->m54, e->m48, e->m58);
                break;
            }
            case -0x74:
                func_0018DCB0(m2B4 + 0x40);
                func_0018DCB0(m2B4 + 0xEC);
                func_0018DCB0(m2B4 + 0x198);
                break;
            case 0x77: {
                void* o = func_00185578(m0C, 0xF27A294D);
                o = func_001B7128(o, e->m4C, func_001E5548(e->m28, 1));
                void* params = func_001E6978(func_001190D0(8));
                func_001E7360(params, 0xCAB94088, e->m2C);
                func_001E7360(params, 0x40C698AF, (unsigned int)m0C->m18);
                ((Comp_00277270*)func_00185578(o, 0x5CB5CB7E))->Run(params);
                if (params)
                    func_001E6AE8(params, 3);
                break;
            }
            case 0x78:
                func_001B7288(func_00185578(m0C, 0xF27A294D), e->m4C);
                break;
            }
        }
        i = (i + 1) % 20;
    } while (i != start);
    m24 = end;
}
