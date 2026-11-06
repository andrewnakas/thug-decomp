/* sym: _vt$15ItBase_002582E0 = 0x00361AA0 */
/* sym: _vt$11It_002582E0 = 0x00375520 */

typedef int qword __attribute__((mode(TI)));

struct Vec_002582E0 {
    union {
        float col[4];
        qword q;
    };
    Vec_002582E0() {}
    Vec_002582E0(float ax, float ay, float az, float aw)
    {
        col[0] = ax;
        col[1] = ay;
        col[2] = az;
        col[3] = aw;
    }
    float& operator[](int i) { return col[i]; }
    const float& operator[](int i) const { return col[i]; }
    float LengthSqr() const { return col[0] * col[0] + col[1] * col[1] + col[2] * col[2]; }
};

static inline Vec_002582E0 operator-(const Vec_002582E0& a, const Vec_002582E0& b)
{
    return Vec_002582E0(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]);
}

struct ItBase_002582E0 {
    int m_0;
    int m_4;
    ItBase_002582E0() { m_4 = 0; }
    virtual void Reset();
    virtual ~ItBase_002582E0() {}
};

struct It_002582E0 : ItBase_002582E0 {
    It_002582E0() {}
    virtual void Reset();
    virtual ~It_002582E0() {}
};

struct Owner_002582E0 {
    char pad[0x2C];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void* GetList();
};

struct Obj_002582E0;
extern "C" Obj_002582E0* func_0018B0C0(It_002582E0* it, void* list, int type);
extern "C" Obj_002582E0* func_0018B148(It_002582E0* it);
extern "C" float sqrtf(float);

struct Obj_002582E0 {
    char pad0[0x10];
    Owner_002582E0* m_owner;
    char pad14[0x50 - 0x14];
    Vec_002582E0 m_pos;

    Obj_002582E0* Fn(int type);
};

Obj_002582E0* Obj_002582E0::Fn(int type)
{
    It_002582E0 it;
    Obj_002582E0* o = func_0018B0C0(&it, m_owner->GetList(), type);
    if (o == this && !(o = func_0018B148(&it))) return 0;
    if (!o) return 0;
    Obj_002582E0* r = o;
    float best = 5322672.0f;
    do {
        Vec_002582E0 d = o->m_pos - m_pos;
        float len = sqrtf(d.LengthSqr());
        if (o != this && len < best) {
            best = len;
            r = o;
        }
        o = func_0018B148(&it);
    } while (o);
    return r;
}
