struct Base12AF80 {
    int m0;
    int m4;
    virtual ~Base12AF80();
};

struct Obj12AF80 : Base12AF80 {
    virtual void Update();
    virtual ~Obj12AF80();
};

Obj12AF80::~Obj12AF80()
{
}
