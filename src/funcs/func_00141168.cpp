struct Cam_00141168 {
    char pad[0x1DC];
    int m1DC;
};

extern "C" void* func_001324B0();
extern "C" void func_00141410(void* mgr);
extern "C" Cam_00141168* func_00141420(void* mgr, int a);
extern "C" void func_0013F940(Cam_00141168* c, float f);

extern "C" void func_00141168(float f)
{
    if (!func_001324B0())
        return;
    func_00141410(func_001324B0());
    Cam_00141168* c;
    while ((c = func_00141420(func_001324B0(), 0)) != 0) {
        if (c->m1DC)
            func_0013F940(c, f);
    }
}
