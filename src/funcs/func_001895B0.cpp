struct Obj_001895B0 {
    char pad0[0x8];
    void* m8;
    void* mC;
    void* Find(unsigned int key);
};

extern "C" void* func_0018A8C0(void* table, unsigned int* key, int a);

void* Obj_001895B0::Find(unsigned int key)
{
    void* r = func_0018A8C0(m8, &key, 1);
    if (!r)
        r = func_0018A8C0(mC, &key, 1);
    return r;
}
