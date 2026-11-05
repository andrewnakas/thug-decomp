extern "C" int func_001E7DE8(void* params, unsigned int id, int* out, int req);
extern "C" void func_001DFF88(int v);

bool func_0020DFB8(void* params, void* script)
{
    int v = 1;
    func_001E7DE8(params, 0, &v, 0);
    func_001DFF88(v);
    return true;
}
