/* fuzzy: 96.6 */
// Updates the object from its component's three parameters and, unless the component says to keep it,
// resets the object's matrix to identity with its rotation part scaled to zero.

typedef int qword __attribute__((mode(TI)));

struct Vec_00267538 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Mat_00267538 {
    Vec_00267538 row[4];
};

struct Comp_00267538 {
    char pad00[0x1C];
    float m_1C;
    float m_20;
    char pad24[0x28 - 0x24];
    float m_28;
    char pad2C[0x48 - 0x2C];
    int m_keep;
};

extern "C" void* func_00256BA0(void* self);
extern "C" void* func_00256BD8(void* self);
extern "C" Comp_00267538* func_00185578(void* self, unsigned int crc);
extern "C" void func_00267270(void* a, void* b, float x, float y, float z);
extern "C" Mat_00267538* func_0011D9E0(void* a);

// Single VU0 macro-mode operations (the vector unit has no C++ spelling).
static inline void LoadVF4(const Vec_00267538* p)
{
    __asm__ __volatile__("lqc2 $vf4, 0(%0)" : : "r"(p));
}

static inline void LoadVF5(const Vec_00267538* p)
{
    __asm__ __volatile__("lqc2 $vf5, 0(%0)" : : "r"(p));
}

static inline void MulVF6()
{
    __asm__ __volatile__("vmul.xyzw $vf6, $vf4, $vf5");
}

static inline void StoreVF6(Vec_00267538* p)
{
    __asm__ __volatile__("sqc2 $vf6, 0(%0)" : : "r"(p) : "memory");
}

// dst = a * b, component by component, on VU0
static inline void Mul_00267538(Vec_00267538* dst, const Vec_00267538* a, const Vec_00267538* b)
{
    LoadVF4(a);
    LoadVF5(b);
    MulVF6();
    StoreVF6(dst);
}

// every row of m multiplied by (s.x, s.y, s.z, 1), component by component
static inline void ScaleRows_00267538(Mat_00267538* m, Vec_00267538* s)
{
    s->w = 1.0f;
    Mul_00267538(&m->row[0], s, &m->row[0]);
    Mul_00267538(&m->row[1], s, &m->row[1]);
    Mul_00267538(&m->row[2], s, &m->row[2]);
    Mul_00267538(&m->row[3], s, &m->row[3]);
}

extern "C" void func_00267538(void* self)
{
    void* a = func_00256BA0(self);
    void* b = func_00256BD8(self);
    Comp_00267538* c0 = func_00185578(self, 0xC695136D);
    Comp_00267538* c1 = func_00185578(self, 0xC695136D);
    Comp_00267538* c2 = func_00185578(self, 0xC695136D);
    func_00267270(a, b, c0->m_28, c1->m_1C, c2->m_20);
    if (func_00185578(self, 0xC695136D)->m_keep == 0) {
        Mat_00267538 m;
        Vec_00267538 s;
        m.row[0].x = 1.0f;
        m.row[0].y = 0.0f;
        m.row[0].z = 0.0f;
        m.row[0].w = 0.0f;
        m.row[1].x = 0.0f;
        m.row[1].y = 1.0f;
        m.row[1].z = 0.0f;
        m.row[1].w = 0.0f;
        m.row[2].x = 0.0f;
        m.row[2].y = 0.0f;
        m.row[2].z = 1.0f;
        m.row[2].w = 0.0f;
        m.row[3].x = 0.0f;
        m.row[3].y = 0.0f;
        m.row[3].z = 0.0f;
        m.row[3].w = 1.0f;
        s.x = 0.0f;
        s.y = 0.0f;
        s.z = 0.0f;
        ScaleRows_00267538(&m, &s);
        *func_0011D9E0(func_00256BA0(self)) = m;
    }
}
