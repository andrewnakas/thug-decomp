extern void* D_004653C0[10];
extern "C" int func_00114B28(void* m, void* a);

extern "C" bool func_0013B268(void* a)
{
    for (unsigned int i = 0; i < 10; i++) {
        if (D_004653C0[i] && func_00114B28(D_004653C0[i], a))
            return true;
    }
    return false;
}
