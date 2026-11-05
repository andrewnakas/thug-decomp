extern "C" void* func_00265EC8(void* self, int b);
extern "C" void* func_00265380(void* p, int a);
extern "C" void func_00266070(void* self, int a, int b);

void* Link_00265FF8(void* self, int a, int b)
{
    void* p = func_00265380(func_00265EC8(self, b), a);
    if (p && a != b)
        func_00266070(self, a, b);
    return p;
}
