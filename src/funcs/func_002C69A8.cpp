extern void* D_0038C7B0;
extern char D_0037A890[];
extern char D_0037A8A0[];

extern "C" void* func_002C95E0(int v);
extern "C" void func_002C91A0(void* p);
extern "C" void func_002C6B08(void* p);
extern "C" int func_001F0D78(char* s);
extern "C" void func_00189750(void* p, int a, int b, unsigned int c, int d, int e);

void func_002C69A8(void* p)
{
    func_002C91A0(func_002C95E0(1));
    func_002C6B08(p);
    void* q = D_0038C7B0;
    int a = func_001F0D78(D_0037A890);
    func_00189750(q, a, func_001F0D78(D_0037A8A0), 0x36B2EE74, 0, 0);
}
