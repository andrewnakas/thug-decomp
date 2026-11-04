struct Obj10A070 {
    char pad[0xC];
    int mC;
    int m10;
    void Reset();
};

void Obj10A070::Reset()
{
    mC = -1;
    m10 = 0;
}
