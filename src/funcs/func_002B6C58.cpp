struct Vec_002B6C58 {
    float x, y, z, w;
};

struct Shape_002B6C58 {
    int m0;
    int m4;
    int m8;
    virtual Vec_002B6C58 GetSize();
};

struct Box_002B6C58 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};

extern "C" void func_002B6C58(Shape_002B6C58* s, Box_002B6C58* b)
{
    Vec_002B6C58 v = s->GetSize();
    b->w = (int)((v.x + 2.0f) * (1.0f / 120.0f));
    b->h = (int)((v.y + 2.0f) * (1.0f / 48.0f));
    b->d = (int)((v.z + 2.0f) * (1.0f / 120.0f));
}
