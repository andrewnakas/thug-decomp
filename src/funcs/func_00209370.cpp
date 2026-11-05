typedef int qword __attribute__((mode(TI)));
struct Obj_00209370 {
    qword m0;
    qword m10;
    void Set(const qword* o);
};

void Obj_00209370::Set(const qword* o)
{
    m10 = *o;
}
