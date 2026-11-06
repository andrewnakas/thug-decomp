extern float D_00394260;
extern "C" void func_0014BF48();
extern "C" void func_0014BEF0(float v);

extern "C" void func_00138028(float v)
{
    if (v <= 0.0f) {
        return;
    }
    D_00394260 = v;
    func_0014BF48();
    func_0014BEF0(v);
}
