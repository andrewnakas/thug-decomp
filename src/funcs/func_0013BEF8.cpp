extern int D_00393F04;
extern const char D_0035E4D8[];
extern char D_003C3910[];
extern "C" void func_00103F28(const void* msg);

void* func_0013BEF8()
{
    if (!D_00393F04) {
        D_00393F04 = 1;
    }
    func_00103F28(D_0035E4D8);
    return D_003C3910;
}
