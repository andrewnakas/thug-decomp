extern char D_003C3990[];
extern "C" void func_00142E10(void* p, int a);

extern "C" void func_00142EB8(void* p, int id)
{
    if (id == 0xFFFF && p) func_00142E10(D_003C3990, 1);
}
