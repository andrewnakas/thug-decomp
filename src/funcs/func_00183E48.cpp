struct Base_00183E48 {
    int m0;
    int m4;
    virtual ~Base_00183E48();
    virtual void F();
};

struct Obj_00183E48 : Base_00183E48 {
    unsigned int mC;
    bool Flag1() const { return (mC & 2) != 0; }
};

void func_00183E48(Obj_00183E48* o)
{
    if (!o->Flag1())
        delete o;
}
