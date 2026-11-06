struct Obj_0021F1C8 {
    int m0;
    char m4[4];
};

extern void* D_0038FC78;
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" Obj_0021F1C8* func_0022E3C8(void* mgr, int id);
extern "C" void* func_001200E0(void* p);
extern "C" void func_00123428(void* p, int a);

bool Cmd_0021F1C8(void* params, void* script)
{
    int id;
    func_001E7DE8(params, 0x67E6859A, &id, 1);
    func_00123428(func_001200E0(func_0022E3C8(D_0038FC78, id)->m4), 0);
    return true;
}
