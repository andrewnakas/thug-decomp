typedef int qword_00167A50 __attribute__((mode(TI)));

struct V_00167A50 {
    union {
        qword_00167A50 q;
        struct {
            float x, y, z, w;
        };
    };
    void Set(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    V_00167A50& operator=(const V_00167A50& o)
    {
        q = o.q;
        return *this;
    }
};

static inline void Swap_00167A50(float& a, float& b)
{
    float t = a;
    a = b;
    b = t;
}

struct M_00167A50 {
    V_00167A50 r[4];
    V_00167A50& operator[](int i) { return r[i]; }
    void Transpose()
    {
        Swap_00167A50(r[0].y, r[1].x);
        Swap_00167A50(r[0].z, r[2].x);
        Swap_00167A50(r[0].w, r[3].x);
        Swap_00167A50(r[1].z, r[2].y);
        Swap_00167A50(r[1].w, r[3].y);
        Swap_00167A50(r[2].w, r[3].z);
    }
};

struct LightDefaults_00167A50 {
    V_00167A50 dir[3];
    V_00167A50 color[3];
    V_00167A50 ambient;
};

extern LightDefaults_00167A50 D_003DD9F0;
extern char D_003E1080[];
extern "C" void func_00323318(void* out, void* a, void* b);

struct Lights_00167A50 {
    unsigned int flags;     /* 0x00 */
    char pad4[0xC];
    V_00167A50 dir[3];      /* 0x10 */
    char pad40[0x40];
    V_00167A50 color[3];    /* 0x80 */
    V_00167A50 ambient;     /* 0xB0 */
    const V_00167A50* GetDir(int i)
    {
        if (flags & (2 << i))
            return &dir[i];
        return &D_003DD9F0.dir[i];
    }
    const V_00167A50* GetColor(int i)
    {
        if (flags & (0x22 << i))
            return &color[i];
        return &D_003DD9F0.color[i];
    }
    const V_00167A50* GetAmbient()
    {
        if (flags & 0x11)
            return &ambient;
        return &D_003DD9F0.ambient;
    }
};

struct Obj_00167A50 {
    char pad0[0x54];
    Lights_00167A50* m_lights;          /* 0x54 */
    char pad58[0xF0 - 0x58];
    V_00167A50 m_lightRows[3];          /* 0xF0: the 4x4 product's last row lands on m_ambient */
    V_00167A50 m_ambient;               /* 0x120 */
    V_00167A50 m_color[3];              /* 0x130 */
    void UpdateLights();
};

/* colours are stored scaled by 1/128 */
static inline void SetColor(V_00167A50* dst, float x, float y, float z, float w)
{
    V_00167A50 s;
    V_00167A50 c;
    c.Set(x, y, z, w);
    s.x = c.x * (1.0f / 128.0f);
    s.y = c.y * (1.0f / 128.0f);
    s.z = c.z * (1.0f / 128.0f);
    s.w = c.w * (1.0f / 128.0f);
    *dst = s;
}

void Obj_00167A50::UpdateLights()
{
    M_00167A50 m;
    m[3].Set(0.0f, 0.0f, 0.0f, 1.0f);
    if (m_lights) {
        const V_00167A50* p;
        m[0] = *m_lights->GetDir(0);
        m[1] = *m_lights->GetDir(1);
        m[2] = *m_lights->GetDir(2);
        func_00323318(&m, D_003E1080, &m);
        m.Transpose();
        func_00323318(m_lightRows, &m, this);
        p = m_lights->GetAmbient();
        SetColor(&m_ambient, p->x, p->y, p->z, p->w);
        p = m_lights->GetColor(0);
        SetColor(&m_color[0], p->x, p->y, p->z, p->w);
        p = m_lights->GetColor(1);
        SetColor(&m_color[1], p->x, p->y, p->z, p->w);
        p = m_lights->GetColor(2);
        SetColor(&m_color[2], p->x, p->y, p->z, p->w);
    } else {
        m[0] = D_003DD9F0.dir[0];
        m[1] = D_003DD9F0.dir[1];
        m[2] = D_003DD9F0.dir[2];
        func_00323318(&m, D_003E1080, &m);
        m.Transpose();
        func_00323318(m_lightRows, &m, this);
        SetColor(&m_ambient, D_003DD9F0.ambient.x, D_003DD9F0.ambient.y, D_003DD9F0.ambient.z, D_003DD9F0.ambient.w);
        SetColor(&m_color[0], D_003DD9F0.color[0].x, D_003DD9F0.color[0].y, D_003DD9F0.color[0].z, D_003DD9F0.color[0].w);
        SetColor(&m_color[1], D_003DD9F0.color[1].x, D_003DD9F0.color[1].y, D_003DD9F0.color[1].z, D_003DD9F0.color[1].w);
        SetColor(&m_color[2], D_003DD9F0.color[2].x, D_003DD9F0.color[2].y, D_003DD9F0.color[2].z, D_003DD9F0.color[2].w);
    }
}
