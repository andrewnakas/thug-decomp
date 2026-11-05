extern "C" void* func_001E55B8(unsigned int name, int a);
extern "C" void* func_001E9378(void* a, int i);
extern "C" int func_00229E70(void* params);

int Get_00229EB0(int index)
{
    void* p = func_001E55B8(0xC472ECC5, 0);
    if (p) {
        return func_00229E70(func_001E9378(p, index));
    }
    return 0;
}
