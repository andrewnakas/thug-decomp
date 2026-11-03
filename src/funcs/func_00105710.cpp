extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;
extern void* D_00393EA0;
extern void* D_00393EA4;
extern void* D_00393EA8;
extern void* D_00393EAC;

void FreeBuffers105710()
{
    if (D_00393EA0)
        func_0010A8D8(D_00388A70, D_00393EA0);
    if (D_00393EA4)
        func_0010A8D8(D_00388A70, D_00393EA4);
    if (D_00393EA8)
        func_0010A8D8(D_00388A70, D_00393EA8);
    if (D_00393EAC)
        func_0010A8D8(D_00388A70, D_00393EAC);
}
