struct Obj172858 {
    char pad[0x64];
    int* m64;
    int Get(int i) const;
};

int Obj172858::Get(int i) const
{
    return m64[i];
}
