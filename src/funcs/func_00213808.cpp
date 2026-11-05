extern int D_0039424C;
extern "C" int func_001E7DE8(void* params, unsigned int id, int* out, int req);

bool func_00213808(void* params, void* script)
{
    int v = 0;
    func_001E7DE8(params, 0x6835B854, &v, 0);
    D_0039424C = v;
    return true;
}
