extern "C" void* func_001E5548(unsigned int id, int v);
extern "C" int func_001E7DE8(void* p, void* key, int* out, int req);

int Get_002BEF38(void* self, void* key)
{
    void* p = func_001E5548(0x9547DA8D, 1);
    int v = 1;
    func_001E7DE8(p, key, &v, 0);
    return v;
}
