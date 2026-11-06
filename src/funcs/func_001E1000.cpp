extern void* D_0038FC78;
extern int D_0038E130;
extern "C" int func_001DED20();
extern "C" void* func_0022E358(void* p);
extern "C" int func_0024F860(void* p);
extern "C" void func_001DEEE0();

extern "C" void func_001E1000(int v)
{
    if (func_001DED20())
        return;
    if (D_0038E130 != v && !func_0024F860(func_0022E358(D_0038FC78)))
        func_001DEEE0();
    D_0038E130 = v;
}
