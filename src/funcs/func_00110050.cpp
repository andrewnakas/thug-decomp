extern int D_00388E20;
extern "C" void func_0010FD30(void* p);

extern "C" int func_00110050(void* p)
{
    if (p) {
        if (!D_00388E20) {
            return -1;
        }
        func_0010FD30(p);
        D_00388E20--;
        return 0;
    }
    return -1;
}
