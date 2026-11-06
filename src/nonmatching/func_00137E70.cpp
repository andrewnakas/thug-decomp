/* fuzzy: 51.3 */
struct Vec_00137E70 {
    float x, y, z, w;
};

extern char D_0035D968[];
extern int D_00393EDC;
extern Vec_00137E70 D_003C38B0;
extern "C" void func_00103F28(const char* msg);

extern "C" Vec_00137E70* func_00137E70()
{
    func_00103F28(D_0035D968);
    if (!D_00393EDC) {
        D_00393EDC = 1;
        D_003C38B0.x = 0.0f;
        D_003C38B0.y = 0.0f;
        D_003C38B0.z = 0.0f;
        D_003C38B0.w = 0.0f;
    }
    return &D_003C38B0;
}
