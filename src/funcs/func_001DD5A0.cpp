extern float D_00388828;
extern float D_0038E0BC;
extern "C" int func_001DC418();
extern "C" void func_001E53A0(unsigned int name, int a);
extern "C" void func_001E1800(float v);
extern "C" void func_001E0C58(float v);

extern "C" void func_001DD5A0(float vol)
{
    if (func_001DC418())
        return;
    func_001E53A0(0xD7BB618D, 0);
    D_0038E0BC = vol;
    float v = vol * D_00388828 * 0.01f;
    if (v < 0.1f)
        v = 0.0f;
    func_001E1800(v);
    func_001E0C58(v);
}
