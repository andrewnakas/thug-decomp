extern "C" bool func_001E8708(void* params, unsigned int name);

class Item_00272300;

class Node_00272300 {
public:
    int m0;
    int m4;
    int m8;
    Item_00272300* mC;
    Item_00272300* m10;
    virtual ~Node_00272300();
};

class Item_00272300 : public Node_00272300 {
public:
    int m18[8];
    int m38;
    Item_00272300* Valid(unsigned k = 0) { return k < ~(unsigned)m4 ? this : 0; }
};

struct Head_00272300 {
    int m0;
    int m4;
    int m8;
    Item_00272300* mC;
};

struct Obj_00272300 {
    char pad[0x34];
    Head_00272300 m_list;
    int m44;
    int m48;
    int m4C;
    void Run(void* params);
};

void Obj_00272300::Run(void* params)
{
    if (func_001E8708(params, 0x97975226)) {
        Item_00272300* n = m_list.mC->Valid();
        while (n) {
            Item_00272300* next = n->mC->Valid();
            if (n->m38 != m4C)
                delete n;
            n = next;
        }
    } else {
        Item_00272300* n = m_list.mC->Valid();
        while (n) {
            Item_00272300* next = n->mC->Valid();
            delete n;
            n = next;
        }
    }
}
