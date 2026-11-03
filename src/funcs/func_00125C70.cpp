struct Base125C70 {
    int m0;
    int m4;
    virtual ~Base125C70();
};

struct Obj125C70 : Base125C70 {
    virtual void Update();
    virtual ~Obj125C70();
};

Obj125C70::~Obj125C70()
{
}
