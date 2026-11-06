struct Mgr_0021E940 {
    char pad[0x3A0];
    void* m3A0;
};

extern Mgr_0021E940* D_0038FC78;
extern char D_00371728[];

extern "C" int func_001E8398(void* params, unsigned int id, unsigned int* out, int req);
extern "C" int func_001E7E58(void* params, const char* name, int* out, int req);
extern "C" void func_0025F708(void* obj, unsigned int id, bool flag);

bool Cmd_0021E940(void* params, void* script)
{
    unsigned int id = 0;
    func_001E8398(params, 0xA1DC81F9, &id, 0);
    int v = 0;
    func_001E7E58(params, D_00371728, &v, 0);
    func_0025F708(D_0038FC78->m3A0, id, v != 0);
    return true;
}
