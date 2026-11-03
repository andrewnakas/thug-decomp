struct Ref_00214800 {
    void* m_p;
};

struct Script_00214800 {
    char pad[0xB8];
    void* m_object;
    Ref_00214800 m_ref;
};

extern "C" bool func_001E8398(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E8180(void* params, unsigned int name, void** out, int required);
extern "C" bool func_001E84E8(void* params, const char* name, unsigned int* out, int required);
extern "C" bool func_001E81F0(void* params, const char* name, void** out, int required);
extern "C" Script_00214800* func_001F0750(int time, void* script_params, unsigned int callback,
                                           void* callback_params, void* object, unsigned int script, int net,
                                           int permanent, bool not_session, int flags);
extern "C" void* func_0022DD38(void* game);
extern "C" void func_00183CB8(void* obj, Ref_00214800* ref);
extern "C" void func_00183C98(void* obj, Ref_00214800* ref);

extern void* D_0038FC78;
extern char D_0038F580[];
extern char D_00370950[];
extern char D_00370960[];

static inline void Release_00214800(Ref_00214800* r)
{
    if (r->m_p) {
        func_00183CB8(r->m_p, r);
        r->m_p = 0;
    }
}

static inline void Assign_00214800(Ref_00214800* r, void* p)
{
    Release_00214800(r);
    r->m_p = p;
    if (p) {
        func_00183C98(p, r);
    }
}

bool Cmd_00214800(void* params, Script_00214800* script)
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
    Script_00214800* s = func_001F0750(time, sparams, callback, cbparams, script->m_object, sname, 0, 0, 0, 0);
    Assign_00214800(&s->m_ref, func_0022DD38(D_0038FC78));
    return true;
}
