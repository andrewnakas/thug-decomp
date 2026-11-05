extern int D_0038881C;
extern int D_00388E18;
extern "C" void* func_0010EC78(const char* name, int a, int b);
extern "C" int func_0010E5C0(void* job, void* buf);
extern "C" int func_0010E4B0(void* job);
extern "C" void func_0010ECF8(void* job);

extern "C" int func_0010FF18(const char* name, void* buf)
{
    void* job;
    if (!D_0038881C || !D_00388E18 || (job = func_0010EC78(name, 0, 100)) == 0) {
        return 0;
    }
    func_0010E5C0(job, buf);
    func_0010E4B0(job);
    func_0010ECF8(job);
    return 1;
}
