extern "C" int func_001E8398(void* params, unsigned int id, unsigned int* out, int req);
extern "C" void* func_00139468(void* node, unsigned int id);
extern "C" void* func_001393A8(void* node, unsigned int key, void* parent);
extern void* D_00393EF4;

bool Cmd_0013A6A0(void* params, void* script)
{
    unsigned int id;
    func_001E8398(params, 0x9FBBDB72, &id, 0);
    void* c = func_00139468(D_00393EF4, id);
    unsigned int key;
    if (c && func_001E8398(params, 0x941CBBBA, &key, 0))
        func_001393A8(D_00393EF4, key, c);
    return true;
}
