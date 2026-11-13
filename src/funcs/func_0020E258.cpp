extern "C" bool func_001E7DE8(void* params, int name, int* out, int assert);
extern "C" bool func_001E0ED8(int a);
extern "C" void func_001E0C20(unsigned long* lo, unsigned long* hi);

bool Cmd_0020E258(void* params, void* script)
{
    int idx = 0;
    func_001E7DE8(params, 0, &idx, 0);
    if (!func_001E0ED8(0))
        return false;
    unsigned long lo;
    unsigned long hi;
    func_001E0C20(&lo, &hi);
    if (idx < 64) {
        if ((int)((lo >> idx) & 1))
            return false;
    } else {
        if ((int)((hi >> (idx - 64)) & 1))
            return false;
    }
    return true;
}
