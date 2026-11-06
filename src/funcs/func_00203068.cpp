extern "C" bool func_001E8180(void* p, int name, int* out, int required);
extern "C" void func_001E6AC8(int v, void* p);

extern "C" bool func_00203068(char* self, int name, void* dst)
{
    int v = 0;
    if (!func_001E8180(self + 4, name, &v, 0))
        return false;
    func_001E6AC8(v, dst);
    return true;
}
