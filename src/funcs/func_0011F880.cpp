/* sym: __13Base_0011F880 = 0x00183CF8 */
/* sym: __12Prm_0011F880 = 0x001E6978 */
/* sym: _vt$13Comp_0011F880 = 0x0035CA80 */
struct Base_0011F880 {
    int m0;
    int m4;
    Base_0011F880();
    virtual void V0();
};

struct Prm_0011F880 {
    int m0;
    int m4;
    Prm_0011F880();
    ~Prm_0011F880();
};

struct Comp_0011F880 : Base_0011F880 {
    char padC[0x48 - 0xC];
    Prm_0011F880 m_params;
    int m50;
    int m54;
    Comp_0011F880();
    virtual void V0();
};

Comp_0011F880::Comp_0011F880()
{
    m50 = 0;
    m54 = 0;
}
