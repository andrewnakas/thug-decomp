struct Data_0029A2F0 {
    char d[0x1132];
};

struct Obj_0029A2F0 {
    char pad[0x38];
    Data_0029A2F0 data;
    void Set(const Data_0029A2F0* src);
};

void Obj_0029A2F0::Set(const Data_0029A2F0* src)
{
    data = *src;
}
