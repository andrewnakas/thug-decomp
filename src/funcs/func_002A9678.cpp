extern void* D_00392068;
extern char D_00392130[];
extern char D_00378A48[];
extern "C" bool func_001E7E58(void* params, const char* name, int* out, int required);
extern "C" int func_002A1DA8(void* net, int id);
extern "C" void func_001E7268(void* params, char* name, int value);

struct Script_002A9678 {
    char pad[0x18];
    void* m18;
};

bool Cmd_002A9678(void* params, Script_002A9678* script)
{
    void* net = D_00392068;
    int id = 0;
    func_001E7E58(params, D_00392130, &id, 1);
    int v = func_002A1DA8(net, id);
    func_001E7268(script->m18, D_00378A48, v);
    return true;
}
