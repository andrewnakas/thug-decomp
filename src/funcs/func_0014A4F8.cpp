extern "C" void* func_00172A28(void* key);

struct Obj_0014A4F8 {
    int m0[2];
    void* m_8;
    bool Load(void* key);
};

bool Obj_0014A4F8::Load(void* key)
{
    m_8 = func_00172A28(key);
    return m_8 != 0;
}
