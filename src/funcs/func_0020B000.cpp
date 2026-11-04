extern void* D_00388948;
extern char D_0036FE70[];
extern char D_0036FE90[];
extern "C" void* func_00107270(void* m, int i);
extern "C" bool func_00107728(void* p);
extern "C" void func_001F0370(char* name, int a, int b, int c);

extern "C" void func_0020B000()
{
    void* m = D_00388948;
    void* a = func_00107270(m, 0);
    void* b = func_00107270(m, 1);
    if (func_00107728(b) && func_00107728(a))
        func_001F0370(D_0036FE70, 0, 0, 0);
    else
        func_001F0370(D_0036FE90, 0, 0, 0);
}
