struct Obj_00265210 {
    char pad[0x20];
    int m20;
    int m24;
    bool Is(int id);
};

bool Obj_00265210::Is(int id)
{
    return m24 && id == m20;
}
