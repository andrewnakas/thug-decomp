extern char D_00376420[];

struct Record_0026E740 {
    int m[5];
};

struct Table_0026E740 {
    int pad0;
    int m_count;
    Record_0026E740* m_records;
};

extern "C" void* func_00122CF8(int size);
extern "C" void* func_001E8DD0(void* p);
extern "C" void func_001E8E98(void* arr, int size, int type);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_0026E258(Record_0026E740* rec, void* params);
extern "C" void func_001E9170(void* arr, int i, void* params);
extern "C" unsigned int func_001F0D78(const char* name);
extern "C" void func_001E7A68(void* params, unsigned int name, int type, void* value);

void func_0026E740(Table_0026E740* table, void* params)
{
    void* arr = func_001E8DD0(func_00122CF8(0x10));
    func_001E8E98(arr, table->m_count, 0xA);
    for (int i = 0; i < table->m_count; i++) {
        void* rec = func_001E6978(func_001190D0(8));
        func_0026E258(&table->m_records[i], rec);
        func_001E9170(arr, i, rec);
    }
    func_001E7A68(params, func_001F0D78(D_00376420), 0xC, arr);
}
