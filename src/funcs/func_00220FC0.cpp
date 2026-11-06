/* NEAR MISS-ish: MATCHES, but needs a dead initialiser 'int b = 0;' (overwritten by b = a before any read) to produce the game's sw $zero,4($sp). Lead to decide. */
extern void* D_0038FC78;
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E8180(void* params, unsigned int name, void** out, int required);
extern "C" char* func_0022E3C8(void* self, int index);
extern "C" void func_001F0210(unsigned int name, void* params, void* obj, int a, int b);

bool Cmd_00220FC0(void* params, void* script)
{
    int a;
    int b = 0;
    a = 0;
    func_001E7DE8(params, 0, &a, 0);
    b = a;
    func_001E7DE8(params, 0x7EA855F0, &b, 0);
    char* obj = func_0022E3C8(D_0038FC78, b) + 4;
    unsigned int name;
    func_001E8398(params, 0xB990D003, &name, 1);
    void* sub = 0;
    func_001E8180(params, 0x46A2869C, &sub, 0);
    func_001F0210(name, sub, obj, 0, 0);
    return true;
}
