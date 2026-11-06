struct Game_0021F5A8 {
    char pad0[0x24];
    void* m24;
};

extern char D_0038F878[];
extern char D_0038F868[];
extern Game_0021F5A8* D_0038FC78;
extern "C" bool func_001E88F8(void* params, char* name, int* out, int required);
extern "C" bool func_001E7E58(void* params, char* name, int* out, int required);
extern "C" void func_00263CE0(void* p, int a, int b);

bool Cmd_0021F5A8(void* params, void* script)
{
    int a;
    func_001E88F8(params, D_0038F878, &a, 1);
    int b = -1;
    func_001E7E58(params, D_0038F868, &b, 0);
    func_00263CE0(D_0038FC78->m24, a, b);
    return true;
}
