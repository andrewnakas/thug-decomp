/* fuzzy: 87.5 */
/* blocked: the game copies the frames base for the loop pointer (daddu $a3,$a2) and assigns sum/clamped to $a0/$t0; running-pointer, indexed and declaration-order forms all keep one register; directed search no match */
/* sym: dpmul = 0x0033E220 */
/* sym: litodp = 0x0033E798 */
struct Timer_0010F958 {
    float ratio;
    float scaled;
    double avg;
    int frames[4];
    int now;
    int prev;
    int index;
};

extern Timer_0010F958 D_00397378;
extern long D_00388D98;
extern int D_00388830;
extern "C" long func_0010FA88();
extern "C" float func_0010FAB0();

extern "C" void func_0010F958()
{
    Timer_0010F958* t = &D_00397378;
    D_00388D98++;
    t->prev = t->now;
    t->now = func_0010FA88();
    t->frames[t->index++] = t->now - t->prev;
    if (t->index == 4) {
        t->index = 0;
    }
    int clamped = 0;
    int sum = 0;
    int* f = t->frames;
    for (int i = 0; i < 4; i++) {
        sum += f[i];
        int v = f[i];
        if (v < 2 || v > 10) {
            v = 1;
        }
        if (v > 4) {
            v = 4;
        }
        clamped += v;
    }
    D_00397378.ratio = clamped * 0.25f;
    D_00397378.avg = sum * 0.25;
    int n = D_00388830;
    D_00397378.scaled = D_00397378.ratio / n * func_0010FAB0();
}
