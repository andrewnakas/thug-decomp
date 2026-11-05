/* sym: __12Mem_0026CB10 = 0x00104008 */
/* sym: _vt$13Node_0026CB10 = 0x003763C8 */
struct Mem_0026CB10 {
    int m0;
    Mem_0026CB10();
    ~Mem_0026CB10();
};

class Link_0026CB10 {
public:
    int m0;
    Link_0026CB10* m4;
    int m8;
    Link_0026CB10* mC;
    Link_0026CB10* m10;
    Link_0026CB10() : m4(this), m8(0), mC(this), m10(this) {}
    virtual ~Link_0026CB10();
    virtual void Run();
};

class Node_0026CB10 : public Link_0026CB10 {
public:
    char pad18[0x40 - 0x18];
    int m40;
    int m44;
    int m48;
    int m4C;
    Mem_0026CB10 m50;
    Node_0026CB10();
    virtual void Update();
    virtual ~Node_0026CB10();
};

Node_0026CB10::Node_0026CB10()
{
    m4C = 1;
    m44 = 0;
    m40 = 0;
}
