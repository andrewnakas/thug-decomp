struct Entry_00295E28 {
    int m0;
    char pad[0x2A1];
    unsigned char m2A5;
    char pad2[0x350 - 0x2A6];
};
extern "C" int func_00294888(Entry_00295E28*);

struct Obj_00295E28 {
    char pad0[0x20];
    Entry_00295E28 m20[50];
    int Count(int key);
};

int Obj_00295E28::Count(int key)
{
    int n = 0;
    Entry_00295E28* e = m20;
    for (int i = 0; i < 50; i++, e++) {
        if (!e->m2A5) continue;
        if (key && e->m0 != key) continue;
        if (func_00294888(e)) n++;
    }
    return n;
}
