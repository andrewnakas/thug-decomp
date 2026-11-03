struct Obj10F638 {
    char pad[0x818];
    int m818[8];
    int Get(int i) const;
};

int Obj10F638::Get(int i) const
{
    return m818[i];
}
