extern float D_0038E134;
extern int D_0038E148;
extern int D_0038E150;
extern int D_0038E130;
extern void* D_0038FC78;
extern "C" int func_001DED20();
extern "C" void* func_0022E358(void* m);
extern "C" bool func_0024F860(void* p);
extern "C" void func_001E34F8(float v);

extern "C" void func_001E00E0(float v)
{
    if (func_001DED20()) return;
    if (v > 100.0f) return;
    if (v < 0.0f) return;
    D_0038E134 = v;
    if (!D_0038E148) return;
    void* mgr = D_0038FC78;
    if (D_0038E150) return;
    if (D_0038E130 && !func_0024F860(func_0022E358(mgr))) return;
    func_001E34F8(v);
}
