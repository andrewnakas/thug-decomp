struct Obj_002182B8 {
    char pad[0x168];
    int m168;
};

extern char D_0038F590[];
extern "C" bool func_001E84E8(void* params, char* name, unsigned int* out, int required);
extern "C" Obj_002182B8* func_00141250(unsigned int id);

extern "C" bool func_002182B8(void* params, void* script)
{
    unsigned int id = 0;
    func_001E84E8(params, D_0038F590, &id, 0);
    func_00141250(id)->m168 = 0;
    return true;
}
