struct Box_002BC218 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};

struct Item_002BC218 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char rot;
    unsigned char flip;
    unsigned char pad5[3];
    int m8;
};

struct Piece_002BC218 {
    Box_002BC218 box;
    char pad6[2];
    unsigned int flags;
    char padC[0x24];
    unsigned int count;
    Item_002BC218 GetItem(int n);
};

extern "C" Item_002BC218* func_002BB3B0(void* self, unsigned int i);
extern "C" void* func_002C0368();
extern "C" Piece_002BC218* func_002BE5F0(void* self, int key, int* out);

Item_002BC218 Piece_002BC218::GetItem(int n)
{
    int k = 0;
    Item_002BC218 r;
    for (unsigned int i = 0; i < count; i++) {
        Item_002BC218* it = func_002BB3B0(this, i);
        Piece_002BC218* sub = func_002BE5F0(func_002C0368(), it->m8, 0);
        if (sub->flags & 0x80) {
            if (k == n) return *it;
            k++;
        } else {
            for (unsigned int j = 0; j < sub->count; j++) {
                Item_002BC218* c = func_002BB3B0(sub, j);
                if (k == n) {
                    r = *c;
                    r.m8 = c->m8;
                    r.rot = c->rot + it->rot;
                    Box_002BC218 pb = box;
                    Box_002BC218 sb = sub->box;
                    unsigned char x = it->x;
                    r.x = x;
                    unsigned char z = it->z;
                    r.z = z;
                    r.y = it->y + c->y;
                    switch (it->rot) {
                    case 0:
                        r.x = x + c->x;
                        r.z = z + c->z;
                        break;
                    case 1:
                        r.x = x + c->z;
                        r.z = z + (pb.w - c->x - sb.w);
                        break;
                    case 2:
                        r.x = x + (pb.w - c->x - sb.w);
                        r.z = z + (pb.d - c->z - sb.d);
                        break;
                    case 3:
                        r.x = x + (pb.d - c->z - sb.d);
                        r.z = z + c->x;
                        break;
                    }
                    return r;
                }
                k++;
            }
        }
    }
    return r;
}
