/* sym: _vt$10Comp277938 = 0x003768F0 */
/* sym: _$_10Part2365A8 = 0x002365A8 */
/* sym: _$_10Base277938 = 0x00184DD8 */
struct Base277938 {
    int m_pad[6];
    Base277938();
    virtual ~Base277938();
};

struct Part2365A8 {
    ~Part2365A8();
};

struct Comp277938 : Base277938 {
    Part2365A8* m1C;
    Comp277938();
    virtual void Update();
    virtual ~Comp277938();
};

Comp277938::~Comp277938()
{
    delete m1C;
}
