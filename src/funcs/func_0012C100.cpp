struct Base12C100 {
    int m0;
    int m4;
    virtual ~Base12C100();
};

struct Obj12C100 : Base12C100 {
    virtual void Update();
    virtual ~Obj12C100();
};

Obj12C100::~Obj12C100()
{
}
