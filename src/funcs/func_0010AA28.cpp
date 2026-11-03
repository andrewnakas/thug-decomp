struct Inner10AA28 {
    char pad[0x38];
    int m38;
};

struct Ref10AA28 {
    Inner10AA28* m0;
};

struct Obj10AA28 {
    char pad[0x8C];
    Ref10AA28* m8C;
    int Get() const;
};

int Obj10AA28::Get() const
{
    return m8C->m0->m38;
}
