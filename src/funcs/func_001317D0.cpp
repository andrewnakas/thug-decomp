extern void* D_004653B0[4];
extern "C" int func_00132FD0(void* p, void* key);

extern "C" int func_001317D0(void* key)
{
    for (int i = 0; i < 4; i++) {
        if (D_004653B0[i]) {
            int r = func_00132FD0(D_004653B0[i], key);
            if (r) {
                return r;
            }
        }
    }
    return 0;
}
