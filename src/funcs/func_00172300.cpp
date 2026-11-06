extern char D_003E0FE0[];
extern char D_003E1030[];
extern "C" void func_0016DC08(void* p);

extern "C" void func_00172300(int a, int b)
{
    if (b == 0xFFFF && a) {
        func_0016DC08(D_003E0FE0);
        func_0016DC08(D_003E1030);
    }
}
