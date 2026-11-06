struct Obj_001B3508 {
    char pad[0x24];
    int m24[4];
    void Clear();
};

void Obj_001B3508::Clear()
{
    int i;
    for (i = 3; i >= 0; i--) {
        m24[i] = 0;
    }
}
