struct Item_0023E1B0 {
    char pad0[0x18];
    void* m18;
};
extern "C" Item_0023E1B0* func_0023BAD8(void* o, int key, int flag);
extern "C" int func_00249C58(void* p);

int Call_0023E1B0(void* o, int key)
{
    return func_00249C58(func_0023BAD8(o, key, 1)->m18);
}
