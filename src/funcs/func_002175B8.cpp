extern "C" void* func_0022BFE0(void* params);
extern "C" int func_001E8A30(void* params, unsigned int id, int* out, int req);
extern "C" void* func_0022BEE0(void* o);
extern "C" void func_00255968(void* p, int v);

bool func_002175B8(void* params, void* script)
{
    void* o = func_0022BFE0(params);
    if (o) {
        int v;
        func_001E8A30(params, 0, &v, 1);
        void* p = func_0022BEE0(o);
        if (p)
            func_00255968(p, v);
    }
    return true;
}
