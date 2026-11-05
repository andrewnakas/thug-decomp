extern "C" void func_001363F0();
extern "C" void* func_001190D0(int n);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AC8(void* p, int a);
extern "C" void* func_0010BDE0(int size);

extern unsigned short* D_00389E40;
extern int D_00389E44;
extern int D_00389E4C;
extern void* D_00389E54;

extern "C" void func_00136440(unsigned short* data, int n, int a2, int a3)
{
    func_001363F0();
    D_00389E54 = func_001E6978(func_001190D0(8));
    func_001E6AC8(D_00389E54, a3);
    if (n) {
        D_00389E40 = (unsigned short*)func_0010BDE0(n * 2);
        for (int i = 0; i < n; i++)
            D_00389E40[i] = data[i];
    }
    D_00389E44 = n;
    D_00389E4C = a2;
}
