struct Obj_001EE620 {
    char pad0[0x10];
    int m10;
    bool Has();
};

bool Obj_001EE620::Has()
{
    return m10 != 0;
}
