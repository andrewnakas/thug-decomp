extern int D_00393F00;
extern const char D_0035E498[];
extern char D_003C3900[];
extern "C" void func_00103F28(const void* msg);

void* func_0013BEA0()
{
    if (!D_00393F00) {
        D_00393F00 = 1;
    }
    func_00103F28(D_0035E498);
    return D_003C3900;
}
