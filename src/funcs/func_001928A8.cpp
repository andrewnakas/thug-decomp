struct Vec_001928A8 {
    float x, y, z, w;
};


extern void* D_00388A70;
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void func_0010A8D8(void* heap, void* p);

struct Corner_001928A8 {
    Vec_001928A8 v;
    char m10[0x10];
    unsigned char m20;
    char pad21[0xF];
    Corner_001928A8() {}
    static void* operator new[](unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
};

static inline void SetFlip_001928A8(Vec_001928A8& d, float v, bool b)
{
    if (b) v = -v;
    d.z = v;
}

struct Box_001928A8 {
    char pad0[0x50];
    Corner_001928A8* m50;
    unsigned short m54;
    void BuildWedge(Vec_001928A8* s);
};

void Box_001928A8::BuildWedge(Vec_001928A8* s)
{
    m54 = 6;
    if (m50) func_0010A8D8(D_00388A70, m50);
    m50 = new Corner_001928A8[m54];
    int n = 0;
    bool b = false;
    do {
        m50[n].v.x = s->x;
        m50[n].v.y = -s->y;
        SetFlip_001928A8(m50[n].v, s->z, b);
        m50[n].v.w = 1.0f;
        m50[n].m20 = 0;
        n++;
        m50[n].v.x = -s->x;
        m50[n].v.y = -s->y;
        SetFlip_001928A8(m50[n].v, s->z, b);
        m50[n].v.w = 1.0f;
        m50[n].m20 = 0;
        n++;
        m50[n].v.x = 0.0f;
        m50[n].v.y = s->y;
        SetFlip_001928A8(m50[n].v, s->z, b);
        m50[n].v.w = 1.0f;
        m50[n].m20 = 0;
        n++;
        b = !b;
    } while (b);
}
