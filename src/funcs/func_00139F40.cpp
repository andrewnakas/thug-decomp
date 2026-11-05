extern "C" int func_001E8398(void* params, unsigned int id, unsigned int* out, int req);
extern "C" int func_001E7DE8(void* params, unsigned int id, int* out, int req);
extern "C" void* func_00139468(void* node, unsigned int id);
extern "C" void func_00138760(void* c, bool a, bool b);
extern void* D_00393EF4;

bool Cmd_00139F40(void* params, void* script)
{
    unsigned int id;
    func_001E8398(params, 0, &id, 0);
    void* c = func_00139468(D_00393EF4, id);
    if (c) {
        int v;
        bool a = false;
        bool b = false;
        if (func_001E7DE8(params, 0xA5D7CFAA, &v, 0))
            a = (v == 1);
        if (func_001E7DE8(params, 0xEEFAF080, &v, 0))
            b = (v == 1);
        func_00138760(c, a, b);
    }
    return true;
}
