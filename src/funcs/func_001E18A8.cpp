extern "C" void func_001E1828();
extern "C" void func_001E23B0(int a, int b, int v);
extern int D_0038E1D8;
extern int D_0038E1DC;

void Fade_001E18A8()
{
    if (D_0038E1D8 != D_0038E1DC) {
        if (D_0038E1DC < D_0038E1D8) {
            D_0038E1DC += 0x334;
            if (D_0038E1D8 < D_0038E1DC) {
                D_0038E1DC = D_0038E1D8;
            }
        } else {
            D_0038E1DC -= 0x334;
            if (D_0038E1DC < D_0038E1D8) {
                D_0038E1DC = D_0038E1D8;
                if (D_0038E1D8 == 0) {
                    func_001E1828();
                }
            }
        }
        func_001E23B0(0x8010, 0xB80, D_0038E1DC);
        func_001E23B0(0x8010, 0xC80, D_0038E1DC);
    }
}
