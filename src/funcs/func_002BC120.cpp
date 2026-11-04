struct Box_002BC120 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};

struct Item_002BC120 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char rot;
    unsigned char flip;
    unsigned char pad5[3];
    int m8;
};

struct Piece_002BC120 {
    char pad0[0x34];
    int m34;
};

extern "C" Item_002BC120* func_002BB3B0(void* self, int i);

struct Obj_002BC120 {
    Box_002BC120 m0;
    char pad6[0x2A];
    int m30;
    void Add(Piece_002BC120* piece, Box_002BC120* box, int rot, int flip);
};

void Obj_002BC120::Add(Piece_002BC120* piece, Box_002BC120* box, int rot, int flip)
{
    Item_002BC120* it = func_002BB3B0(this, m30++);
    if (!piece) return;
    it->x = box->x;
    it->y = box->y;
    it->z = box->z;
    it->rot = rot;
    it->flip = flip;
    it->m8 = piece->m34;
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
}
