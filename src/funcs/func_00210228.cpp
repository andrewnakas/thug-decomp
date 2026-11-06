extern char D_00370300[];
extern "C" bool func_001E8398(void* params, unsigned int name, int* out, int required);
extern "C" void* func_001DB060(int id);
extern "C" void func_001DC0A8(void* p);
extern "C" void func_00103F28(char* fmt);

bool Cmd_00210228(void* params, void* script)
{
    int id;
    if (!func_001E8398(params, 0x3789AC4E, &id, 0)) {
        func_00103F28(D_00370300);
        return false;
    }
    func_001DC0A8(func_001DB060(id));
    return true;
}
