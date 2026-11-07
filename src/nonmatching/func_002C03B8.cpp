/* fuzzy: 67.5 */
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
    return b->x < a->x + a->w && a->x < b->x + b->w && b->z < a->z + a->d && a->z < b->z + b->d;
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
