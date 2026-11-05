extern char D_00364480[];
extern "C" int func_001E2170(int core);
extern "C" void func_00103F28(const char* fmt);
extern "C" int func_001E1F08(void* snd, int voice, float l, float r, float pitch);

int Play_001E1CA0(void* snd, float* vol, int high, float pitch)
{
    int mask;
    int i;
    if (high) {
        mask = func_001E2170(1);
        for (i = 11; i < 21; i++) {
            if ((mask >> i) & 1) {
                return func_001E1F08(snd, i + 21, vol[0], vol[1], pitch);
            }
        }
        func_00103F28(D_00364480);
    }
    mask = func_001E2170(0);
    for (i = 0; i < 21; i++) {
        if ((mask >> i) & 1) {
            return func_001E1F08(snd, i, vol[0], vol[1], pitch);
        }
    }
    mask = func_001E2170(1);
    for (i = 0; i < 21; i++) {
        if ((mask >> i) & 1) {
            return func_001E1F08(snd, i + 21, vol[0], vol[1], pitch);
        }
    }
    return -1;
}
