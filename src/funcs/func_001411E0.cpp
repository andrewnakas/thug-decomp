struct Cam_001411E0 {
    char pad[0x1DC];
    int m1DC;
};

extern "C" void* func_001324B0();
extern "C" void func_00141410(void* mgr);
extern "C" Cam_001411E0* func_00141420(void* mgr, int a);
extern "C" void func_0013FCB8(Cam_001411E0* c);

extern "C" void func_001411E0()
{
    if (!func_001324B0())
        return;
    func_00141410(func_001324B0());
    Cam_001411E0* c;
    while ((c = func_00141420(func_001324B0(), 0)) != 0) {
        if (c->m1DC)
            func_0013FCB8(c);
    }
}
