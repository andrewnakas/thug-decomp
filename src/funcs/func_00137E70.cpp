struct Vec_00137E70 {
    float x, y, z, w;
};

extern char D_0035D968[];
extern int D_00393EDC;
extern Vec_00137E70 D_003C38B0;
extern "C" int func_00103F28(const char* fmt, ...);

extern "C" Vec_00137E70* func_00137E70()
{
    func_00103F28(D_0035D968);
    if (!D_00393EDC) {
        D_00393EDC = 1;
        float zero = 0.0f;
        D_003C38B0.x = zero;
        D_003C38B0.y = zero;
        D_003C38B0.z = zero;
        D_003C38B0.w = zero;
    }
    return &D_003C38B0;
}
