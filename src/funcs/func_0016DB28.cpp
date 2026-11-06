struct Node_0016DB28 {
    char pad0[0x1C];
    unsigned int m1C;
    Node_0016DB28* m20;
    int m24;
    Node_0016DB28* m28;
    bool Detach(Node_0016DB28* parent);
};

bool Node_0016DB28::Detach(Node_0016DB28* parent)
{
    if ((m1C & 2) || !parent->m20)
        return false;
    if (parent->m20 == this) {
        parent->m20 = m28;
        return true;
    }
    for (Node_0016DB28* p = parent->m20; p->m28; p = p->m28) {
        if (p->m28 == this) {
            p->m28 = p->m28->m28;
            return true;
        }
    }
    return false;
}
