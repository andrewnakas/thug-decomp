extern "C" int func_00215EE0(int a, int b);
extern "C" float func_0022E060(int a, int b);
extern int D_0038FC78;

struct Obj_00203A90 {
    char pad0[0x18];
    int m_18;
    char pad1C[0x2F0 - 0x1C];
    float m_vals[4];
    void Set(int i, float v);
};

void Obj_00203A90::Set(int i, float v)
{
    if (func_00215EE0(0, 0)) {
        v += func_0022E060(D_0038FC78, m_18);
        if (v > 10.0f) {
            v = 10.0f;
        }
        if (v < 0.0f) {
            v = 0.0f;
        }
    }
    m_vals[i] = v;
}
