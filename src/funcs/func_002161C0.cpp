extern int D_0038F33C;
extern "C" int func_001E8A30(void* params, unsigned int id, int* out, int req);

bool func_002161C0(void* params, void* script)
{
    int v;
    func_001E8A30(params, 0xAE94C183, &v, 1);
    return D_0038F33C == v;
}
