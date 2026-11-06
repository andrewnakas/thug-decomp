extern int D_003E26F8[3];
extern int D_003E2708[3];
extern float D_003E11F0[3];

extern "C" int func_0016D6F8(void* self, float* rad, float* pos)
{
    int out = 0;
    int* f = D_003E26F8;
    if ((f[0] && pos[0] + rad[0] <= D_003E11F0[0]) ||
        (f[1] && pos[1] + rad[1] <= D_003E11F0[1]) ||
        (f[2] && pos[2] + rad[2] <= D_003E11F0[2])) {
        out = 1;
    } else {
        int* g = D_003E2708;
        if ((g[0] && pos[0] - rad[0] >= D_003E11F0[0]) ||
            (g[1] && pos[1] - rad[1] >= D_003E11F0[1]) ||
            (g[2] && pos[2] - rad[2] >= D_003E11F0[2])) {
            out = 1;
        }
    }
    return out;
}
