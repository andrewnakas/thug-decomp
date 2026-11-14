/* fuzzy: 90.8 */
/* blocked: the game's list First() compares against a zero register (sltu with $a2 = 0, set at the top of the loop
   body); member ValidK(unsigned k = 0), an explicit index and the r = 0 form all fold to a plain movn. */
class Item_002710B8;

class Node_002710B8 {
public:
    int m0;
    int m4;
    int m8;
    Item_002710B8* mC;
    Item_002710B8* m10;
    virtual ~Node_002710B8();
};

class Item_002710B8 : public Node_002710B8 {
public:
    int m18;
    unsigned int m1C;
    int m20;
    int m24;
    int m28;
    int m2C;
    int m30;
    int m34;
    Item_002710B8* Valid()
    {
        Item_002710B8* r = 0;
        if (m4 != -1)
            r = this;
        return r;
    }
};

struct Head_002710B8 {
    int m0;
    int m4;
    int m8;
    Item_002710B8* mC;
    Item_002710B8* First(unsigned k = 0)
    {
        Item_002710B8* r = mC;
        return k < ~(unsigned)r->m4 ? r : 0;
    }
    void Remove(Item_002710B8* n, int key)
    {
        Item_002710B8* m = First();
        while (m) {
            Item_002710B8* mn = m->mC->Valid();
            if (!m->m34 && m->m28 == n->m18 && m->m30 == key && m->m2C == n->m20) {
                delete m;
                return;
            }
            m = mn;
        }
    }
};

struct Obj_002710B8 {
    char pad[0x1C];
    Head_002710B8 m_items;
    char pad2[0x34 - 0x2C];
    Head_002710B8 m_links;
    void Run(unsigned int mask, unsigned int bits);
};

void Obj_002710B8::Run(unsigned int mask, unsigned int bits)
{
    Item_002710B8* n = m_items.mC->Valid();
    while (n) {
        Item_002710B8* next = n->mC->Valid();
        n->m1C &= ~bits;
        if (n->m1C & mask) {
            int key = n->m2C;
            if (key) {
                m_links.Remove(n, key);
            }
            delete n;
        }
        n = next;
    }
}
