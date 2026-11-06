extern int D_0038DF18;
extern void* D_004686C8[];
extern "C" void func_001DAD00(void* o, void* p);

void func_001DAE80(void* p)
{
    for (int i = 0; i < D_0038DF18; i++)
        func_001DAD00(D_004686C8[i], p);
}
