struct Obj_00181BC0 {
    char pad0[0x8];
    unsigned int m8;
    char padC[0x38 - 0xC];
    unsigned int m38;
    bool Fn();
};

bool Obj_00181BC0::Fn()
{
    for (unsigned int i = 0; i <= m8; i++) {
        if (m38 & (0x2040000 << i))
            return true;
    }
    return false;
}
