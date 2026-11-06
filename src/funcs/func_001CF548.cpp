struct Skater_001CF548 {
    char pad0[0x1370];
    float m_speed;
    char pad1374[0x1388 - 0x1374];
    void* m_obj;
};

struct Comp_001CF548 {
    char pad0[0x2C];
    void* m_params;
    char pad30[0xB4 - 0x30];
    int m_last_time;
    Skater_001CF548* m_skater;
    void* m_sound;
    void Update();
};

extern "C" int func_0010FC30();
extern "C" float func_001CF8E0(Comp_001CF548* c, unsigned int name);
extern "C" float func_001CF8B8(Comp_001CF548* c, unsigned int name);
extern "C" void func_001E72B0(void* s, unsigned int name, float value);
extern "C" void func_001A3208(void* sound, void* params);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001848F0(void* obj, unsigned int name, void* params);
extern "C" void func_001E6AE8(void* s, int flags);

static inline float Clamp_001CF548(float v, float lo, float hi)
{
    float r;
    if (v > hi)
        r = hi;
    else
        r = v;
    if (r < lo)
        r = lo;
    return r;
}

void Comp_001CF548::Update()
{
    int last = m_last_time;
    float elapsed = (float)(unsigned int)(func_0010FC30() - last);
    if (elapsed < func_001CF8E0(this, 0x71B4B9FE)) {
        return;
    }
    float ratio = m_skater->m_speed / func_001CF8B8(this, 0xCEA59D0B);
    if (func_001CF8E0(this, 0xF6981837) < ratio) {
        func_001E72B0(m_params, 0x9E497FC6, ratio * 100.0f);
        func_001A3208(m_sound, m_params);
        m_last_time = func_0010FC30();
        void* s = func_001E6978(func_001190D0(8));
        func_001E72B0(s, 0x29461E27, Clamp_001CF548(ratio, 0.0f, 1.0f));
        func_001848F0(m_skater->m_obj, 0xC4A60423, s);
        if (s) {
            func_001E6AE8(s, 3);
        }
    }
}
