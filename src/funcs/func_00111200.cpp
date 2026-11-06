/* sym: __13Base_00111200 = 0x0010E3C0 */
/* sym: _vt$13File_00111200 = 0x0035BF30 */
class Base_00111200 {
public:
    int m0[14];
    Base_00111200();
    virtual void V0();
};

class File_00111200 : public Base_00111200 {
public:
    int m3C;
    int m40[64];
    int m140;
    int m144;
    int m148;
    int m14C;
    File_00111200();
    virtual void V0();
};

File_00111200::File_00111200()
{
    m3C = -1;
    m140 = 0;
    m144 = 0;
    m148 = 0;
    m14C = 0;
}
