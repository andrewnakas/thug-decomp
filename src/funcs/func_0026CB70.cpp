struct Obj_0026CB70 {
    char pad[0x40];
    int m40;
    int m44;
    void Commit();
};

void Obj_0026CB70::Commit()
{
    m44 += m40;
    m40 = 0;
}
