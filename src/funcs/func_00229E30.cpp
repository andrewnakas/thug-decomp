extern "C" void* func_00229DF0();
extern "C" int func_001E8398(void* params, unsigned int name, int* out, int req);

extern "C" int func_00229E30()
{
    void* p = func_00229DF0();
    int v = 0;
    func_001E8398(p, 0xA1DC81F9, &v, 0);
    return v;
}
