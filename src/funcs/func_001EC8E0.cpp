extern int D_0038E6E4;
extern "C" void func_001EE070(void* p);

void func_001EC8E0(void* p, int flags)
{
    D_0038E6E4--;
    if (flags & 1)
        func_001EE070(p);
}
