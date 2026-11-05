extern "C" void* func_00134BB8(void* table, int* key, int n);

struct Obj_00136F30 {
    int m0[8];
    void* m_20;
    bool Has(int key);
};

bool Obj_00136F30::Has(int key)
{
    return func_00134BB8(m_20, &key, 1) != 0;
}
