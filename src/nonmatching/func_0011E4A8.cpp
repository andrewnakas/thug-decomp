/* fuzzy: 85.4 */
// Skeleton pose: builds each bone's matrix from its rotation and translation (or copies a fixed one),
// applies per-bone scale and the parent transform, then multiplies every bone by its inverse-bind matrix.

typedef int qword __attribute__((mode(TI)));

struct Vec_0011E4A8 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Mat_0011E4A8 {
    Vec_0011E4A8 row[4];
};

struct Bone_0011E4A8 {
    int m_00;
    Mat_0011E4A8* m_parent;
    int m_08;
    unsigned int m_flags;
    int m_10[4];
    Vec_0011E4A8 m_scale;
};

struct Skel_0011E4A8 {
    int m_00;
    Mat_0011E4A8* m_mats;
    char* m_data;
    int m_shift;
    int m_10;
    int m_count;
    Bone_0011E4A8* m_bones;
};

extern "C" void func_0011E278(const Vec_0011E4A8* rot, const Vec_0011E4A8* pos, Mat_0011E4A8* out, int a, int b);
extern "C" void func_00323318(Mat_0011E4A8* out, const Mat_0011E4A8* a, const Mat_0011E4A8* b);
extern "C" Mat_0011E4A8* func_0011F540(char* data);

// Single VU0 macro-mode operations (the vector unit has no C++ spelling).
static inline void LoadVF4(const Vec_0011E4A8* p)
{
    __asm__ __volatile__("lqc2 $vf4, 0(%0)" : : "r"(p));
}

static inline void LoadVF5(const Vec_0011E4A8* p)
{
    __asm__ __volatile__("lqc2 $vf5, 0(%0)" : : "r"(p));
}

static inline void MulVF6()
{
    __asm__ __volatile__("vmul.xyzw $vf6, $vf4, $vf5");
}

static inline void StoreVF6(Vec_0011E4A8* p)
{
    __asm__ __volatile__("sqc2 $vf6, 0(%0)" : : "r"(p) : "memory");
}

// dst = a * b, component by component, on VU0
static inline void Mul_0011E4A8(Vec_0011E4A8* dst, const Vec_0011E4A8* a, const Vec_0011E4A8* b)
{
    LoadVF4(a);
    LoadVF5(b);
    MulVF6();
    StoreVF6(dst);
}

static inline void ScaleRows_0011E4A8(Mat_0011E4A8* m, const Vec_0011E4A8* s)
{
    Vec_0011E4A8* r = m->row;
    Mul_0011E4A8(r, s, r);
    r++;
    Mul_0011E4A8(r, s, r);
    r++;
    Mul_0011E4A8(r, s, r);
    r++;
    Mul_0011E4A8(r, s, r);
}

static inline void Scale_0011E4A8(Vec_0011E4A8* v, float s)
{
    v->x *= s;
    v->y *= s;
    v->z *= s;
    v->w *= s;
}

extern "C" void func_0011E4A8(Skel_0011E4A8* self, const Vec_0011E4A8* rot, const Vec_0011E4A8* pos)
{
    int bit = 1 << self->m_shift;
    unsigned int* fixed = (unsigned int*)(self->m_data + 0x308);
    Bone_0011E4A8* bone = self->m_bones;
    Mat_0011E4A8* mat = self->m_mats;
    int i;
    for (i = 0; i < self->m_count; i++) {
        if (!(bone->m_flags & 0x40000000)) {
            if (!(fixed[i] & bit)) {
                func_0011E278(rot, pos, mat, 0, 0);
                if (bone->m_flags & 0x10000000) {
                    ScaleRows_0011E4A8(mat, &bone->m_scale);
                }
                if (i != 0) {
                    func_00323318(mat, bone->m_parent, mat);
                }
            } else {
                *mat = *bone->m_parent;
            }
        }
        mat++;
        bone++;
        rot++;
        pos++;
    }

    Mat_0011E4A8* inv = func_0011F540(self->m_data);
    bone = self->m_bones;
    mat = self->m_mats;
    for (i = 0; i < self->m_count; i++) {
        if (!(bone->m_flags & 0x40000000)) {
            if (bone->m_flags & 0x20000000) {
                Scale_0011E4A8(&mat->row[0], bone->m_scale.x);
                Scale_0011E4A8(&mat->row[1], bone->m_scale.y);
                Scale_0011E4A8(&mat->row[2], bone->m_scale.z);
            }
            Mat_0011E4A8 r;
            Mat_0011E4A8 t = *inv;
            func_00323318(&t, mat, &t);
            r = t;
            *mat = r;
            mat->row[0].w = 0.0f;
            mat->row[1].w = 0.0f;
            mat->row[2].w = 0.0f;
        }
        inv++;
        mat++;
        bone++;
    }
}
