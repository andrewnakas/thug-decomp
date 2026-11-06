typedef int qword __attribute__((mode(TI)));
extern "C" float sqrtf(float);

struct Vec_0014DFA8 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
    Vec_0014DFA8() {}
    Vec_0014DFA8(float ax, float ay, float az) { x = ax; y = ay; z = az; }
    float Length() const { return sqrtf(x * x + y * y + z * z); }
};

struct Obj_0014DFA8 {
    char pad0[0x30];
    Vec_0014DFA8 m30[4];
    Vec_0014DFA8 Fn() const;
};

Vec_0014DFA8 Obj_0014DFA8::Fn() const
{
    const Vec_0014DFA8& a = m30[0];
    const Vec_0014DFA8& b = m30[1];
    const Vec_0014DFA8& c = m30[2];
    Vec_0014DFA8 r(a.Length(), b.Length(), c.Length());
    return r;
}
