extern "C" void* func_00240850();
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" void func_0023C378(void* owner, int id);
extern "C" void func_0023C348(void* owner, int id);

bool Cmd_00240BE0(void* params, void* script)
{
    void* owner = func_00240850();
    unsigned int id;
    func_001E8398(params, 0xA1DC81F9, &id, 1);
    if (func_001E8708(params, 0x687DE558)) {
        func_0023C378(owner, id);
    } else {
        func_0023C348(owner, id);
    }
    return true;
}
