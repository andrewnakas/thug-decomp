extern "C" unsigned long func_0010FA80();
extern volatile unsigned int D_0038E1F8[2];
extern int D_00394338[2];

static inline unsigned long Lag_001E2338(int i)
{
    unsigned long t = D_0038E1F8[i];
    return t - func_0010FA80();
}

int func_001E2338(int i)
{
    while (Lag_001E2338(i)) {
    }
    /* the game re-reads the stamp and the clock once more after the wait (lw + jal, result unused) */
    Lag_001E2338(i);
    return D_00394338[i];
}
