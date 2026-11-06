/* fuzzy: 88.0 */
extern "C" long func_0010FA98();
extern "C" float func_00341068(float x);   /* sinf */

struct Wave_001681B8 {
    float speed[2];      /* 0x00 */
    float freq[2];       /* 0x08 */
    float amp[2];        /* 0x10 */
    float phase[2];      /* 0x18 */
    float fixed[2];      /* 0x20 */
};

struct Obj_001681B8 {
    char pad[0x160];
    float offset[2];     /* 0x160 */
    void UpdateWave(Wave_001681B8* w, int stopped);
};

static inline float WrapAngle(float a)
{
    return a - (float)(int)(a * 0.15915494f) * 6.2831855f;
}

/* scrolling offset in [-8, 8): scroll * t + amplitude * sin(...), wrapped to 16 */
static inline float Scroll(float base, float amp, float s)
{
    float v = base + amp * s + 8.0f;
    return v - (float)(((int)v >> 4) << 4);
}

void Obj_001681B8::UpdateWave(Wave_001681B8* w, int stopped)
{
    if (stopped) {
        offset[0] = w->fixed[0];
        offset[1] = w->fixed[1];
        return;
    }
    float t = (float)(int)(func_0010FA98() & 0xFFFFFF) * (1.0f / 60.0f);
    float a0 = w->freq[0] * t;
    float b0 = w->speed[0] * t;
    float s0 = func_00341068(WrapAngle(a0 + w->phase[0]));
    offset[0] = Scroll(b0, w->amp[0], s0);
    if (offset[0] < 0.0f)
        offset[0] += 8.0f;
    else
        offset[0] -= 8.0f;
    float a1 = w->freq[1] * t;
    float b1 = w->speed[1] * t;
    float s1 = func_00341068(WrapAngle(a1 + w->phase[1]));
    offset[1] = Scroll(b1, w->amp[1], s1);
    if (offset[1] < 0.0f)
        offset[1] += 8.0f;
    else
        offset[1] -= 8.0f;
}
