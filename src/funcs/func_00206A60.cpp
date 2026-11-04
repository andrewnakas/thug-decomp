struct Cat_00206A60 {
    void* m_params;
    void* m_rot;
    void* m_pos;
};

extern "C" void* func_00122CF8(int size);
extern "C" void* func_001E8DD0(void* p);
extern "C" void func_001E8E98(void* arr, int type, int size);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E77D0(void* s, unsigned int name, void* value);
extern "C" void func_001E7648(void* s, unsigned int name, void* value);
extern "C" void func_001E9170(void* arr, int i, void* s);
extern "C" void func_001E7720(void* s, unsigned int name, void* arr);

struct Skater_00206A60 {
    char pad[0x248];
    Cat_00206A60* m_cats[11];
    void SaveCATInfo(void* params);
};

void Skater_00206A60::SaveCATInfo(void* params)
{
    void* arr = func_001E8DD0(func_00122CF8(0x10));
    func_001E8E98(arr, 11, 10);
    for (int i = 0; i < 11; i++) {
        void* s = func_001E6978(func_001190D0(8));
        func_001E77D0(s, 0x26A7CADF, m_cats[i]->m_params);
        func_001E7648(s, 0x6B19FC8F, m_cats[i]->m_pos);
        func_001E7648(s, 0x2E628EE6, m_cats[i]->m_rot);
        func_001E9170(arr, i, s);
    }
    func_001E7720(params, 0x1E26FD3E, arr);
}
