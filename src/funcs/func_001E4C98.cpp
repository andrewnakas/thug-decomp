extern int D_0038E400;
extern int D_0038E40C;
extern void* D_0038E3FC;
extern void* D_0038E3F8;
extern void* D_0038E404;
extern int D_0038E408;
extern "C" void* func_0010BDE0(int size);

extern "C" void func_001E4C98(int a, int b)
{
    D_0038E400 = a;
    D_0038E40C = b;
    void* p = func_0010BDE0(a);
    D_0038E3F8 = p;
    D_0038E3FC = p;
    D_0038E404 = func_0010BDE0(D_0038E40C * 8);
    D_0038E408 = 0;
}
