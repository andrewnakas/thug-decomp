struct Rect_002BAC50 {
    unsigned char x;
    unsigned char m1;
    unsigned char y;
    unsigned char w;
    unsigned char m4;
    unsigned char h;
};
extern "C" bool func_002BAC50(Rect_002BAC50* a, Rect_002BAC50* b)
{
    unsigned char ax = a->x;
    unsigned char bx = b->x;
    if (ax >= bx && ax + a->w <= bx + b->w) {
        unsigned char ay = a->y;
        unsigned char by = b->y;
        if (ay >= by && ay + a->h <= by + b->h)
            return true;
    }
    return false;
}
