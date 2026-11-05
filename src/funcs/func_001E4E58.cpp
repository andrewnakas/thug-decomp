extern char* D_0038E3F8;
extern unsigned int D_0038E400;
extern "C" void func_0010BEB8(void* p);

extern "C" void func_001E4E58(char* p)
{
    if (p < D_0038E3F8 || p >= D_0038E3F8 + D_0038E400)
        func_0010BEB8(p);
}
