extern unsigned int D_003921A8;
extern "C" unsigned int func_0010FC30();
extern "C" void func_001F0210(unsigned int name, void* params, int a, int b, int c);

static inline bool Elapsed_002A8CA8(unsigned int ms, unsigned int now, unsigned int start)
{
    return now - start > ms;
}

bool Cmd_002A8CA8(void* params, void* script)
{
    if (Elapsed_002A8CA8(3000, func_0010FC30(), D_003921A8)) {
        func_001F0210(0x55AF7C02, 0, 0, 0, 0);
        D_003921A8 = func_0010FC30();
    }
    return true;
}
