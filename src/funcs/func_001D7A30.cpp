struct Obj_001D7A30 {
    unsigned int m0;
    void SetFlag(int on);
};

void Obj_001D7A30::SetFlag(int on)
{
    if (on) m0 |= 1;
    else m0 &= ~1u;
}
