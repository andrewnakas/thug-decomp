extern "C" bool func_001E8398(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E8180(void* params, unsigned int name, void** out, int required);
extern "C" bool func_001E84E8(void* params, const char* name, unsigned int* out, int required);
extern "C" bool func_001E81F0(void* params, const char* name, void** out, int required);
extern "C" int func_001E87B8(void* params, const char* name);
extern "C" bool func_001E7E58(void* params, const char* name, int* out, int required);
extern "C" void* func_001F0750(int time, void* script_params, unsigned int callback, void* callback_params,
                               void* object, unsigned int script, int net, int permanent, bool not_session,
                               int flags);

extern char D_0038F580[];
extern char D_00370950[];
extern char D_00370960[];
extern char D_00370970[];
extern char D_00370980[];
extern char D_00370990[];

struct Script_00214600 {
    char pad[0xB8];
    void* m_object;
};

bool Cmd_00214600(void* params, Script_00214600* script)
{
    int time = 0;
    func_001E8398(params, 0, &time, 0);
    void* sparams = 0;
    func_001E8180(params, 0x7031F10C, &sparams, 0);
    unsigned int sname = 0;
    func_001E84E8(params, D_0038F580, &sname, 0);
    unsigned int callback = 0;
    func_001E84E8(params, D_00370950, &callback, 0);
    void* cbparams = 0;
    func_001E81F0(params, D_00370960, &cbparams, 0);
    int net = func_001E87B8(params, D_00370970);
    int permanent = func_001E87B8(params, D_00370980);
    int not_session = 0;
    func_001E7E58(params, D_00370990, &not_session, 0);
    func_001F0750(time, sparams, callback, cbparams, script->m_object, sname, net, permanent, not_session != 0, 0);
    return true;
}
