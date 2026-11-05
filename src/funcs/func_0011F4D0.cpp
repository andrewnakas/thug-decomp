extern "C" int func_0011F508(void* self, int key);

struct Obj_0011F4D0 {
    char pad[0x108];
    int m_a[64];
    int Find(int i);
};

int Obj_0011F4D0::Find(int i)
{
    return func_0011F508(this, m_a[i]);
}
