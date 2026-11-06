extern "C" float func_0010FAB8();
extern "C" float func_001001B8(float target, float cur, float step);

struct Lerp_001A37A8 {
    char pad[8];
    float m8;
    float mC;
    char pad10[8];
    float m18;
    float m1C;
    float m20;
    float m24;
};

struct Obj_001A37A8 {
    void Method(Lerp_001A37A8* s);
};

static inline float Frames_001A37A8()
{
    return func_0010FAB8() * 60.0f;
}

void Obj_001A37A8::Method(Lerp_001A37A8* s)
{
    if (s->m18 != s->m8)
        s->m8 = func_001001B8(s->m18, s->m8, s->m20 * Frames_001A37A8());
    if (s->m1C != s->mC)
        s->mC = func_001001B8(s->m1C, s->mC, s->m24 * Frames_001A37A8());
}
