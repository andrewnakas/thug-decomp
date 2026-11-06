class Obj_00138700 {
public:
    int m0;
    int m4;
    virtual void V0();
    virtual void V1();
    virtual int V2(int a, int b, int d, int e);
    int Set(int a, int b, int c, int d, int e);
};

int Obj_00138700::Set(int a, int b, int c, int d, int e)
{
    m0 = c;
    return V2(a, b, d, e);
}
