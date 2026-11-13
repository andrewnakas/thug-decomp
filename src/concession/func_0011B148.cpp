/* force: {"kind": "sched", "pass": 2, "block": 0, "clock": 17, "first": [32, 58]} */
/* blocked: sched1 priority difference (scale load prio 30 vs 42) feeding a sched2 luid tie; forced = MATCH (oracle) */
struct Anim_0011B148 {
    char pad0[0x18];
    float m_start;
    float pad1C;
    float m_end;
};

struct Wobble_0011B148 {
    int m_0;
    Anim_0011B148* m_anim;
    char pad8[0x18 - 0x8];
    float m_amp0;
    float m_amp1;
    float m_freq0;
    float m_freq1;
    float m_scale;
    float m_cur;
};

extern "C" int func_0010FC30();
extern "C" float func_00341068(float a);

extern "C" float func_0011B148(Wobble_0011B148* w)
{
    float cur = w->m_cur;
    float start = w->m_anim->m_start;
    float end = w->m_anim->m_end;
    float s = (w->m_scale - 1.0f) * __builtin_fabsf(cur - (end + start) * 0.5f) / ((end - start) * 0.5f) + 1.0f;
    float a0 = w->m_amp0;
    float a1 = w->m_amp1;
    float f0 = w->m_freq0;
    float f1 = w->m_freq1;
    a0 *= s;
    a1 *= s;
    if (cur - a0 - a1 < start) {
        cur = start + a0 + a1;
    }
    if (end < cur + a0 + a1) {
        cur = end - a0 - a1;
    }
    float t = (float)func_0010FC30() * f0;
    t = t - (float)(int)t;
    float v = a0 + a1 * func_00341068((t + t) * 3.14159274f);
    t = (float)func_0010FC30() * f1;
    t = t - (float)(int)t;
    v *= func_00341068((t + t) * 3.14159274f);
    cur += v;
    if (cur < w->m_anim->m_start) {
        cur = w->m_anim->m_start;
    }
    if (w->m_anim->m_end < cur) {
        cur = w->m_anim->m_end;
    }
    return cur;
}
