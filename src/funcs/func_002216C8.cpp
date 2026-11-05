struct Script_002216C8 {
    char pad[0x18];
    void* m_params;
};

extern void* D_0038FC78;
extern char D_003716B0[];
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" void* func_0022E050(void* self);
extern "C" void* func_002629A8(void* obj, int index);
extern "C" int func_00261EE0(void* obj);
extern "C" void func_001E7268(void* params, char* name, int value);

bool Cmd_002216C8(void* params, Script_002216C8* script)
{
    int index;
    func_001E7DE8(params, 0x67E6859A, &index, 1);
    int v = func_00261EE0(func_002629A8(func_0022E050(D_0038FC78), index));
    func_001E7268(script->m_params, D_003716B0, v);
    return true;
}
