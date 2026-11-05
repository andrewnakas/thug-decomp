struct Obj_001F9F10 {
    char pad[0x2C4];
    int m2C4;
    int m2C8;
    int m2CC;
    int m2D0;
    int Test();
};

int Obj_001F9F10::Test()
{
    if (m2C8 && m2D0)
        return 1;
    if (!m2C4 || m2CC)
        return 1;
    return 0;
}
