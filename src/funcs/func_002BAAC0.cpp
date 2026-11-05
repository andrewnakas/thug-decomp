/* sym: __12Box_002BAAC0UcScUcUcUcUc = 0x002BAA28 */
/* sym: _vt$14Piece_002BAAC0 = 0x0037A740 */

struct Box_002BAAC0 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
    Box_002BAAC0(unsigned char x = 0, signed char y = 0, unsigned char z = 0,
                 unsigned char w = 0, unsigned char h = 0, unsigned char d = 0);
};

struct Piece_002BAAC0 {
    Box_002BAAC0 m0;
    char pad6[2];
    int m8;
    char padC[0x1C];
    void* m28;
    int m2C;
    int m30;
    int m34;
    Piece_002BAAC0();
    virtual void V1();
};

Piece_002BAAC0::Piece_002BAAC0()
{
    m8 = 0;
    m28 = 0;
    m2C = 0;
    m30 = 0;
}
