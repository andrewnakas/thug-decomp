struct Entry_002DBCA8 {
    int m0;
};

struct Table_002DBCA8;

struct Mgr_002DBCA8 {
    char pad0[0x9E00];
    char m9E00[4];
};

extern Mgr_002DBCA8* D_00392068;
extern "C" Entry_002DBCA8* func_002DB9A0(void* t);

int func_002DBCA8()
{
    Entry_002DBCA8* e = func_002DB9A0(D_00392068->m9E00);
    if (e && e->m0)
        return 0;
    return 1;
}
