struct Info_00203868 {
    char pad0[0x6C];
    int m6C;
};

struct Holder_00203868 {
    char pad0[0x1C];
    Info_00203868* m1C;
};

struct Game_00203868 {
    char pad0[0x24];
    void* m24;
    char pad28[0x464 - 0x28];
    float m464;
};

extern Game_00203868* D_0038FC78;
extern void* D_00392068;

extern "C" float func_002032A0(unsigned int crc, int a);
extern "C" void* func_00203300(unsigned int crc, int a);
extern "C" int func_002A19A8(void* net);
extern "C" void* func_002A52F0(void* net, unsigned short id);
extern "C" int func_002B2F30(void* p);
extern "C" int func_002B22B8(void* p);
extern "C" int func_00215EE0(int a, int b);
extern "C" int func_00263BD8(void* a, void* b);

struct Self_00203868 {
    char pad0[0x18];
    unsigned short m_id;
    char pad1A[0x2D8 - 0x1A];
    Holder_00203868* m2D8;
    char pad2DC[0x2F0 - 0x2DC];
    float m_speeds[1];

    float NetSpeed(float v)
    {
        if (func_002A19A8(D_00392068)) {
            void* p = func_002A52F0(D_00392068, m_id);
            if (p) {
                if (!func_002B2F30(p)) {
                    v = 10.0f;
                    if (func_002B22B8(p))
                        v = 6.0f;
                } else {
                    v = 1.0f;
                }
            } else {
                v = 10.0f;
            }
        } else if (func_00215EE0(0, 0)) {
            void* p = func_002A52F0(D_00392068, m_id);
            if (p && func_002B2F30(p))
                v = 1.0f;
        }
        return v;
    }

    float GetSpeed(int idx);
};

float Self_00203868::GetSpeed(int idx)
{
    float v;
    float t = D_0038FC78->m464;
    if (t == 0.0f && (t = m_speeds[idx]) == -1.0f)
        v = func_002032A0(0x6357D57C, 0);
    else
        v = t;
    v = NetSpeed(v);
    v = NetSpeed(v);
    void* g = D_0038FC78->m24;
    if (func_00263BD8(g, func_00203300(0x6B0F24BC, 0)))
        v = 15.0f;
    if (m2D8->m1C->m6C)
        v += 3.0f;
    return v;
}
