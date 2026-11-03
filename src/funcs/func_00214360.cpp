extern void* D_0038FC78;

extern "C" bool func_00235F70(void* game);
extern "C" void* func_001E55B8(unsigned int name, int create);
extern "C" void* func_001E9378(void* arr, int i);
extern "C" bool func_0022EEC0(void* game, void* node);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" void* func_00131E48();
extern "C" void* func_00132FD0(void* scene, unsigned int name);
extern "C" void func_00135490(void* sector, int a);

bool func_00214360(int index)
{
    void* game = D_0038FC78;
    if (func_00235F70(game))
        return true;
    void* node = func_001E9378(func_001E55B8(0xC472ECC5, 0), index);
    if (func_0022EEC0(game, node))
        return true;
    unsigned int type = 0;
    func_001E8398(node, 0x12B4E660, &type, 0);
    if (type != 0xB7B3BD86 && type != 0xBF4D3536)
        return false;
    unsigned int name = 0;
    if (func_001E8398(node, 0xA1DC81F9, &name, 0))
        func_00135490(func_00132FD0(func_00131E48(), name), 1);
    return true;
}
