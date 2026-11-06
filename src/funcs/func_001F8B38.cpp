extern "C" char* func_00331A9C(char*, char*);
extern "C" char* func_003248E0(char*, char*);

struct Entry_001F8B38 {
    char m_name[0x58];
};

extern char* D_00351FC8[];
extern Entry_001F8B38 D_003F3400[];
extern char D_003F3458[];
extern char D_0038EB98[];

int func_001F8B38(int, char* a, char* b)
{
    int i = 0;
    int done = 0;
    while (!done) {
        func_00331A9C(D_003F3400[i].m_name, D_00351FC8[i]);
        if (D_00351FC8[i][0] == 0) {
            done = 1;
        } else {
            i++;
        }
    }
    func_003248E0(D_003F3458, a);
    func_003248E0(D_003F3458, D_0038EB98);
    func_003248E0(D_003F3458 + 0xB0, b);
    func_003248E0(D_003F3458 + 0xB0, D_0038EB98);
    return 0;
}
