struct Cam_001412A0 {
    char pad[0x1E0];
    int m1E0;
    char pad1E4[0xC];
    bool m1F0;
};

extern "C" Cam_001412A0* func_0014E588(unsigned int id, int a1, int a2, int a3, int t0, int t1, int t2, int t3, int s0, float f);
extern "C" void func_001404C8(Cam_001412A0* c, int a);
extern "C" void* func_001324B0();
extern "C" bool func_00141538(void* mgr, unsigned int* id, Cam_001412A0* c);

extern "C" Cam_001412A0* func_001412A0(unsigned int id, int a1, int a2, int a3, int t0, int t1, int t2, int t3, int s0, float f, int active)
{
    Cam_001412A0* c = func_0014E588(id, a1, a2, a3, t0, t1, t2, t3, s0, f);
    c->m1F0 = active;
    func_001404C8(c, 1);
    c->m1E0 = 0;
    func_00141538(func_001324B0(), &id, c);
    return c;
}
