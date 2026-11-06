typedef int qword_001CAC08 __attribute__((mode(TI)));

struct Vec_001CAC08 {
    union {
        qword_001CAC08 q;
        float c[4];
    };
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
};

static inline void Sub_001CAC08(Vec_001CAC08& r, const Vec_001CAC08& a, const Vec_001CAC08& b)
{
    r[0] = a[0] - b[0];
    r[1] = a[1] - b[1];
    r[2] = a[2] - b[2];
    r[3] = a[3] - b[3];
}

struct Node_001CAC08 {
    char pad0[0x50];
    Node_001CAC08* m50;
    Node_001CAC08* m54;
    unsigned int m58;
};

extern char D_00363660[];
extern char D_0036367F[];
extern char D_003636A0[];
extern char D_003636C0[];

extern "C" void func_00103F28(const char* fmt, ...);
extern "C" void func_0026B1B0(Vec_001CAC08* out, void* rail, Node_001CAC08* n);
extern "C" void func_003233B8(Vec_001CAC08* out, Vec_001CAC08* in);
extern "C" int func_001CB7B8(Node_001CAC08* n, int a);
extern "C" bool func_0026A968(Vec_001CAC08* a, Vec_001CAC08* b);
extern "C" bool func_0026A0D0(void* rail, Node_001CAC08* n, int a, Node_001CAC08** out);
extern "C" bool func_0026A058(void* rail, Node_001CAC08* n, Node_001CAC08* ref);

struct Obj_001CAC08 {
    char pad0[0xA24];
    void* mA24;
    bool NextSegment(float* t, Node_001CAC08* a, Node_001CAC08* b, Node_001CAC08** pa, Node_001CAC08** pb);
};

bool Obj_001CAC08::NextSegment(float* t, Node_001CAC08* a, Node_001CAC08* b, Node_001CAC08** pa,
                               Node_001CAC08** pb)
{
    Node_001CAC08* found = 0;
    Vec_001CAC08 v0;
    Vec_001CAC08 v1;
    if (*t < 0.0f) {
        if (a->m54 && func_001CB7B8(a->m54, 2) && !(a->m54->m58 & 8)) {
            func_0026B1B0(&v0, mA24, a->m54);
            func_0026B1B0(&v1, mA24, a);
            if (func_0026A968(&v0, &v1)) {
                *pb = a;
                *pa = a->m54;
                return true;
            }
        }
        if (!func_0026A0D0(mA24, a, 0x28, &found)) {
            return false;
        }
    } else {
        if (b->m50 && func_001CB7B8(b, 2) && !(b->m58 & 8)) {
            func_0026B1B0(&v0, mA24, b);
            func_0026B1B0(&v1, mA24, b->m50);
            if (func_0026A968(&v0, &v1)) {
                *pa = b;
                *pb = b->m50;
                return true;
            }
        }
        if (!func_0026A0D0(mA24, b, 0x28, &found)) {
            return false;
        }
    }
    int fwd = 0;
    if (func_0026A058(mA24, found, b) || func_0026A058(mA24, found->m50, a)) {
        fwd = 1;
    }
    Vec_001CAC08 p1;
    Vec_001CAC08 p2;
    func_0026B1B0(&p1, mA24, b);
    func_0026B1B0(&p2, mA24, a);
    Sub_001CAC08(v1, p1, p2);
    func_003233B8(&v1, &v1);
    v0 = v1;
    Vec_001CAC08 p3;
    func_0026B1B0(&p2, mA24, found->m50);
    func_0026B1B0(&p3, mA24, found);
    Sub_001CAC08(p1, p2, p3);
    func_003233B8(&p1, &p1);
    v1 = p1;
    if (!fwd) {
        v1[0] = -v1[0];
        v1[1] = -v1[1];
        v1[2] = -v1[2];
        v1[3] = -v1[3];
    }
    if (v0[0] * v1[0] + v0[1] * v1[1] + v0[2] * v1[2] < -0.8659999967f) {
        func_00103F28(D_00363660, D_0036367F, 0x4DB, D_003636A0);
        return false;
    }
    if (!fwd) {
        *t = 1.0f - *t;
    }
    *pa = found;
    *pb = found->m50;
    func_00103F28(D_00363660, D_0036367F, 0x4E5, D_003636C0);
    return true;
}
