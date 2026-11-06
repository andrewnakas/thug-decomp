/* sym: __13Base_00146C90 = 0x001385A0 */
/* sym: _vt$12Snd_00146C90 = 0x0035F198 */
class Base_00146C90 {
public:
    int m0;
    int m4;
    Base_00146C90();
    virtual ~Base_00146C90();
};

class Snd_00146C90 : public Base_00146C90 {
public:
    short mC;
    short mE;
    unsigned char m10;
    unsigned char m11;
    unsigned char m12;
    int m14;
    int m18;
    void* m1C;
    int m20;
    void* m24;
    void* m28;
    void* m2C;
    Snd_00146C90(int id);
    virtual ~Snd_00146C90();
};

Snd_00146C90::Snd_00146C90(int id)
{
    m18 = id;
    m14 = 0;
    m1C = 0;
    m20 = 0;
    m24 = 0;
    m28 = 0;
    m2C = 0;
    m12 = 0;
    m11 = 0;
    m10 = 0;
    mE = 0;
    mC = 0;
}
