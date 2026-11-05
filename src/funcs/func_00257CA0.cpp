/* sym: _vt$15ItBase_00257CA0 = 0x00361AA0 */
/* sym: _vt$11It_00257CA0 = 0x00375520 */

typedef int qword __attribute__((mode(TI)));

struct Vec_00257CA0 {
    union {
        float col[4];
        qword q;
    };
    Vec_00257CA0() {}
    Vec_00257CA0(float ax, float ay, float az, float aw)
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

static inline Vec_00257CA0 operator-(const Vec_00257CA0& a, const Vec_00257CA0& b)
{
    return Vec_00257CA0(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]);
}

struct ItBase_00257CA0 {
    int m_0;
    int m_4;
    ItBase_00257CA0() { m_4 = 0; }
    virtual void Reset();
    virtual ~ItBase_00257CA0() {}
};

struct It_00257CA0 : ItBase_00257CA0 {
    It_00257CA0() {}
    virtual void Reset();
    virtual ~It_00257CA0() {}
};

struct Owner_00257CA0 {
    char pad[0x2C];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void* GetList();
};

struct Obj_00257CA0;
extern "C" Obj_00257CA0* func_0018B0C0(It_00257CA0* it, void* list, int type);
extern "C" Obj_00257CA0* func_0018B148(It_00257CA0* it);
extern "C" int func_002577E0(Obj_00257CA0* self, Obj_00257CA0* o, void* filter);
extern "C" bool func_00257B58(Obj_00257CA0* self, void* filter, float r);

struct Obj_00257CA0 {
    char pad0[0x10];
    Owner_00257CA0* m_owner;
    char pad14[0x50 - 0x14];
    Vec_00257CA0 m_pos;

    bool AnyNear(int a, int b, float r, void* filter, unsigned int kind);
};

bool Obj_00257CA0::AnyNear(int a, int b, float r, void* filter, unsigned int kind)
{
    It_00257CA0 it;
    int type;
    switch (kind) {
    case 0x88C21962:
        type = 3;
        break;
    case 0x061A741E:
        type = 2;
        break;
    case 0x5B8AB877:
        return func_00257B58(this, filter, r);
    case 0x3B5737A6:
        type = 4;
        break;
    default:
        return false;
    }
    for (Obj_00257CA0* o = func_0018B0C0(&it, m_owner->GetList(), type); o; o = func_0018B148(&it)) {
        if (o == this) {
            continue;
        }
        if (filter) {
            if (func_002577E0(this, o, filter)) {
                return true;
            }
        } else {
            Vec_00257CA0 d = o->m_pos - m_pos;
            if (d.LengthSqr() < r) {
                return true;
            }
        }
    }
    return false;
}
