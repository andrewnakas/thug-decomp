/* fuzzy: 71.8 */

typedef int qword __attribute__((mode(TI)));

struct Vec_00256E10 {
    union {
        float col[4];
        qword q;
    };
    Vec_00256E10() {}
    Vec_00256E10(float ax, float ay, float az, float aw)
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

static inline Vec_00256E10 operator-(const Vec_00256E10& a, const Vec_00256E10& b)
{
    return Vec_00256E10(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]);
}

struct Obj_00256E10;

extern char D_00361AA0[];

struct Node_00256E10 {
    int m0;
    Obj_00256E10* data;
    int m8;
    Node_00256E10* next;
    Obj_00256E10* GetData() { return data; }
    Node_00256E10* Valid(unsigned k = 0) { return k < ~(unsigned)data ? this : 0; }
};

struct It_00256E10 {
    int m0;
    Node_00256E10* cur;
    void* vt;
    It_00256E10() { vt = D_00361AA0; cur = 0; }
    ~It_00256E10() { vt = D_00361AA0; }
    Obj_00256E10* Next() {
        cur = cur->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Obj_00256E10* Advance(Node_00256E10* c) {
        cur = c->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Obj_00256E10* First(Node_00256E10* h) {
        cur = h;
        return Next();
    }
};

struct Owner_00256E10 {
    char pad[0x2C];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual Node_00256E10* GetList();
};

extern "C" int func_00229E30(void* p);
extern "C" int func_002577E0(Obj_00256E10* self, Obj_00256E10* o, void* filter);

struct Obj_00256E10 {
    char pad0[0x10];
    Owner_00256E10* m_owner;
    char pad14[4];
    int m18;
    char pad1C[0x50 - 0x1C];
    Vec_00256E10 m_pos;

    bool Fn(void* kind, int r, void* filter);
};

bool Obj_00256E10::Fn(void* kind, int r, void* filter)
{
    bool found = false;
    int type = func_00229E30(kind);
    It_00256E10 it;
    Obj_00256E10* o = it.First(m_owner->GetList());
    while (o) {
        Obj_00256E10* s = o;
        o = it.Next();
        if (s->m18 == type && s != this) {
            if (filter) {
                if (func_002577E0(this, s, filter))
                    found = true;
            } else {
                Vec_00256E10 d = s->m_pos - m_pos;
                if (d.LengthSqr() < (float)r)
                    found = true;
            }
        }
    }
    return found;
}
