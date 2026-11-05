struct Entry_002220B8 {
    unsigned char m0;
    unsigned char m1;
    char pad2[2];
    int m4;
    int m8;
};

extern char D_00371900[];
extern "C" Entry_002220B8* func_001E6E90(int s, Entry_002220B8* prev);
extern "C" void func_00103F28(char* fmt, ...);

int func_002220B8(int s, int id)
{
    int r = 0;
    Entry_002220B8* e = func_001E6E90(s, 0);
    while (e) {
        Entry_002220B8* next = func_001E6E90(s, e);
        if (e->m1 == 1 && e->m8 == id) {
            func_00103F28(D_00371900, e->m8);
            r = e->m4;
        }
        e = next;
    }
    return r;
}
