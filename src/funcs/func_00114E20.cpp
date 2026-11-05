typedef int qword __attribute__((mode(TI)));

struct Row_00114E20 {
    qword q;
};

struct Mat_00114E20 {
    Row_00114E20 r[4];
    void Set(const Mat_00114E20& m)
    {
        r[0] = m.r[0];
        r[1] = m.r[1];
        r[2] = m.r[2];
        r[3] = m.r[3];
    }
};

struct Obj_00114E20 {
    char pad[0x70];
    Mat_00114E20 m_70;
    void SetMatrix(const Mat_00114E20* m);
};

void Obj_00114E20::SetMatrix(const Mat_00114E20* m)
{
    m_70.Set(*m);
}
