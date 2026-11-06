extern "C" void* func_00243C18(void* tbl, int* key, int flag);

struct Obj_0023BB50 {
    int m0;
    char m4[0x10];
    void* Find(int key);
};

void* Obj_0023BB50::Find(int key)
{
    return func_00243C18(m4, &key, 0);
}
