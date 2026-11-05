struct Obj_002654F8 {
    char pad[0x1C];
    int m1C;
    int m20;
    int m24;
    bool Take(int id);
};

bool Obj_002654F8::Take(int id)
{
    if (m24 && m20 == id) {
        m24 = 0;
        m1C = 0;
        return true;
    }
    return false;
}
