struct Obj_002306A0 {
    char pad[0x3AC];
    unsigned int m_3AC;
    bool Check();
};

extern void* D_00392068;
extern char D_00372CC0[];
extern char D_00372F48[];
extern "C" bool func_002A1998(void* a);
extern "C" unsigned int func_001F0D78(char* s);

bool Obj_002306A0::Check()
{
    if (func_002A1998(D_00392068)) {
        return true;
    }
    if (m_3AC == func_001F0D78(D_00372CC0) || m_3AC == func_001F0D78(D_00372F48)) {
        return true;
    }
    return false;
}
