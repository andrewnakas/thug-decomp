/* fuzzy: 61.8 */
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern void* D_00388A70;
extern void* D_0038A630;

struct Rgba_00143690 {
    unsigned char r, g, b, a;
    Rgba_00143690(const Rgba_00143690& o) { *this = o; }
};

struct Fx_00143690 {
    int m0;
    Rgba_00143690 m4;
    Rgba_00143690 m8;
    int mC;
    int m10;
    float m14;
    float m18;
    float m1C;
    int m20;
    Fx_00143690(int id, Rgba_00143690 a, Rgba_00143690 b, int n, float t, float u)
        : m4(a), m8(b)
    {
        m18 = t;
        m1C = u;
        m10 = n;
        m0 = id;
        m14 = t;
        m20 = 0;
    }
    static void* operator new(unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
};

extern "C" void func_001447F8(void* table, Fx_00143690** key, Fx_00143690* fx);

extern "C" void func_00143690(int id, Rgba_00143690 a, Rgba_00143690 b, int n, float t, float u)
{
    Fx_00143690* fx = new Fx_00143690(id, a, b, n, t, u);
    func_001447F8(D_0038A630, &fx, fx);
}
