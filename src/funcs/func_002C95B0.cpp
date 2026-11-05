struct Box_002C95B0 {
    unsigned char m[6];
};

extern "C" void* func_002C0640(void* board, Box_002C95B0* box, int* out);

struct Obj_002C95B0 {
    char pad0[8];
    void* m8;
    char padC[4];
    Box_002C95B0 m10;
    bool Has();
};

bool Obj_002C95B0::Has()
{
    int idx;
    return func_002C0640(m8, &m10, &idx) != 0;
}
