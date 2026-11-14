/* fuzzy: 94.4 */
/* blocked (lane2 b3): game computes the tilt target into $f1 in both arms (if/else, bc1fl) and copies it with mov.s $f3,$f1 at 0x1CE410. if/else or ternary gets the branch shape but no copy (size -4); the copy appears only if Approach assigns its target parameter (non-readonly inline parm), which then drops the eps reload in the pan call. Inline returning the target, v*=k in both arms: no copy. */
struct Button_001CE2E8 {
    char pad[0x14];
    int m_pressed;
};

struct Pad_001CE2E8 {
    char pad0[0x148];
    Button_001CE2E8 m_toggle;
    char pad160[0x220 - 0x160];
    Button_001CE2E8 m_reset;
    char pad238[0x254 - 0x238];
    float m_stickX;
    float m_stickY;
};

struct Input_001CE2E8 {
    char pad0[0x24];
    Pad_001CE2E8 m_pad1;
    char pad[0x2A0 - 0x24 - sizeof(Pad_001CE2E8)];
    Pad_001CE2E8 m_pad2;
};

struct Owner_001CE2E8 {
    char pad[0x18];
    unsigned int m_type;
};

struct Cam_001CE2E8 {
    char pad0[0xC];
    Owner_001CE2E8* m_owner;
    char pad10[0x1C - 0x10];
    bool m_free;
    int m_lerping;
    char pad24[4];
    float m_tilt;
    float m_pan;
    char pad30[4];
    float m_tiltTarget;
    float m_panTarget;
    float m_tiltRate;
    float m_panRate;
    float m_time;
    Input_001CE2E8* m_input;
    void Update();
};

extern char D_00363750[];

extern "C" int func_001E5628(unsigned int key, int a);
extern "C" void func_00103F28(const char* fmt, ...);
extern "C" void func_0026FDC8(Button_001CE2E8* b);
extern "C" void func_001F0210(unsigned int name, void* params, int a, int b, int c);
extern "C" float func_0010FAB8();

static inline void Approach_001CE2E8(float& cur, float target, float dt)
{
    float d = target - cur;
    if (__builtin_fabsf(d) > 0.001f) {
        float r = dt * 3.75f;
        cur = cur + d * r;
    } else {
        cur = target;
    }
}

void Cam_001CE2E8::Update()
{
    Pad_001CE2E8* pad;
    if (func_001E5628(0x702247A5, 0)) {
        pad = &m_input->m_pad2;
    } else {
        pad = &m_input->m_pad1;
    }
    if (!func_001E5628(0xF3E055E1, 1)) {
        Button_001CE2E8* b = &pad->m_reset;
        if (b->m_pressed) {
            func_00103F28(D_00363750);
            func_0026FDC8(b);
            if (m_owner->m_type == 0x967C138C) {
                func_001F0210(0x60871393, 0, 0, 0, 0);
            } else {
                func_001F0210(0xA1B1146D, 0, 0, 0, 0);
            }
        }
    }
    Button_001CE2E8* t = &pad->m_toggle;
    if (t->m_pressed) {
        m_free = !m_free;
        func_0026FDC8(t);
    }
    float dt = func_0010FAB8();
    if (!m_free && !m_lerping) {
        float v = pad->m_stickY;
        float target = v * -0.7f;
        if (v < 0.0f) {
            target = v * -0.97999996f;
        }
        Approach_001CE2E8(m_tilt, target, dt);
        Approach_001CE2E8(m_pan, pad->m_stickX * 3.0f, dt);
    }
    float dt2 = func_0010FAB8();
    if (m_lerping && m_time > 0.0f) {
        if (dt2 < m_time) {
            m_time -= dt2;
            m_pan += m_panRate * dt2;
            m_tilt += m_tiltRate * dt2;
        } else {
            m_pan = m_panTarget;
            m_tilt = m_tiltTarget;
            m_time = 0.0f;
        }
    }
}
