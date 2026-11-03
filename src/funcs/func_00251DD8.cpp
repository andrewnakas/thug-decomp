struct Str_00251DD8 {
    int m_data[4];
};

struct Entry_00251DD8 {
    Str_00251DD8 m_name;
    int m_pos;
    int m_arr[3];
    int m_20;
};

extern char D_00374D00[];
extern const char D_00374B88[];
extern const char D_00374D18[];
extern char D_00374D30[];
extern char D_00374D40[];
extern char D_003906C8[];
extern char D_003906B8[];

extern "C" int func_00240850();
extern "C" int func_0023EBD0(int);
extern "C" void* func_001190D0(int size);
extern "C" void* func_00122CF8(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void* func_001E8DD0(void* p);
extern "C" void func_001E8E98(void* arr, int type, int size);
extern "C" int func_00103F28(const char* fmt, ...);
extern "C" const char* func_001041B8(Str_00251DD8* s);
extern "C" int func_00250C50(Entry_00251DD8* e, int mode);
extern "C" void func_001E7138(void* s, const char* name, const char* value);
extern "C" void func_001E7268(void* s, const char* name, int value);
extern "C" void func_001E7360(void* s, int name, unsigned int value);
extern "C" void func_001E9170(void* arr, int index, void* s);
extern "C" void func_001E76D8(void* s, const char* name, void* arr);
extern "C" void func_001E6518(void* arr);
extern "C" void func_001E8DE8(void* arr, int in_chrg);
extern "C" void func_001E6AE8(void* s, int in_chrg);
extern "C" int func_001F0938(const char* name, void* params, int a, int b, int c, int d, int e, int f, int g, int h);

struct Table_00251DD8 {
    int m_0;
    int m_4;
    int m_round;
    Entry_00251DD8 m_entries[8];
    void SetupJudgeText();
};

void Table_00251DD8::SetupJudgeText()
{
    if (!func_0023EBD0(func_00240850()))
        return;
    void* params = func_001E6978(func_001190D0(8));
    void* arr = func_001E8DD0(func_00122CF8(0x10));
    func_001E8E98(arr, 5, 10);
    func_00103F28(D_00374D00);
    for (int i = 0; i < 8; i++) {
        func_00103F28(D_00374B88, i, m_entries[i].m_pos, func_001041B8(&m_entries[i].m_name), m_entries[i].m_arr[0], m_entries[i].m_arr[1], m_entries[i].m_arr[2], func_00250C50(&m_entries[i], 3));
    }
    for (int i = 0; i < 5; i++) {
        void* s = func_001E6978(func_001190D0(8));
        func_001E7138(s, D_003906C8, func_001041B8(&m_entries[i].m_name));
        func_00103F28(D_00374D18, m_round);
        func_001E7268(s, D_003906B8, func_00250C50(&m_entries[i], m_round));
        if (m_entries[i].m_pos == 0)
            func_001E7360(s, 0, 0x67E6859A);
        func_001E9170(arr, i, s);
    }
    func_001E76D8(params, D_00374D30, arr);
    func_001E6518(arr);
    if (arr)
        func_001E8DE8(arr, 3);
    func_001F0938(D_00374D40, params, 0, 0, -1, 0, 0, 0, 0, 0);
    if (params)
        func_001E6AE8(params, 3);
}
