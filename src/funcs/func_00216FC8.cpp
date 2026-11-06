struct Mgr_00216FC8 {
    char m_pad0[0x3B4];
    unsigned int m3B4;
};

extern Mgr_00216FC8* D_0038FC78;
extern void* D_00392068;
extern char D_00370C90[];
extern "C" int func_002A19A8(void* p);
extern "C" unsigned int func_001F0D78(char* s);

bool Cmd_00216FC8(void* params, void* script)
{
    Mgr_00216FC8* mgr = D_0038FC78;
    bool r = false;
    if (func_002A19A8(D_00392068))
        r = (mgr->m3B4 == func_001F0D78(D_00370C90));
    return r;
}
