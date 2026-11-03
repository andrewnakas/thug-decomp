extern int D_00393F08;
extern const char D_0035E528[];
extern char D_003C3950[];
extern "C" void func_00103F28(const void* msg);

void* func_0013BF70()
{
    if (!D_00393F08) {
        D_00393F08 = 1;
    }
    func_00103F28(D_0035E528);
    return D_003C3950;
}
