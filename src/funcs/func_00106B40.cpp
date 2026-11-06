extern "C" void* func_001046B0(int size);
extern "C" void* func_00107A58(void* mem, int a, int b, int c);

extern "C" void* func_00106B40(void* self, int a, int b, int c)
{
    return func_00107A58(func_001046B0(0xF0), a, b, c);
}
