extern int D_0038E0A0;
extern float D_00388828;

extern "C" float func_001E0180();
extern "C" float func_001DD618(int a);
extern "C" void func_001F82E8(int v);

extern "C" void func_001F7A00()
{
    int id = D_0038E0A0;
    float a = func_001E0180() * D_00388828 * 0.01f;
    float b = func_001DD618(id) * D_00388828 * 0.01f;
    float m = (a > b) ? a : b;
    func_001F82E8((int)(m * 163.83f));
}
