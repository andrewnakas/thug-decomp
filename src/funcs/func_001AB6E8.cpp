extern "C" int func_001E8180(void* s, unsigned int name, int* out, int req);

int Get_001AB6E8(void*, void* s)
{
    int v = 0;
    func_001E8180(s, 0x68B74085, &v, 0);
    return v;
}
