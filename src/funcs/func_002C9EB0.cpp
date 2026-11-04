struct Box_002C9EB0 {
    unsigned char x;
    signed char y;
    unsigned char z;
};

struct Obj_002C9EB0 {
    char pad[0x80];
    Box_002C9EB0 m80;
    char pad83[0xC8 - 0x83];
    int mC8;
    int Same(Box_002C9EB0* b);
};

int Obj_002C9EB0::Same(Box_002C9EB0* b)
{
    if (mC8 == 1) {
        Box_002C9EB0* p = &m80;
        if (b->x != p->x || b->y != p->y || b->z != p->z)
            return 0;
    }
    return 1;
}
