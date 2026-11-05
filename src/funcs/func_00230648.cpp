struct Obj_00230648 {
    char pad[0x3B0];
    unsigned int m_3B0;
    bool Check();
};

extern void* D_00392068;
extern char D_00372F38[];
extern "C" bool func_002A19A8(void* a);
extern "C" unsigned int func_001F0D78(char* s);

bool Obj_00230648::Check()
{
    bool r = false;
    if (func_002A19A8(D_00392068)) {
        r = m_3B0 != func_001F0D78(D_00372F38);
    }
    return r;
}
