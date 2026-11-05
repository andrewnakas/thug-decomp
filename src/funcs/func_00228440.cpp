extern void* D_0038F9C4;
extern int D_0038F9C8;
extern "C" void func_001E6AE8(void* p, int flags);

bool Cmd_00228440(void* params, void* script)
{
    if (D_0038F9C4) {
        func_001E6AE8(D_0038F9C4, 3);
        D_0038F9C4 = 0;
    }
    D_0038F9C8 = 0;
    return true;
}
