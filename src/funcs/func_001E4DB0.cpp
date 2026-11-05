extern int D_0038E3F4;
extern void* D_0038E404;
extern "C" void func_0010BEB8(void* p);

void Free_001E4DB0()
{
    D_0038E3F4 = 0;
    if (D_0038E404) {
        func_0010BEB8(D_0038E404);
        D_0038E404 = 0;
    }
}
