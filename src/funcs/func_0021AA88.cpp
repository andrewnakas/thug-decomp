extern "C" int func_001E7DE8(void* params, unsigned int id, int* out, int req);
extern "C" void func_00132978(bool v);

bool func_0021AA88(void* params, void* script)
{
    int v = 0;
    func_001E7DE8(params, 0x1A4E0EF9, &v, 0);
    func_00132978(v > 0);
    return true;
}
