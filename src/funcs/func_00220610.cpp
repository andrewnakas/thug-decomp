struct Obj_00220610;
struct Comp_00220610;

extern void* D_0038FC78;

extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" Obj_00220610* func_0022DE70(void* mgr, int id);
extern "C" char* func_0022E3C8(void* mgr, int id);
extern "C" Comp_00220610* func_00185578(Obj_00220610* o, unsigned int type);
extern "C" void func_0018DC70(Comp_00220610* c, char* data, unsigned int name);

bool func_00220610(void* params)
{
    int index = 0;
    int id = 0;
    func_001E7DE8(params, 0x7EA855F0, &index, 1);
    func_001E7DE8(params, 0x5B8AB877, &id, 1);
    Obj_00220610* o = func_0022DE70(D_0038FC78, id);
    char* data = func_0022E3C8(D_0038FC78, index) + 4;
    func_0018DC70(func_00185578(o, 0x286A8D26), data, 0x091D6261);
    return true;
}
