struct Rgba_00148678 {
    unsigned char r, g, b, a;
};

struct Pal_00148678 {
    char pad[0x10];
    unsigned char* m10;
};

extern unsigned char D_004654E8[];

struct Img_00148678 {
    char pad[0xC];
    unsigned short m_width;
    unsigned short m_height;
    char pad10[0xC];
    Pal_00148678* m1C;
    char pad20[0x8];
    unsigned int* m28;
    unsigned char Nearest(const Rgba_00148678* c);
    void SetPixel(unsigned int c, unsigned short x, unsigned short y);
};

extern "C" unsigned char func_00147F08(Img_00148678* self, const Rgba_00148678* c);

void Img_00148678::SetPixel(unsigned int c, unsigned short x, unsigned short y)
{
    if (m28) {
        m28[y * m_width + x] = c;
    } else {
        unsigned char* pix = m1C->m10;
        Rgba_00148678 tmp = *(Rgba_00148678*)&c;
        unsigned char i = func_00147F08(this, &tmp);
        int row = y + 1;
        pix[(m_height - row) * m_width + x] = D_004654E8[i];
    }
}
