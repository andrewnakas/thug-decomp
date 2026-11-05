struct Mat_0013B4A8 {
    char pad[0x18];
    void* m18;
};

extern float D_0039426C;
extern float D_00394270;
extern float D_0038A0EC;
extern int D_0038A0E8;
extern "C" float func_00341158(float x);
extern "C" Mat_0013B4A8* func_0013AF50(int i);
extern "C" void func_00114D48(void* p);

static inline float Rad_0013B4A8(float d) { return d * 0.017453294f; }

extern "C" void func_0013B4A8(float fov)
{
    if (fov == 0.0f)
        fov = D_0039426C;
    D_00394270 = fov;
    D_0038A0EC = func_00341158(Rad_0013B4A8(fov * 0.5f)) / func_00341158(Rad_0013B4A8(D_0039426C * 0.5f));
    for (int i = 0; i < D_0038A0E8; i++) {
        Mat_0013B4A8* m = func_0013AF50(i);
        if (m && m->m18)
            func_00114D48(m->m18);
    }
}
