/* sym: __13Base_002B6E18 = 0x002B6C00 */
/* sym: _vt$12Der_002B6E18 = 0x0037A3E0 */

struct Base_002B6E18 {
    int m0;
    unsigned int m4;
    int m8;
    Base_002B6E18();
    virtual void V1();
    virtual void V2();
};

struct Der_002B6E18 : Base_002B6E18 {
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    Der_002B6E18();
    virtual void V1();
    virtual void V2();
};

Der_002B6E18::Der_002B6E18()
{
    m4 |= 1;
    m20 = 1;
    m24 = 0;
}
