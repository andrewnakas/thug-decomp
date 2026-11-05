struct Obj_002BCF28 {
    char pad0[0x6A64];
    unsigned int m6A64;
    bool Ready();
};

bool Obj_002BCF28::Ready()
{
    if (!(m6A64 & 5) || (m6A64 & 8))
        return false;
    return true;
}
