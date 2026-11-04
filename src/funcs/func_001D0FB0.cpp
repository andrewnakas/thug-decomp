extern char D_00363A18[];

struct Obj {
    char pad[0x20];
    void* m_vt;
    Obj();
};

Obj::Obj()
{
    m_vt = D_00363A18;
}
