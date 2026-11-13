/* fuzzy: 98.9 */
// Builds a scaled orientation matrix from a direction and the third row of a reference matrix
// (side = dir x up), moves it to pos + dir * offset and hands it to the attached object.

typedef int qword __attribute__((mode(TI)));

struct Vec_001154D0 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Mat_001154D0 {
    Vec_001154D0 row[4];
};

struct Obj_001154D0 {
    char pad00[0xC];
    void* m_target;
    float m_scale;
    float m_offset;
};

extern "C" void func_0013CD08(void* target, Mat_001154D0* m, int a, int b);

// Single VU0 macro-mode operations (the vector unit has no C++ spelling).
static inline void LoadVF4(const Vec_001154D0* p)
{
    __asm__ __volatile__("lqc2 $vf4, 0(%0)" : : "r"(p));
}

static inline void LoadVF5(const Vec_001154D0* p)
{
    __asm__ __volatile__("lqc2 $vf5, 0(%0)" : : "r"(p));
}

static inline void MulVF6()
{
    __asm__ __volatile__("vmul.xyzw $vf6, $vf4, $vf5");
}

static inline void StoreVF6(Vec_001154D0* p)
{
    __asm__ __volatile__("sqc2 $vf6, 0(%0)" : : "r"(p) : "memory");
}

// dst = a * b, component by component, on VU0
static inline void Mul_001154D0(Vec_001154D0* dst, const Vec_001154D0* a, const Vec_001154D0* b)
{
    LoadVF4(a);
    LoadVF5(b);
    MulVF6();
    StoreVF6(dst);
}

// every row of m multiplied by s, component by component
static inline void ScaleRows_001154D0(Mat_001154D0* m, Vec_001154D0* s)
{
    Mul_001154D0(&m->row[0], s, &m->row[0]);
    Mul_001154D0(&m->row[1], s, &m->row[1]);
    Mul_001154D0(&m->row[2], s, &m->row[2]);
    Mul_001154D0(&m->row[3], s, &m->row[3]);
}

extern "C" void func_001154D0(Obj_001154D0* self, const Vec_001154D0* pos, const Mat_001154D0* ref,
                              const Vec_001154D0* dir)
{
    Mat_001154D0 m;
    Vec_001154D0 v;
    m.row[1] = *dir;
    m.row[2] = ref->row[2];
    v.x = m.row[1].y * m.row[2].z - m.row[1].z * m.row[2].y;
    v.y = m.row[1].z * m.row[2].x - m.row[1].x * m.row[2].z;
    v.z = m.row[1].x * m.row[2].y - m.row[1].y * m.row[2].x;
    v.w = 0.0f;
    m.row[0] = v;
    float s = self->m_scale;
    v.x = s;
    v.y = s;
    v.z = s;
    Vec_001154D0* sv = &v;  // game: w is stored through a register copy of &v (swc1 $f9, 0xC($v1))
    sv->w = 1.0f;
    ScaleRows_001154D0(&m, &v);
    float k = self->m_offset;
    Vec_001154D0 p;
    Vec_001154D0 d;
    d.x = dir->x * k;
    d.y = dir->y * k;
    d.z = dir->z * k;
    d.w = dir->w * k;
    p.x = pos->x + d.x;
    p.y = pos->y + d.y;
    p.z = pos->z + d.z;
    p.w = pos->w + d.w;
    m.row[3] = p;
    if (self->m_target) {
        func_0013CD08(self->m_target, &m, 1, 0);
    }
}
