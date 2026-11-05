extern "C" int func_001E8870(void* params, unsigned int id, void** out, int req);
extern "C" void func_0010BFC0(void* p);

bool func_00218AE0(void* params, void* script)
{
    void* s;
    func_001E8870(params, 0, &s, 1);
    func_0010BFC0(s);
    return true;
}
