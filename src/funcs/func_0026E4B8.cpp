extern "C" void func_0026E208(void* p, void* a);

struct Elem_0026E4B8 {
    char pad[0x14];
};

struct Arr_0026E4B8 {
    int m0;
    int m_count;
    Elem_0026E4B8* m_items;
    void Run(void* a);
};

void Arr_0026E4B8::Run(void* a)
{
    for (int i = 0; i < m_count; i++)
        func_0026E208(&m_items[i], a);
}
