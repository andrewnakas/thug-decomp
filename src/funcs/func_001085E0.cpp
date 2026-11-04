struct Inner1085E0 {
    char pad[0xC];
    int mC;
};

struct Obj1085E0 {
    char pad[0x10];
    Inner1085E0* m10;
    void ClearInner();
};

void Obj1085E0::ClearInner()
{
    m10->mC = 0;
}
