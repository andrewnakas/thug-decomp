/* fuzzy: 95.0 */
struct Vec_00137E70 {
    float x, y, z, w;
    void Set(float a, float b, float c, float d)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }
};

extern char D_0035D968[];
extern int D_00393EDC;
extern Vec_00137E70 D_003C38B0;
extern "C" void func_00103F28(const char* fmt, ...);

extern "C" Vec_00137E70* func_00137E70()
{
    func_00103F28(D_0035D968);
    if (!D_00393EDC) {
        D_00393EDC = 1;
        D_003C38B0.Set(0.0f, 0.0f, 0.0f, 0.0f);
    }
    return &D_003C38B0;
}
