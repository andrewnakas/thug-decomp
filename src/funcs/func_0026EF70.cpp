extern char D_00376490[];
extern char D_003764A0[];

extern "C" void* func_00122CF8(int size);
extern "C" void* func_001E8DD0(void* p);
extern "C" void func_001E8E98(void* arr, int size, int type);
extern "C" void func_001E9170(void* arr, int index, void* value);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E7A68(void* params, unsigned int name, int type, void* value);
extern "C" void func_001E7A30(void* params, unsigned int name, int type, char* value);
extern "C" unsigned int func_001F0D78(char* s);
extern "C" char* func_0026DF90(void* p);

struct Rec_0026EF70 {
    char m[0x1C];
};

extern "C" void func_0026EB38(Rec_0026EF70* rec, void* out);

struct Records_0026EF70 {
    int m0;
    int m4;
    void* m8;
    Rec_0026EF70* mC;
    void WriteToStructure(void* out);
};

void Records_0026EF70::WriteToStructure(void* out)
{
    void* arr = func_001E8DD0(func_00122CF8(0x10));
    func_001E8E98(arr, m4, 0xA);
    for (int i = 0; i < m4; i++) {
        void* s = func_001E6978(func_001190D0(8));
        func_0026EB38(&mC[i], s);
        func_001E9170(arr, i, s);
    }
    func_001E7A68(out, func_001F0D78(D_00376490), 0xC, arr);
    unsigned int key = func_001F0D78(D_003764A0);
    func_001E7A30(out, key, 3, func_0026DF90(m8));
}
