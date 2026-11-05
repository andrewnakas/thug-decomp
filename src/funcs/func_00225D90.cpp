extern int D_00388814;
extern "C" int func_00225E68(void* b);
extern "C" int func_00225E18();
extern "C" int func_00225C68(void* a);

int Calc_00225D90(void* a, void* b)
{
    int r = func_00225E68(b) / func_00225E18();
    if (D_00388814 != 4) {
        if (D_00388814 < 5) {
            if (D_00388814 > 0) {
                r += func_00225C68(a);
                r += 4;
            }
        }
    } else {
        r += 3;
    }
    return r;
}
