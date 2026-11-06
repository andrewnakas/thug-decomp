struct Mgr_0021E830 {
    char m_pad0[0x39C];
    void* m39C;
};

extern Mgr_0021E830* D_0038FC78;
extern char D_0038F850[];
extern char D_00371748[];
extern "C" int func_001E87B8(void* params, char* name);
extern "C" void func_001F0370(char* fmt, int a, int b, int c);
extern "C" void func_0025F9D0(void* p, unsigned int a, void* b, unsigned int c);

bool Cmd_0021E830(void* params, void* script)
{
    func_001E87B8(params, D_0038F850);
    func_001F0370(D_00371748, 0, 0, 0);
    func_0025F9D0(D_0038FC78->m39C, 0xF5012F52, params, 0xF5012F52);
    return true;
}
