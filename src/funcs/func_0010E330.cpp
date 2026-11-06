/* Static-init: clears a 100-entry pointer table (last to first) and a 200-entry table of 16-byte records. */
struct Rec_0010E330 {
    int a, b, c, d;
};

extern int D_00396568[100];
extern Rec_0010E330 D_003966F8[200];

void func_0010E330(int initialize, int priority)
{
    if (priority == 0xFFFF && initialize) {
        for (int i = 99; i >= 0; i--)
            D_00396568[i] = 0;
        Rec_0010E330* r = D_003966F8;
        for (int i = 199; i >= 0; i--) {
            r->a = 0;
            r->b = 0;
            r->c = 0;
            r->d = 0;
            r++;
        }
    }
}
