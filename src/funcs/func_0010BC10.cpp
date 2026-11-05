extern void* D_00388A70;
extern "C" void func_0010BA18(void* o);
extern "C" void func_0010A9B0(void* o);
extern "C" void func_0010A598(void* o, int f);

void Free_0010BC10()
{
    if (D_00388A70) {
        func_0010BA18(D_00388A70);
        func_0010A9B0(D_00388A70);
        func_0010A598(D_00388A70, 2);
        D_00388A70 = 0;
    }
}
