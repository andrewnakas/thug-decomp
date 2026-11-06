struct Comp_00215FB8 {
    unsigned char m0;
    unsigned char m_type;
    char m_pad2[2];
    int m_name;
    int m_val;
};

extern void* D_0038FC78;

extern "C" Comp_00215FB8* func_001E6E90(void* params, Comp_00215FB8* prev);
extern "C" void* func_0022E358(void* mgr);
extern "C" int func_0024F908(void* obj, int key);

bool Cmd_00215FB8(void* params)
{
    void* mgr = D_0038FC78;
    for (Comp_00215FB8* c = func_001E6E90(params, 0); c; c = func_001E6E90(params, c)) {
        if (c->m_name == 0 && c->m_type == 13) {
            if (func_0024F908(func_0022E358(mgr), c->m_val))
                return true;
        }
    }
    return false;
}
