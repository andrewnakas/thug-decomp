struct Entry_00295B98 {
    int m0;
    char m4[0x2A1];
    unsigned char m2A5;
    char pad2[0x350 - 0x2A6];
};
extern "C" int func_00291EC0();
extern "C" int func_00336228(const char*, const char*);

struct Obj_00295B98 {
    char pad0[0x20];
    Entry_00295B98 m20[50];
    Entry_00295B98* FindByName(const char* name);
};

Entry_00295B98* Obj_00295B98::FindByName(const char* name)
{
    int key = func_00291EC0();
    for (int i = 0; i < 50; i++) {
        if (m20[i].m2A5 && m20[i].m0 == key && func_00336228(m20[i].m4, name) == 0) return &m20[i];
    }
    return 0;
}
