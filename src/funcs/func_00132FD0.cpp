extern "C" void* func_00134BB8(void* table, int* key, int n);

struct Obj_00132FD0 {
    char pad[0xD0];
    void* m_D0;
    void* Find(int key);
};

void* Obj_00132FD0::Find(int key)
{
    return func_00134BB8(m_D0, &key, 1);
}
