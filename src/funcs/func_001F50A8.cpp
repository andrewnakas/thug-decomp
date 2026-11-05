struct Obj_001F50A8 {
    char pad0[0xC];
    int mC;
    int m10;
    bool Same();
};

bool Obj_001F50A8::Same()
{
    return mC == m10;
}
