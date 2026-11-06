/* sym: __12Mem_0026CD40 = 0x00104008 */
/* sym: _vt$13Node_0026CD40 = 0x00376368 */
struct Mem_0026CD40 {
    int m0;
    Mem_0026CD40();
    ~Mem_0026CD40();
};

class Link_0026CD40 {
public:
    int m0;
    Link_0026CD40* m4;
    int m8;
    Link_0026CD40* mC;
    Link_0026CD40* m10;
    Link_0026CD40() : m4(this), m8(0), mC(this), m10(this) {}
    virtual ~Link_0026CD40();
    virtual void Run();
};

class Node_0026CD40 : public Link_0026CD40 {
public:
    Mem_0026CD40 m18;
    Node_0026CD40();
    virtual void Update();
    virtual ~Node_0026CD40();
};

Node_0026CD40::Node_0026CD40()
{
}
