struct Box_002BBFD8 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};

struct Item_002BBFD8 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char rot;
    unsigned char flip;
    unsigned char pad5[3];
    int m8;
};

struct Piece_002BBFD8 {
    int m0;
    unsigned int m4;
};

extern "C" Item_002BBFD8* func_002BB3B0(void* self, int i);
extern "C" void* func_002B6CF0(Piece_002BBFD8* p);
extern "C" int func_002B6E90(void* p);
extern "C" unsigned char* func_002BAA48(void* b, int idx);

struct Obj_002BBFD8 {
    Box_002BBFD8 m0;
    char pad6[0x2A];
    int m30;
    void Add(Piece_002BBFD8* piece, Box_002BBFD8* box, int rot, int flip);
};

void Obj_002BBFD8::Add(Piece_002BBFD8* piece, Box_002BBFD8* box, int rot, int flip)
{
    void* src = 0;
    if (piece->m4 & 1) src = func_002B6CF0(piece);
    Item_002BBFD8* it = func_002BB3B0(this, m30++);
    if (!src) return;
    it->x = box->x;
    it->y = box->y;
    it->z = box->z;
    it->rot = rot;
    it->flip = flip;
    it->m8 = func_002B6E90(src);
    int ex = box->x + box->w;
    int ey = box->y + box->h;
    int ez = box->z + box->d;
    unsigned char w = m0.w;
    unsigned char h = m0.h;
    unsigned char d = m0.d;
    if (w < ex) w = ex;
    if (h < ey) h = ey;
    if (d < ez) d = ez;
    m0.w = w;
    m0.h = h;
    m0.d = d;
    if (!*func_002BAA48(this, 4)) *func_002BAA48(this, 4) = 1;
}
