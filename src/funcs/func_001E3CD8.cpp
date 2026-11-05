extern "C" void func_001E28F8(int cmd, void* p, int a, int b);

void func_001E3CD8(void* p, int mode)
{
    if (mode == 1)
        func_001E28F8(0x100, p, 0, 0);
    else
        func_001E28F8(0x120, p, 0, 0);
}
