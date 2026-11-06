extern "C" void* func_0018A8C0(void* table, int* key, int n);

struct Obj_00189600 {
    int m0[3];
    void* m_C;
    void* Find(int key);
};

void* Obj_00189600::Find(int key)
{
    return func_0018A8C0(m_C, &key, 1);
}
