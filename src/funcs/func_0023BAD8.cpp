extern "C" void* func_00243BC8(void* tbl, int* key, int flag);

struct Obj_0023BAD8 {
    int m0;
    char m4[0x10];
    void* Find(int key, int flag);
};

void* Obj_0023BAD8::Find(int key, int flag)
{
    return func_00243BC8(m4, &key, flag);
}
