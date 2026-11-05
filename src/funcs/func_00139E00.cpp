extern "C" int func_001E8870(void* params, unsigned int id, char** out, int req);
extern "C" int func_001E8398(void* params, unsigned int id, unsigned int* out, int req);
extern "C" bool func_001E8708(void* params, unsigned int id);
extern "C" void* func_001394A0(void* node, char* name);
extern "C" void* func_00139468(void* node, unsigned int id);
extern "C" bool func_001390E0(void* node, void* c);
extern void* D_00393EF4;

bool Cmd_00139E00(void* params, void* script)
{
    char* name;
    unsigned int id;
    void* c = 0;
    if (func_001E8870(params, 0, &name, 0)) {
        c = func_001394A0(D_00393EF4, name);
    } else if (func_001E8398(params, 0, &id, 0)) {
        c = func_00139468(D_00393EF4, id);
    }
    if (c)
        func_001390E0(D_00393EF4, c);
    else
        func_001E8708(params, 0x3D92465E);
    return true;
}
