extern void* D_0038FB60;
extern void* D_0038FB64;
extern "C" void func_0010BEB8(void* p);

void Free_00229890()
{
    if (D_0038FB60) {
        func_0010BEB8(D_0038FB60);
        D_0038FB60 = 0;
        D_0038FB64 = 0;
    }
}
