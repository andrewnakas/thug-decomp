struct Obj_0024B520 {
    char pad0[0x98];
    int m98;
    char pad9C[0xA4 - 0x9C];
    int mA4;
    bool Busy();
};

bool Obj_0024B520::Busy()
{
    bool r = false;
    if (m98 || mA4) r = true;
    return r;
}
