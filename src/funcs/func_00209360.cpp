typedef int qword __attribute__((mode(TI)));
struct Vec_00209360 {
    qword q;
    void Set(const Vec_00209360* o);
};

void Vec_00209360::Set(const Vec_00209360* o)
{
    q = o->q;
}
