extern "C" void* func_001E55B8(unsigned int id, int v);
extern "C" void* func_001E9378(void* a, int i);
extern "C" bool func_002584A0(void* p);

bool Fn_002584E0(int i)
{
    return func_002584A0(func_001E9378(func_001E55B8(0xC472ECC5, 0), i));
}
