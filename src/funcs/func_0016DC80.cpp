typedef int qword __attribute__((mode(TI)));

class Obj_0016DC80 {
public:
    qword m_rows[5];
    Obj_0016DC80* Copy(const Obj_0016DC80* src);
};

Obj_0016DC80* Obj_0016DC80::Copy(const Obj_0016DC80* src)
{
    *this = *src;
    return this;
}
