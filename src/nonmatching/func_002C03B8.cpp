/* fuzzy: 50.0 */
struct Box_002C03B8 {
    unsigned char x;
    unsigned char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};

static inline bool Overlap_002C03B8(const Box_002C03B8* a, const Box_002C03B8* b)
{
    if (b->x >= a->x + a->w) return false;
    if (a->x >= b->x + b->w) return false;
    if (b->z >= a->z + a->d) return false;
    if (a->z >= b->z + b->d) return false;
    return true;
}

struct Obj_002C03B8 {
    char pad[0x6AA8];
    Box_002C03B8 m_boxes[8];
    unsigned int m_numBoxes;
    bool Hits(const Box_002C03B8* box);
};

bool Obj_002C03B8::Hits(const Box_002C03B8* box)
{
    for (unsigned int i = 0; i < m_numBoxes; i++) {
        bool hit = Overlap_002C03B8(box, &m_boxes[i]);
        if (hit) return true;
    }
    return false;
}
