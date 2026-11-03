struct Base14B028 {
    int m_pad[5];
    Base14B028();
    virtual ~Base14B028();
};

struct Comp14B080 : Base14B028 {
    Comp14B080();
    virtual void Update();
    virtual ~Comp14B080();
};

Comp14B080::~Comp14B080()
{
}
