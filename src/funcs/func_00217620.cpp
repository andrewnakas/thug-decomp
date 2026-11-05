struct Pair_00217620 {
    float x, y, z, w;
};

extern "C" void* func_0022BFE0(void* params);
extern "C" void func_001E4C80(Pair_00217620* p);
extern "C" bool func_001E8998(void* params, unsigned int name, Pair_00217620* out, int required);
extern "C" void* func_0022BEE0(void* o);
extern "C" void* func_00185578(void* o, unsigned int name);
extern "C" void func_0018CA90(void* c, int a, float b);

bool Cmd_00217620(void* params, void* script)
{
    void* obj = func_0022BFE0(params);
    if (!obj) return true;
    Pair_00217620 v;
    func_001E4C80(&v);
    if (!func_001E8998(params, 0, &v, 0)) return false;
    void* c = func_0022BEE0(obj);
    if (c) func_0018CA90(func_00185578(c, 0x286A8D26), (int)v.y, v.z);
    return true;
}
