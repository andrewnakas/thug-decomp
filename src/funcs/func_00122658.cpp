extern "C" void func_00138970(void* params, void* obj, int flag);
extern void* D_003895E8;

bool Cmd122658(void* params, void* script)
{
    if (D_003895E8) {
        func_00138970(params, D_003895E8, 0);
        return true;
    }
    return false;
}
