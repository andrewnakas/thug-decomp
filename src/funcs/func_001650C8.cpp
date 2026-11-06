extern int D_0038882C;
extern int D_00394090;
extern "C" void func_0017EEF0(int x0, int x1, int y0, int y1);
extern "C" void func_00123618();
extern "C" void func_0017F1C8();
extern "C" void func_0017AEC0();

void func_001650C8()
{
    bool f = D_0038882C == 1;
    func_0017EEF0(0, f ? 0x27F : 0x1FF, 0, f ? 0x1BF : 0x1FF);
    func_00123618();
    func_0017F1C8();
    func_0017AEC0();
    D_00394090++;
}
