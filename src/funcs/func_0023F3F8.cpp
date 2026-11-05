struct Obj_0023F3F8 {
    char pad0[0x44];
    int m44;
    void Set(int on);
};

void Obj_0023F3F8::Set(int on)
{
    if (on) m44 = 1;
    else m44 = 0;
}
