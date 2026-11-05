struct Item_001D0888 {
    char pad[0x20];
    virtual int v0();
    virtual int v1();
    virtual int v2();
    virtual int v3();
    virtual int v4();
    virtual int v5();
};
struct Obj_001D0888 {
    char pad[0xC];
    void* mC;
    bool Check(int key);
};
extern "C" Item_001D0888* func_001D0E90(void* tbl, int* key, int n);

bool Obj_001D0888::Check(int key)
{
    Item_001D0888* p = func_001D0E90(mC, &key, 1);
    if (p && p->v5())
        return true;
    return false;
}
