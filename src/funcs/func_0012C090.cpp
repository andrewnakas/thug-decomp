struct Base12C090 {
    int m0;
    int m4;
    virtual ~Base12C090();
};

struct Obj12C090 : Base12C090 {
    virtual void Update();
    virtual ~Obj12C090();
};

Obj12C090::~Obj12C090()
{
}
