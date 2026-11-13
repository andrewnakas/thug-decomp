/* fuzzy: 50.7 */
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

struct M_00167A50 {
    V_00167A50 r[4];
    void Transpose()
    {
        float a = r[0].y, b = r[0].z, c = r[0].w;
        float d = r[1].z, e = r[1].w, f = r[2].w;
        r[0].y = r[1].x; r[1].x = a;
        r[0].z = r[2].x; r[2].x = b;
        r[0].w = r[3].x; r[3].x = c;
        r[1].z = r[2].y; r[2].y = d;
        r[1].w = r[3].y; r[3].y = e;
        r[2].w = r[3].z; r[3].z = f;
    }
};

struct Lights_00167A50 {
    unsigned int flags;     /* 0x00 */
    char pad4[0xC];
    V_00167A50 dir[3];      /* 0x10 */
    char pad40[0x40];
    V_00167A50 color[3];    /* 0x80 */
    V_00167A50 ambient;     /* 0xB0 */
};

struct LightDefaults_00167A50 {
    V_00167A50 dir[3];
    V_00167A50 color[3];
    V_00167A50 ambient;
};

extern LightDefaults_00167A50 D_003DD9F0;
extern char D_003E1080[];
extern "C" void func_00323318(void* out, void* a, void* b);

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
static inline void SetColor(V_00167A50* dst, const V_00167A50* src)
{
    V_00167A50 s;
    V_00167A50 c;
    c.x = src->x;
    c.y = src->y;
    c.z = src->z;
    c.w = src->w;
    s.x = c.x * (1.0f / 128.0f);
    s.y = c.y * (1.0f / 128.0f);
    s.z = c.z * (1.0f / 128.0f);
    s.w = c.w * (1.0f / 128.0f);
    *dst = s;
}

void Obj_00167A50::UpdateLights()
{
    M_00167A50 m;
    m.r[3].Set(0.0f, 0.0f, 0.0f, 1.0f);
    if (m_lights) {
        m.r[0] = *((m_lights->flags & 2) ? &m_lights->dir[0] : &D_003DD9F0.dir[0]);
        m.r[1] = *((m_lights->flags & 4) ? &m_lights->dir[1] : &D_003DD9F0.dir[1]);
        m.r[2] = *((m_lights->flags & 8) ? &m_lights->dir[2] : &D_003DD9F0.dir[2]);
        func_00323318(&m, D_003E1080, &m);
        m.Transpose();
        func_00323318(m_lightRows, &m, this);
        SetColor(&m_ambient, (m_lights->flags & 0x11) ? &m_lights->ambient : &D_003DD9F0.ambient);
        SetColor(&m_color[0], (m_lights->flags & 0x22) ? &m_lights->color[0] : &D_003DD9F0.color[0]);
        SetColor(&m_color[1], (m_lights->flags & 0x44) ? &m_lights->color[1] : &D_003DD9F0.color[1]);
        SetColor(&m_color[2], (m_lights->flags & 0x88) ? &m_lights->color[2] : &D_003DD9F0.color[2]);
    } else {
        m.r[0] = D_003DD9F0.dir[0];
        m.r[1] = D_003DD9F0.dir[1];
        m.r[2] = D_003DD9F0.dir[2];
        func_00323318(&m, D_003E1080, &m);
        m.Transpose();
        func_00323318(m_lightRows, &m, this);
        SetColor(&m_ambient, &D_003DD9F0.ambient);
        SetColor(&m_color[0], &D_003DD9F0.color[0]);
        SetColor(&m_color[1], &D_003DD9F0.color[1]);
        SetColor(&m_color[2], &D_003DD9F0.color[2]);
    }
}
