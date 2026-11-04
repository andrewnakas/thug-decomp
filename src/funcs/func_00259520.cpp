typedef int qword __attribute__((mode(TI)));

union Vec_00259520 {
    qword q;
    struct { float x, y, z, w; } v;
};

struct Obj_00259520 {
    char m_pad[0x50];
    Vec_00259520 m_pos;
    void GetPos(Vec_00259520* out);
};

void Obj_00259520::GetPos(Vec_00259520* out)
{
    *out = m_pos;
}
