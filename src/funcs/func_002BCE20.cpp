struct Obj_002BCE20 {
    char pad0[0x6A60];
    void* m6A60;
    int m6A64;
    void* Get(int clear);
};

void* Obj_002BCE20::Get(int clear)
{
    if (clear)
        m6A64 &= ~8;
    return m6A60;
}
