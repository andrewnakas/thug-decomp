struct Record_0026EE78 {
    char data[0x1C];
};

struct Array_0026EE78 {
    char pad0[0xC];
    int m_size;
};

struct Records_0026EE78 {
    int m0;
    int m_count;
    void* m_initials;
    Record_0026EE78* m_records;
    void ReadFromStructure(void* s);
};

extern "C" bool func_001E82B8(void* s, char* name, Array_0026EE78** out, int required);
extern "C" void* func_001E9378(Array_0026EE78* a, int index);
extern "C" void func_0026EA30(Record_0026EE78* r, void* s);
extern "C" bool func_001E8890(void* s, char* name, const char** out, int required);
extern "C" void func_0026DF70(void* initials, const char* s);

extern char D_00376490[];
extern char D_003764A0[];
extern char D_00391468[];

void Records_0026EE78::ReadFromStructure(void* s)
{
    Array_0026EE78* arr = 0;
    func_001E82B8(s, D_00376490, &arr, 0);
    if (m_count != arr->m_size) {
        return;
    }
    for (int i = 0; i < m_count; i++) {
        func_0026EA30(&m_records[i], func_001E9378(arr, i));
    }
    const char* initials = D_00391468;
    func_001E8890(s, D_003764A0, &initials, 0);
    func_0026DF70(m_initials, initials);
}
