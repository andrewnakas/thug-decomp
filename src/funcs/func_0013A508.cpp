extern "C" int func_001E8398(void* params, unsigned int id, unsigned int* out, int req);
extern "C" int func_001E7DE8(void* params, unsigned int id, int* out, int req);
extern "C" int func_001E8918(void* params, unsigned int id, float* out, int req);
extern "C" void* func_00139468(void* node, unsigned int id);
extern "C" void func_001388A0(void* c, bool b, float f);
extern void* D_00393EF4;

bool Cmd_0013A508(void* params, void* script)
{
    unsigned int id;
    func_001E8398(params, 0, &id, 0);
    void* c = func_00139468(D_00393EF4, id);
    if (c) {
        float f = 1.0f;
        int v = 0;
        func_001E8918(params, 0x2689291C, &f, 1);
        func_001E7DE8(params, 0xC164842A, &v, 0);
        func_001388A0(c, v == 1, f);
    }
    return true;
}
