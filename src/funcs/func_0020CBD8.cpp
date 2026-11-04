extern char D_0038F380[];
extern char D_00370010[];
extern char D_00370028[];
extern char D_00370040[];
extern char D_00370060[];
extern char D_00370078[];
extern char D_00370090[];
extern char D_003700A8[];
extern char D_0038F388[];
extern char D_0038F390[];
extern int D_00388830;
extern int D_0038881C;
extern int D_00388818;

extern "C" int func_00103F28(const char* fmt, ...);
extern "C" const char* func_00106930();
extern "C" const char* func_001069B0();
extern "C" const char* func_00106838();
extern "C" const char* func_001068D0();

bool Cmd_0020CBD8(void* params, void* script)
{
    func_00103F28(D_0038F380);
    func_00103F28(D_00370010);
    func_00103F28(D_00370028, func_00106930());
    func_00103F28(D_00370040, func_001069B0(), D_00388830);
    func_00103F28(D_00370060, func_00106838());
    func_00103F28(D_00370078, func_001068D0());
    func_00103F28(D_00370090, D_0038881C ? D_0038F388 : D_0038F390);
    func_00103F28(D_003700A8, D_00388818 ? D_0038F388 : D_0038F390);
    func_00103F28(D_0038F380);
    return true;
}
