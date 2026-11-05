extern "C" void* func_00240850();
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" void func_00240748(void* game, unsigned int id, bool a, bool b);

bool func_002437D0(void* params)
{
    void* game = func_00240850();
    unsigned int id;
    func_001E8398(params, 0x944B2900, &id, 1);
    bool a = func_001E8708(params, 0x977FE2CF);
    bool b = func_001E8708(params, 0x531FF702);
    func_00240748(game, id, a, b);
    return true;
}
