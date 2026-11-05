extern "C" void* func_00266978(void* map, int* key, int a);

struct Obj_00265EA0 {
    char pad[0x20];
    int m_map;
    void* Find(int key);
};

void* Obj_00265EA0::Find(int key)
{
    return func_00266978(&m_map, &key, 0);
}
