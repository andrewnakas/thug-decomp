struct Entry_0026A958 {
    char pad[0x5C];
    short m5C;
    bool Is(int id);
};

bool Entry_0026A958::Is(int id)
{
    return m5C == id;
}
