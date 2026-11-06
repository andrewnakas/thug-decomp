extern int D_0038881C;
extern void* D_00388E24;
extern int D_00388E28;
extern int D_00388E10;
extern "C" void func_0010BEB8(void* p);
extern "C" int func_0031EB08(int h);
extern "C" int func_0031F7E8(int h);

extern "C" void func_00110CF8()
{
    if (D_0038881C) {
        func_0010BEB8(D_00388E24);
        D_00388E24 = 0;
        func_0031EB08(D_00388E28);
        D_00388E28 = -1;
        if (D_00388E10) {
            func_0031F7E8(D_00388E10);
            D_00388E10 = 0;
        }
    }
}
