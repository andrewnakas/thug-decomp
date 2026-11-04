extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

void FreeNode_00248920(void* p, int flags)
{
    if (flags & 1)
        func_0010A8D8(D_00388A70, p);
}
