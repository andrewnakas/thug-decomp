struct Obj_001F5180 {
    char pad0[0xC];
    int mC;
    bool Empty();
};

bool Obj_001F5180::Empty()
{
    return mC == 0;
}
